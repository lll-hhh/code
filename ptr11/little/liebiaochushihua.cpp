#include <iostream>
using namespace std;

class Test
{
public:
    Test(int){}
private:
    Test(const Test&){}
};
int main()
{
    Test t(1);
    //Test t=1;error
    Test t1={1};
    Test t2{1};
    int a1 = { 1314 };
    int a2{ 1314 };
    int arr1[] = { 1, 2, 3 };
    int arr2[]{ 1, 2, 3 };

    int * p =new int{520};
    double b =double{52.134};
    int * array =new int[3]{1,2,3};

}

class Person
{
public:
    Person(int id, string name)
    {
        cout << "id: " << id << ", name: " << name << endl;
    }
};

Person func()
{
    return { 9527, "华安" };
}

int main(void)
{
    Person p = func();
    return 0;
}