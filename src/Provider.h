// Provider.h: interface for the Provider class 
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



#ifndef INCLUDED_Provider_H
#define INCLUDED_Provider_H

#ifndef INCLUDED_VECTOR
#include <vector>
#define INCLUDED_VECTOR
#endif

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

#include <rude/config.h>

namespace rude{
namespace shipping{

class Service;
class Address;
class Package;
class RequestBuilder;
class ResponseParser;

//=
// Represents Provider parameters
//
//=
class Provider{

	std::string d_error;
	std::string d_description;




	bool loadServices(Config &config);

protected:
	Service *d_currentService;
	   std::vector<Service*> d_vector;
	Provider();

	
public:

	void setDescription(const char *desc);

	void setError(const char *);
	//=
	// Destroys Provider object
	//=
	virtual ~Provider();

	//=
	// Initialize....
	//=
	bool configure(Config &config);
	virtual bool concreteConfigure(Config &config) =0;

	//=
	// Calculates things....
	//=
	virtual bool calculate(Package &package, Address &src, Address &dest) =0;

	virtual const char *getName() const = 0;

	const char *getDescription();
	//=
	// Returns Provider error  
	//=
	const char *getError() const;

	//=
	// Set Service 
	//= 
	void setService(int index);


	//=
	// Returns the number of services per Provider 
	//=
	int getNumServices() const;
	
	//=
	// Returns the price of service per Provider 
	//=
	double getServicePrice() const;
	
	//=
	// Returns the name of service per Provider 
	//=
	const char *getServiceName() const;
	
	//=
	// Returns the length of time of service per Provider 
	//=
	const char *getServiceError() const;
	
	//=
	//
	//=
	const char *getServiceDescription() const;
	
	//=
	// Returns current service 
	//=
	Service *getCurrentService();

};

} // end namespace shipping
} // end namespace rude

#endif

