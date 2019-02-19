#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class PERSON{
protected:
    string hoTen, queQuan;
    int ngaySinh;
};

class KYSU : public PERSON{
    string nganh;
    int namTN;
public:
    void nhap(){
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Ngay sinh: ";  cin >> ngaySinh;
        cin.ignore(1);
        cout << "Que quan: ";   getline(cin, queQuan);
        cout << "Nganh: ";  getline(cin, nganh);
        cout << "Nam tot nghiep: "; cin >> namTN;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << hoTen << setw(15) << ngaySinh << setw(15) << queQuan << setw(15) << nganh << setw(15) << namTN << endl;
    }
    friend int max_Year(int n, KYSU *a);
    friend int main();
};

int max_Year(int n, KYSU *a){
    int mAX = a[0].namTN;
    for(int i=0; i<n; i++){
        if(a[i].namTN > a[0].namTN)   mAX = a[i].namTN;
    }
    return mAX;
}

int main(){
    int n;
    cout << "Tong so ky su: ";  cin >> n;   cin.ignore(1);
    KYSU *a = new KYSU[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << endl << setw(40) << "DANH SACH KY SU" << endl << endl;
    cout << setw(20) << "HO TEN" << setw(15) << "NGAY SINH" << setw(15) << "QUE QUAN" << setw(15) << "NGANH" << setw(15) << "NAM TN" << endl;
    for(int i=0; i<n; i++)  a[i].xuat();
    cout << "---------------------------------------------------------------------------------" << endl;
    int year = max_Year(n, a);
    cout << endl << setw(60) << "THONG TIN CAC KY SU TOT NGHIEP GAN DAY NHAT" << endl << endl;
    cout << setw(20) << "HO TEN" << setw(15) << "NGAY SINH" << setw(15) << "QUE QUAN" << setw(15) << "NGANH" << setw(15) << "NAM TN" << endl;
    for(int i=0; i<n; i++){
        if(a[i].namTN == year)  a[i].xuat();
    }
    cout << "---------------------------------------------------------------------------------" << endl;
    return 0;
}