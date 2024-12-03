#include<bits/stdc++.h>
using namespace std;

enum class Color { red, green, blue };
//强作用域，强类型枚举成员的名称不会被输出到其父作用域空间。
//强类型枚举只能是有名枚举，如果是匿名枚举会导致枚举值无法使用（因为没有作用域名称）。
//转换限制，强类型枚举成员的值不可以与整型隐式地相互转换。

//可以指定底层类型(默认是int)
enum class liuhao:int{red,green,blue};
enum struct liuchen:char{red,green,blue};
//template<typename T>
//enum class liuchen:T{red,green,blue};
//模板化类的枚举是不允许的
int main()
{
    //int m=red;
    //int n=color::red;
    //不能直接进行赋值，因为强枚举类型是不可以隐式转换的
    //强作用于类型，不能直接使用，枚举值前必须加枚举类型
    if((int)Color::red>=2)
    {
        cout<<"equal"<<endl;
    }
    else
    {
        cout<<"not equal"<<endl;
    }
    Color c1 = green;          // C++11以前的用法,因为前面有好几个green
    Color c2 = Color::green;  // C++11的扩展语法
    return 0;
}
//c++11对普通枚举类型进行了扩展，可以指定枚举类型的底层类型
//c++11中枚举成员的名字会自动输出到父作用域空间，