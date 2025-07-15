#include <iostream>
using namespace std;

class Person{
protected:
string name;
int age;
char gender;
public:
Person(string n,int a,char g){
	name = n;
	age = a;
	gender = g;
}
virtual void displayInfo(){
	cout <<"Name: "<< name<<endl;
	cout <<"Age: "<< age<<endl;
	cout <<"Gender: "<< gender<<endl;
}
};

class Student: public Person{
	private:
		double grade;
	public:
	Student(string n,int a, char g, double gr): Person(n,a,g){
		grade = gr;
	}
	void displayInfo ()override{
	Person::displayInfo();
	cout <<"Grade: "<<grade<<endl;
	}
};

class Teacher: public Person{
	private:
		double salary;
	public:
	Teacher(string n,int a, char g, double sal): Person(n,a,g){
		salary = sal;
	}
	void displayInfo ()override{
	Person::displayInfo();
	cout <<"Salary: "<<salary<<endl;
	}
};
int main() {
	cout <<"Student 1 Details: "<<endl;
	Student One("Eduardo",22,'M',90.21);
	One.displayInfo();
	cout<<"==================================="<<endl;
	cout <<"Student 2 Details: "<<endl;
	Student Two("Kot",21,'M',99.75);
	Two.displayInfo();
	cout<<"==================================="<<endl;
	cout <<"Teacher Details: "<<endl;
	Teacher Uno("Sensei",31,'F',40000);
	Uno.displayInfo();
	
	return 0;
}
