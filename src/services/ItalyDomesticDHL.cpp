// ItalyDomesticDHL.cpp: implementation for the ItalyDomesticDHL class
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



#include "ItalyDomesticDHL.h"

#include "../utility/USPSPackageSizeFinder.h"

#include "../utility/LiveRateRequest.h"

#include "../calculators/USPSDomesticCalculator.h"

using namespace rude::shipping;


namespace rude{
namespace shipping{

// Constructors & Destructor
//

ItalyDomesticDHL::ItalyDomesticDHL()
{
	setName("Italy Domestic DHL");
}

ItalyDomesticDHL::~ItalyDomesticDHL()
{

}



bool ItalyDomesticDHL::calculate(Package &p, Address &source, Address &dest)
{
	// First check Origination Address
	//
	string temp=source.getCountryCode();
	if(temp != "IT")
	{
		setServiceCode(INVALID_ORIGIN_ADDRESS);
		setError("Origination Country was not IT");
		return false;
	}



	// Then check Destination Address
	// 
	temp=dest.getCountryCode();
	if(temp != "IT")
	{
		setServiceCode(INVALID_DESTINATION_ADDRESS);
		setError("Destination Country was not IT");
		return false;
	}



	double weight=p.getWeightKilograms();

	
	if(weight > 30)
	{
		double price = 19.85;
		double extraweight = weight - 30;
		
		// add 1 because (int) cast takes floor, not ceiling
		//
		price += ((int) extraweight + 1) * 1.45;
		
		setPrice(price);	

	}
	else if(weight > 20)
	{
		setPrice(19.85);
	}
	else if(weight > 10 )
	{
		setPrice(14.55);
	}
	else
	{
		setPrice(9.50);
	}
	
	

	setServiceCode(SUCCESS);
	return true;

}


}}

