#include <iostream>

using std::cout; 


void shell_sort(int arr[],int n){

	for(int part = n/2; part > 0; part/=2){

		for(int i = part; i < n; i++){

			int tmp = arr[i];
			int j;

			for(j = i; j >= part && arr[j - part] > tmp; j-=part)
				arr[j] = arr[j - part];

			arr[j] = tmp;

		}
	}

}

int main(void){

	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);

	cout << "Sorted by Shell Sort\n";
	shell_sort(arr,n);

	for(int x = 0; x < n; x++)
		cout << arr[x] << " ";

	cout << "\n";

	return 0;
}