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
        date::nhap();
        cout << "Chung minh thu: "; cin.getline(cmt, 30);
        cout << "Ho ten: "; cin.getline(hoTen, 30);
        cout << "Noi sinh: ";   cin.getline(noiSinh, 30);
    }
    void xuat(){
        cout << setw(15) << cmt << setw(15) << hoTen << setw(15) << noiSinh;
        date::xuat();
        cout << endl;
    }
    nguoi operator+(nguoi y){
        nguoi tg;
        tg.cmt = y.cmt;
        tg.hoTen = y.hoTen;
        tg.noiSinh = y.noiSinh;
        tg.date.ngay = y.date.ngay;
        tg.date.thang = y.date.thang;
        tg.date.nam = y.date.nam;
    }
};