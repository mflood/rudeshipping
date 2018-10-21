// USPSDomesticCalculator.cpp: implementation for the USPSDomesticCalculator class
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



#include "USPSDomesticCalculator.h"

#include "../utility/USPSPackageSizeFinder.h"

#include "../utility/LiveRateRequest.h"
#include "../utility/URLEncoder.h"


using namespace rude::shipping;
using namespace std;

namespace rude{
namespace shipping{

// Constructors & Destructor
//

USPSDomesticCalculator::USPSDomesticCalculator(const char *serveraddress, const char *userid, const char *password)
{
	d_serveraddress=serveraddress ? serveraddress :"";
	d_userid=userid ? userid :"";
	d_password=password ? password :"";

	d_price=0;
	d_error="";
}

USPSDomesticCalculator::~USPSDomesticCalculator()
{


}


void USPSDomesticCalculator::setError(const char *error)
{
	d_error = error ?error : "";
}

const char *USPSDomesticCalculator::getError()
{
	return d_error.c_str();
}


void USPSDomesticCalculator::setPrice(double d)
{
	d_price=d;
}

double USPSDomesticCalculator::getPrice()
{
	return d_price;
}




bool USPSDomesticCalculator::calculate(Package &p, Address &source, Address &dest, const char *servicename)
{

	// BUILD XML REQUEST
	//

	URLEncoder encoder;
	
	double oz = p.getWeightOunces();
	int pounds = (int) oz / 16;
	int ounces = (int) oz % 16;
	char pbuffer[10];
	char obuffer[10];

	sprintf(pbuffer, "%d", pounds);
	sprintf(obuffer, "%d", ounces);	


	USPSPackageSizeFinder pf;
	string size=pf.getSize(&p);
	

	std::string xml = "<RateRequest USERID=\"";
	xml += d_userid; 
	xml += "\" PASSWORD=\"";
	xml += d_password; 
	xml += "\">";
	xml +=		 "<Package ID=\"0\">";
	xml +=			"<Service>";
	xml += 			 servicename;
	xml += 			"</Service>";
	xml += 			"<ZipOrigination>";
	xml += 				source.getZip();
	xml += 			"</ZipOrigination>";
	xml += 			"<ZipDestination>";
	xml += 				dest.getZip();
	xml += 			"</ZipDestination>";
	xml += 			"<Pounds>";
	xml += 				pbuffer;
	xml += 			"</Pounds>";
	xml += 			"<Ounces>";
	xml +=				obuffer;
	xml += 			"</Ounces>";
	xml += 			"<Container>None</Container>";
	xml += 			"<Size>";
	xml += 			      size;
	xml += 			"</Size>";
	xml += 			"<Machinable>True</Machinable>";
	xml +=		 "</Package>";
	xml +=    "</RateRequest>";

	string postdata = "API=Rate&XML=";
	postdata += encoder.encode(xml.c_str());

	LiveRateRequest httprequest;
	httprequest.setPort(80);
	httprequest.setPath("/ShippingAPI.dll");
	httprequest.setAddress(d_serveraddress.c_str());
	httprequest.useSecureConnection(false);

	if(!httprequest.sendRequest(postdata.c_str()))
	{
		setError(httprequest.getError());
		return false;
	}

	const char * response=httprequest.getRawResponse();


	const char *startpostage=strstr(response, "<Postage>");
	if(startpostage)
	{
		// advance pointer past tag
		startpostage += 9;
		const char *endpostage = strstr(startpostage, "</Postage>");
		if(endpostage)
		{
			char postage[20];
			int x;
			for(x=0 ; startpostage != endpostage; startpostage++, x++)
			{ 
				postage[x]=*startpostage;

			}
			postage[x]=0;
			double intpostage;
			sscanf(postage, "%lg", &intpostage);
			setPrice(intpostage);
			return true;
		}
		else
		{
			setError("Could not determine postage");
			return false;
		}
	}
	else
	{
		const char *starterror = strstr(response, "<Description>");
		if(starterror)
		{
			starterror +=13;
			const char *enderror=strstr(starterror, "</Description>");
			std::string serror="";
			for(; starterror != enderror; starterror++)
			{
				serror+= *starterror;
				
			}
			setError(serror.c_str());
			return false;
		}
		else
		{
			setError("Could not determine error");
			return false;
		}
	}

}


}}

