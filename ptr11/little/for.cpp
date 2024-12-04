#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> t={1,2,3,4,5};
    for(auto value:t){
        cout<<value;
    }
    for(auto &value:t){
        value++;
    }
    for(const auto &value:t){
        cout<<value;
    }
}