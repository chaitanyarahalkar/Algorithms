#include <iostream>

using std::cout;

void heapify(int arr[],int i,int n){

	int tmp = arr[i];
	int j = 2 * i;

	while(j <= n){

		if(j < n  && arr[j+1] > arr[j])
			j++;
		if(tmp > arr[j])
			break;

		else if(tmp <= arr[j]){
			arr[j/2] = arr[j];
			j*=2;
		}
	}
	arr[j/2] = tmp;
}

void heap_sort(int arr[],int n){

	for(int i = n; i >= 2; i--){

		int tmp = arr[i];
		arr[i] = arr[1];
		arr[1] = tmp;

		heapify(arr,1,i-1);

	}

}

void build_max_heap(int arr[],int n){

	for(int i = n/2; i >=1; i--)
		heapify(arr,i,n);

}

int main(void){

	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);


	build_max_heap(arr,n);
	heap_sort(arr,n);

	cout << "Sorted By Heap Sort\n";

	for(int i = 1; i <= n; i++)
		cout << arr[i] << " ";

	cout << "\n";
	return 0;
}