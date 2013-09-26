## Process this file with automake to produce Makefile.in

TESTS = check_snake
check_PROGRAMS = check_snake
check_snake_SOURCES = check_snake.c $(top_builddir)/src/snake.h
check_snake_CFLAGS = @CHECK_CFLAGS@
check_snake_LDADD = $(top_builddir)/src/libsnake.la @CHECK_LIBS@
