// AbstractImplementation.cpp: implementation for the AbstractImplementation class
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



#include "AbstractImplementation.h"


namespace rude{
namespace shipping{


// Static Method Definitions
//
const char *AbstractImplementation::version()
{
	return "1.1"; 
}

// Constructors & Destructor
//
AbstractImplementation::AbstractImplementation()
{
	d_error = "";
}

AbstractImplementation::~AbstractImplementation()
{
}

void AbstractImplementation::setError(const char *error)
{
	d_error = error ? error : "";
}

const char *AbstractImplementation::getError() const
{
	return d_error.c_str();
}

}}
