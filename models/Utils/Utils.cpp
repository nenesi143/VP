#include "Utils.h"
#include "../Employee/Employee.h"
#include "../Supplier/Supplier.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void SortEmployees(vector<employee*>& employees){
    int command;
    
    wcout << L"|-------------------------------------------|" << endl;
    wcout << L"| 1 - Сортировать по возрастанию            |" << endl;
    wcout << L"| 2 - Сортировать по Убыванию               |" << endl;
    wcout << L"|-------------------------------------------|" << endl;
    wcout << L"Введите команду: ";
    wcin >> command;

    switch(command){
        case 1: sort(employees.begin(), employees.end(), [](employee* a, employee* b){
            return *a < *b;
        });
        break;
        case 2: sort(employees.begin(), employees.end(), [](employee* a, employee* b){
            return *a > *b;
        });
        break;
        default:
        wcout << L"Неверная команда!" << endl;
        break;
    }
}

void SortSuppliers(vector<supplier*>& suppliers){
    int command;
    
    wcout << L"|-------------------------------------------|" << endl;
    wcout << L"| 1 - Сортировать по возрастанию            |" << endl;
    wcout << L"| 2 - Сортировать по Убыванию               |" << endl;
    wcout << L"|-------------------------------------------|" << endl;
    wcout << L"Введите команду: ";
    wcin >> command;

    switch(command){
        case 1: sort(suppliers.begin(), suppliers.end(), [](supplier* a, supplier* b){
            return *a < *b;
        });
        break;
        case 2: sort(suppliers.begin(), suppliers.end(), [](supplier* a, supplier* b){
            return *a > *b;
        });
        break;
        default:
        wcout << L"Неверная команда!" << endl;
        break;
    }
}

void DeleteEmployee(vector<employee*>& employees){
    int index;
    
    for (int i = 0; i < employees.size(); i++){
        wcout << i + 1 << L" ";
        employees[i]->GetRecord();
    }

    wcout << L"Введите индекс удаляемой записи: ";
    wcin >> index;

    delete employees[index - 1];
}

void DeleteSupplier(vector<supplier*>& suppliers){
    int index;
    
    for (int i = 0; i < suppliers.size(); i++){
        wcout << i + 1 << L" " << endl;
        suppliers[i]->GetRecord();
    }

    wcout << L"Введите индекс удаляемой записи: ";
    wcin >> index;

    delete suppliers[index - 1];
}

/*void PrintAllRecordsEmp(employee* emp, int size){
    wcout << left << L"| "
    << setw(4) << L"№" << L" | "
    << setw(20) << L"Фамилия" << L" | "
    << setw(20) << L"Имя" << L" | "
    << setw(10) << L"Возраст" << L" | "
    << setw(20) << L"Должность" << L" |" << endl;
    wcout << setfill(L'-') << setw(91) << L"-" << setfill(L' ') << endl;

    for (int i = 0; i < lenght; i++){
        emp[i].PrintRecordEmp(i + 1);
    }
}

void PrintAllRecordsSup(supplier* sup, int size){
    wcout << left << L"| "
    << setw(4) << L"№" << L" | "
    << setw(20) << L"Фамилия" << L" | "
    << setw(20) << L"Имя" << L" | "
    << setw(10) << L"Возраст" << L" | "
    << setw(20) << L"Тип продукта" << L" |" << endl;
    wcout << setfill(L'-') << setw(91) << L"-" << setfill(L' ') << endl;
    for (int i = 0; i < lenght; i++){
        sup[i].PrintRecordSup(i + 1);
    }
}*/