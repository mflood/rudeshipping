// Provider.cpp: implementation for the Provider class 
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



#include "Provider.h"

#include <rude/config.h>

#include "Service.h"


#include <string>
#include <stdio.h>

using namespace std;

namespace rude{
namespace shipping{

// Static Variable Definitions
// 

// Static Method Definitions
// 

// Constructors & Destructor
// 
Provider::Provider()
{
	d_description="";
	d_error = "";

	d_currentService = 0;
}

Provider::~Provider()
{
	std::vector<Service*>::iterator iter;
	for(iter = d_vector.begin(); iter != d_vector.end(); iter++)
	{
		delete (*iter);
	}
}

void Provider::setDescription(const char *desc)
{
	d_description = desc ? desc : "";
}


const char *Provider::getDescription()
{
	return d_description.c_str();
}


bool Provider::configure(Config &config)
{
	if(concreteConfigure(config))
	{
		return loadServices(config);
	}
	return false;

}	

bool Provider::loadServices(Config &config)
{



	return true;

}

//=


// Instance Method Definitions
// 


void Provider::setService(int index)
{
	std::vector<Service*>::iterator iter;
	int x = 0;
	for (iter = d_vector.begin(); iter != d_vector.end(); iter++)
	{
		if (x == index)
		{
			d_currentService = (*iter);
			return;
		}
		x++;
	}
	d_currentService = 0;
}

// Instance Method Definitions
// 





void Provider::setError(const char *error)
{
	d_error = error ? error : "";
}

const char *Provider::getError() const
{
	return d_error.c_str();
}


int Provider::getNumServices() const
{
	return d_vector.size();
}

double Provider::getServicePrice() const
{
	if (d_currentService)
	{
		return d_currentService->getPrice();
	}
	return 0;
}


const char *Provider::getServiceDescription() const
{
	if(d_currentService)
	{
		return d_currentService->getDescription();
	}
	return "No Current Service";

}

const char *Provider::getServiceName() const
{
	if (d_currentService)
	{
		return d_currentService->getName();
	}
	return "No current Service";
}

const char *Provider::getServiceError() const
{
	if (d_currentService)
	{
		return d_currentService->getError();
	}
	return 0;
}

Service *Provider::getCurrentService()
{
	return d_currentService;
}

} // end namespace shipping
} // end namespace rude


