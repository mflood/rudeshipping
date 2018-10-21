// Address.h: interface for the Address class 
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



#ifndef INCLUDED_Address_H
#define INCLUDED_Address_H

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

using namespace std;
namespace rude{
namespace shipping{
//=
// Represents Address parameters 
//
//=
class Address{

	std::string d_countrycode;
	std::string d_zip;
	std::string d_city;
	std::string d_state;
	bool d_isResidence;

public:
	//=
	// Creates Address object
	//=
	Address();

	//=
	// Destroys Address object
	//=
	~Address();

	//=
	// Sets the country code of the Address object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=
	void setCountryCode(const char *countryCode);

	//= 
	// Sets the zip of the Address object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=
	void setZip(const char *zip); 

	//=
	// Sets the city type of the Address object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=
	void setCity(const char *city);

	//=
	// Sets the state of the Address object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=
	void setState(const char *state);

	//=
	// Sets the residence status of the Address object 
	// Should be called with true when the Address is a residence
	// Should be called with false when the Address is a business
	//=
	void isResidence(bool yesno);

	//=
	// Returns the country code of the Address object
	//=
	const char *getCountryCode() const;

	//= 
	// Returns the zip of the Address object
	//=
	const char *getZip() const; 

	//=
	// Returns the city type of the Address object
	//=
	const char *getCity() const;

	//=
	// Returns the state of the Address object
	//=
	const char *getState() const;

	//=
	// Returns the residence status of the Address object
	//=
	bool isResidence();

};


} // end namespace shipping
} // end namespace rude

#endif
