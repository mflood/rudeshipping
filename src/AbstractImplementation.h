// AbstractImplementation.h: interface for the AbstractImplementation class
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



#ifndef INCLUDED_AbstractImplementation_H
#define INCLUDED_AbstractImplementation_H

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#define INCLUDED_IOSTREAM
#endif

namespace rude{
namespace shipping{

//=
// AbstractImplementation implements the component
// Following the Bridge design pattern, the Rude_ShipCalculator and AbstractImplementation objects allow the
// interface and the implementation of the component to vary independently.
// The Rude_ShipCalculator object is the public interface, and it forwards all of its messages to
// this object (AbstractImplementation) to be carried out.  This means we can completely scrap this class
// and plug in a new implementation without breaking existing projects that use this component.
// Also, we can plug in a new interface that limits the amount of functions available to users without
// modifying this implementation object. Furthermore, the bridge allows us to completely hide implementation details, protecting our code.
// 
//=
class AbstractImplementation{
	std::string d_error;
protected:

	AbstractImplementation();
	void setError(const char *);

public:
	virtual ~AbstractImplementation();
	
	static const char *version();
	
	virtual void resetPackage()=0;
	virtual void addPackage(double l_inches, double w_inches, double h_inches, double pounds)=0;
	virtual void setPackageHeight(double inches)=0;
	virtual void setPackageWidth(double inches)=0;
	virtual void setPackageLength(double inches)=0;
	virtual void setPackageWeight(double wieght)=0;

	virtual double getPackageLength() = 0;
	virtual double getPackageWidth() = 0;
	virtual double getPackageHeight() = 0;
	virtual double getPackageWeight() = 0;

	virtual void setSourceCity(const char *)=0;
	virtual void setSourceState(const char*)=0;
	virtual void setSourceCountryCode(const char *)=0;
	virtual void setSourceZip(const char*)=0;

	virtual void setDestCity(const char *)=0;
	virtual void setDestState(const char*)=0;
	virtual void setDestCountryCode(const char *)=0;
	virtual void setDestZip(const char *)=0;
	virtual void setDestIsResidence(bool isit) = 0;


	virtual bool initialize(const char *configfile) = 0;
	
	//=
	// Calculate shipment cost with ??
	//= 
	virtual bool calculate()=0;
	
	//=
	// Returns the number of providers
	//=
	virtual	int getNumProviders() const=0;

	//=
	// Set Provider 
	//= 
	virtual void setProvider(int index)=0;
	
	//=
	// Returns provider name 
	//=
	virtual const char *getProviderName() const=0;

	//=
	// Returns provider error 
	//=
	virtual const char *getProviderError() const=0;	

	//=
	// Returns the number of services per provider 
	//=
	virtual int getNumServices() const=0;
	
	//=
	// Set Service 
	//= 
	virtual void setService(int index)=0;
	
	//=
	// Returns service name 
	//=
	virtual const char *getServiceName() const=0;

	//=
	// Returns service name 
	//=
	virtual const char *getServiceDescription() const=0;

	//=
	// Returns service name 
	//=
	virtual const char *getServiceError() const=0;

	//=
	// Returns the price of service per provider 
	//=
	virtual double getServicePrice() const=0;
	
	//=
	// Returns the most recent error string, if there is one.
	//=
	const char *getError() const;

};

} // end namespace shipping
} // end namespace rude

#endif


