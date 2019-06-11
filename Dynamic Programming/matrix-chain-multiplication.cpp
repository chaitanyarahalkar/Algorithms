#include <iostream>

using std::cout;

int matrix_chain_multiplication(int arr[],int n){

	int table[n][n];
	for(int i = 0; i < n; i++)
		table[i][i] = 0;

	for(int chlen = 2; chlen < n; chlen++){

		for(int i = 1; i < n - chlen + 1; i++){

			int j = i + chlen - 1;
			table[i][j] = INT_MAX;

			for(int k = i; k <= j -1; k++){

				int q = table[i][k] + table[k+1][j] + arr[i-1]*arr[k]*arr[j];

				if(q < table[i][j])
					table[i][j] = q;
			}
		}
	}

	return table[1][n-1];
}

int main(void){

	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(int);

	int result = matrix_chain_multiplication(arr,n);

	cout << "Minimum number of multiplications required are " << result << "\n";
	return 0;
}