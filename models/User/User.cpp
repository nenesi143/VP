#include "User.h"
#include <locale>
#include <iostream>

using namespace std;


void User::SetRecord() {
    wcout << L"Введите Фамилию: ";
    getline(wcin, m_surname);
    wcout << L"Введите имя: ";
    getline(wcin, m_name);
    wcout << L"Введите возраст: ";
    wcin >> m_age;
    wcin.ignore();
    wcout << L"Введите логин: ";
    getline(wcin, m_login);
    wcout << L"Введите пароль: ";
    getline(wcin, m_password);
}
void User::GetRecord() const{
    wcout << L"Фамилия - " << m_surname << endl;
    wcout << L"Имя: " << m_name <<endl;
    wcout << L"Возраст: " << m_age << endl;
    //wcout << L"Логин: " << m_login << endl; 
    //wcout << L"Пароль: " << m_password << endl;

}
wstring User::GetSurname() const{
    return m_surname;
}
wstring User::GetName() const{
    return m_name;
}
int User::GetAge() const{
    return m_age;
}
wstring User::GetLogin() const{
    return m_login;
}
wstring User::GetPassword() const{
    return m_password;
}