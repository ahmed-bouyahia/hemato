## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = hemato

hemato_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	DON.c DON.h \
	users.c users.h \
	donneur.c donneur.h \
	function.c function.h \
	fonction.c strcuture.h \
	director.c director.h \
	login.c login.h 

hemato_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

