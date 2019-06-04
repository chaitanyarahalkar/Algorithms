#include <iostream>

using std::cout; 

void swap(int &x,int &y){

	int tmp = x;
	x = y;
	y = tmp;

}

void selection_sort(int arr[],int n){

	int j,min;
	for(int i = 0; i < n-1; i++){

		min = i;
		for(j = i+1; j < n; j++)
			if(arr[j] < arr[min])
				min = j;

		swap(arr[min],arr[i]);

	}


}

int main(void){

	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);

	cout << "Sorted by Selection Sort\n";
	selection_sort(arr,n);

	for(int x = 0; x < n; x++)
		cout << arr[x] << " ";

	cout << "\n";

	return 0;
}