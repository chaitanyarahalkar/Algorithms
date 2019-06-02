#include <iostream>

using std::cout;


void combinations(int arr[],int n ,int r,int index,int data[],int i){

	if(index == r){

		for(int j = 0; j < r; j++)
			cout << data[j] << " ";
		cout << "\n";
		return;
	}

	if(i >= n)
		return;

	data[index] = arr[i];
	combinations(arr,n,r,index+1,data,i+1);

	combinations(arr,n,r,index,data,i+1);
}

int main(void){

	int arr[] = {1,2,3,4,5};
	int r = 3;
	int n = sizeof(arr)/sizeof(int);

	int data[r];

	combinations(arr,n,r,0,data,0);

	return 0;
}