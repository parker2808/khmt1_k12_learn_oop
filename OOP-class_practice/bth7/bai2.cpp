#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class SCHOOL{
    char name[30];
    int date;
public:
    friend class FACULTY;
    friend class STUDENT;
};

class FACULTY{
    char name[30];
    int date;
    SCHOOL x;
public:
    void input(){
        cout << "Faculty name : ";   cin.getline(name, 100);
        cout << "Faculty date : ";   cin >> date;    cin.ignore(1);
        cout << "School name  : ";    cin.getline(x.name, 100);
        cout << "School date  : ";    cin >> x.date;  cin.ignore(1);
    }
    void output(){
        cout << setw(20) << name << setw(15) << date << setw(15) << x.name << setw(15) << x.date;
    }
    friend class STUDENT;
};

class PERSON{
protected:
    char name[30];
    int birth;
    char address[30];
public:
    void input(){
        cout << "Person name  : ";  cin.getline(name, 100);
        cout << "Birthday     : ";  cin >> birth;   cin.ignore(1);
        cout << "Address      : ";  cin.getline(address, 100);
    }
    void output(){
        cout << setw(15) << name << setw(15) << birth << setw(15) << address;
    }
    PERSON(){
        strcpy(name, " ");
        birth = 0;
        strcpy(address, " ");
    }
};

class STUDENT : public PERSON{
    FACULTY y;
    char Class[30];
    float score;
public:
    void input(){
        PERSON::input();
        y.input();
        cout << "Student class : "; cin.getline(Class, 100);
        cout << "Student score : "; cin >> score;   cin.ignore(1);
    }
    void output(){
        cout << "// information Student" << endl << endl;
        cout << setw(15) << "PERSON NAME" << setw(15) << "BIRTHDAY" << setw(15) << "ADDRESS" << setw(15) << "CLASS NAME" << setw(15) << "SCORE" << endl;
        PERSON::output();
        cout << setw(15) << Class << setw(15) << score << endl;
        cout << endl << "// information Faculty & School" << endl << endl;
        cout << setw(20) << "FACULTY NAME" << setw(15) << "FACULTY DATE" << setw(15) << "SCHOOL NAME" << setw(15) << "SCHOOL DATE" << endl;
        y.output(); cout << endl;
    }
    STUDENT() : PERSON(){
        strcpy(Class, " ");
        score = 0;
        strcpy(y.name, " ");
        y.date = 0;
        strcpy(y.x.name, " ");
        y.x.date = 0;
    }
};

int main(){
    STUDENT a;
    a.input();
    cout << endl;
    a.output();
    return 0;
}