#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Employee class
class Employee {
private:
    string name;
    int productivityScore;

public:
    Employee(string name) : name(name), productivityScore(0) {}

    void fillData() {
        cout << "Employee Name: " << name << endl;
        cout << "Enter productivity score (0-100): ";
        cin >> productivityScore;
    }

    int getProductivityScore() {
        return productivityScore;
    }

    string getName() {
        return name;
    }
};

// Manager class
class Manager {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void fillData() {
        cout << "Manager" << endl;
        for (Employee* employee : employees) {
            employee->fillData();
        }
    }

    void evaluate() {
        for (Employee* employee : employees) {
            int productivityScore = employee->getProductivityScore();
            string employeeName = employee->getName();

            cout << "Evaluation for Employee: " << employeeName << endl;

            if (productivityScore >= 80) {
                cout << "Employee is performing excellently!" << endl;
            } else if (productivityScore >= 60) {
                cout << "Employee is performing well." << endl;
            } else if (productivityScore >= 40) {
                cout << "Employee needs improvement." << endl;
            } else {
                cout << "Employee is underperforming." << endl;
            }

            cout << endl;
        }
    }
};

int main() {
    // Create employees
    Employee employee1("John Doe");
    Employee employee2("Jane Smith");
    Employee employee3("Mark Johnson");

    // Create a manager
    Manager manager;
    manager.addEmployee(&employee1);
    manager.addEmployee(&employee2);
    manager.addEmployee(&employee3);

    // Fill data by manager and employees
    manager.fillData();

    // Evaluate employees' performance
    manager.evaluate();

    return 0;
}
