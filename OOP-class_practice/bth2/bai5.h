#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class OTO{
    string maoto;
    double giamua;
    float tyle, namsd;
public:
    void nhap();
    void xuat();
};

void OTO::nhap(){
    cout << "Ma o to: ";    getline(cin, maoto);
    cout << "Gia mua moi: ";    cin >> giamua;
    cout << "Ty le khau hao: "; cin >> tyle;
    cout << "Nam su dung: ";    cin >> namsd;
    cin.ignore(1);
}

void OTO::xuat(){
    cout << setw(10) << maoto << setw(10) << setprecision(1) << giamua << setw(10) << setprecision(3) << tyle << setw(10) << setprecision(1) << namsd;
    double giatri = giamua;
    for(int i=0; i<namsd; i++)  giatri-=giatri*tyle;
    cout << setw(15) << fixed << giatri << endl;  
}