#ifndef EMPLOYEE_H  // Добавьте этот страж
#define EMPLOYEE_H
#include "../User/User.h"

using namespace std;

class employee: public User{
    private:
        wstring m_position;
        friend wostream& operator<<(wostream& out, const employee& emp);
        friend wistream& operator>>(wistream& in, employee& emp);
    public:
        wstring GetPosition() const;
        void SetPosition();
        void print() override;
        bool operator<(const employee& other) const;
        bool operator>(const employee& other) const;
};

#endif