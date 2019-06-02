#include <iostream>

using std::cout;
using std::string;

void substrings(string str){

	int n = str.length();

	for(int l = 1;l <= n; l++){
		for(int i=0; i <= n - l; i++){

			int j = i + l - 1;
			for(int k = i; k <= j; k++)
				cout << str[k];
			cout << "\n";
		}
	}
}

void substr(string str){

	int n = str.length();
	for(int l = 1; l <= n; l++)
		for(int i = 0; i <= n-l; i++)
			cout << str.substr(i,l) << "\n";
}
int main(void){


	string test = "abcdef";

	cout << "Manual method\n";
	substrings(test);

	cout << "Using substr\n";
	substr(test);

	return 0;	
}