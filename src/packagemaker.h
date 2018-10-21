// packagemaker.h
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




#ifndef INCLUDED_PACKAGEMAKER_H
#define INCLUDED_PACKAGEMAKER_H

namespace rude{
namespace shipping{

class PackageMaker{

	double d_width;
	double d_height;
	double d_length;
	double d_weight;

public:

	PackageMaker();
	static void swapLengths(double& length, double& width, double& height);
	void reset();
	// inches / pounds
	void addPackage(double length, double width, double height, double weight);

	// inches / pounds
	//
	double getLength();
	double getWidth();
	double getHeight();
	double getWeight();
	


};

}
}

#endif

