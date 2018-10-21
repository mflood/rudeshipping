// AllProvider.cpp
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


#include "AllProvider.h"

#include "Service.h"
#include "src/services/USPSDomesticParcelPost.h"
#include "src/services/USPSDomesticExpress.h"
#include "src/services/USPSDomesticPriority.h"
#include "src/services/ItalyDomesticDHL.h"
#include "src/services/ItalyDomestic3Day.h"
#include "src/services/ItalyInternationalDHL.h"
#include "src/services/ItalyInternational3Day.h"
#include "src/services/UPSStandard.h"
#include "src/services/UPSGround.h"
#include "src/services/UPSNextDayAir.h"
#include "src/services/UPS2ndDayAir.h"
#include "src/services/UPS3DaySelect.h"
#include "src/services/UPSWorldwideExpress.h"
#include "src/services/UPSWorldwideExpedited.h"
#include "src/services/UPSExpressSaver.h"
#include "src/services/PickUp.h"

using namespace std;

namespace rude{
namespace shipping{

AllProvider::AllProvider()
{

}


bool AllProvider::concreteConfigure(Config &config)
{

        Service *service = new UPSGround();

	
	d_currentService = service;
        d_vector.push_back(service);

	
        d_vector.push_back(new UPSStandard()); // canada
        d_vector.push_back(new UPS3DaySelect());
        d_vector.push_back(new UPS2ndDayAir());
        d_vector.push_back(new UPSNextDayAir());
		
        d_vector.push_back(new USPSDomesticParcelPost());
        d_vector.push_back(new USPSDomesticPriority());

        d_vector.push_back(new UPSWorldwideExpress());
        d_vector.push_back(new UPSWorldwideExpedited());


        // d_vector.push_back(new UPSExpressSaver());
	// d_vector.push_back(new USPSDomesticExpress());
	
        d_vector.push_back(new PickUp());
	
        d_vector.push_back(new ItalyDomesticDHL());
        d_vector.push_back(new ItalyDomestic3Day());
        d_vector.push_back(new ItalyInternationalDHL());
        d_vector.push_back(new ItalyInternational3Day());
	
	return true;
}


const char *AllProvider::getName() const
{
	return "All Known Services";
}


bool AllProvider::calculate(Package &package, Address &src, Address &dest)
{
	   int num = d_vector.size();
	   for(int x=0; x< num; x++)
	   {
		Service *s = d_vector[x];
		s->calculate(package, src, dest);
	   }
	   return true;
}


}}


