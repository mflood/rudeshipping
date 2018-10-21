// shipping.h: interface for the Shipping class
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



#ifndef INCLUDED_SHIPPING_H
#define INCLUDED_SHIPPING_H


namespace rude{

namespace shipping{
	class AbstractImplementation;
}


class Shipping
{
	rude::shipping::AbstractImplementation *d_implementation; // Bridge
	
public:

	//=
	// Constructor
	//=
	Shipping();

	//=
	// Destructor
	//=
	~Shipping();
	
	//=
	// Returns the version of the component.
	//
	// <b>Example:</b>
	// 
	// <code>const char *version = Shipping::version();</code>
	//=
	static const char *version();

	//=
	// Loads all the providers and services
	//=
	bool initialize(const char *configfile);
	
	//=
	// Returns the most recent error string, if there is one.
	//=
	const char *getError() const;

	void resetPackage();
	void addPackage(double length_inches, double width_inches, double height_inches, double pounds);

	//=
	// Sets the height of the package in inches
	//=
	void setPackageHeight(double inches);

	//=
	// Sets the width of the package in inches
	//=
	void setPackageWidth(double inches);

	//=
	// Sets the length of the package in inches
	//=
	void setPackageLength(double inches);

	//=
	// Sets the weight of the package in pounds
	//=
	void setPackageWeight(double pounds);

	double getPackageHeight();
	double getPackageLength();
	double getPackageWidth();
	double getPackageWeight();


	//=
	// Sets the country code of the origination address
	//=
	void setSourceCity(const char *city);

	//=
	// Sets the country code of the origination address
	//=
	void setSourceState(const char *state);

	//=
	// Sets the country code of the origination address
	//=
	void setSourceCountryCode(const char *code);

	//=
	// Sets the zip/postal code of the originating address
	//=
	void setSourceZip(const char *zipcode);



	//=
	// Sets the country code of the origination address
	//=
	void setDestCity(const char *city);

	//=
	// Sets the country code of the origination address
	//=
	void setDestState(const char *state);
	
	//=
	// Sets the coutry code of the destination address
	//=
	void setDestCountryCode(const char *code);

	//=
	// Sets the zip/postal code of the destination address
	//=
	void setDestZip(const char *zipcode);

	void setDestIsResidence(bool isit);
	
	//=
	// Calculate shipment cost 
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
	// Return Provider Name
	//= 
	const char *getProviderName() const;

	//=
	// Returns error (if any) associated with provider
	//=
	const char *getProviderError() const;

	//=
	// Returns the number of services offered by the currently selected provider  
	//=
	int getNumServices() const;

	//=
	// Set the current (active) service within  the currently selected provider
	//= 
	void setService(int index);

	//=
	// Returns the name/code of the currently selected service
	//= 
	const char *getServiceName() const;

	//=
	// Returns the human-readable description of the currently selected service
	//= 
	const char *getServiceDescription() const;

	//=
	//=
	// Returns the delivery price of the currently selected service
	// If the price is 0, it can be assumed that there is an error associated with the service
	//=
	double getServicePrice() const;

	// Returns the error (if any) associated with the currently selected service
	//= 
	const char *getServiceError() const;
};

} // end namespace rude

#endif


