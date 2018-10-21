// PickUp.cpp: implementation for the PickUp class
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



#include "PickUp.h"

#include "../utility/USPSPackageSizeFinder.h"

#include "../utility/LiveRateRequest.h"

#include "../calculators/USPSDomesticCalculator.h"

using namespace rude::shipping;


namespace rude{
namespace shipping{

// Constructors & Destructor
//

PickUp::PickUp()
{
	setName("Pick Up");
}

PickUp::~PickUp()
{

}



bool PickUp::calculate(Package &p, Address &source, Address &dest)
{
	// First check Origination Address
	//
	
	string source_state=source.getState();
	string dest_state=dest.getState();
	if(source_state != dest_state)
	{
		setServiceCode(INVALID_DESTINATION_ADDRESS);
		setError("Destination State was not the same as Origination State");
		return false;
	}

	setPrice(0.00);
	setServiceCode(SUCCESS);
	return true;

}


}}

