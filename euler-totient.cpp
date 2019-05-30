#include <iostream>

using std::cout; 

int gcd(int a,int b){
	if(a == 0)
		return b;
	return gcd(b % a,a);
}

int totient(int& n){
	int ans = 1;

	for(int i = 2; i < n; i++)
		if(gcd(i,n) == 1)
			ans++;

	return ans;
}
int main(void){

	int n = 10;
	int result = totient(n);

	cout << "Φ(" << n << ")=" << result << "\n";
	assert(result == 4);

	return 0;
}