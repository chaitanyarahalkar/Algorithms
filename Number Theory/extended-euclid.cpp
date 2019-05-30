#include <iostream>

using std::cout;


int extended_euclid(int a,int b,int* x,int* y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1,y1;

	int gcd = extended_euclid(b%a,a,&x1,&y1);

	*x = y1 - (b/a)*x1;
	*y = x1;

	return gcd;
}
int main(void){

	int x,y;
	int a = 100;
	int b = 201;

	int gcd = extended_euclid(a,b,&x,&y);

	cout << "GCD " << gcd << "\n";

	assert(gcd == 1);


	return 0;
}