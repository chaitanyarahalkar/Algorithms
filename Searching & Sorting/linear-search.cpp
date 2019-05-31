#include <iostream>

using std::cout;
using std::string;
using std::to_string;

string search(int arr[],int n,int val){

	for(int i = 0; i < n; i++)
		if(arr[i] == val)
			return "Found at index " + to_string(i);

	return "Not found!";
}

int main(void){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(int);
	int val = 5;
	
	string res = search(arr,n,val);
	cout << res << "\n";

	return 0;
}