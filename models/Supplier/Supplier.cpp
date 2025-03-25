#include "Supplier.h"
#include "../User/User.h"
#include <iostream>

using namespace std;

void supplier::SetProductType(){
    wcout << L"Введите название продукции: ";
    getline(wcin, m_productType);
}

wstring supplier::GetProductType() const{
    return m_productType;
}

void supplier::print() {
    wcout << L"Поставщик: " << GetSurname() << L" " << GetName() << endl;
    wcout << L"Тип продукции: " << m_productType << endl;
}

wostream& operator<<(wostream& out, const supplier& sup) {
    out << L"Поставщик: " << sup.GetSurname() << L" " << sup.GetName() << endl;
    out << L"Возраст: " << sup.GetAge() << endl;
    out << L"Тип продукции: " << sup.GetProductType() << endl;
    return out;
}

wistream& operator>>(wistream& in, supplier& sup){
    wstring surname, name, productType;
    int age;

    wcout << L"Введите фамилию: ";
    getline(in, surname);
    wcout << L"Введите имя: ";
    getline(in, name);
    wcout << L"Введите возраст: ";
    in >> age;
    in.ignore();
    wcout << L"Введите должность: ";
    getline(in, productType);

    sup.m_surname = surname;
    sup.m_name = name;
    sup.m_age = age;
    sup.m_productType = productType;

    return in;
}

bool supplier::operator<(const supplier& other) const{
    return m_surname < other.m_surname;
}

bool supplier::operator>(const supplier& other) const{
    return m_surname > other.m_surname;
}

bool supplier::operator==(const supplier& other) const{
    return m_surname == other.m_surname;
}

/*void supplier::PrintRecordSup(int index) const {
    wcout << left << L"| "
    << setw(5) << index L" | "
    << setw(20) << m_surname << L" | "
    << setw(20) << m_name << L" | "
    << setw(10) << m_age << L" | "
    << setw(20) << m_productType << L" | " << endl;

    wcout << setfill(L'-') << setw(91) << L"-" << setfill(L' ') << endl;
}*/