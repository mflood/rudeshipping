// LiveRateRequest.cpp
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


#include "LiveRateRequest.h"

#include <rude/socket.h>

#include <string>

//#include <iostream> // DEBUG ONLY


using namespace std;

namespace rude{
namespace shipping{


LiveRateRequest::LiveRateRequest()
{
	d_response="";
	d_request="";
	d_error="";
	
	d_address="";
	d_port=80;
	d_path="/";
	d_usessl=false;
}

LiveRateRequest::~LiveRateRequest()
{

}

void LiveRateRequest::setPort(int port)
{
	d_port = port ? port :80;
}

int LiveRateRequest::getPort()
{
	return d_port;
}

void LiveRateRequest::setAddress(const char *address)
{
	d_address = address ? address : "";
}

const char *LiveRateRequest::getAddress()
{
	return d_address.c_str();
}

void LiveRateRequest::useSecureConnection(bool doit)
{
	d_usessl=doit;
}

bool LiveRateRequest::useSecureConnection()
{
	return d_usessl;
}

void LiveRateRequest::setPath(const char *path)
{
	d_path= path ? path : "/";
}

const char *LiveRateRequest::getPath()
{
	return d_path.c_str();
}

const char *LiveRateRequest::getRawRequest()
{
	return d_request.c_str();
}

const char *LiveRateRequest::getRawResponse()
{
	return d_response.c_str();
}

const char *LiveRateRequest::getError()
{
	return d_error.c_str();
}

bool LiveRateRequest::sendRequest(const char *postdata)
{
	bool connected;
	Socket socket;

	d_response="";
	d_request="";
		
	if(d_usessl)
	{
		connected = socket.connectSSL(d_address.c_str(), d_port);
	}
	else
	{
		connected = socket.connect(d_address.c_str(), d_port);
	}
		
	if(!connected)
	{
		d_error=socket.getError();
		return false;
	}

	std::string posteddata = postdata ? postdata : "";
		
	int postlength = posteddata.size();

	char strlength[10];
	sprintf(strlength, "%d", postlength);
	
		// cout << "\t\tREQUEST: \n\n" << posteddata << "\n\nPosted Data Length: " << strlength << "\n";
	
		
	d_request = "POST ";
	d_request += d_path;
	d_request += " HTTP/1.0\n";
	d_request += "Hostname: ";
	d_request += d_address;
	d_request += "\n";
	d_request += "Content-Type: application/x-www-form-urlencoded\n";
	d_request += "Content-Length: ";
	d_request += strlength;
	d_request += "\n\n";
	d_request += posteddata.c_str();

	//cout << " ********** REQUEST ********** \n";
	//cout << d_request << "\n";

	socket.sends(d_request.c_str());
	
	
	const char *returnval=socket.reads();
	socket.close();
	
	if(!returnval)
	{
		d_error=socket.getError();
		return false;
	}
	
		
	d_response=returnval;
	if(string::npos == d_response.find(" 200 OK"))
	{
		d_error="HTTP Error - could not find 200 OK status in response headers";
		return false;
	}

	//cout << " ********** REPONSE ********** \n";
	//cout << d_response << "\n";
	
	return true;
}



}}

