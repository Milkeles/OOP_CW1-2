#include "Employee.h"

#include <iostream>
#include <string>

CEmployee::CEmployee(void) {
    name = "";
    EGN = "";
    dailyWage = 0;
    daysWorked = 0;
}

CEmployee::CEmployee(std::string name, std::string EGN, int dailyWage, short daysWorked) {
    this->name = name;
    this->EGN = EGN;
    this->dailyWage = dailyWage;
    this->daysWorked = daysWorked;
}

bool CEmployee::isValidEGN(const std::string& EGN) {
    // Validate length
    if (EGN.length() != 10)
        return false;

    // Validate symbols
    for (char symbol : EGN) {
        if (!isdigit(symbol))
            return false;
    }

    // Validate birthdate
    short year = stoi(EGN.substr(0, 2));
    short month = stoi(EGN.substr(2, 2));
    short day = stoi(EGN.substr(4, 2));

    if (month > 40) {
        year += 2000;
        month -= 40;
    }
    else {
        year += 1900;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Validate last digit
    short weights[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };
    short sum = 0;

    for (int i = 0; i < 9; ++i) {
        sum += (EGN[i] - '0') * weights[i];
    }

    if (sum % 11 != EGN[9] - '0')
        return false;

    return true;
}

void CEmployee::setData(void) {
    std::cout << "Name: ";
    getline(std::cin, name);

    std::cout << "EGN: ";
    getline(std::cin, EGN);

    while (!isValidEGN(EGN)) {
        std::cerr << "Invalid EGN! Please try again: ";
        getline(std::cin, EGN);
    }

    std::cout << "Daily wage: ";
    std::cin >> dailyWage;
    std::cin.ignore();

    std::cout << "Days worked: ";
    std::cin >> daysWorked;
    std::cin.ignore();

    while (daysWorked > 31 && daysWorked < 28) {
        std::cout << "Invalid days in a month! Please try again: ";
        std::cin >> daysWorked;
        std::cin.ignore();
    }
}

void CEmployee::display(void) {
    std::cout << "Name: " << name << '\n';
    std::cout << "EGN: " << EGN << '\n';
    std::cout << "Daily wage: " << dailyWage << '\n';
    std::cout << "Days worked: " << daysWorked << '\n';
}

std::string CEmployee::getName(void) {
    return name;
}

bool CEmployee::isMale(void) {
    // Even 9th digit -> Male
    if (EGN[8] % 2 == 0) {
        return true;
    }

    return false;
}

short CEmployee::getBirthMonth(void) {
    short month = stoi(EGN.substr(2, 2));

    // People born in 2000s and 1800s
    if (month > 40) {
        month -= 40;
    }
    else if (month > 20) {
        month -= 20;
    }

    return month;
}

int CEmployee::getSalary(void) {
    return (daysWorked * dailyWage);
}
