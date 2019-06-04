#include <iostream>

using std::cout;

void merge(int arr[],int l,int m,int h){
	
	int n1 = m - l + 1;
	int n2 = h - m;
	int left[n1],right[n2];

	for(int i = 0; i < n1; i++)
		left[i] = arr[l + i];

	for(int i = 0; i < n2; i++)
		right[i] = arr[m + 1 + i];


	int i,j,k;
	i = j = 0;
	k = l;

	while(i < n1 && j < n2){
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while(i < n1)
		arr[k++] = left[i++];

	while(j < n2)
		arr[k++] = right[j++];
}

void merge_sort(int arr[],int l,int h){

	if(l < h){
		int m = (l + h)/2;

		merge_sort(arr,l,m);
		merge_sort(arr,m+1,h);

		merge(arr,l,m,h);
	}

}

int main(void){


	int arr[] = {7,6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(int);


	merge_sort(arr,0,n-1);


	cout << "Sorted by Merge Sort\n";
	for(int x = 0; x < n; x++)
		cout << arr[x] << " ";

	cout << "\n";


	return 0;
}