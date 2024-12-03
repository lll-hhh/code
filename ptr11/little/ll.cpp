#include<bits/stdc++.h>
//long long 
//对应类型的数值可以使用LL或者ll后缀
//unsigned long long
//对应类型的数值可以使用ULL或者ull
//或者 Ull、uLL (等大小写混合)后缀
/*以下类型呢等价
long long int
signed long long int
signed long long

unsigned long long 
unsigned long long int
*/
long long num1=1234567ll;
long long num2=1234567LL;
int main()
{
    long long a= LLONG_MIN;
    long long b= LLONG_MAX;
    unsigned long long c=ULLONG_MAX;
    std::cout<<a<<b<<c<<std::endl;
}
//隐式转换规则
/*长度越大的整型等级越高
比如 long long int 的等级会高于int。

长度相同的情况下，标准整型的等级高于扩展类型，
比如 long long int 和 int64 如果都是64 位长度，
则long long int类型的等级更高。

相同大小的有符号类型和无符号类型的等级相同，
long long int 和unsigned longlong int的等级就相同。

转换过程中，低等级整型需要转换为高等级整型，
有符号的需要转换为无符号整形。
*/