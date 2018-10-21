// package.cpp: implementation for the package class
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



#include "Package.h"

using namespace rude::shipping;

// Static Variable Definitions
//


//Static Method Definitions
//


// Constructors & Destructor
//
Package::Package()
{
	d_height = 0;
	d_length = 0;
	d_width = 0;
	d_weight = 0;
	d_value = 0;
	d_packagetype = "";
	d_isHazardous = false;
}

Package::~Package()
{
}

//Instance Method Definitions
//
void Package::setHeightInches(double height) 
{
	if (height > 0)
	{
		d_height = height;
	}
	else
	{
		d_height = 0;
	}
}
	
void Package::setLengthInches(double length) 
{
	if (length > 0)
	{
		d_length = length;
	}
	else
	{
		d_length = 0;
	}
}

void Package::setWidthInches(double width)
{
	if (width > 0)
	{
		d_width = width;
	}
	else
	{
		d_width = 0;
	}
}

void Package::setWeightPounds(double weight)
{
	if (weight > 0)
	{
		d_weight = weight;
	}
	else
	{
		d_weight = 0;
	}
}

double Package::getWeightPounds() const
{
	return d_weight;
}

void Package::setWeightOunces(double weight)
{
	setWeightPounds(weight / 16.0);
}

double Package::getWeightOunces() const
{
	return d_weight * 16.0;
}

void Package::setWeightKilograms(double weight)
{
	setWeightPounds(weight / 0.45359237 );
}

double Package::getWeightKilograms() const
{
	return d_weight * 0.45359237;
}

void Package::setWeightGrams(double weight)
{
	setWeightPounds(weight / 453.59237 );
}

double Package::getWeightGrams() const
{
	return d_weight * 453.59237;
}

void Package::setInsuredValue(double value)
{
	if (value > 0)
	{
		d_value = value;
	}
	else
	{
		d_value = 0;
	}
}
	
void Package::setPackageType(const char *packagetype)
{
	d_packagetype = packagetype ? packagetype : "";
}


void Package::isHazardous(bool yesno)
{
	d_isHazardous = yesno;
}


double Package::getHeightInches() const
{
	return d_height;
}

double Package::getLengthInches() const 
{
	return d_length;
}

double Package::getWidthInches() const
{
	return d_width;
}

double Package::getInsuredValue() const
{
	return d_value;
}
	
const char *Package::getPackageType() const
{
	return d_packagetype.c_str();
}


bool Package::isHazardous()
{
	return d_isHazardous;
}
	

