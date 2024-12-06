#include<bits/stdc++.h>
using namespace std;
class Test
{
public:
    Test(){}
};
int main()
{
    Test t;
    Test t1(t);
    Test && t2=move(t1);
}