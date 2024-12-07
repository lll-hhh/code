#include<bits/stdc++.h>
using namespace std;

class A{};
class B{B(){}};
class C:B{};
class D{virtual void fn(){}};
class E:virtual public A{};

int main()
{
        cout << std::boolalpha;
    cout << "is_trivial:" << std::endl;
    cout << "int: " << is_trivial<int>::value << endl;
    cout << "A: " << is_trivial<A>::value << endl;
    cout << "B: " << is_trivial<B>::value << endl;
    cout << "C: " << is_trivial<C>::value << endl;
    cout << "D: " << is_trivial<D>::value << endl;
    cout << "E: " << is_trivial<E>::value << endl;
    return 0;
}
