#ifndef SUPPLIER_H  // Добавьте этот страж
#define SUPPLIER_H
#include "../User/User.h"

using namespace std;

class supplier : public User{
    private:
        wstring m_productType;
        friend wostream& operator<<(wostream& out, const supplier& sup);
        friend wistream& operator>>(wistream& in, supplier& sup);
    public:
        void SetProductType();
        wstring GetProductType() const;
        void print() override;
        bool operator<(const supplier& other) const;
        bool operator>(const supplier& other) const;
};

#endif