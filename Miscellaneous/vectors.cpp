#include <bits/stdc++.h>
using namespace std;

void vector_operations(vector<int> v){

        for(int i = 0;i < 100; i++)
            v.push_back(i);

        v.pop_back();
        v.insert(v.begin(),101);

        auto itr = v.begin();
        itr++;
        v.erase(itr);

        cout << "Element at front " << v.front() << "\n";
        cout << "Element at back "  <<v.back() << "\n";
        cout << "Element at position 20 " <<v.at(20) << "\n";
        cout << "Size of vector " << v.size() << "\n";

        for(auto i = v.begin(); i != v.end(); i++)
            cout << *i << "\n";

        v.clear();

        cout << "Container is empty " <<v.empty() << "\n";
}
int main(void){

    vector<int> v; 

    vector_operations(v);

    return 0;
}