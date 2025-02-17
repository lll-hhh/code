#include<iostream>
#include<thread>
#include<memory>
struct func{
    int &_i;
    func(int x):_i(x){}
    void operator()(){
        for(int i=0;i<3;i++){
            i=_i;
            std::cout<<"_i is"<<_i<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};
void oops(){
    int some_local_state=0;
    func myfunc(some_local_state);
    std::thread p1(myfunc);
    p1.detach();
}



void oops2(){
    std::shared_ptr<int> some_local_state=std::make_shared<int>(0);
    func myfunc(*some_local_state);
    //std::thread p1(myfunc);
    std::thread p1([some_local_state,&myfunc](){myfunc();});
    p1.detach();
}

void catch_exception(){
    int some_local_state=0;
    func myfunc(some_local_state);
    std::thread functhread{myfunc};
    try{
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    catch(std::exception &e){
        functhread.join();
        throw;
    }
    functhread.join();
}


class thread_guard{
private:
    std::thread& _t;
public:
    explicit thread_guard(std::thread& t):_t(t){}
    ~thread_guard(){
        if(_t.joinable()){
            _t.join();
        }
    }
    thread_guard (thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};//简单的线程守卫

void auto_guard(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

}
//慎用隐式转换
//引用参数
void param_change(int &param){
    param++;
}
void param_test(int param){
    std::thread t1(param_change,param);//错误，param传给param_change是右值传递给左值，会出错,故改成
    std::thread t1(param_change,std::ref(param));
    t1.join();

}
//回调函数加不加地址都正确

//独占（不支持拷贝或构造）
//通过move将所有权转移给线程
void deal_unique(std::unique_ptr<int> p){
    (*p)++;
}
void move_oops(){
    std::unique_ptr<int> p1=std::make_unique<int>(100);
    std::thread t(deal_unique,std::move(p1));
    t.join();

}


int main(){
    //oops();
    //oops2();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

