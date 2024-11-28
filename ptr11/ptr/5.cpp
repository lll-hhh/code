#include <iostream>
#include <memory>
using namespace std;

void deleteptr(int *p){
    delete p;
    cout<<"OK"<<endl;
}

template<typename T>
shared_ptr<T> make_shared_array(size_t size){
    return shared_ptr<T>(new T[size],default_delete<T[]>());
}






template<typename T>
shared_ptr<T> make_shared_array1(size_t size){
    return shared_ptr<T>(new T[size],deleteptr());
}






int main(){
    shared_ptr<int> ptr(new int(42),deleteptr);
    //lambda表达式
    shared_ptr<int> ptr2(new int(42),[](int *p){delete p;});
    //shared_ptr管理动态数组时，需要用自定义删除器或者C++11的删除器
    shared_ptr<int> ptr3(new int[10],[](int*p){delete[] p;});
    shared_ptr<int> otr4(new (int[10]),default_delete<int[]>());
    shared_ptr<int> ptr5=make_shared_array<int>(10);
}