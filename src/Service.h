// Service.h: interface for the ship_service class 
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



#ifndef INCLUDED_Service_H
#define INCLUDED_Service_H


#include "Address.h"
#include "Package.h"


#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

namespace rude{
namespace shipping{
//=
// Represents service parameters
//
//=

enum ServiceCode{ SUCCESS, INVALID_PACKAGE, INVALID_ORIGIN_ADDRESS, INVALID_DESTINATION_ADDRESS, ERROR };

class Service{

	ServiceCode d_code;
	std::string d_error;
	std::string d_name;
	std::string d_desc;
	double d_price;

protected:
	Service();
	void setPrice(double);
	void setName(const char *);
	void setDescription(const char *);
	void setError(const char *);
	void setServiceCode(ServiceCode s);
	
public:

	~Service();


	//=
	// Returns the price of the service object
	//=
	double getPrice() const;
	

	//=
	// Sets the name of the service object
	// Accepts any string
	// If passed a null value, it will be converted to the empty string
	//=


	//=
	// Returns the service name of the service object
	//=
	const char *getName() const;
	
	


	const char *getDescription() const;



	const char *getError() const;


	
	ServiceCode getServiceCode();


	virtual bool calculate(Package &p, Address &source, Address & Dest) = 0;

	
	

};

} // end namespace shipping
} // end namespace rude

#endif

