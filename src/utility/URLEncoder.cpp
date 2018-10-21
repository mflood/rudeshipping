// URLEncoder.cpp
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




#include "URLEncoder.h"

#include <string.h>
#include <stdio.h>
namespace rude{
namespace shipping{

const char *URLEncoder::encode(const char *data)
{

	d_result = "";
	int len=strlen(data);
	for(int x=0; x<len; x++)
	{
		if( ( data[x] >= 'a' && data[x] <= 'z' ) || ( data[x] >= 'A' && data[x] <='Z' ) )
		{
			d_result += data[x];
		}
		else
		{
			char hex[3];
			sprintf(hex, "%02x", data[x]);
			d_result += "%";
			d_result += hex;
		}
	} 

	return d_result.c_str();
}
}}
