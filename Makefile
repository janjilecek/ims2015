#############################################################################
# Makefile for building: ims_proj
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  ims_proj.pro
# Template: app
# Command: /usr/lib/qt/bin/qmake -o Makefile ims_proj.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -Wall -W -fPIC $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -lsimlib -lm -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -std=c++0x -Wall -W -fPIC $(DEFINES)
INCPATH       = -I. -I/usr/lib/qt/mkspecs/linux-g++
QMAKE         = /usr/lib/qt/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = ims_proj1.0.0
DISTDIR = /home/john/ims/ims_proj/.tmp/ims_proj1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-O1,--sort-common,--as-needed,-z,relro
LIBS          = $(SUBLIBS) -lsimlib -lm 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		krizovatka.cpp \
		rameno.cpp \
		semafor.cpp \
		dopravniprostredek.cpp \
		generator.cpp \
		pruh.cpp \
		outputgnuplot.cpp \
		dataformatter.cpp 
OBJECTS       = main.o \
		krizovatka.o \
		rameno.o \
		semafor.o \
		dopravniprostredek.o \
		generator.o \
		pruh.o \
		outputgnuplot.o \
		dataformatter.o
DIST          = ims_proj.pro krizovatka.h \
		rameno.h \
		semafor.h \
		dopravniprostredek.h \
		generator.h \
		pruh.h \
		outputgnuplot.h \
		dataformatter.h main.cpp \
		krizovatka.cpp \
		rameno.cpp \
		semafor.cpp \
		dopravniprostredek.cpp \
		generator.cpp \
		pruh.cpp \
		outputgnuplot.cpp \
		dataformatter.cpp
QMAKE_TARGET  = ims_proj
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = ims_proj


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)


qmake: FORCE
	@$(QMAKE) -o Makefile ims_proj.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp krizovatka.h \
		rameno.h \
		semafor.h \
		pruh.h \
		generator.h \
		dopravniprostredek.h \
		outputgnuplot.h \
		dataformatter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

krizovatka.o: krizovatka.cpp krizovatka.h \
		rameno.h \
		semafor.h \
		pruh.h \
		generator.h \
		dopravniprostredek.h \
		outputgnuplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o krizovatka.o krizovatka.cpp

rameno.o: rameno.cpp rameno.h \
		semafor.h \
		pruh.h \
		generator.h \
		dopravniprostredek.h \
		outputgnuplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o rameno.o rameno.cpp

semafor.o: semafor.cpp semafor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o semafor.o semafor.cpp

dopravniprostredek.o: dopravniprostredek.cpp dopravniprostredek.h \
		pruh.h \
		semafor.h \
		generator.h \
		outputgnuplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dopravniprostredek.o dopravniprostredek.cpp

generator.o: generator.cpp generator.h \
		pruh.h \
		semafor.h \
		outputgnuplot.h \
		dopravniprostredek.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o generator.o generator.cpp

pruh.o: pruh.cpp pruh.h \
		semafor.h \
		generator.h \
		dopravniprostredek.h \
		outputgnuplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pruh.o pruh.cpp

outputgnuplot.o: outputgnuplot.cpp outputgnuplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o outputgnuplot.o outputgnuplot.cpp

dataformatter.o: dataformatter.cpp dataformatter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataformatter.o dataformatter.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

