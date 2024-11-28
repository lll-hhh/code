#include<iostream>

class Taskqueue
{
public:
  Taskqueue& operator=(const Taskqueue& obj)=delete;
  Taskqueue(const Taskqueue& obj)=delete;
  static Taskqueue* getinstance(){
    if (my_task==nullptr){
    std::cout<<"ok"<<std::endl;
    my_task=new Taskqueue;
    }
    return my_task;
  }
private:
  Taskqueue()=default;
  static Taskqueue* my_task;
};
Taskqueue* Taskqueue::my_task=nullptr;
int main()
{
  Taskqueue* obj=Taskqueue::getinstance();
}