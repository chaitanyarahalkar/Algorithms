#include <iostream>

using std::cout;
using std::max;

int integer_knapsack(int capacity,int weights[],int values[],int n){
	
	int table[n+1][capacity+1];

	for(int i = 0; i <= n;i++){
		for(int w = 0; w <= capacity; w++){

			if(i == 0 || w == 0)
				table[i][w] = 0;
			else if(weights[i-1] <= w)
				table[i][w] = max(values[i-1] + table[i-1][w - weights[i-1]],table[i-1][w]);
			else
				table[i][w] = table[i-1][w];
		}
	}
	return table[n][capacity];

}
int main(void){

	int values[] = {60,100,120};
	int weights[] = {10,20,30};

	int capacity = 50;

	int n = sizeof(values)/sizeof(int);

	int result = integer_knapsack(capacity,weights,values,n);

	cout << "Maximum profit possible is " << result << "\n";

	return 0;
}