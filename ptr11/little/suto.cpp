#include<bits/stdc++.h>
using namespace std;
int tmp = 250;
const auto tmp2 = tmp;
//auto=int; tmp2=const int
auto tmp3=tmp2;
//auto=const int; tmp3=const int
const auto &tmp4=tmp;
//auto=int;tmp4=const int&
auto &tmp5=tmp3;
//auto=const int; tmp5=const int&

int func(auto a,auto b){
    cout<<a<<b;
    return a+b;
}//错误写法

class Test
{
public:
    //auto v1=0;//error
    //static auto v2=0; 
    //error类的静态非常量成员不允许在类内直接初始化
    static const auto v3=0;
    //static auto v4;没有初始化auto失效
    int num;
};

int func()
{//不能声明数组
    int array[]={1,2,3,4,5,6};
    auto t1=array;
    //auto t2[]=array;
    //auto t3[]={1,2,3,4,5};
}

template <typename T>
struct liuhao{};

auto func1()
{
    liuhao<double> t;
    auto liuchen =t;
    //liuhao<auto> liuchen2=liuhao;
    //无法推断出模版函数
    return liuchen;
}
//下面是快乐编程

int main()
{
    map<int,string> person;
    map<int,string>::iterator it =person.begin();
    for(;it!=person.end();++it){}
    for(auto it=person.begin();it!=person.end();++it){}
}

class T1
{
public:
    static int get(){
        return 10;
    }
};

class T2
{
public:
    static string get(){
        return "hello";
    }
};

template <class A>
void func(){
    auto val=A::get();
    cout<<"val:"<<val<<endl;
}

int a=10;
decltype(a) b=99;// b -> int
decltype(a+3.14) c=1234253; // c -> double
decltype(a+b*c) d=520.1314; // d -> double
//表达式为普通变量或者普通表达式或者类表达式，在这种情况下，使用decltype推导出的类型和表达式的类型是一致的。
//表达式是函数调用，使用decltype推导出的类型和函数返回值一致。

//表达式是一个左值，或者被括号( )包围，
//使用 decltype推导出的是表达式类型的引用
//（如果有const、volatile限定符不能忽略）。

const Test obj;
decltype(obj.num)a=0;
decltype((obj.num))b=a;
int n=0;int m=0;
decltype(n+m) d=n;
decltype(n=n+m)d=n;
/*
obj.num 为类的成员访问表达式，符合场景1，因此 a 的类型为int
obj.num 带有括号，符合场景3，因此b 的类型为 const int&。
n+m 得到一个右值，符合场景1，因此c的类型为 int
n=n+m 得到一个左值 n，符合场景3，因此d的类型为 int&
*/
template <typename T>
class container{
public:
    void func(T& c){
        for(m_it=c.begin();m_it!=c.end();m_it++)
        {
            cout<< *m_it<<endl;
        }
    }
private:
    decltype(T().begin()) m_it;
};

int func2()
{
    const list<int> lst{1,2,3,4,5,6};
    container<const list<int>> liuhao;
    liuhao.func(lst);
    return 0;
}

template <typename T, typename U>
// 返回类型后置语法
auto add(T t, U u) -> decltype(t+u) 
{
    return t + u;
}
//error
//decltype(t+u) add(T t, U u) 
//{
//    return t + u;
//}
auto z= add(10,12);
