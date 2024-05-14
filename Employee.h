#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class CEmployee {
protected:
    std::string name, EGN;
    int dailyWage;
    short daysWorked;
    bool isValidEGN(const std::string&);

public:
    CEmployee(void);
    CEmployee(std::string, std::string, int, short);
    void setData(void);
    void display(void);
    std::string getName(void);
    bool isMale(void);
    short getBirthMonth(void);
    int getSalary(void);
};

#endif
