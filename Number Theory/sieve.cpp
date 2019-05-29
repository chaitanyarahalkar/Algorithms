#include <iostream>
#include <vector>

using std::cout;
using std::vector;


vector<int> sieve(int& n){

	vector<int> primes;
	bool num[n+1];

	memset(num,true,sizeof(num));

	for (int i = 2; i*i <= n ; i++){
		if(num[i])
			for(int j=i*i;j<=n;j+=i)
				num[j] = false;

	}
	for(int k=2;k<=n;k++)
		if(num[k])
			primes.push_back(k);

	return primes;			
}
int main(void){

	int n = 100;

	cout << "Primes under " << n << "\n";
	vector<int> primes = sieve(n);
	
	for(int i:primes){
		cout << i << "\n";
	}
	return 0;
}