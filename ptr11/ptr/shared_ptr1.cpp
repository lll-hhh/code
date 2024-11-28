#include <iostream>
#include <memory>
using namespace std;

int mian(){
    shared_ptr<int> ptr1(new int(42));
    cout<<ptr1.use_count()<<endl;
    shared_ptr<int> ptr2(ptr1);
    cout<<ptr2.use_count()<<endl;
    shared_ptr<int> ptr3=ptr1;
    cout<<ptr3.use_count()<<endl;
    shared_ptr<int> ptr4(std::move(ptr1));
    cout<<ptr4.use_count()<<endl;
    shared_ptr<int> ptr5=std::move(ptr1);
    cout<<ptr5.use_count()<<endl;
}
/*
ptr1管理的内存引用计数: 1
ptr2管理的内存引用计数: 2
ptr3管理的内存引用计数: 3
ptr4管理的内存引用计数: 3
ptr5管理的内存引用计数: 3
*/
