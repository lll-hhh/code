#include <iostream>
#include <thread>
struct MyFunctor{
    void operator()(){
        std::cout<<"ok"<<std::endl;
    }
};
void func(){
    std::cout<<"ok3"<<std::endl;
}
class Func_class{
public:
    void func_class_test(){
        std::cout<<"ok4"<<std::endl;
    }
};
int main(){
    MyFunctor fun;
    Func_class obj;
    std::thread p1(fun);
    //或者
    std::thread p1{MyFunctor()};
    
    std::thread p2([](){std::cout<<"ok2"<<std::endl;});
    std::thread p3(func);
    std::thread p4(&Func_class::func_class_test,&obj);
    p1.join();//伪函数
    p2.join();//lambda函数
    p3.join();//普通函数
    p4.join();//类函数
    return 0;
    //回调函数就是在线程中执行的具体任务或代码块。
    //都需要再线程生命周期结束前正确处理资源
}