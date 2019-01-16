#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class OTO{
    string maoto;
    float giamuamoi, namsudung, tyle;
public:
    void nhap(){
        cout << "Ma OTO: "; getline(cin, maoto);
        cout << "Gia mua moi: ";    cin >> giamuamoi;
        cout << "So nam su dung: "; cin >> namsudung;
        cout << "Ty le khau hao/nam: "; cin >> tyle;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << maoto << setw(20) << giamuamoi << setw(20) << namsudung << setw(10) << tyle << "%" << endl;
    }
};

int main(){
    int n;
    cout << "Nhap vao so mau oto: ";    cin >> n;
    cin.ignore(1);
    OTO *a=new OTO[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << ":" << endl;
        a[i].nhap();
    }
    cout << setw(20) << "MAOTO" << setw(20) << "GIAMUAMOI" << setw(20) << "NAMSUDUNG" << setw(10) << "TYLE" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    cout << endl;
    return 0;
}
