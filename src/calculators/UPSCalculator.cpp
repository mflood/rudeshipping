// UPSCalculator.cpp: implementation for the UPSCalculator class
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



#include "UPSCalculator.h"

#include "../utility/LiveRateRequest.h"

using namespace rude::shipping;
using namespace std;

namespace rude{
namespace shipping{

// Constructors & Destructor
//

UPSCalculator::UPSCalculator(const char *serveraddress, const char *license, const char *userid, const char *password)
{
	d_serveraddress=serveraddress ? serveraddress :"";
	d_license=license ? license :"";
	d_userid=userid ? userid :"";
	d_password=password ? password :"";

	d_price=0;
	d_error="";
}

UPSCalculator::~UPSCalculator()
{


}


void UPSCalculator::setError(const char *error)
{
	d_error = error ?error : "";
}

const char *UPSCalculator::getError()
{
	return d_error.c_str();
}


void UPSCalculator::setPrice(double d)
{
	d_price=d;
}

double UPSCalculator::getPrice()
{
	return d_price;
}




bool UPSCalculator::calculate(Package &p, Address &source, Address &dest, const char *servicecode)
{

	// BUILD XML REQUEST
	//


	
	// BUILD XML REQUEST
	//
	
	std::string xml = "<?xml version=\"1.0\"?>";
	xml += "<AccessRequest xml:lang=\"en-US\">";
	xml +=	 "<AccessLicenseNumber>";
	xml += d_license;
	xml += "</AccessLicenseNumber>";
	xml +=	 "<UserId>";
	xml += d_userid;
	xml += "</UserId>";
	xml +=	 "<Password>";
	xml += d_password;
	xml += "</Password>";
	xml += "</AccessRequest>";
	xml += "<?xml version=\"1.0\"?>";
	xml += "<RatingServiceSelectionRequest xml:lang=\"en-US\">";
	xml +=   "<Request>";
	xml +=      "<TransactionReference>";
	xml +=   	   "<CustomerContext>Bare Bones Rate Request</CustomerContext>";
	xml +=   	      "<XpciVersion>1.0001</XpciVersion>";
	xml +=      "</TransactionReference>";
	xml +=      "<RequestAction>Rate</RequestAction>";
	xml +=      "<RequestOption>Rate</RequestOption>";
	xml +=   "</Request>";
	xml +=   "<PickupType>";
	xml +=      "<Code>01</Code>";
	xml +=   "</PickupType>";
	xml +=   "<Shipment>";
	xml +=      "<Shipper>";
	xml +=         "<Address>";
	xml +=            "<PostalCode>";
	xml += 	        source.getZip();
	xml += 	    "</PostalCode>";
	xml +=            "<CountryCode>";
	xml += 		source.getCountryCode();
	xml += 	    "</CountryCode>";
	xml +=         "</Address>";
	xml +=      "</Shipper>";

	xml += "<ShipTo>";
	xml += "<Address>";
	xml +=            "<PostalCode>";
	xml += 	        dest.getZip();
	xml += 	    "</PostalCode>";
	xml +=            "<CountryCode>";
	xml += 		dest.getCountryCode();
	xml += 	    "</CountryCode>";

	if(dest.isResidence())
	{
		xml += "<ResidentialAddressIndicator/>";
	}

	xml += "</Address>";
	xml += "</ShipTo>";

	xml += "<ShipFrom>";
	xml += "<Address>";
	xml +=            "<PostalCode>";
	xml += 	        source.getZip();
	xml += 	    "</PostalCode>";
	xml +=            "<CountryCode>";
	xml += 		source.getCountryCode();
	xml += 	    "</CountryCode>";
	xml += "</Address>";
	xml += "</ShipFrom>";
	
	xml += "<Service>";
	xml += "<Code>";
	xml += servicecode; 
	xml += "</Code>";
	xml += "</Service>";
	
	xml += "<Package>";
	
		xml += "<PackagingType>";
			xml += "<Code>02</Code>";
		xml += "</PackagingType>";
	
		xml += "<Dimensions>";
			xml += "<UnitOfMeasurement>";
				xml += "<Code>IN</Code>";
			xml += "</UnitOfMeasurement>";

			xml += "<Length>";
			char lbuffer[10];
			sprintf(lbuffer, "%0.2f", p.getLengthInches()); 
			xml += lbuffer;
			xml += "</Length>";

			xml += "<Width>";
			char wbuffer[10];
			sprintf(wbuffer, "%0.2f", p.getWidthInches()); 
			xml += wbuffer;
			xml += "</Width>";

			xml += "<Height>";
			char hbuffer[10];
			sprintf(hbuffer, "%0.2f", p.getHeightInches()); 
			xml += hbuffer;
			xml += "</Height>";

		xml += "</Dimensions>";
	
		xml += "<PackageWeight>";
			xml += "<UnitOfMeasurement>";
				xml += "<Code>LBS</Code>";
			xml += "</UnitOfMeasurement>";
			xml +=            "<Weight>";

			double sw = p.getWeightPounds();
			if(sw < .5)
			{
				sw = .5;
			}
			char w[10];
			sprintf(w, "%0.2f", sw); 


			xml += 	        w;
			xml += 	    "</Weight>";
			xml += "</PackageWeight>";
	
	xml += "</Package>";
	xml += "</Shipment>";
	xml += "</RatingServiceSelectionRequest>";



	
	// SEND REQUEST
	//
	string postdata = xml;

	LiveRateRequest httprequest;
	httprequest.setPort(443);
	httprequest.setPath("/ups.app/xml/Rate");
	httprequest.setAddress(d_serveraddress.c_str());
	httprequest.useSecureConnection(true);

	if(!httprequest.sendRequest(postdata.c_str()))
	{
		setError(httprequest.getError());
		return false;
	}

	const char * response=httprequest.getRawResponse();


	// PARSE RESPONSE
	//
	const char *ratedshipment= strstr(response, "<RatedShipment>");
	if(ratedshipment)
	{
		const char *totalcharges= strstr(ratedshipment, "<TotalCharges>");
		if(totalcharges)
		{
			const char *monetaryvalue= strstr(totalcharges,"<MonetaryValue>");
			if(monetaryvalue)
			{
				monetaryvalue += strlen("<MonetaryValue>");
				const char *endtag = strstr(monetaryvalue, "</MonetaryValue>");
				if(endtag)
				{
					char postage[20];
					int x;
					for(x=0 ; monetaryvalue != endtag; monetaryvalue++, x++)
					{ 
						postage[x]=*monetaryvalue;
					}
					postage[x]=0;
					double intpostage;
					sscanf(postage, "%lg", &intpostage);
					setPrice(intpostage);
					return true;
				}
			}
		}
	}
	// look for error

	const char *error= strstr(response, "<Error>");
	if(error)
	{
		const char *errordesc= strstr(error, "<ErrorDescription>");
		if(errordesc)
		{
				errordesc += strlen("<ErrorDescription>");
				const char *endtag = strstr(errordesc, "</ErrorDescription>");
				if(endtag)
				{
					std::string strerror="";
					int x;
					for(x=0 ; errordesc != endtag; errordesc++, x++)
					{ 
						strerror += *errordesc;
					}

					setError(strerror.c_str());

				}
		}
	}
	return false;
}


}}

