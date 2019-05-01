#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class date{
protected:
    int ngay, thang, nam;
public:
    date(){
        ngay = thang = nam = 0;
    }
    date(int a, int b, int c){
        ngay = a;
        thang = b;
        nam = c;
    }
    void nhap(){
        cout << "Ngay: ";   cin >> ngay;
        cout << "Thang: ";  cin >> thang;
        cout << "Nam: ";    cin >> nam;
        cin.ignore(1);
    }
    void xuat(){
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class nguoi : public date{
    char cmt[30];
    char hoTen[30];
    char noiSinh[30];
public:
    nguoi():date(){
        strcpy(cmt, " ");
        strcpy(hoTen, " ");
        strcpy(noiSinh, " ");
    }
    nguoi(int a, int b, int c, char *d, char *e, char *f):date(a, b, c){
        strcpy(cmt, d);
        strcpy(hoTen, e);
        strcpy(noiSinh, f);
    }
    void nhap(){
        cout << "Chung minh thu: "; cin.getline(cmt, 30);
        cout << "Ho ten: "; cin.getline(hoTen, 30);
        cout << "Noi sinh: ";   cin.getline(noiSinh, 30);
        cout << "-- Nhap ngay sinh --" << endl; date::nhap();
    }
    void xuat(){
        cout << setw(15) << cmt << setw(15) << hoTen << setw(15) << noiSinh << setw(9);
        date::xuat();
        cout << endl;
    }
    nguoi operator==(nguoi y){
        nguoi tg;
        strcpy(tg.cmt, y.cmt);
        strcpy(tg.hoTen, y.hoTen);
        strcpy(tg.noiSinh, y.noiSinh);
        tg.ngay = y.ngay;
        tg.thang = y.thang;
        tg.nam = y.nam;
        return tg;
    }
    friend void sortAge(int n, nguoi *a);
};

void swap(nguoi &a, nguoi &b){
    nguoi tg = a; a = b; b = tg;
}

void sortAge(int n, nguoi *a){
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
            if (a[j].nam > a[j+1].nam)  swap(a[j], a[j+1]);
        }
    }
}

int main(){
    int n;
    nguoi *a;
    cout << "Tong so nguoi can nhap: "; cin >> n;   cin.ignore(1);
    a = new nguoi[n];
    for(int i=0; i<n; i++){
        cout << "-- Nguoi thu " << i+1 << " --" << endl;
        a[i].nhap();
    }
    cout << setw(50) << "-- Danh sach nguoi --" << endl;
    cout << setw(15) << "CMT" << setw(15) << "HoTen" << setw(15) << "NoiSinh" << setw(15) << "NgaySinh" << endl;
    for(int i=0; i<n; i++)  a[i].xuat();

    //sap xep giam dan theo tuoi
    cout << setw(50) << "-- Danh sach nguoi sap xep giam dan theo tuoi --" << endl;
    cout << setw(15) << "CMT" << setw(15) << "HoTen" << setw(15) << "NoiSinh" << setw(15) << "NgaySinh" << endl;
    sortAge(n, a);
    for (int i = 0; i < n; i++) a[i].xuat();
    return 0;
}
