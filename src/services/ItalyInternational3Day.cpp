// ItalyInternational3Day.cpp: implementation for the ItalyInternational3Day class
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



#include "ItalyInternational3Day.h"

using namespace rude::shipping;


namespace rude{
namespace shipping{

// Constructors & Destructor
//

ItalyInternational3Day::ItalyInternational3Day()
{
	setName("Italy International 3 Day");
}

ItalyInternational3Day::~ItalyInternational3Day()
{

}



bool ItalyInternational3Day::calculate(Package &p, Address &source, Address &dest)
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
	if(temp == "IT")
	{
		setServiceCode(INVALID_DESTINATION_ADDRESS);
		setError("Destination Country was IT");
		return false;
	}



	double weight=p.getWeightKilograms();
	

	
	if(weight > 30)
	{
		setServiceCode(INVALID_PACKAGE);
		setError("Package was more than 30 Kilograms");
		return false;	

	}
	else if(weight > 20)
	{
		setPrice(137.71);
	}
	else if(weight > 10)
	{
		setPrice(99.25);
	}
	else
	{
		setPrice(60.92);
	}

	setServiceCode(SUCCESS);
	return true;

}


}}

