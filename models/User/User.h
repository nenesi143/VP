#pragma once

#include <string>
#include <locale>

using namespace std;

class User{
    protected:
    wstring m_surname;
    wstring m_name;
    int m_age;
    wstring m_login;
    wstring m_password;
    wstring m_role;

    public:
    virtual void print() = 0;
    void SetRecord();
    void GetRecord() const;
    wstring GetSurname() const;
    wstring GetName() const;
    int GetAge() const;
    wstring GetLogin() const;
    wstring GetPassword() const;
};
