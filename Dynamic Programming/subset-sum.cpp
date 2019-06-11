#include <iostream>

using std::cout;

bool subset_sum_check(int arr[],int n,int sum){

	bool table[n+1][sum+1];

	for(int i = 0; i <= n; i++)
		table[i][0] = true;

	for(int i = 1; i <= sum; i++)
		table[0][i] = false;

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= sum; j++){

			if(j < arr[i-1])
				table[i][j] = table[i-1][j];
			else if(j >= arr[i-1])
				table[i][j] = table[i-1][j] || table[i-1][j - arr[i-1]];
		}
	}
	return table[n][sum];
}

int main(void){

	int arr[] = {3,34,4,13,51,6};
	int n = sizeof(arr)/sizeof(int);
	int sum = 41; 

	bool result = subset_sum_check(arr,n,sum);

	assert(result == true);
	if(result)
		cout << "Subset with sum " << sum << " exists\n";
	else
		cout << "Subset with sum " << sum << " does not exist\n";

	return 0;

}