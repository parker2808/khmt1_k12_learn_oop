#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class DATE{
    int ngay, thang, nam;
public:
    void nhap(){
        cout << "Ngay: ";   cin >> ngay;
        cout << "Thang: ";  cin >> thang;
        cout << "Nam: ";    cin >> nam;
    }
    void xuat(){
        cout << setw(15) << ngay << "/" << thang << "/" << nam << endl;
    }
};

class NHANSU{
    string manhansu, hoten;
    DATE ns;
public:
    void nhap(){
        cout << "Ma nhan su: "; getline(cin, manhansu);
        cout << "Ho Ten: "; getline(cin, hoten);
        ns.nhap();
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << manhansu << setw(20) << hoten;
        ns.xuat();
    }
};

int main(){
    int n;
    cout << "Nhap vao tong so nhan su: ";   cin >> n;
    cin.ignore(1);
    NHANSU *a = new NHANSU[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << ": " << endl;
        a[i].nhap();
    }
    cout << endl;
    cout << setw(10) << "MANHANSU" << setw(17) << "HOTEN" << setw(20) << "DATE" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
