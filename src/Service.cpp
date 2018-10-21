// Service.cpp: implementation for the ship_service class 
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


#include "Service.h"

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

namespace rude{
namespace shipping{

// Static Variable Definitions
// 

// Static Method Definitions
// 

//  Constructors & Destructor
// 
Service::Service()
{
	d_name = "";
	d_desc = "";
	d_price = 0;
	d_error = "";
}

Service::~Service()
{
}

void Service::setPrice(double price) 
{
 	if (price > 0)
        {
		d_price = price;
        }	
        else
        {
                d_price = 0;
        }
}
	
void Service::setName(const char *sname)
{
	d_name = sname? sname : "";
}

void Service::setDescription(const char *desc)
{
	d_desc = desc ? desc : "";
}

void Service::setError(const char *error)
{
	d_error = error ? error : "";
}

double Service::getPrice() const
{
	return d_price;
}

const char *Service::getName() const
{
	return d_name.c_str();
}

const char *Service::getDescription() const
{
	if(d_desc != "")
	{
		return d_desc.c_str();
	}
	else
	{
		return d_name.c_str();
	}
}

const char *Service::getError() const
{
	return d_error.c_str();
}

void Service::setServiceCode(ServiceCode s)
{
	d_code=s;
}

ServiceCode Service::getServiceCode()
{
	return d_code;
}


} // end namespace shipping
} // end namespace rude


