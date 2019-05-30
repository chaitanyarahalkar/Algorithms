#include <iostream>

using std::cout;

int gcd(int a,int b){
	if(a == 0)
		return b;
	return gcd(b%a,a);

}
int hcf(int a,int b){
	return (a*b)/gcd(a,b);
}
int main(void){

	int a = 10; 
	int b = 12;


	int g = gcd(a,b);
	int h = hcf(a,b);

	cout << "GCD " << g << "\n";
	cout << "HCF " << h << "\n";

	assert(g == 2);
	assert(h == 60);

	return 0;
}