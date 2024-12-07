#include<bits/stdc++.h>
using namespace std;

class Base
{
public:
    void setText(string str)
    {
        notes = str;
    }
    void print()
    {
        cout << "Base notes: " << notes << endl;
    }
private:
    string notes;
};

union Student
{
    Student()
    {
        new (&name)string;
    }
    ~Student(){}

    int id;
    Base tmp;
    string name;
};

int main()
{
    Student s;
    s.name = "蒙奇·D·路?";
    s.tmp.setText("我是要成?海?王的男人!");
    s.tmp.print();
    cout << "Student name: " << s.name << endl;
    return 0;
}