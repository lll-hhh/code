#include<bits/stdc++.h>
using namespace std;
int main(){
    shared_ptr<int> sp(new int);
    weak_ptr<int> ptr1();
    //weak_ptr<int> ptr2=ptr1;
    //weak_ptr<int> ptr2(ptr1);
    weak_ptr<int> ptr3(sp);
    weak_ptr<int> ptr4(ptr3);
    weak_ptr<int> ptr5=ptr3;
    weak_ptr <int> ptr6=(make_shared<int>(100));
}