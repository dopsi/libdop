#include "dop/filesystem.h"
#include "dop/version.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int remove_r(char * path) {
	char p[1024] = { '\0' };
	int ret=0;
	
	strcpy(p, path);
	struct stat s;

	if (stat(path, &s)) {
		perror(path);
		return -1;
	}

	if (S_ISDIR(s.st_mode)) {
		// remove directory
		DIR * d = opendir(path);
		struct dirent * de;

		while ( (de = readdir(d)) != NULL) {
			memset(p, '\0', sizeof(p));
			strcpy(p, path);
			if ( strcmp(de->d_name, ".") && strcmp(de->d_name, "..")) {
				if ( ( ret = remove_r( strcat(strcat(p, "/"), de->d_name) ) )) {
					return ret;
				}
			}
		}
		if (rmdir(path)) {
			perror("rmdir");
			return 1;
		}
		return 0;
	} else if (S_ISREG(s.st_mode)) {
		remove(path);
		return 0;
	} else {
		fprintf(stderr, "Cannot remove, wrong type\n");
		return 1;
	}
}

