// USPSPackageSizeFinder.cpp
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




#include "USPSPackageSizeFinder.h"
#include "../Package.h"

#include <string.h>
#include <stdio.h>


namespace rude{
namespace shipping{

const char *USPSPackageSizeFinder::getSize(Package *p)
{
	double dim[3]; // holds length, width, height
	dim[0] = p->getLengthInches();
	dim[1] = p->getWidthInches();
	dim[2] = p->getHeightInches();

	// put the dims in order
        //
	if(dim[0] < dim[2])
	{
		double t = dim[2];
		dim[2]=dim[0];
		dim[0]=t;
	}
	
	if(dim[0] < dim[1])
	{
		double t = dim[1];
		dim[1]=dim[0];
		dim[0]=t;
	}

	if(dim[1] < dim[2])
	{
		double t = dim[2];
		dim[2]=dim[1];
		dim[1]=t;
	}

	
	double girth = (2 * dim[1] ) + ( 2 * dim[2] );
	double packageLength = dim[0] + girth;
	if (packageLength <= 84.0)
	{
		return "Regular";
	}
	else if (packageLength <= 108.0)
	{
		return "Large";
	}
	else if (packageLength <= 130.0)
	{
		return "Oversize";
	}
	else
	{
		return ""; // its too big.....
	}
}

}}// end namespaces

