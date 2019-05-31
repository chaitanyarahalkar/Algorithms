#include <iostream>

using std::cout;
using std::string;
using std::to_string; 

string binary_search(int arr[],int n,int val){

	int low = 0;
	int high = n;
	int mid;

	while(low <= high){

		mid = int((low + high)/2);

		
		if(arr[mid] == val)
			return "Found at index " + to_string(mid);

		if(arr[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	} 

	return "Not found!";
}

int main(void){

	int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
	int n = sizeof(arr)/sizeof(int);
	int val = 8;

	string res = binary_search(arr,n,val);
	cout << res << "\n";

	return 0;
}