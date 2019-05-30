#include <iostream>
#define P 1000000007

using std::cout; 


int main(void){

	int a = INT_MAX;
	int b = INT_MAX;

	cout << ((a % P) + (b % P)) % P << "\n"; 

	cout << ((a % P) * (b * P)) % P << "\n";

	cout << ((a % P) - (b * P)) % P << "\n";

	int p = 21;
	int q = 10;

	int m = 1027;

	assert(((p + q) % m) == (((p % m) + (q % m)) % m));

	assert(((p - q) % m) == (((p % m) - (q % m)) % m));

	assert(((p * q) % m) == (((p % m) * (q % m)) % m));
	return 0;
}