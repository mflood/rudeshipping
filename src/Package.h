// Package.h: interface for the package class 
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



#ifndef INCLUDED_Package_H
#define INCLUDED_Package_H

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

using namespace std;
namespace rude{
namespace shipping{
//=
// Represents package parameters
//
//=
class Package{

	double d_height;
	double d_length;
	double d_width;
	double d_weight;
	double d_value;
	std::string d_packagetype;
	bool d_isHazardous;


public:
	//=
	// Creates Package object
	//=
	Package();

	//=
	// Destroys Package object
	//=
	~Package();

	//= 
	// Sets the height of the package object
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setHeightInches(double height); 
	
	//= 
	// Sets the length of the package object
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setLengthInches(double length); 

	//=
	// Sets the width of the package object
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setWidthInches(double width);

	//=
	// Sets the weight of the package object in pounds
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setWeightPounds(double weight);

	//=
	// Sets the weight of the package object in ounces
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setWeightOunces(double weight);

	//=
	// Sets the weight of the package object in kilograms
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setWeightKilograms(double weight);

	//=
	// Sets the weight of the package object in grams
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setWeightGrams(double weight);

	//=
	// Sets the dollar value of the package object
	// Accepts any double value
	// Forces value to 0 if value < 0.  
	//=
	void setInsuredValue(double value);
	
	//=
	// Sets the package type of the package object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=
	void setPackageType(const char *packagetype);

	//=
	// Sets the hazardous status of the package object
	// Should be called with true when the package is hazardous 
	// Should be called with false when the package is not hazardous 
	//=
	void isHazardous(bool yesno);
	

	//= 
	// Returns the height of the package object
	//=
	double getHeightInches() const; 
	
	//= 
	// Returns the length of the package object
	//=
	double getLengthInches() const; 

	//=
	// Returns the width of the package object
	//=
	double getWidthInches() const;

	//=
	// Returns the weight of the package object in pounds
	//=
	double getWeightPounds() const;

	//=
	// Returns the weight of the package object in ounces
	//=
	double getWeightOunces() const;

	//=
	// Returns the weight of the package object in kilograms
	//=
	double getWeightKilograms() const;

	//=
	// Returns the weight of the package object in grams
	//=
	double getWeightGrams() const;

	//=
	// Returns the dollar value of the package object
	//=
	double getInsuredValue() const;
	
	//=
	// Returns the package type of the package object
	//=
	const char *getPackageType() const;
	

	//=
	// Returns the hazardous status of the package object
	//=
	bool isHazardous();
	
};


} // end namespace shipping
} // end namespace rude

#endif
