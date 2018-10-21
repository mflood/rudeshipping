// Implementation.cpp: implementation for the Implementation class
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



#include "Implementation.h"

#include "Service.h"

#include <rude/config.h>

#ifndef INCLUDED_ADDRESS_H
#include "Address.h"
#endif

#ifndef INCLUDED_Package_H
#include "Package.h"
#endif

#ifndef INCLUDED_PROVIDER_H
#include "Provider.h"
#endif

#ifndef INCLUDED_PROVIDERFACTORY_H
#include "AllProvider.h"
#endif


using namespace rude::shipping;

namespace rude{
namespace shipping{

// Static Variable Definitions
//

// Static Method Definitions
//

// Constructors & Destructor
//
Implementation::Implementation()
{
	d_error = "";
	d_currentProvider = 0;
}

Implementation::~Implementation()
{
	std::vector<Provider*>::iterator iter;
	for (iter=d_vector.begin(); iter != d_vector.end(); iter++)
	{
		delete (*iter);
	}
}

// Creates the providers, and sets their description
// based on the configuration file
// Then lets them configure themselves
// Also sets the default information for the address object
// 
// in the config file, requires two sections:
//
// [source address]
// country = <UPS country code>
// zip = <zipcode>
//
// [providers]
// <factory name> = <display name>
// 
bool Implementation::initialize(const char *configfile)
{

	Config config;
	if(config.load(configfile))
	{
		config.setSection("source address", true);
		setSourceCountryCode(config.getStringValue("country"));
		setSourceZip(config.getStringValue("zip"));
	}


	
	Provider *provider = new AllProvider();
	provider->setDescription("ALL SERVICES");
	if(!provider->configure(config))
	{
		setError(provider->getError());
		return false;
	}

	d_vector.push_back(provider);
	d_currentProvider = provider;

	return true;
	
}


// Instance Method Definitions
//

void Implementation::resetPackage()
{
	d_package.setHeightInches(0);
	d_package.setWidthInches(0);
	d_package.setLengthInches(0);
	d_package.setWeightPounds(0);
	d_packagemaker.reset();
}

void Implementation::addPackage(double length_in, double width_in, double height_in, double pounds)
{
	d_packagemaker.addPackage(length_in, width_in, height_in, pounds);
	d_package.setHeightInches(d_packagemaker.getHeight());
	d_package.setLengthInches(d_packagemaker.getLength());
	d_package.setWidthInches(d_packagemaker.getWidth());
	d_package.setWeightPounds(d_packagemaker.getWeight());
}

void Implementation::setPackageHeight(double inches)
{
	d_package.setHeightInches(inches);
}

void Implementation::setPackageWidth(double inches)
{
	d_package.setWidthInches(inches);
}

void Implementation::setPackageLength(double inches)
{
	d_package.setLengthInches(inches);
}

void Implementation::setPackageWeight(double pounds)
{
	d_package.setWeightPounds(pounds);
}

double Implementation::getPackageLength()
{
	return d_package.getLengthInches();
}

double Implementation::getPackageWidth()
{
	return d_package.getWidthInches();
}

double Implementation::getPackageHeight()
{
	return d_package.getHeightInches();
}

double Implementation::getPackageWeight()
{
	return d_package.getWeightPounds();
}

void Implementation::setSourceCity(const char *city)
{
	d_sourceaddress.setCity(city);
}

void Implementation::setSourceState(const char *state)
{
	d_sourceaddress.setState(state);
}

void Implementation::setSourceCountryCode(const char *country)
{
	d_sourceaddress.setCountryCode(country);
}

void Implementation::setSourceZip(const char *zip)
{
	d_sourceaddress.setZip(zip);
}

void Implementation::setDestCity(const char *city)
{
	d_destaddress.setCity(city);
}

void Implementation::setDestState(const char *state)
{
	d_destaddress.setState(state);
}

void Implementation::setDestCountryCode(const char *country )
{
	d_destaddress.setCountryCode(country);
}

void Implementation::setDestZip(const char *zip)
{
	d_destaddress.setZip(zip);
}

void Implementation::setDestIsResidence(bool isit)
{
	d_destaddress.isResidence(isit);
}

bool Implementation::calculate()
{
	if(d_vector.size())
	{
		std::vector<Provider*>::iterator iter;
		for (iter = d_vector.begin(); iter != d_vector.end(); iter++)
		{
			(*iter)->calculate(d_package, d_sourceaddress, d_destaddress);
		}
		return true;
	}
	else
	{
		setError("No Providers Available");
		return false;
	}
}
	
int Implementation::getNumProviders() const
{
	return d_vector.size();
}

void Implementation::setProvider(int index)
{
	std::vector<Provider*>::iterator iter;
	int x = 0;
	for (iter = d_vector.begin(); iter != d_vector.end(); iter++)
	{
		if (x == index)
		{
			d_currentProvider = (*iter);
			return;
		}
		x++;
	}
	d_currentProvider = 0;
}

const char *Implementation::getProviderName() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getDescription();
	}
	else
	{
		return "No current Provider";
	}
}

const char *Implementation::getProviderError() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getError();
	}
	else
	{
		return "No current Provider";
	}
}

int Implementation::getNumServices() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getNumServices();
	}
	return 0;
}


void Implementation::setService(int index)
{
	if (d_currentProvider)
	{
		d_currentProvider->setService(index);
	}
}

const char *Implementation::getServiceName() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getServiceName();
	}
	return "No current Provider";
}
	
const char *Implementation::getServiceDescription() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getServiceDescription();
	}
	return "No current Provider";
}

	
double Implementation::getServicePrice() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getServicePrice();
	}
	return 0;
}

const char *Implementation::getServiceError() const
{
	if (d_currentProvider)
	{
		return d_currentProvider->getServiceError();
	}
	return "No current Provider";
}

	
const char *Implementation::getError() const
{
	return d_error.c_str();
}

} // end namespace shipping
} // end namespace rude
