#include<bits/stdc++.h>
using namespace std;
int main(){
    shared_ptr<int> shared(new int(10));
    weak_ptr<int> weak(shared);
    cout<<"1.weak"<<(weak.expired()?"is":"isn't")<<"expired"<<endl;
    shared.reset();
    cout<<"2.weak"<<(weak.expired()?"is":"isn't")<<"expired"<<endl;



    shared_ptr<int> sp1,sp2,sp3;
    weak_ptr<int> wp;

    sp1=make_shared<int>(520);

    wp=sp1;
    sp2=wp.lock();
    cout << "use_count: " << wp.use_count() << endl;

    sp1.reset();
    cout << "use_count: " << wp.use_count() << endl;

    sp1 = wp.lock();
    cout << "use_count: " << wp.use_count() << endl;

    cout << "*sp1: " << *sp1 << endl;
    cout << "*sp2: " << *sp2 << endl;
    
    return 0;
}