#include<iostream>
double triangle(double a,double b,double c){
  double s=(a+b+c)/2;
  if(a+b<=c||a+c<=b||b+c<=a)throw a;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
  double a=9.0,b=2.1,c=2.2;
  try{
   triangle(a,b,c); 
  }
  catch(double){
    std::cout<<"not"<<std::endl;
  }
  std::cout<<std::endl;
}
