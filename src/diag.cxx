/*
 * acpd.cxx
 * 
 * Copyright 2021 Michael Tate <mike@Michaels-MBP>
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
#include "../inc/toolbox.hxx"

int main(void)
{
	int foobar = 0;

	const ul Limit = 10000000;
	// Generate an array/vector of primes 2 => Limit/2
	std::vector<ul> primes;
	SieveOfEratosthenes(primes, (Limit/2)+1);

	std::vector<ul> data;	// 0 <= index < Limit
	
#if(1)
	printf("Setting data array\n");
	for(ul x = 0; x < Limit; ++x) {
		data.push_back(1);
		//printf("%lu,%lu  ", x, data[x]);
	}
#endif

	printf("Setup complete\n");
	
	return 0;
}

