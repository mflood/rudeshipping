// shipping.cpp: implementation for the Shipping class
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

#include "shipping.h"

#ifndef INCLUDED_Implementation_H
#include "Implementation.h"
#endif

using namespace rude::shipping;

namespace rude{

// Static Method Definitions
/////////////////////////////


const char *Shipping::version()
{
	return Implementation::version();
}


// Constructors & Destructor
/////////////////////////////////


Shipping::Shipping()
{
	d_implementation = new Implementation();
}


bool Shipping::initialize(const char *configfile)
{
	return d_implementation->initialize(configfile);
}

Shipping::~Shipping()
{
	delete d_implementation;
}


// Member method Definitions
/////////////////////////////

void Shipping::resetPackage()
{
	d_implementation->resetPackage();
}

void Shipping::addPackage(double length_in, double width_in, double height_in, double pounds)
{
	d_implementation->addPackage(length_in, width_in, height_in, pounds);
}

void Shipping::setPackageHeight(double inches)
{
	d_implementation->setPackageHeight(inches);
}

void Shipping::setPackageWidth(double inches)
{
	d_implementation->setPackageWidth(inches);
}

void Shipping::setPackageLength(double inches)
{
	d_implementation->setPackageLength(inches);
}

void Shipping::setPackageWeight(double pounds)
{
	d_implementation->setPackageWeight(pounds);
}

double Shipping::getPackageLength()
{
	return d_implementation->getPackageLength();
}

double Shipping::getPackageWidth()
{
	return d_implementation->getPackageWidth();
}

double Shipping::getPackageHeight()
{
	return d_implementation->getPackageHeight();
}

double Shipping::getPackageWeight()
{
	return d_implementation->getPackageWeight();
}

void Shipping::setSourceCity(const char *city)
{
	d_implementation->setSourceCity(city);
}

void Shipping::setSourceState(const char *state)
{
	d_implementation->setSourceState(state);
}

void Shipping::setSourceCountryCode(const char *code)
{
	d_implementation->setSourceCountryCode(code);
}

void Shipping::setSourceZip(const char *zipcode)
{
	d_implementation->setSourceZip(zipcode);
}

void Shipping::setDestCity(const char *city)
{
	d_implementation->setDestCity(city);
}

void Shipping::setDestState(const char *state)
{
	d_implementation->setDestState(state);
}

void Shipping::setDestCountryCode(const char *code)
{
	d_implementation->setDestCountryCode(code);
}

void Shipping::setDestZip(const char *zipcode)
{
	d_implementation->setDestZip(zipcode);
}

void Shipping::setDestIsResidence(bool isit)
{
	d_implementation->setDestIsResidence(isit);
}	
bool Shipping::calculate()
{
	return d_implementation->calculate();
}
	
int Shipping::getNumProviders() const
{
	return d_implementation->getNumProviders();
}

void Shipping::setProvider(int index)
{
	d_implementation->setProvider(index);
}

const char *Shipping::getProviderName() const
{
	return d_implementation->getProviderName();
}

const char *Shipping::getProviderError() const
{
	return d_implementation->getProviderError();
}

int Shipping::getNumServices() const
{
	return d_implementation->getNumServices();
}

void Shipping::setService(int index)
{
	d_implementation->setService(index);
}

const char *Shipping::getServiceName() const
{
	return d_implementation->getServiceName();
}

const char *Shipping::getServiceDescription() const
{
	return d_implementation->getServiceDescription();
}

double Shipping::getServicePrice() const
{
	return d_implementation->getServicePrice();
}

const char *Shipping::getServiceError() const
{
	return d_implementation->getServiceError();
}	
	
const char *Shipping::getError() const
{
	return d_implementation->getError();
}

}
