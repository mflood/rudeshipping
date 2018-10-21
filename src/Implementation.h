// Implementation.h: interface for the shipimpl class
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



#ifndef INCLUDED_Implementation_H
#define INCLUDED_Implementation_H

#include "AbstractImplementation.h"
#include "Address.h"
#include "Package.h"
#include "packagemaker.h"
#include <vector>
#include <string>

namespace rude{
namespace shipping{

//=
// Implementation implements the component
// Following the Bridge design pattern, the Rude_TestCalculator and Implementation objects allow the
// interface and the implementation of the component to vary independently.
// The Rude_TestCalculator object is the public interface, and it forwards all of its messages to
// this object (Implementation) to be carried out.  This means we can completely scrap this class
// and plug in a new implementation without breaking existing projects that use this component.
// Also, we can plug in a new interface that limits the amount of functions available to users without
// modifying this implementation object. Furthermore, the bridge allows us to completely hide implementation details, protecting our code.
// 
//=
class Provider;

class Implementation: public rude::shipping::AbstractImplementation{

	std::string d_error;
	std::vector<Provider*> d_vector;
	Provider *d_currentProvider;
	PackageMaker d_packagemaker;
	rude::shipping::Address d_destaddress;
	rude::shipping::Address d_sourceaddress;
	rude::shipping::Package d_package;
	
public:

	Implementation();

	~Implementation();

	bool initialize(const char *configfile);
	
	void resetPackage();
	void addPackage(double length_in, double width_in, double height_in, double pounds);
	void setPackageHeight(double inches);
	void setPackageWidth(double inches);
	void setPackageLength(double inches);
	void setPackageWeight(double wieght);

	double getPackageWeight();
	double getPackageLength();
	double getPackageHeight();
	double getPackageWidth();

	void setSourceCity(const char *);
	void setSourceState(const char*);	
	void setSourceCountryCode(const char *);
	void setSourceZip(const char*);

	void setDestCity(const char *);
	void setDestState(const char*);	
	void setDestCountryCode(const char *);
	void setDestZip(const char *);
	void setDestIsResidence(bool isit);
	//=
	// Calculate shipment cost with ??
	//= 
	bool calculate();
	
	//=
	// Returns the number of providers
	//=
	int getNumProviders() const;
	
	//=
	// Set Provider
	//= 
	void setProvider(int index);
	
	//=
	// Returns provider name  
	//=
	const char *getProviderName() const;

	//=
	// Returns provider error 
	//=
	const char *getProviderError() const;	

	//=
	// Set Service
	//= 
	void setService(int index);

	//=
	// Returns service name  
	//=
	const char *getServiceName() const;

	//=
	// Returns the number of services per provider 
	//=
	int getNumServices() const;
	
	//=
	// Returns the price of service per provider 
	//=
	double getServicePrice() const;
	
	//=
	// Returns service name 
	//=
	const char *getServiceDescription() const;

	//=
	// Returns service name 
	//=
	const char *getServiceError() const;


	//=
	// Returns the most recent error string, if there is one.
	//=
	const char *getError() const;

};

} // end namespace shipping
} // end namespace rude

#endif


