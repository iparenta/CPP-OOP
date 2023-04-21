#include <iostream>
using std::string;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee
{
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        if (age >= 18)
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void IntroduceYourself()
    {
        std::cout<<"Name - " << Name << std::endl;
        std::cout<<"Company - " << Company << std::endl;
        std::cout<<"Age - " << Age << std::endl;
    }

    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " , sorry NO promotion for you!" << std::endl;

    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    
    virtual void Work()
    {
        std::cout << Name << " is checking email, task backlog, performing tasks..."<< std::endl;
    } 
};

class Developer:public Employee
{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug()
    {
        std:: cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work()
    {
        std::cout << Name << " is writing "<< FavProgrammingLanguage << " code" << std::endl;
    } 
    
};

class Teacher: public Employee 
{
public:
    string Subject;
    void PrepareLesson()
    {
        std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work()
    {
        std::cout << Name << " is teaching "<< Subject << std::endl;
    } 
};

int main()
{
    // Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);

    // Employee employee2 = Employee("John", "Amazon", 35);
  

    Developer d = Developer( "Saldina", "YT-CodeBeauty", 25, "C++");
    // d.FixBug();
    // d.FixBug();
    // d.FixBug();
    // d.AskForPromotion();
    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    // t.PrepareLesson();
    // t.AskForPromotion();
    // d.Work();
    // t.Work();
    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
}