#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a1="123"+to_string(4);
    string str1 = "45";
    string str2 = "3.14159";
    string str3 = "9527 with words";
    string str4 = "words and 2";
    
    int myint1 = stoi(str1);
    int myint2 = stof(str2);
    int myint3 = stoi(str3);
    //如果字符串的前半部分字符是数值类型，
    //后半部不是，那么前半部分会被转换为对应的数值，
    //并通过返回值返回
    int myint4 = stoi(str4);
    //错误的转换，如果字符第一个字符不是数值类型转换失败
}