// UPSWorldwideExpedited.h: interface for the UPSWorldwideExpedited class 
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



#ifndef INCLUDED_UPSWorldwideExpedited_H
#define INCLUDED_UPSWorldwideExpedited_H

#include "../Service.h"

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

using namespace std;

namespace rude{
namespace shipping{

class UPSWorldwideExpedited: public Service{


public:
	//=
	// Creates UPSWorldwideExpedited object
	//=
	UPSWorldwideExpedited();

	//=
	// Destroys UPSWorldwideExpedited object
	//=
	~UPSWorldwideExpedited();


	bool calculate(Package &p, Address &source, Address &dest);

};

} // end namespace shipping
} // end namespace rude

#endif

