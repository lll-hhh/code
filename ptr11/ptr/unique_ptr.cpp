#include <iostream>
#include <memory>
using namespace std;


unique_ptr<int> func(){
    return unique_ptr<int>(new int(42));
}
int main(){
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2=func();
    unique_ptr<int> ptr3=move(ptr1);
    unique_ptr<int> ptr4=make_unique<int>(100);

    ptr2.reset(new int(529));
    ptr2.reset();
    cout<<*ptr3.get();
    
}