#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// copy constructor - used to copy the properties of one object into another 
    
class Teacher{
    private:
        double salary;
    public:
        string name;
        string dept;
    
    Teacher(string name,string dept,double salary){
        this->name = name;
        this->dept = dept;
        this->salary = salary;
    } 
    
    // custom copy constructor pass by reference 
    Teacher(Teacher &t){
        cout << "CUSTOM COPY CONSTUCTOR INITIALISED" << endl;
        this->name = t.name;
        this->dept = t.dept;
        this->salary = t.salary;
    }
    
    // destructor 
    // DESTUCTOR - opposite of constructor
    // constructor allocates new memory to object 
    // destructor deallocates the memory of object 
    // compiler creates destructor automatically for object 
    // only removes statically allocated,any dynamically memory allocated using new keyword must be removed using delete keyword
    
    // dectructor has same name as the class, it is called automatically
    
    ~Teacher(){
        cout << "Destructor is deallocating memory" << endl;
    }

};


    // by default C++ gives us a copy constructor for each class 
    
    // there are 2 types of copies of an object 
    // DEEP or SHALLOW COPY
    
    //default constructor always performs shallow copies
    // SHALLOW COPY - value of data is copied from another
    
    // more about them later (DO IT LATER WHEN REQUIRED)
    
    
        // INHERITENCE 
    // properties of parent class are passed/inherited to child / derieved class
    // parent aka base class
    // child aka derieved class
    
class Person{
    public:
        Person(){
            cout << "Parent Constructor is called first"  << endl;
        };
        string name;
        int age;
        
        Person(string name,int age){
            this->name = name;
            this->age = age;
        }
};

    // this is Student class extending/ inheriting Person class
    
    // MAKE SURE THAT A DEFAULT CONTRUCTOR OF PARENT CLASS IS ALWAYS PRESENT TO BE ABLE TO USE INHERITENCE IN CHILD CLASS
    
class Student : public Person {
    // student is also a person and will have name and age.
    // therefore use inheritence
    // since student class is a child class of Person
    // we do not need to create name and age again.
    
    public:
        Student(){
            cout << "Child constructor is called next" << endl;
        };
        int rollno;
        void getInfo(){
            cout << "Name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "rollno : " << rollno << endl;
        }
};

    // during inheritence parent constructor is called first and then child constructor is called. 
    // for destructor first child destructor is called then parent destructor 

class Pet{
    public:
        string name;
        int age;
        Pet(string name,int age){
            this->name = name;
            this->age = age;
        }
};

class Dog : public Pet{
    public:
        string favFood;
        
        // creating a parameterized constructor for child class
        // do not mention the datatype in parent class here vvvv
        Dog (string name, int age,string favFood) : Pet(name,age){
            this->favFood = favFood;
        }
        
};

// mode of inheritence : basically what access modifier will each inherited member will have. 

// private members of parent class are never inherited to child class
// public members of parent class are always inherited and the access modifer is same as parent class.  

// TYPE OF INHERITENCE 
// SINGLE INHERITENCE : SINGLE PARENT SINGLE CHILD
// MULTILEVEL INHERITENCE : PARENT, CHILD, CHILD OF CHILD 
// MULTIPLE INHERITENCE : 2 PARENT 1 CHILD 
// HIERARCHIAL INHERITENCE : 1 PARENT MULTIPLE CHILDS
// HYBRID INHERITENCE : MIX OF EVERYTHING ABOVE

// Example of Multiple inheritence 
class Student1{
    public:
    string name;
    int rollno;
};

class Teacher1{
    public:
    string subject;
    string dept;
    double salary;
};

class TA : public Student1, public Teacher1 {
    public:
    void getInfo(){
        cout << "name : " << this->name << endl;
        cout << "roll no : " << this->rollno << endl;
        cout << "subject : " << this->subject << endl;
        cout << "department : " << this->dept << endl;
        cout << "salary : " << this->salary << endl;
    }
};

int main() {
    
    Teacher t1("YASH","CSE",2500);
    cout << t1.name << endl;
    cout << t1.dept << endl;
    
    
    Student s1;
    s1.name = "Yash";
    s1.age = 20;
    s1.rollno = 124006;
    s1.getInfo();
    
    Dog Moti("Moti",2,"Doodh Roti");
    cout << "Name of Pet : "<< Moti.name << endl;
    cout << "Age of Pet : " << Moti.age << endl;
    cout << "Favourite Food : " << Moti.favFood << endl;
    
    TA ta;
    ta.name = "yash";
    ta.rollno = 123456;
    ta.subject = "Maths and computing";
    ta.salary = 2333999;
    ta.dept = "CSE";
    
    ta.getInfo();
    
    // REMAINING CONCEPTS:
    
    // POLYMORPHISM
    // FUNCTION OVERLOADING
    // ABSTRACTION 
    // ABSTRACT CLASS
    // STATIC KEYWORD
    
}
