# Process this file with autoconf to produce a configure script.
#
# Copyright (C) 2003, 2004, 2005 Matthew Flood
# See file AUTHORS for contact information
#
# This file is part of RudeShipping.
#
# RudeShipping is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# RudeShipping is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with RudeConfig; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#
#------------------------------------------------------------------------

AC_INIT(RudeShipping, 3.1.1, matt@rudeserver.com, rudeshipping)
AC_CANONICAL_TARGET([])
AM_INIT_AUTOMAKE(rudeshipping, 3.1.1)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_LIBTOOL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lrudesocket':
AC_CHECK_LIB([rudesocket], [main])
AC_CHECK_LIB([rudeconfig], [main])

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h])


# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strstr])
AC_OUTPUT(Makefile )


