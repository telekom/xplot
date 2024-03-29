# Generated automatically from Makefile.in by configure.

#
# Makefile for xplot
#
# This software is being provided to you, the LICENSEE, by the
# Massachusetts Institute of Technology (M.I.T.) under the following
# license.  By obtaining, using and/or copying this software, you agree
# that you have read, understood, and will comply with these terms and
# conditions:
# 
# Permission to use, copy, modify and distribute, including the right to
# grant others the right to distribute at any tier, this software and
# its documentation for any purpose and without fee or royalty is hereby
# granted, provided that you agree to comply with the following
# copyright notice and statements, including the disclaimer, and that
# the same appear on ALL copies of the software and documentation,
# including modifications that you make for internal use or for
# distribution:
# 
# Copyright 1992,1993 by the Massachusetts Institute of Technology.
#                     All rights reserved.
# 
# THIS SOFTWARE IS PROVIDED "AS IS", AND M.I.T. MAKES NO REPRESENTATIONS
# OR WARRANTIES, EXPRESS OR IMPLIED.  By way of example, but not
# limitation, M.I.T. MAKES NO REPRESENTATIONS OR WARRANTIES OF
# MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE
# OF THE LICENSED SOFTWARE OR DOCUMENTATION WILL NOT INFRINGE ANY THIRD
# PARTY PATENTS, COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS.
# 
# The name of the Massachusetts Institute of Technology or M.I.T. may
# NOT be used in advertising or publicity pertaining to distribution of
# the software.  Title to copyright in this software and any associated
# documentation shall at all times remain with M.I.T., and USER agrees
# to preserve same.
# 

DEFINES= 

CC= gcc
CFLAGS=-g -O2 -Wall  -I/usr/X11R6/include ${DEFINES}
LIBS= -lm -lX11   -L/usr/X11R6/lib

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_MAN = ${INSTALL} -m 644

prefix = /usr/local

exec_prefix = ${prefix}

bindir = $(exec_prefix)/bin
mandir = $(exec_prefix)/man/man1

CFILES= xplot.c version_string.c coord.c unsigned.c signed.c timeval.c double.c dtime.c inject_buffer.c
OFILES= xplot.o version_string.o coord.o unsigned.o signed.o timeval.o double.o dtime.o inject_buffer.o

PROG= xplot

MANFILES= xplot.1 tcpdump2xplot.1

all:	${PROG}

${PROG}: ${OFILES}
	${CC} ${CFLAGS} -o $@.new ${OFILES} ${LIBS}
	-mv -f $@ $@.old
	mv -f $@.new $@

version_string.c: version
	echo 'char *version_string = "'`cat version`'";' >version_string.c

install: all
	mkdir -p $(bindir)
	$(INSTALL_PROGRAM) xplot $(bindir)/xplot
	$(INSTALL) tcpdump2xplot.pl $(bindir)/tcpdump2xplot
	mkdir -p $(mandir)
	$(INSTALL_MAN) $(MANFILES) $(mandir)
clean:
	rm -f ${PROG} ${PROG}.old *.o version_string.c

# (note: "mkdep" below denotes the BSD 4.3+tahoe /usr/bin/mkdep )
depend:
	mkdep ${INCLUDES} ${CFILES}
