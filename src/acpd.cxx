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

int main(int argc, char **argv)
{
	// 1 < n < 10^x
	const ul Limit = 10000000;
	// Generate an array/vector of primes 2 => Limit/2
	std::vector<ul> primes;
	SieveOfEratosthenes(primes, (Limit/2)+1);
	// We need to assoc. each n with number of divisors of n.
	// In general this is the product of each prime exponent + 1
	// 144 = 2^4 * 3^2.  Number of divisors = (4+1)(2+1) = 15
	std::array<ul, Limit> data;	// 0 <= index < Limit
	printf("Setting data array\n");
	for(ul x = 0; x < Limit; ++x) {
		data[x] = 1;
		printf("%llu,%llu  ", x, data[x]);
	}
	printf("Setup complete\n");
	// using each prime, set values for the prime and multiples in data array
	for(auto a = primes.begin(); a != primes.end(); ++a){
		ul p = *a;  // index (prime) into data array;
		for(ul w = p; w < Limit; w += p){
			ul temp = w;
			ul  exp = 1;
			while((temp % p) == 0){
				temp /= p;
				exp += 1;
			}
			data[w] *= exp;
		}
	}
	for(ul x = 0; x < Limit; ++x) printf("%llu : %llu\n", x, data[x]);
	return 0;
}

