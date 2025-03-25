#include "Employee.h"
#include "../User/User.h"
#include <iostream>
#include <iomanip>

using namespace std;

void employee::SetPosition(){
    wcout << L"Введите должность: ";
    getline(wcin, m_position);
}

wstring employee::GetPosition() const{
    return m_position;
}

void employee::print() {
    wcout << L"Сотрудник: " << GetSurname() << L" " << GetName() << endl;
    wcout << L"Должность: " << m_position << endl; 
}

wostream& operator<<(wostream& out, const employee& emp) {
    out << L"Сотрудник: " << emp.GetSurname() << L" " << emp.GetName() << endl;
    out << L"Возраст: " << emp.GetAge() << endl;
    out << L"Должность: " << emp.GetPosition() << endl;
    return out;
}

wistream& operator>>(wistream& in, employee& emp){
    wstring surname, name, position;
    int age;
    wcout << L"Введите фамилию: ";
    getline(in, surname);
    wcout << L"Введите имя: ";
    getline(in, name);
    wcout << L"Введите возраст: ";
    in >> age;
    in.ignore();
    wcout << L"Введите должность: ";
    getline(in, position);

    emp.m_surname = surname;
    emp.m_name = name;
    emp.m_age = age;
    emp.m_position = position;

    return in;
}

bool employee::operator<(const employee& other) const{
    return m_surname < other.m_surname;
}

bool employee::operator>(const employee& other) const{
    return m_surname > other.m_surname;
}

bool employee::operator==(const employee& other) const{
    return m_surname == other.m_surname;
}

/*void employee::PrintRecordEmp(int index) const {
    wcout << left << L"| "
    << setw(5) << index << L" | "
    << setw(20) << m_surname << L" | "
    << setw(20) << m_name << L" | "
    << setw(10) << m_age << L" | "
    << setw(20) << m_position << L" |" << endl;

    wcout << setfill(L'-') << setw(91) << L"-" << setfill(L' ') << endl;
}*/