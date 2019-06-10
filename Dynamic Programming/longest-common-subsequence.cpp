#include <iostream>
#include <cassert>

using std::cout;
using std::string;
using std::max;


int lcs(string x,string y,int m,int n){

	int table[m+1][n+1];

	for(int i = 0; i <=m; i++){
		for(int j = 0; j <=n; j++){
			if(i == 0 || j == 0)
				table[i][j] = 0;
			else if(x[i-1] == y[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else 
				table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}

	return table[m][n];
}
int main(void){

	string x = "AGGTAB";
	string y = "GXTXAYB";

	int m = x.length();
	int n = y.length();

	int result = lcs(x,y,m,n);

	assert(result==4);

	cout << "LCS of the given two sequences is " << result << "\n";

	return 0;
}