#include "../User/User.h"
#include "../Employee/Employee.h"
#include "../Supplier/Supplier.h"
#include <vector>
#include <fstream>

class Auth{
    public:
        wstring RunAuthMenu();
        wstring Authentication();
        void Registration();
        void SaveFromFile(vector<employee*>& employees, vector<supplier*>& suppliers);
};