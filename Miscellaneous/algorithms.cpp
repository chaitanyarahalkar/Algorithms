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

    cout << "Maximum element " << *max_element(v.begin(),v.end());
    cout << "Minimum element " << *min_element(v.begin(),v.end());
    //cout << "Accumulation (Sum) " << accumulate(v.begin(),v.end(),0);

    cout << "Occurences of " << n << count(v.begin(),v.end(),n);
    //cout << "Find element " << n - 2 << find(v.begin(),v.end(),n-2) != v.end() ? cout << "Found at " << find(v.begin(),v.end(),n-2) << "\n" : cout << "Not found!\n";

    sort(v.begin(),v.end());
    cout << "Element found with Binary Search" << binary_search(v.begin(),v.end(), n - 3);

}
int main(void){

    algorithms_implementation();

    return 0;
}

