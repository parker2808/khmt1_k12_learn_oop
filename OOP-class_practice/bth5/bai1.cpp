#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class PERSON{
protected:
    string hoTen, ngaySinh, queQuan;
public:
};

class KYSU : public PERSON{
    string nganh;
    int namTN;
public:
    void nhap(){
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Ngay sinh: ";  getline(cin, ngaySinh);
        cout << "Que quan: ";   getline(cin, queQuan);
        cout << "Nganh: ";  getline(cin, nganh);
        cout << "Nam tot nghiep: "; cin >> namTN;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << hoTen << setw(15) << ngaySinh << setw(15) << queQuan << setw(15) << nganh << setw(15) << namTN << endl;
    }
    friend int year_MAX(KYSU *a, int n);
    friend int main();
};

int year_MAX(KYSU *a, int n){
    int mAX = a[0].namTN;
    for(int i=0; i<n; i++){
        if(a[i].namTN > a[0].namTN) mAX = a[i].namTN;
    }
    return mAX;
}

int main(){
    int n;  cout << "Tong so ky su: ";  cin >> n;   cin.ignore(1);
    cout << "NHAP VAO DANH SACH KY SU" << endl;
    KYSU *a = new KYSU[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << endl << setw(40) << "DANH SACH KY SU" << endl;
    cout << setw(20) << "HOTEN" << setw(15) << "NGAYSINH" << setw(15) << "QUEQUAN" << setw(15) << "NGANH" << setw(15) << "NAMTN" << endl;
    for(int i=0; i<n; i++)  a[i].xuat();
    int nam = year_MAX(a, n);
    cout << endl << setw(40) << "DANH SACH KY SU TOT NGHIEP GAN NHAT" << endl;
    for(int i=0; i<n; i++){
        if(a[i].namTN == nam)   a[i].xuat();
    }
    return 0;
}