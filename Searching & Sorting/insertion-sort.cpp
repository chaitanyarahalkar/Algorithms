#include <iostream>

using std::cout;


void insertion_sort(int arr[],int n){


	for(int i = 1; i < n; i++){
		int key = arr[i];
		int j = i - 1;

		while(j >= 0 && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
	}

}

int main(void){


	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);

	cout << "Sorted by Insertion Sort\n";
	insertion_sort(arr,n);

	for(int x = 0; x < n; x++)
		cout << arr[x] << " ";

	cout << "\n";

	return 0;
}