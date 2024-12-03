#include<bits/stdc++.h>
using namespace std;
//c++11友元类最重要的新特性是可以将友元类声明为模板类
//而且c++11友元声明可以不加类型参数，类型参数包括类模板参数和非类型参数


class test;

template <typename T>
class Math
{
public:
    Math(int num,int sco):number(num),score(sco){}
    friend test;
    //friend class English<int>;
    friend English<T>;//都可以
private:
    int number;
    int score;
};

template <typename T>
class English{
public:
    English(int num,int sco):number(num),score(sco){}
    friend test;
private:
    int number;
    int score;
};

class test{
public:
    void test_1(int num,int sco,Math<int> &math){
        math.number=num;
        math.score=sco;
    }
    void test_2(int num,int sco,English<int> &english){
        english.number=num;
        english.score=sco;
    }
};