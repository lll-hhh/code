#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len=128;
    shared_ptr<char> ptr(new char[len]);

    char* add =ptr.get();
    memset(add,0,len);
    strcpy(add,"hello world");

    shared_ptr<int> p(new int);
    *p=100;
    cout<<*p.get()<<"   "<<*p<<endl;


}