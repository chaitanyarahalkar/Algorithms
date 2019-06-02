#include <iostream>
#include <unordered_map>
#define lli long long int
using namespace std;

int main() {
	// your code goes here
	
	lli tt; 
	cin >> tt; 
	
	while(tt--){
	    cout << "test " << tt  << "\n";
	    lli n;
	    unordered_map<char,int> m;
	    string arr[n];
	    
	    m['c'] = m['o'] = m['d'] = m['e'] = m['h'] = m['f'] = 0;
	    lli cnt = 0;
	    cin >> n;
	    lli i = 0;
	    
	    for(int i=0;i<n;i++){
	         cin >> arr[i];
	         lli j = 0;
	         while(arr[i][j]!='\0'){
	             switch(arr[i][j]){
	                 case 'c' : m['c']++; break;
	                 case 'o' : m['o']++; break;
	                 case 'd' : m['d']++; break;
	                 case 'e' : m['e']++; break;
	                 case 'h' : m['h']++; break;
	                 case 'f' : m['f']++; break;
	             }
	             j++;
	         }
	    }
	    
	    for(auto x:m)
	        cout << x.first << "->" << x.second << "\n" ;
	    
	}
	
	return 0;
}
