#include <iostream>
#include<exception>
#include <regex>
using namespace std;
class Day_Error : public exception
{
private:
    string D_err = "DayError";
public:
     string what() {
        return D_err;
    }
};

class Month_Error:public exception {
private:
    string M_err = "MonthError";
public:
     string what() {
        return M_err;
    }
};
void convert_to_alphabetic(int month , int day)
{
    try {
        if (month > 12 || month < 1) {
            throw Month_Error();
        }
        if (day > 31 || day <= 0) {
            throw Day_Error();
        }
        else {
            if (month == 1)
                cout << "January " << day << endl;
            else if (month == 2 && day <= 29)
                cout << "February " << day << endl;
            else if (month == 3)
                cout << "March " << day << endl;
            else if (month == 4)
                cout << "April " << day << endl;
            else if (month == 5 && day <= 30)
                cout << "May " << day << endl;
            else if (month == 6)
                cout << "June " << day << endl;
            else if (month == 7 && day <= 30)
                cout << "July " << day << endl;
            else if (month == 8)
                cout << "August " << day << endl;
            else if (month == 9 && day <= 30)
                cout << "September " << day << endl;
            else if (month == 10)
                cout << "October " << day << endl;
            else if (month == 11 && day <= 30)
                cout << "November " << day << endl;
            else if (month == 12)
                cout << "December " << day << endl;
            else
                throw Day_Error();
        }
    }
    catch (Month_Error &M) {
        cerr << M.what()<< endl;
        exit(0);
    }
    catch (Day_Error &D) {
        cerr << D.what() <<endl;
        exit(0);
    }
}
bool Is_Valid(string & Word){

    regex Format("[0-9]+(/)[0-9]+") ;
    return regex_match(Word, Format) ;
}
int main() {

    while (true)
    {
        string input;
        here:
        cout << "Enter the date with that form (1/31 or 01/31)(if want to exit enter -1)-->";

        getline(cin, input);
        if(!Is_Valid(input)) {
            cout << "Invalid input" << endl;
            goto here;
        }

        if(input == "-1")
            break;

        int month = stoi(input.substr(0, input.find('/')));

        int day = stoi(input.substr(input.find('/') + 1, -1));

        convert_to_alphabetic(month, day);
    }
}

