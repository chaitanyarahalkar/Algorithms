#include <iostream>

using std::cout; 

void swap(int &x,int &y){

	int tmp = x;
	x = y;
	y = tmp;

}

void bubble_sort(int arr[],int n){
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(arr[j] > arr[j+1])
				swap(arr[j],arr[j+1]);

}

int main(void){

	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);

	cout << "Sorted by Bubble Sort\n";
	bubble_sort(arr,n);

	for(int x = 0; x < n; x++)
		cout << arr[x] << " ";

	cout << "\n";

	return 0;
}