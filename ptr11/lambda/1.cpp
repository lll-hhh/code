#include <bits/stdc++.h>
using namespace std;

using func_ptr=int(*)(int);

func_ptr ff = [](int a){
    return a;
};
int main()
{
    int num=10;
    auto f =[](){return 1;};
    auto f1=[=](int a)mutable{return 1+num;};
    std::function<int(int)> f1=[](int a){return a;};
    std::function<int(int)> f2=bind([](int a){return a;},placeholders::_1);
    ff(1234);
    f1(10);
}