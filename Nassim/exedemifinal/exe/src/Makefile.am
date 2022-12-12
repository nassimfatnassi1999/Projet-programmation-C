## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = exe

exe_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	function.c function.h   \
	function_Stat_Nassim.c\
	bv.c bv.h \
	election.c election.h \
	login.h login.c
	

exe_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

