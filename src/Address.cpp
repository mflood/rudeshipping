// Address.cpp: implementation for the Address class
//
// Copyright (C) 2003, 2004, 2005 Matthew Flood
// See file AUTHORS for contact information
//
// This file is part of RudeShipping.
//
// RudeShipping is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
// 
// RudeShipping is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with RudeShipping; (see COPYING) if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
// 02111-1307, USA.
//------------------------------------------------------------------------

 
#include "Address.h"

using namespace rude::shipping;


namespace rude{

namespace shipping{

// Static Variable Definitions
//


//Static Method Definitions
//


// Constructors & Destructor
//
Address::Address()
{
	d_countrycode = "";
	d_zip = "";
	d_city = "";
	d_state = "";
	d_isResidence = false;
}

Address::~Address()
{

}


//Instance Method Definitions
//
void Address::setCountryCode(const char *countrycode)
{
	d_countrycode = countrycode ? countrycode : "";
}

const char *Address::getCountryCode() const
{
	return d_countrycode.c_str();
}

void Address::setZip(const char *zip)
{
	d_zip = zip ? zip : "";
}

const char *Address::getZip() const
{
	return d_zip.c_str();
}


void Address::setCity(const char *city)
{
	d_city = city ? city : "";
}

const char *Address::getCity() const
{
	return d_city.c_str();
}


void Address::setState(const char *state)
{
	d_state = state ? state : "";
}

const char *Address::getState() const
{
	return d_state.c_str();
}


void Address::isResidence(bool yesno)
{
	d_isResidence = yesno;
}

bool Address::isResidence()
{
	return d_isResidence;
}

}}

