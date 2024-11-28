#include<bits/stdc++.h>
using namespace std;

class Test:public enable_shared_from_this<Test>
{
public:
    shared_ptr<Test> getshared_(){
        return shared_from_this();
    }
    ~Test(){
        cout<<"class Test is disstruct ..."<<endl;
    }
};

int main() 
{
    shared_ptr<Test> sp1(new Test);
    cout << "use_count: " << sp1.use_count() << endl;
    shared_ptr<Test> sp2 = sp1->getshared_();
    cout << "use_count: " << sp1.use_count() << endl;
    return 0;
}

