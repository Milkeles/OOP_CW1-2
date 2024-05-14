#include <iostream>
#include <vector>

#include "Employee.h"

using namespace std;

void displayMenu() {
    cout << "\nMENU\n";
    cout << "1. Add data for new employee.\n";
    cout << "2. Display all data.\n";
    cout << "3. Display names of men earning between 300 and 500 lv.\n";
    cout << "4. Create a new array of women, who earned more than 300 lv and "
        "are born in a particular month.\n";
    cout << "0. Cease the execution." << endl;
    cout << "Choice: ";
}

void addEmployee(vector<CEmployee>& employees) {
    CEmployee newEmployee;
    newEmployee.setData();
    employees.push_back(newEmployee);
}

// No filter
void displayFilteredData(vector<CEmployee>& employees) {
    for (CEmployee employee : employees) {
        employee.display();
        putchar('\n');
    }
}

// gender == true -> Male
void displayFilteredData(vector<CEmployee>& employees, int min, int max, bool gender) {
    for (CEmployee employee : employees) {
        int salary = employee.getSalary();
        if (salary >= min && salary <= max && employee.isMale() == gender) {
            cout << employee.getName() << '\n';
        }
    }
}

vector<string> getWomenArray(vector<CEmployee>& employees) {
    vector <string> womenNames;
    short birthMonth;
    cout << "Birth month: "; cin >> birthMonth;
    for (CEmployee employee : employees) {
        int salary = employee.getSalary();
        if (salary >= 300 && !employee.isMale() && employee.getBirthMonth() == birthMonth) {
            womenNames.push_back(employee.getName());
        }
    }

    if (!womenNames.empty()) {
        cout << "Created array: ";
        size_t arraySize = womenNames.size();
        for (size_t i = 0; i < arraySize; ++i) {
            cout << womenNames[i];
            if (i != womenNames.size() - 1) {
                cout << ", ";
            }
        }
        putchar('\n');
    }
    return womenNames;
}

int main() {
    char selectedOption;
    vector <CEmployee> employees;
    vector<string> women;
    do {
        displayMenu();
        cin >> selectedOption;
        cin.ignore();

        switch (selectedOption) {
        case '0':
            break;
        case '1':
            addEmployee(employees);
            break;
        case '2':
            displayFilteredData(employees);
            break;
        case '3':
            displayFilteredData(employees, 300, 500, true);
            break;
        case '4':
            women = getWomenArray(employees);
            break;
        default:
            cerr << "Invalid option. Please try again!\n";
            break;
        }
    } while (selectedOption != '0');
    return 0;
}
