#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::vector;

vector<int> sieve(int& n){

	vector<int> primes;
	bool num[n+1];

	memset(num,true,sizeof(num));

	for (int i = 2; i*i < n ; i++){
		if(num[i])
			for(int j = i*2; j < n;j += i)
				num[j] = false;

	}
	for(int k = 2;k < n;k++)
		if(num[k])
			primes.push_back(k);

	return primes;			
}

vector<int> seg_sieve(int& n){
	int bound = floor(sqrt(n)) + 1;

	vector<int> primes = sieve(bound);
	vector<int> seg_primes;

	int l = bound;
	int h = 2*bound;

	while(l < n){
		if(h >= n)
			h = n;

		bool marked[bound+1];
		memset(marked,true,sizeof(marked));


		for(int i = 0; i < primes.size(); i++){
			int lower = floor(l/primes[i])*primes[i];

			if(lower < l)
				lower += primes[i];


			for(int j = lower; j < h; j+=primes[i])
				marked[j - l] = false;
		}

		for(int k = l; k < h; k++)
			if(marked[k - l])
				seg_primes.push_back(k);

		l += bound;
		h += bound;
	}

	return seg_primes;
}


int main(void){

	int n = 100;

	vector<int> seg_primes = seg_sieve(n);

	cout << "Primes under " << n << "\n";
	for(int p:seg_primes)
		cout << p << "\n";

	return 0;
}