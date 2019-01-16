#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class DOANHNGHIEP{
    string tenDN, diachi;
    int sonhanvien;
    float doanhthu;
public:
    void nhap(){
        cout << "Ten doanh nghiep: ";   getline(cin, tenDN);
        cout << "Dia chi: ";            getline(cin, diachi);
        cout << "So nhan vien: ";       cin >> sonhanvien;
        cout << "Doanh thu: ";          cin >> doanhthu;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << tenDN << setw(20) << diachi << setw(20) << sonhanvien << setw(10) << doanhthu << endl;
    }
};

int main(){
    int n;
    cout << "Nhap vao so doanh nghiep can nhap: ";  cin >> n;
    cin.ignore(1);
    DOANHNGHIEP *a = new DOANHNGHIEP[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << ": " << endl;
        a[i].nhap();
    }
    cout << "===============================================================================" << endl;
    cout << setw(20) << "TENDOANHNGHIEP" << setw(20) << "DIACHIDOANHNGHIEP" << setw(20) << "SONHANVIEN" << setw(10) << "DOANHTHU" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    cout << "===============================================================================" << endl;
    return 0;
}
