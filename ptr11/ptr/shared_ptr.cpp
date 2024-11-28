#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1(new int(42));
    //使用智能指针管理一块int内存

    std::shared_ptr<char> ptr2(new char[23]);
    //使用智能指针管理一块char数组内存

    std::cout<<ptr1.use_count()<<std::endl;
    //输出ptr1管理的内存引用数量

    std::shared_ptr<int> ptr3;
    // 创建智能指针对象, 不管理任何内存

    std::shared_ptr<int>(nullptr);
    // 创建智能指针对象，初始化为空

    std::cout<<ptr3.use_count()<<std::endl;
    
    //如果智能指针被初始化了一块有效内存，
    //那么这块内存的引用计数+1，
    //如果智能指针没有被初始化
    //或者被初始化为nullptr空指针
    //引用计数不会+1。
    //不要使用一个原始指针初始化多个shared_ptr。

    int *p =new int;
    std::shared_ptr<int> ptr4(p);
    //std::shared_ptr<int> ptr5(p);报错

    


}