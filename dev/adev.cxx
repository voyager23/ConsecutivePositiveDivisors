/*
 * adev.cxx
 * 
 * Copyright 2021 Mike <mike@aorus>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <array>
#include <iterator>

#include "toolbox.hxx"

typedef uint64_t ul;
typedef struct {
	ul n;	ul limit;		ul phi;
}Data;

int main(int argc, char **argv)
{
	const ul Limit = 16;
	std::vector<Data> data;
	std::vector<Data>::iterator a,w;
	// setup
	for(ul x = 1; x <= Limit; ++x) data.push_back({x, (x/2)+1, 0});
	a = std::next(data.begin(),1);
	while(a < data.end()){
		//
		w = a;
		while(w < data.end()){
			if( (a->n <= w->limit) and ( (w->n % a->n) == 0) ) w->phi += 1;
			std::advance(w, a->n);
		}
		
		std::advance(a,1);
		
		// debug print
		for (auto x = data.begin()+1; x != data.end(); ++x) printf("n:%llu limit:%llu phi:%llu\n", x->n, x->limit, x->phi);
		printf("a advanced to %llu\n", a->n);
	}
	return 0;
}

