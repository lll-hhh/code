#include<bits/stdc++.h>
using namespace std;
char* createArray(int size){
    assert(size>0);
    char* array =new char[size];
    return array;
}
static_assert(sizeof(int)==4,"int not 4 bytes");
static_assert(sizeof(long long)==8, "错误, 不是64位平台...");
int main()
{
    char* myArray = createArray(10);
    delete[] myArray;
    return 0;



}