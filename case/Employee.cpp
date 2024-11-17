#include <iostream>
#include <map>

using namespace std;

class Employee {
private:
    struct EmployeeInfo {
        string name, role;
        double salary;
    };
    map<int, EmployeeInfo> employees;

public:
    void addEmployee(int empID, string name, string role, double salary) {
        if (employees.emplace(empID, EmployeeInfo{name, role, salary}).second)
            cout << "Employee added: " << name << " (Role: " << role << ", Salary: " << salary << ")" << endl;
        else
            cout << "Employee ID already exists!" << endl;
    }

    void removeEmployee(int empID) {
        auto it = employees.find(empID);
        if (it != employees.end()) {
            cout << "Employee removed: " << it->second.name << endl;
            employees.erase(it);
        } else {
            cout << "Employee ID not found!" << endl;
        }
    }

    void viewEmployees() {
        for (const auto &e : employees)
            cout << "ID: " << e.first << ", Name: " << e.second.name
                 << ", Role: " << e.second.role << ", Salary: " << e.second.salary << endl;
    }
};

int main() {
    Employee empSystem;
    empSystem.addEmployee(1, "Alice", "Manager", 75000.0);
    empSystem.addEmployee(2, "Bob", "Developer", 50000.0);
    empSystem.viewEmployees();
    empSystem.removeEmployee(1);
    empSystem.viewEmployees();
    return 0;
}
