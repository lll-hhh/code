#include<bits/stdc++.h>
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