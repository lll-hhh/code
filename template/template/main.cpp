#include<bits/stdc++.h>
#include<cstdint>
template<class T>
T add(const T& x, const T& y) {
    return x + y;
}

template<typename T> class ClassA;

template<class T> class ClassA
{
    T number;
};

template<typename T> class vector
{
public:
    void push_back(T const&);
    void clear();
private:
    T* elements;
};

template<typename T> class liuhao
{
public:
    void clear();

};

template<typename T> void liuhao<T>::clear() {
    std::cout << "liuhao clear" << std::endl;
}

template<typename T> void foo1(T const& x);
template<typename T> T foo2(int const& x);
template<typename T, typename U> void foo3(T const& x, U const& y);
template<typename T> void foo4(int const& x) {
    T liu;
}

template <typename T> T Add(T a, T b)
{
    return a + b;
}

template <typename T > T Minus(T a, T b) {
    return a - b;
}

float test[1024];

template <typename T> T GetValue(int index) {
    return static_cast<T>(test[index]);
}
float a = GetValue<float>(0);
int b = GetValue<int>(0);

template <typename T, int Size> struct Array {
    T data[Size];
};
Array<int, 10> arr;


template <int> class test_1 {};
int main() {
    int x = 10;
    test_1<10> t1;
    //test_1<x> t2;
}

template <int i> class A {
public:
    void foo(int) {

    }
};

template <bool b, void (*a)()>class B {};
template <typename T, int (A<1>::* p)(T)>class C {};
template < void (A<2>::*a)(int),int b>class D {};


struct Variant {
    union {
        int x;
        float y;

    }data;
    uint32_t typeId;
};

Variant addFloatOrMulInt(Variant const* a, Variant const* b)
{
    Variant ret;
    assert(a->typeId == b->typeId);
    if (a->typeId == TYPE_INT) {
        ret.data.x = a->data.x * b->data.x;
        ret.typeId = TYPE_INT;
    }
    else if (a->typeId == TYPE_FLOAT) {
        ret.data.y = a->data.y + b->data.y;
        ret.typeId = TYPE_FLOAT;
    }
    else {
        // 处理未知类型的情况
        assert(false);
    }

    return ret;
}
enum DATA_TYPE {
    TYPE_INT,
    TYPE_FLOAT
};

#define hong_test(type,a,op,b,result) (*(type const*)(result)) = (*(type const*)(a)) op (*(type *)(b))
void doDiv(void* out, void const* data0, void const* data1, DATA_TYPE type) {

}
template<typename T>
class RemoveReference
{
public:
    typedef T Result;
};

//template<typename T>
//class RemoveReference<T*>
//{
//public:
//    typedef T Result;
//};//特化去除指针

template<typename T>
class RemoveReference<T*>
{
public:
    typedef typename RemiveReference<T>::Result Result
};

void dowork(int);
void dowork(float);
void dowork(int,int);
void ffff() {
    dowork(10);
    dowork(10.0f);
    dowork(10,0);
}

template <typename T> struct dowork1;
template <>struct dowork1<int>{};
template <>struct dowork1<float>{};
//template <>struct dowork1<int, int> {};

template <typename T0, typename T1 = void> struct DoWork;

template <typename T> struct DoWork<T> {};
template <>           struct DoWork<int> {};
template <>           struct DoWork<float> {};
template <>           struct DoWork<int, int> {};

DoWork<int> i;
DoWork<float> f;
DoWork<double> d;
DoWork<int, int> ii;

template <typename... Ts> class tuple;

//template <typename... Ts,typename U>class X{};
template <typename... Ts> class Y{};
template <typename... Ts,typename U>class Y<U,Ts...>{};
//template <typename...Ts,typename U>class Y<Ts...,U>{};

template<typename T0, typename T1 = void, typename T2 = void>class Tuple;

#include <type_traits>
#include <complex>

template <typename T> T CustomDiv(T lhs, T rhs) {}

template <typename T, bool IsFoalt = std::is_floating_point<T>::value> struct SafeDivide {
    static T Do(T lhs, T rhs) {
        return CustomDiv(lhs, rhs);
    }
};
template <typename T>struct SafeDivide<T, true> {
    static T Do(T lhs, T rhs) {
        return lhs / rhs;
    }
};
template <typename T>struct SafeDivide<T, false> {
    static T Do(T lhs, T rhs) {
        return lhs;
    }
};
void safeDivide() {
    SafeDivide<int>::Do(10, 0);
    SafeDivide<float>::Do(10.0f, 0.0f);
    SafeDivide<double>::Do(10.0, 0.0);
}



template <typename T> T CustomDiv(T lhs, T rhs) {
    T v;
    // Custom Div的实现
    return v;
}

template <typename T, typename Enabled = std::true_type> struct SafeDivide1 {
    static T Do(T lhs, T rhs) {
        return CustomDiv(lhs, rhs);
    }
};

template <typename T> struct SafeDivide1<
    T, typename std::is_floating_point<T>::type> {    // 偏特化A
    static T Do(T lhs, T rhs) {
        return lhs / rhs;
    }
};

template <typename T> struct SafeDivide1<
    T, typename std::is_integral<T>::type> {          // 偏特化B
    static T Do(T lhs, T rhs) {
        return rhs == 0 ? 0 : lhs / rhs;
    }
};

void foo() {
    SafeDivide<float>::Do(1.0f, 2.0f);	// 调用偏特化A
    SafeDivide<int>::Do(1, 2);          // 调用偏特化B
    SafeDivide<std::complex<float>>::Do({ 1.f, 2.f }, { 1.f, -2.f });
}


struct U {
    typedef int type;
};
template<typename T, typename U>
void fff(T t,typename U::type u)
{

}

void callFoo() {
    fff<int, U>(10, 10);
}

struct ICounter {
    virtual void increase() = 0;
    virtual ~ICounter() {}
};

struct Counter : public ICounter {
    void increase() override {
        // Implements
    }
};

template <typename T> void inc_counter(
    T& counterObj,
    typename std::enable_if<std::is_base_of<ICounter, T>::value>::type* = nullptr);

template <typename T> void inc_counter(
    T& counterInt,
    typename std::enable_if<std::is_integral<T>::value>::type* = nullptr);
//类型类别
//std::is_integral
//std::is_floating_point
//std::is_arithmetic
//std::is_enum
//std::is_union
//std::is_class
//std::is_function
//std::is_array
//std::is_pointer
//std::is_lvalue_reference
//std::is_rvalue_reference
//std::is_member_object_pointer
//std::is_member_function_pointer
//std::is_member_pointer
//std::is_fundamental
//std::is_object
//std::is_scalar
//std::is_compound
//std::is_reference
//std::is_const
//std::is_volatile
//std::is_void
//类型属性
//std::is_pod
//std::is_empty
//std::is_polymorphic
//std::is_abstract
//std::is_final
//std::is_signed
//std::is_unsigned
//std::is_referenceable
//构造和赋值
//std::is_constructible
//std::is_default_constructible
//std::is_copy_constructible
//std::is_move_constructible
//std::is_assignable
//std::is_copy_assignable
//std::is_move_assignable
//std::is_trivially_constructible
//std::is_trivially_default_constructible
//std::is_trivially_copy_constructible
//std::is_trivially_move_constructible
//std::is_trivially_assignable
//std::is_trivially_copy_assignable
//std::is_trivially_move_assignable
//std::is_trivially_destructible
//std::is_nothrow_constructible
//std::is_nothrow_default_constructible
//std::is_nothrow_copy_constructible
//std::is_nothrow_move_constructible
//std::is_nothrow_assignable
//std::is_nothrow_copy_assignable
//std::is_nothrow_move_assignable
//std::is_nothrow_destructible
//std::is_swappable
//std::is_swappable_with
//析构
//std::is_destructible
//.................

