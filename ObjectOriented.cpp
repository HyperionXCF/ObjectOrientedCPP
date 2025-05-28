//object oriented programming - a paradigm which allows to encapsulate code into objects and methods on objects
// ususally great to represent real life concepts in terms of code 

#include <bits/stdc++.h>
using namespace std;

// declaring a class

class Teacher{
    // properties or attributes of teacher class
public:
    string name;
    string dept;
    string subject;
    double salary;
    
    // methods or member functions of teacher class
    void changeDept(string newDept){
        dept = newDept;
    }
    
    // now create the object of this class in main 
    
    // creating a copy constructor
    // constructor named Teacher will get the parameter of type == Teacher passed by reference.
    
};

int main() {
    // objects - entities in real world
    // classes - blueprint of these object, has behaviour, functions and characterstic properties of that objects - it can also be a group of objects 
    //  method - function written inside a class, associated with an object.
    
    // class product - properties : name price description discount
    // class product - methods  : buyNow, addToCart, addToWishlist, return, replace 
    
    // now same blueprint (class) can be used to create multiple products without the need to repeat the same code and variables again and again
    
    // creating an object
    // <className> <objectName>;
    
    Teacher t1;
    
    // use dot operator to access and update the properties of class
    
    t1.name = "RGT sir";
    t1.dept = "AS&H";
    t1.subject = "MultiVariate Calculus";
    t1.salary = 25000;
    
    cout << t1.name << endl; // this line will show error that name is private member of Teacher.
    
    // access modifiers need to used to overcome this
    // access modifier is a keyword : 
    // private, public, protected
    
    // private - data and methods accessible only inside the class
    // by default everything attribute and method is private in C++
    
    
    
    class Student{
        // everything below private access modifier is now private and accessible only inside the Student class.
    private:
        string name;
        int rollno;
        int sub1Mark;
        int sub2Mark;
        int sub3Mark;
        int total;
    
        int totalMarks(int m1,int m2, int m3){
            return m1+m2+m3;
        }
        
    // to access private data outside the class we can create public functions and return the private data.
    public:
        // this type of function is called setter function
        // - generally used to set the private values;
        void setTotal(int s){
            total = s;
        }
        // this type of function is called getter function
        // - generally used to get the values of private data members
        int getTotal(){
            return total;
        }
    };
    
    Student s1;
    s1.setTotal(300);
    cout << "total marks of student after setting is : " <<s1.getTotal() << endl;
    
    //public - data and methods accessible in and outside the class
    
    class College{
    public:
        string name;
        int numberOfBranches;
        int numberOfStudentsin1Branch;
        
        int totalStudent(int B,int Sin1B){
            return B*Sin1B;
        }
        
    };
    
    College PCCOE;
    PCCOE.name = "PCCOE Akurdi";
    PCCOE.numberOfBranches = 6;
    PCCOE.numberOfStudentsin1Branch = 120;
    
    cout << PCCOE.name << endl;
    cout << PCCOE.numberOfBranches << endl;
    cout << PCCOE.numberOfStudentsin1Branch << endl;
    
    int total = PCCOE.totalStudent(PCCOE.numberOfBranches,PCCOE.numberOfStudentsin1Branch);
    cout << total << endl;
    
    // protected access modifier 
    // the data and methods are accessible inside the class and to its derieved classes.
    
    // during inheritence, the private properties of parent class remains private but protected properties gets inherited to the child class
    
    // ENCAPSULATION
    // ABSTRACTION
    // INHERITENCE
    // POLYMORPHISM
    
    // ENCAPSULATION - declaration and wrapping up of data-members & member-fns inside a single unit called class is called encapsulation
    // helps to hide sensitive data - use private access modifier 
    
    class Account{
        public:
            string ACID;
            string userName;
            double balance;
        private:
            string password; // hidden sensitive data 
    };
    
    // CONSTRUCTOR - special type of method 
    // invoked or called automatically whenever an object is created
    // it is used to initialise objects
    
    // class is blueprint for creating objects, class doesn't really occupy any memory 
    // but when we create an object of that class we need to allocate the new object memory & simultaneously we need to declare and initialise the data members and member function with some initial or default values.
    // if we do not create a constructor, the compiler creates it automatically 
    
    // properties of constructor 
    
    // 1. no return type not even void
    // 2. same name as the class itself
    // 3. whenever we create an object the constructor is called automatically and the code inside it will get executed
    //4. we can set / initialize the some data members and fns with default values inside the constructor
    //5. constructor fn is called only once and only during object creation
    //6. constructor is always public
    //7. allocation of memory for object happens when constructor is called.
    
    class Phone{
    private:
        int IMEI;
    public:
        string brand;
        string model;
        string origin;
        
        Phone(){
            cout << "Phone is powered ON" << endl;
            origin = "INDIA"; // here we have set the default data for data member => origin 
        }
    };
    
    Phone S22;
    cout << S22.origin << endl;
    
    // TYPES OF CONSTRUCTORS
    // 1. non parameterized - arguments can't be passed into these type of constructors example - Phone(){} in code above
    // 2. parameterized - we can pass arguments while creating object.
    
    class Friend{
    public:
        string firstName;
        string surname;
        int birthYear;
        
        // parameterised constructor for initialising the data member like firstName, surname, birthYear of a friend object.
        Friend(string f,string s,int by){
            cout << "Friend Created Successfully!" << endl;
            firstName = f;
            surname = s;
            birthYear = by;
        }
        
        // method to get the information about the friend.
        // non- parameterised.
        void getInfo(){
            cout << "Name : " << firstName << " " << surname << endl;
        }
        
        // we can write multiple constructor in same class (obviously they will have same name since construtor always have the name of class itself).
        // just make sure that each of them have have different parameters;
        
        // phenomenon of having multiple constructor in one class is known as CONTRUCTOR OVERLOAD and it is an example of POLYMORPHISM
        
        Friend(){
            cout << "Lets be Friends." << endl;
        }
    };
    
    Friend Vipul("Vipul","Pawar",2004);
    Vipul.getInfo();
    
    // THIS pointer 
    // this pointer points to the current object 
    
    class animal{
        public:
            string species;
            string name;
            
            animal(string species,string name){
                // species = species this statement is confusing for compiler, to point to object properties use this keyword
                // this keyword clarify the difference between both species property and species parameter;
                this->species = species; 
                this->name = name;
            }
    };
    
    animal Cat("Felis catus","kitty");
    cout << Cat.species << endl;
    cout << Cat.name << endl;
    
    // this keyword store the memory address of the class it is pointing towards.
    
    // this is memory of object
    // use dereferencing operator to access object 
    // therefore *this is object
    // now to call the data members or member fns we can simply use 
    // (*this).species === this->species
    
    
    // 3. copy constructor 
    
    // copy constructor is a special type of constructor which is used to copy properties of one object into another.
    // c++ by defaults creates copy constructor.
    
    Teacher t2(t1); // Teacher class did not had any user defined copy constructor so default copy constructor (available in C++) is used. 
    
    // creating a copy constructor inside Teacher class - refer Teacher class.

    // done on 28th May 2025; 
    // continue learning from copy constructors; deep and shallow copies concept.

}
