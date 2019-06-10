#include <iostream>

using std::cout;
using std::max;
using std::string;

int longest_common_substring(string x,string y,int m,int n){

	int table[m+1][n+1];
	int result = 0;

	for(int i = 0;i <= m;i++){
		for(int j = 0;j <= n;j++){
			
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(x[i-1] == y[j-1]){
				table[i][j] = table[i-1][j-1] + 1;
				result = max(result,table[i][j]);
			}
			else
				table[i][j] = 0;
		}
	}

	return result;
}
int main(void){

	string x = "abcdeaceadaeaeab";
	string y = "abcabbaaedcaabae";

	int m = x.length();
	int n = y.length();

	int result = longest_common_substring(x,y,m,n);
	cout << "Length of longest common substring is " << result << "\n";

	return 0;
}