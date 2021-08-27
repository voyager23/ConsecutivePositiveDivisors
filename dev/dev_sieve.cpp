#include <iostream>
#include <numeric>
#include <array>
#include <vector>

#define NL std::cout<<std::endl

std::vector<int> gdc1;

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

int main(void) {
    std::vector<int> primes;
    const int n = 314;
    SieveOfEratosthenes(primes,n);
    for(auto pf = primes.begin(); pf != primes.end(); ++pf) printf("%d  ", *pf);
    NL;
}
