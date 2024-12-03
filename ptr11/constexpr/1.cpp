#include<bits/stdc++.h>

//constexpr相当于const的更加严格的版本
//必须在编译阶段就确定值
constexpr int i=520;
constexpr int j=i+1;
struct T{
    int a;
};
constexpr struct T t;

constexpr int fuc1(){
    constexpr int a=0;
    return a;
}

template <typename T>
constexpr T display(T t){
    return t;
}
//constexpr修饰构造函数只能在后面直接用输入为成员变量赋值，不能在函数体里面进行
struct Person{
    constexpr Person(const char* p,int age):name(p),_age(age)
    {}
private:
    int _age;
    const char* name;
};

int main()
{
    constexpr int a=display<int>(1);
    constexpr int b=display(520);
    constexpr struct T liuhao{19};
    constexpr struct T liuhao2=display(liuhao);
}