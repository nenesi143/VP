#include "models/Employee/Employee.h"
#include "models/Supplier/Supplier.h"
#include "models/User/User.h"
#include "models/Authentication/Auth.h"
#include "models/Utils/Utils.h"
#include <locale> 
#include <iostream>
#include <vector>

using namespace std;

void MainMenu(wstring& role, vector<employee*>& employees, vector<supplier*>& suppliers);

int main(){

    setlocale(LC_ALL, "Russian");

    vector<employee*> employees;
    vector<supplier*> suppliers;
    Auth auth;
    wstring role = auth.RunAuthMenu();

    if (!role.empty()) {
        MainMenu(role, employees, suppliers);
    }

    for (employee* emp : employees) {
        delete emp;
    }
    for (supplier* sup : suppliers){
        delete sup;
    }
}

void MainMenu(wstring& role, vector<employee*>& employees, vector<supplier*>& suppliers){
    employee* emp = nullptr;
    supplier* sup = nullptr;
    if (role == L"admin"){

        while (true) {

        wcout << L"|-------------------------------------------|" << endl;
        wcout << L"| 1 - Вывести данные о пользователях        |" << endl;
        wcout << L"| 0 - Выход из программы                    |" << endl;
        wcout << L"|-------------------------------------------|" << endl;

            int command;
            wcout << L"Введите номер команды: ";
            wcin >> command;

            switch(command){
                case 1:
                    for (employee* emp : employees){
                        emp->GetRecord();
                        wcout << L"|-------------------------------------------|" << endl;
                    }
                    for (supplier* sup : suppliers){
                        sup->GetRecord();
                        wcout << L"|-------------------------------------------|" << endl;
                    }
                    break;
                case 0:
                    return;
                default:
                    wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                    break;
            }
        }
    }
    else if (role == L"user"){
        while (true) {

            wcout << L"|-------------------------------------------|" << endl;
            wcout << L"| 1 - Создать объект класса сотрудник       |" << endl;
            wcout << L"| 2 - Вывести данные о сотруднике           |" << endl;
            wcout << L"| 3 - Создать объект класса поставщик       |" << endl;
            wcout << L"| 4 - Вывести данные о поставщике           |" << endl;
            wcout << L"| 5 - Сортировка сотрудников                |" << endl;
            wcout << L"| 6 - Сортировка поставщиков                |" << endl;
            wcout << L"| 7 - Удаление записи сотрудника            |" << endl;
            wcout << L"| 8 - Удаление записи поставщика            |" << endl;
            wcout << L"| 0 - Выход из программы                    |" << endl;
            wcout << L"|-------------------------------------------|" << endl;
            wcout << endl;
    
            int command;
            wcout << L"Введите номер команды: ";
            wcin >> command;
            wcin.ignore();
    
            switch(command){
                case 1:
                    emp = new employee();
                    wcin >> *emp;
                    employees.push_back(emp);
                    break;
                case 2:
                    for (employee* emp : employees){
                        wcout << *emp;
                        wcout << L"---------------------------------------------" << endl;
                    }
                    break;
                case 3:
                    sup = new supplier();
                    wcin >> *sup;
                    suppliers.push_back(sup);
                    break;
                case 4:
                for (supplier* sup : suppliers){
                    wcout << *sup;
                    wcout << L"---------------------------------------------" << endl;
                }
                    break;
                case 5:
                    SortEmployees(employees);
                    break;
                case 6:
                    SortSuppliers(suppliers);
                    break;
                case 7:
                    DeleteEmployee(employees);
                    break;
                case 8:
                    DeleteSupplier(suppliers);
                    break;
                case 0:
                    Auth auth;
                    auth.SaveFromFile(employees, suppliers);
                    return;
                default:
                    wcout << L"Неверная команда! Попробуйте еще раз." << endl;
                    break;
            }
        }
    }
}
