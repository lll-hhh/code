#include<iostream>

class Salary{
public:
        Salary(){Wage=0;Subsidy=0;Rent =0;Waterfee=0;Elecfee=0;}
        Salary(double wage,double Wage,double subsidy,
    class    double rent,double waterfee,double elecfee){
        Wage=wage;Subsidy=subsidy;Rent=rent;
        Waterfee=waterfee;Elecfee=elecfee;}
        void set_Wage(double x){Wage=x;}
        void set_Subsidy(double x){Subsidy=x;}
        void set_Rent(double x){Rent=x;}
        void set_Waterfee(double x){Waterfee=x;}
        void set_Electfee(double x){Elecfee=x;}
        double get_Wage(){return Wage;}
        double get_Subsidy(){return Subsidy;}
        double get_Rent(){return Rent;}
        double get_Waterfee(){return Waterfee;}
        double get_Elecfee(){return Elecfee;}
        double RealSalary(){return Wage+Subsidy-Rent-Waterfee-Elecfee;}
private:
        double Wage;
        double Subsidy;
        double Rent;
        double Waterfee;
        double Elecfee;
};
int main()
{
    Salary salary_test;
    salary_test.set_Wage(100);
    salary_test.set_Electfee(10);
    salary_test.set_Waterfee(10);
    salary_test.set_Subsidy(50);
    salary_test.set_Rent(20);
    std::cout<<salary_test.get_Wage()<<std::endl;
    std::cout<<salary_test.get_Elecfee()<<std::endl;
    std::cout<<salary_test.get_Waterfee()<<std::endl;
    std::cout<<salary_test.get_Subsidy()<<std::endl;
    std::cout<<salary_test.get_Rent()<<std::endl;
    std::cout<<salary_test.RealSalary()<<std::endl;
    
}