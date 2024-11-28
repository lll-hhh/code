#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Test{
public:
    Test() 
    {
        cout << "construct Test..." << endl;
    }
    Test(int x) 
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str) 
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "destruct Test ..." << endl;
    }
};
int main(){
    shared_ptr<int> ptr1 = make_shared<int>(42);
    shared_ptr<Test>ptr2 = make_shared<Test>();
    shared_ptr<Test>ptr3 = make_shared<Test>(100);
    shared_ptr<Test>ptr3 =make_shared<Test>("hello");
}