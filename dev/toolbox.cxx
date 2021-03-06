/*
 * toolbox.cxx
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

#include "toolbox.hxx"

#define NL std::cout<<std::endl

void SieveOfEratosthenes(std::vector<int> &primes,int n)
{
    // internal vector of bool
    std::vector<bool> prime;
    // Set n+1 entries in vector<bool> to true
    for(int c = 0; c != n+1; ++c) prime.push_back(true);

    for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiples
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    primes.clear();
    for(auto pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
}

#if(0)
int main(void) {
    std::vector<int> primes;
    const int n = 999;
    SieveOfEratosthenes(primes,n);
    for(auto pf = primes.begin(); pf != primes.end(); ++pf) printf("%d  ", *pf);
    NL;
}
#endif


