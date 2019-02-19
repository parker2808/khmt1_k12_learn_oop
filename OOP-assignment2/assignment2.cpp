#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class LOPHOC;

class NGUOI{
protected:
    string hoTen, queQuan, ngaySinh;
public:
    void nhap(){
        cout << "Ho ten       : ";     getline(cin, hoTen);
        cout << "Ngay sinh    : ";     getline(cin, ngaySinh);
        cout << "Que quan     : ";     getline(cin, queQuan);
    }
    void xuat(){
        cout << setw(25) << hoTen << setw(20) << ngaySinh << setw(20) << queQuan;
    }
};

class SINHVIEN : public NGUOI{
    string maSV, nganh;
    int khoaHoc;
public:
    void nhap(){
        NGUOI :: nhap();
        cout << "Ma sinh vien : ";      getline(cin, maSV);
        cout << "Nganh        : ";      getline(cin, nganh);
        cout << "Khoa hoc     : ";      cin >> khoaHoc;     cin.ignore(1);
    }
    void xuat(){
        NGUOI :: xuat();
        cout << setw(20) << maSV << setw(20) << nganh << setw(20) << khoaHoc << endl;
    }
    friend class LOPHOC;
    friend int check_K11(LOPHOC a);
    friend void sort_Course(LOPHOC a);
};

class LOPHOC{
    string maLop, tenLop, ngayMo, giaoVien;
    int n;
    SINHVIEN *sinhVien;
public:
    void nhap(){
        cout << "Ma lop hoc        : ";     getline(cin, maLop);
        cout << "Ten lop hoc       : ";     getline(cin, tenLop);
        cout << "Ngay mo           : ";     getline(cin, ngayMo);
        cout << "Giao vien         : ";     getline(cin, giaoVien);
        cout << endl << "Tong so sinh vien : ";     cin >> n;   cin.ignore(1);
        sinhVien = new SINHVIEN[n];
        for(int i=0; i<n; i++){
            cout << "STT" << i+1 << endl;
            sinhVien[i].nhap();
        }
        cout << endl;
    }
    void xuat(){
        cout << endl << setw(70) << "THONG TIN LOP HOC" << endl << endl;
        cout << setw(24) << "MA LOP HOC  : " << maLop << endl;
        cout << setw(24) << "TEN LOP HOC : " << tenLop << endl;
        cout << setw(24) << "NGAY MO     : " << ngayMo << endl;
        cout << setw(24) << "GIAO VIEN   : " << giaoVien << endl << endl;
        cout << setw(25) << "HO TEN" << setw(20) << "NGAY SINH" << setw(20) << "QUE QUAN" << setw(20) << "MA SV" << setw(20) << "NGANH" << setw(20) << "KHOA HOC" << endl << endl;
        for(int i=0; i<n; i++)  sinhVien[i].xuat();
        cout << endl;
    }
    friend int check_K11(LOPHOC a);
    friend void sort_Course(LOPHOC a);
};

// dem so sinh vien khoa 11
int check_K11(LOPHOC a){
    int dem = 0;
    for(int i=0; i<a.n; i++){
        if(a.sinhVien[i].khoaHoc == 11)     dem++;
    }
    return dem;
}

// doi cho 2 gia tri
void swapped(SINHVIEN &a, SINHVIEN &b)
{
    SINHVIEN tg = a;  a = b;  b = tg;
}

// sap xep tang dan theo khoa hoc
void sort_Course(LOPHOC a){
    for(int i=1; i<a.n; i++){
        for(int j=0; j<a.n-1; j++){
            if(a.sinhVien[i].khoaHoc < a.sinhVien[j].khoaHoc)   swapped(a.sinhVien[i], a.sinhVien[j]);
        }
    }
}

int main(){
    LOPHOC a;
    a.nhap();
    cout << "_______________________________________________________________________________________________________________________________________" << endl;
    cout << endl << setw(39) << "- THONG TIN LOP HOC VUA NHAP : " << endl;
    a.xuat();
    cout << "_______________________________________________________________________________________________________________________________________" << endl;
    int khoaHoc = check_K11(a);
    cout << endl << setw(53) << "- SO SINH VIEN KHOA 11 CO TRONG LOP HOC LA : " << khoaHoc << endl;
    cout << "_______________________________________________________________________________________________________________________________________" << endl;
    cout << endl << setw(63) << "- DANH SACH SINH VIEN SAP XEP TANG DAN THEO KHOA HOC : " << endl << endl;
    sort_Course(a);     a.xuat();
    cout << "_______________________________________________________________________________________________________________________________________" << endl;
    return 0;
}