// LiveRateRequest.h
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


#ifndef INCLUDED_LiveRateRequest_H
#define INCLUDED_LiveRateRequest_H

#include <string>

namespace rude{
namespace shipping{

class LiveRateRequest{

	std::string d_response;
	std::string d_request;
	std::string d_error;
	int d_responsecode;
	std::string d_address;
	int d_port;
	std::string d_path;
	bool d_usessl;
	
public:

	LiveRateRequest();

	void setPort(int port);
	int getPort();

	void setAddress(const char *address);
	const char *getAddress();

	void useSecureConnection(bool doit);
	bool useSecureConnection();

	void setPath(const char *path);
	const char *getPath();

	bool sendRequest(const char *postdata);


	const char *getRawRequest();
	const char *getRawResponse();
	const char *getError();

	
	~LiveRateRequest();
};

}}

#endif

