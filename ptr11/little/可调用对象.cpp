#include<bits/stdc++.h>
using namespace std;

//1.一个函数指针
int print(int a,double b){
    cout<<a<<b<<endl;
    return 0;
}

int (*func)(int,double)=&print;
//2.一个具有operator（）成员函数的类对象（仿函数）
struct Test
{
    void operator()(string msg){
        cout<<msg<<endl;
    }
};

//3.是一个可悲转换为函数指针的类对象
using func_ptr=void (*)(int,string);
struct Test1
{
    static void print(int a,string b)
    {
        cout<<"name:"<<b<<" age:"<<a<<endl;
    }
    operator func_ptr(){
        return print;
    }
};

struct Test2
{
    void print(int a,string b)
    {
        cout<<"name:"<<b<<" age:"<<a<<endl;
    }
    int m_num;
};

int main()
{
    Test t;
    t("liuhao");
    Test1 t1;
    t1(19,"liuhao");

    void (Test2::*func_ptr)(int,string)=&Test2::print;
    int Test2::*obj_ptr = &Test2::m_num;
    Test2 t2;
    (t2.*func_ptr)(19,"liuhao");
    t2.*obj_ptr=20;
}
