// UPS2ndDayAir.cpp: implementation for the UPS2ndDayAir class
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



#include "UPS2ndDayAir.h"

#include "../utility/LiveRateRequest.h"

#include "../calculators/UPSCalculator.h"

using namespace rude::shipping;


namespace rude{
namespace shipping{

// Constructors & Destructor
//

UPS2ndDayAir::UPS2ndDayAir()
{
	setName("UPS 2nd Day Air");
}

UPS2ndDayAir::~UPS2ndDayAir()
{

}



bool UPS2ndDayAir::calculate(Package &p, Address &source, Address &dest)
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


	UPSCalculator calculator("www.ups.com", "9999999111111111", "myupsuserid", "myupspassword" );

	if(!calculator.calculate(p, source, dest, "02"))
	{
		setServiceCode(ERROR);
		setError(calculator.getError());
		return false;	
	}

	setPrice(calculator.getPrice() + 8.00);

	setServiceCode(SUCCESS);
	return true;

}


}}

