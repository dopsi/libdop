#
# The MIT License (MIT)
#
# Copyright (c) 2015 Simon Doppler
#
# Permission is hereby granted, free of charge, to any person obtaining a 
# copy of this software and associated documentation files (the 
# "Software"), to deal in the Software without restriction, including 
# without limitation the rights to use, copy, modify, merge, publish, 
# distribute, sublicense, and/or sell copies of the Software, and to 
# permit persons to whom the Software is furnished to do so, subject to 
# the following conditions:
#
# The above copyright notice and this permission notice shall be included 
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#


# Compilation options
export CC = gcc
export CFLAGS = -c -Wall -g -fPIC
LDFLAGS = -shared

# Directories
SRCDIR = src
INCLUDES = include/dop

# Files
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
FILES = src include pkgconfig Makefile

# Program attributes
TARGET = libdop
VERSION_FILE	= include/dop/version.h
VERSION_MAJOR	= $(shell grep VER_MAJOR $(VERSION_FILE) | cut -d ' ' -f 3)
VERSION_MINOR	= $(shell grep VER_MINOR $(VERSION_FILE) | cut -d ' ' -f 3)
VERSION_REVISION	= $(shell grep VER_REVISION $(VERSION_FILE) | cut -d ' ' -f 3)
VERSION	= $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_REVISION)

# Tools
PACK = tar
COMPRESS = xz
CP = cp
MKDIR = mkdir
PACKAGE = $(TARGET)-$(VERSION).tar

# Installation options
PREFIX	= /usr/local
OWNER	= root
GROUP	= root
MODE	= 644
INSTALL	= install -o $(OWNER) -g $(GROUP) -m $(MODE) 

all: $(TARGET).so

$(TARGET).so:	src
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS)

src:
	$(MAKE) -C src

.PHONY:	src clean mrproper install init run pack pack-test depend uninstall

clean:
	rm -rf $(OBJECTS)

distclean: clean
	rm -rf $(TARGET).so
	rm -f $(TARGET)-*.tar.*

pack:	distclean
	tar cf $(PACKAGE) $(FILES)
	xz -f $(PACKAGE)

pack-test: pack
	mkdir test
	(cp $(PACKAGE).xz test && cd test && tar xf $(PACKAGE).xz && $(MAKE)) || rm -rf test
	rm -rf test

install:	$(TARGET).so
	$(MKDIR) -p $(PREFIX)/lib
	$(INSTALL) -s $(TARGET).so $(PREFIX)/lib
	$(MKDIR) -p $(PREFIX)/include/dop
	$(CP) -r include/dop/* $(PREFIX)/include/dop
	$(MKDIR) -p $(PREFIX)/lib/pkgconfig
	$(CP) -rT pkgconfig $(PREFIX)/lib/pkgconfig
	sed -i -e "s|MK_PREFIX|$(PREFIX)|g" $(PREFIX)/lib/pkgconfig/libdop.pc

depend:
	$(MAKE) -C src $@

uninstall:
	$(RM) -r $(PREFIX)/include/dop
	$(RM) $(PREFIX)/lib/libdop.so
	$(RM) $(PREFIX)/lib/pkgconfig/libdop.pc
