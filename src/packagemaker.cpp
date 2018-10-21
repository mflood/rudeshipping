// packagemaker.cpp
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


#include "packagemaker.h"

namespace rude{
namespace shipping{
PackageMaker::PackageMaker()
{
	d_length=0;
	d_width=0;
	d_height=0;
	d_weight=0;
}


void PackageMaker::reset()
{
	d_length=0;
	d_width=0;
	d_height=0;
	d_weight=0;
}

double PackageMaker::getLength()
{
	return d_length;
}

double PackageMaker::getWidth()
{
	return d_width;
}

double PackageMaker::getHeight()
{
	return d_height;
}

double PackageMaker::getWeight()
{
	return d_weight;
}

void PackageMaker::swapLengths(double &length, double &width, double &height)
{
	double largest, middle, smallest;
	if(length >= width && length >= height)
	{
		largest = length; // Correct 
		middle = width; // guess temporarily
		smallest = height; // guess temporarily
	}
	else if(width >= length && width >= height)
	{
		largest = width; // Correct
		middle = length;
		smallest = height;
	}
	else
	{
		largest = height;
		middle = length;
		smallest = width;
	}

	// Largest is assigned to length
	//
	length = largest;

	// See if guesses were correct
	//	
	if(middle  >= smallest)
	{
		// Guesses were correct - 
		// assign middle to width and shortest to height
		width = middle;
		height = smallest;
	}
	else
	{
		// Guesses were wrong 
		// assign middle to width and shortest to height
		width = smallest;
		height = middle;
	}

}

void PackageMaker::addPackage(double length, double width, double height, double weight)
{
	// Should shuffle incoming data around so that length is largest value and height is smallest
	swapLengths(length, width, height);

	// The weights are simply accumulative....
	d_weight += weight;
	
	// The new length will be the longer of the two products.
	d_length = (length > d_length) ? length : d_length;

	// the new width will be the wider of the two products
	d_width = (width > d_width) ? width : d_width;

	// The new height will be acculmulative
	d_height += height;

	// Should adjust final values so that d_length is largest value and d_height is the smallest
	swapLengths(d_length, d_width, d_height);
}

}}
