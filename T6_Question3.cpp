#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee() {}
    Employee(string name, double a_salary) {
        this->name = name;
        salary = a_salary;
    }

    string getName() {
        return name;
    }

    void setName(string a_name) {
        name = a_name;
    }

    double getSalary() {
        return salary;
    }

    void setSalary(double a_salary) {
        salary = a_salary;
    }

    void displayStaffInformation() {
        cout << "Name : " << name << ", Salary = RM " << salary << endl;
    }

    void incrementSalary(float rate) {
        if (salary < 2000) {
            salary = salary + (salary * rate);
        } else {
            cout << name << " not qualified for salary increment" << endl;
        }
    }
};

class Company {
private:
    int numberOfStaff;
    Employee *staffList;

public:
    Company() : numberOfStaff(0), staffList(nullptr) {}

    ~Company() {
        delete[] staffList;
    }

    void getDataFromFile(string filename) {
        fstream file(filename);
        string str;
        int num = 0;

        // First pass: count lines
        while (getline(file, str))
            if (!str.empty()) num++;
        file.close();

        // Allocate array
        numberOfStaff = num;
        staffList = new Employee[numberOfStaff];

        // Second pass: store names
        fstream file2(filename);
        for (int i = 0; i < numberOfStaff; i++) {
            getline(file2, str);
            staffList[i].setName(str);
        }
        file2.close();
    }

    void getSalaryFromFile(string filename) {
        fstream file(filename);
        string str;
        float sal;

        for (int i = 0; i < numberOfStaff; i++) {
            getline(file, str);
            sal = stof(str);
            staffList[i].setSalary(sal);
        }
        file.close();
    }

    void showAllStaff() {
        cout << "List of staff" << endl;
        for (int i = 0; i < numberOfStaff; i++)
            cout << staffList[i].getName() << endl;
        cout << "Number of staff = " << numberOfStaff << endl;
    }

    void showAllSalary() {
        for (int i = 0; i < numberOfStaff; i++) {
            cout << staffList[i].getName()
                 << " salary in RM :" 
                 << staffList[i].getSalary() << endl;
        }
    }
};

int main() {
    Employee e1 = Employee("Nurazlan", 1800);
    e1.displayStaffInformation();
    e1.incrementSalary(0.20);
    cout << "\nAfter salary increment" << endl;
    e1.displayStaffInformation();

    Employee e2 = Employee("Donald James", 3500);
    e2.incrementSalary(0.20);

    Company astro;
    cout << "\n\nReading staff name from text file " << endl;
    astro.getDataFromFile("staff.txt");
    astro.showAllStaff();

    cout << endl;
    cout << "\nReading salary from text file " << endl;
    astro.getSalaryFromFile("salary.txt");
    astro.showAllSalary();

    cout << "\n\n";
    return 1;
}