#include "Auth.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <vector>
#include <sstream> // Для istringstream

using namespace std;

wstring Auth::Authentication(){
    wstring login, password;

    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);

    wifstream file("user.txt");

    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
        return L"";
    }

    wstring line;
    
    while(getline(file, line)){
        wistringstream temp(line);

        wstring tempLogin, tempPassword, tempRole;

        temp >> tempLogin >> tempPassword >> tempRole;

        if (tempLogin == login and tempPassword == password){
            if (tempRole == L"admin"){
                wcout << L"Вы вошли как администратор!" << endl;
            }
            else{
                wcout << L"Вы вошли как пользователь!" << endl;
            }
            return tempRole;
        }
    }

    wcout << L"Неверный логин или пароль!" << endl; 
    return L"";
}

void Auth::Registration(){

    wstring login, password, role;

    wcout << L"Введите логин: ";
    getline(wcin, login);
    wcout << L"Введите пароль: ";
    getline(wcin, password);
    wcout << L"Введите роль (admin/user): ";
    getline(wcin, role);

    wofstream file("user.txt", ios::app);

    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
    }

    file << login << " " << password << " " << role << endl;

    file.close();
    wcout << L"Вы успешно зарегистрировались!" << endl;
    
}

void Auth::SaveFromFile(vector<employee*>& employees, vector<supplier*>& suppliers){

    wofstream file("record.txt", ios::app);

    if (!file.is_open()){
        wcout << L"Ошибка открытия файла!" << endl;
    }
    if (!employees.empty()){
        for (employee* emp : employees){
            file << emp->GetSurname() << " " << emp ->GetName() << " " << emp->GetAge() << " " << emp->GetPosition() << endl;
        }
    }

    if (!suppliers.empty()){
        for (supplier* sup : suppliers){
            file << sup->GetSurname() << " " << sup ->GetName() << " " << sup->GetAge() << " " << sup->GetProductType() << endl;;
        }
    }

    file.close();
    wcout << L"Записи успешно сохранены в файл!" << endl;
}

wstring Auth::RunAuthMenu(){
    
    while (true){

        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 1 - Для авторизации в программу           |" << endl;
        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 2 - Для регистрации в программу           |" << endl;
        wcout << L"|-------------------------------------------|" << endl;
        wcout << endl;

        int command;

        wcout << L"Введите команду: ";
        wcin >> command;
        wcin.ignore();

        switch(command){
            case 1:{
                wstring role = Auth::Authentication();
                if (!role.empty()){
                return role;
                }
                break;
            }
            break;
            case 2:
                Auth::Registration();
                break;
            default:
                wcout << L"Неверная команда! Попробуйте еще раз." << endl;
        }
    }
    return L"";
}