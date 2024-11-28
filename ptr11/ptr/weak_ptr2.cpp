#include<bits/stdc++.h>
using namespace std;

struct Test{
    shared_ptr<Test> getSharedPtr()
    {
        return shared_ptr<Test>(this);
    }

    ~Test()
    {
        cout<<"disstruct"<<endl;
    }
};

int main()
{
    shared_ptr<Test> sp1(new Test);
    shared_ptr<Test> sp2=sp1->getSharedPtr();
}