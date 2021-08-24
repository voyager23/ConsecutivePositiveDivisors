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

typedef uint64_t ul;
typedef struct {
	ul n;	ul residue;		ul phi;
}Data;

int main(int argc, char **argv)
{
	const ul Limit = 50;
	std::vector<Data> data;
	std::vector<Data>::iterator a,w;
	for(ul x = 1; x <= Limit; ++x) data.push_back({x,x,2});
	a = std::next(data.begin(),2);
	w = a;
	while(w < data.end()){
		while((w->residue % 2) == 0){
			w->residue /= a->n;
			w->phi += 1;
		}
		std::advance(w, a->n);
	}
	// debug print of database
	return 0;
}

