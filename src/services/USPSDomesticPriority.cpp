// USPSDomesticPriority.cpp: implementation for the USPSDomesticPriority class
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



#include "USPSDomesticPriority.h"

#include "../utility/USPSPackageSizeFinder.h"

#include "../utility/LiveRateRequest.h"

#include "../calculators/USPSDomesticCalculator.h"

using namespace rude::shipping;


namespace rude{
namespace shipping{

// Constructors & Destructor
//

USPSDomesticPriority::USPSDomesticPriority()
{
	setName("USPS Domestic Priority");
}

USPSDomesticPriority::~USPSDomesticPriority()
{

}



bool USPSDomesticPriority::calculate(Package &p, Address &source, Address &dest)
{
	// First check Origination Address
	//
	string temp=source.getCountryCode();
	if(temp != "US")
	{
		setServiceCode(INVALID_ORIGIN_ADDRESS);
		setError("Origination Country was not US");
		return false;
	}

	// check source zip code
	//
	temp=source.getZip();
	if(temp  == "")
	{
		setServiceCode(ERROR);
		setError("Missing Origin Zip Code");
		return false;
	}


	// Then check Destination Address
	// 
	temp=dest.getCountryCode();
	if(temp != "US")
	{
		setServiceCode(INVALID_DESTINATION_ADDRESS);
		setError("Destination Country was not US");
		return false;
	}

	// check source zip code
	//
	temp=dest.getZip();
	if(temp  == "")
	{
		setServiceCode(ERROR);
		setError("Missing Destination Zip Code");
		return false;
	}

	// check the package 
	//
	USPSPackageSizeFinder pf;
	string size=pf.getSize(&p);
	if(size == "")
	{
		setServiceCode(INVALID_PACKAGE);
		setError("Package size too big");
		return false;	
	}

	USPSDomesticCalculator calculator("Production.ShippingAPIs.com", "092FUELC1091", "671UI81ES103");

	if(!calculator.calculate(p, source, dest, "Priority"))
	{
		setServiceCode(ERROR);
		setError(calculator.getError());
		return false;	
	}

	setPrice(calculator.getPrice() + 10.00);

	setServiceCode(SUCCESS);
	return true;

}


}}

