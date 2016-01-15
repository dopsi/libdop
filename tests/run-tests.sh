#!/bin/sh

for i in *.test ; do
	echo "### Running test '$i' ###"
	LD_LIBRARY_PATH="..:$LD_LIBRARY_PATH" "./$i"
	echo "#########################"
	echo ""
done
