#include <iostream>
#include <algorithm>
#include <vector> 

using std::cout;
using std::vector;


void algorithms_implementation(){

    vector<int> v;
    int n = 100;
    for (int i = n - 1; i >= 0; i--){
        v.push_back(i);
    }

    sort(v.begin(),v.end());

    cout << "Sorted array\n";

    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << "\n";

    reverse(v.begin(),v.end());

    cout << "Reversed array\n"; 

    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << "\n";

    cout << "Maximum element " << *max_element(v.begin(),v.end()) << "\n";
    cout << "Minimum element " << *min_element(v.begin(),v.end()) << "\n";
    

    cout << "Occurences of " << n << count(v.begin(),v.end(),n) << "\n";
    cout << "Find element " << n - 2 << (find(v.begin(),v.end(),n-2) != v.end() ? " Found\n" : " Not found!\n");

    sort(v.begin(),v.end());
    cout << "Element found with Binary Search " << binary_search(v.begin(),v.end(), n - 3) << "\n";

}
int main(void){

    algorithms_implementation();

    return 0;
}

