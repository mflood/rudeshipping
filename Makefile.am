# Makefile.am for RudeShipping C++ Library
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

lib_LTLIBRARIES = librudeshipping.la

librudeshipping_la_SOURCES =	\
	src/Package.h \
	src/Package.cpp \
	src/Address.h \
	src/Address.cpp \
	src/Provider.h \
	src/Provider.cpp \
	src/AllProvider.h \
	src/AllProvider.cpp \
	src/Service.h \
	src/Service.cpp \
	src/shipping.h \
	src/shipping.cpp \
	src/packagemaker.h \
	src/packagemaker.cpp \
	src/AbstractImplementation.h \
	src/AbstractImplementation.cpp \
	src/Implementation.h \
	src/Implementation.cpp \
	src/utility/USPSPackageSizeFinder.h \
	src/utility/USPSPackageSizeFinder.cpp \
	src/utility/URLEncoder.h \
	src/utility/URLEncoder.cpp \
	src/utility/UPSCodeToUSPSCountry.h \
	src/utility/UPSCodeToUSPSCountry.cpp \
	src/utility/LiveRateRequest.h \
	src/utility/LiveRateRequest.cpp \
	src/services/PickUp.h \
	src/services/PickUp.cpp \
	src/services/USPSDomesticParcelPost.h \
	src/services/USPSDomesticParcelPost.cpp \
	src/services/USPSDomesticExpress.h \
	src/services/USPSDomesticExpress.cpp \
	src/services/USPSDomesticPriority.h \
	src/services/USPSDomesticPriority.cpp \
	src/services/ItalyDomesticDHL.h \
	src/services/ItalyDomesticDHL.cpp \
	src/services/ItalyDomestic3Day.h \
	src/services/ItalyDomestic3Day.cpp \
	src/services/ItalyInternational3Day.h \
	src/services/ItalyInternational3Day.cpp \
	src/services/ItalyInternationalDHL.h \
	src/services/ItalyInternationalDHL.cpp \
	src/services/UPSStandard.h \
	src/services/UPSStandard.cpp \
	src/services/UPSGround.h \
	src/services/UPSGround.cpp \
	src/services/UPSNextDayAir.h \
	src/services/UPSNextDayAir.cpp \
	src/services/UPS2ndDayAir.h \
	src/services/UPS2ndDayAir.cpp \
	src/services/UPS3DaySelect.h \
	src/services/UPS3DaySelect.cpp \
	src/services/UPSExpressSaver.h \
	src/services/UPSExpressSaver.cpp \
	src/services/UPSWorldwideExpress.h \
	src/services/UPSWorldwideExpress.cpp \
	src/services/UPSWorldwideExpedited.h \
	src/services/UPSWorldwideExpedited.cpp \
	src/calculators/USPSDomesticCalculator.h \
	src/calculators/USPSDomesticCalculator.cpp \
	src/calculators/UPSCalculator.h \
	src/calculators/UPSCalculator.cpp


librudeshipping_la_LDFLAGS = -version-info 3:1:1
librudeshipping_la_LIBADD = -lrudesocket -lrudeconfig


pkginclude_HEADERS = src/shipping.h
pkgincludedir = $(includedir)/rude


AUTOMAKE_OPTIONS = gnits dist-bzip2 dist-shar dist-zip


