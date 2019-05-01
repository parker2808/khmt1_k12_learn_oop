#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class list;

class xe{
protected:
    char mauSon[20];
    char bienSo[20];
    char noiDk[20];
    int namDk;
public:
    xe(){
        strcpy(mauSon, " ");
        strcpy(bienSo, " ");
        strcpy(noiDk, " ");
        namDk = 0;
    }
    xe(char *a, char *b, char *c, int d){
        strcpy(mauSon, a);
        strcpy(bienSo, b);
        strcpy(noiDk, c);
        namDk = d;
    }
    ~xe(){
        //
    }
    void nhap(){
        cout << "Mau son: ";    cin.getline(mauSon, 20);
        cout << "Bien so: ";    cin.getline(bienSo, 20);
        cout << "Noi dang ky: ";    cin.getline(noiDk, 20);
        cout << "Nam dang ky: ";    cin >> namDk;   cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << mauSon << setw(15) << bienSo << setw(15) << noiDk << setw(15) << namDk;
    }
    friend void findLocal(list x);
};

class chuSoHuu : public xe{
    char tenCsh[30];
    char chungMt[30];
public:
    chuSoHuu() : xe(){
        strcpy(tenCsh, " ");
        strcpy(chungMt, " ");
    }
    chuSoHuu(char *a, char *b, char *c, int d, char *e, char *f) : xe(a, b, c, d){
        strcpy(tenCsh, e);
        strcpy(chungMt, f);
    }
    void nhap(){
        xe::nhap();
        cout << "Ten chu so huu: "; cin.getline(tenCsh, 30);
        cout << "Chung minh thu: "; cin.getline(chungMt, 30);
    }
    void xuat(){
        xe::xuat();
        cout << setw(15) << tenCsh << setw(15) << chungMt << endl;
    }
};

class list{
    int n;
    chuSoHuu *a;
public:
    void nhap(){
        cout << "Nhap tong so chu so huu: ";    cin >> n;   cin.ignore(1);
        a = new chuSoHuu[n];
        for(int i=0; i<n; i++){
            cout << "- Person " << i+1 << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << setw(50) << "-- Danh sach chu so huu --" << endl;
        cout << setw(15) << "ChuSoHuu" << setw(15) << "CMT" << setw(15) << "MauSon" << setw(15) << "BienSo" << setw(15) << "NoiDK" << setw(15) << "NamDK" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
    friend void findLocal(list x);
};

void findLocal(list x){
    for(int i=0; i<x.n; i++){
        if (strcmp(x.a[i].noiDk, "HaNoi")==0)   x.a[i].xuat();
    }
}

int main(){
    list a;
    a.nhap();
    a.xuat();
    cout << "-- Danh sach cac chu so huu co noi dang ky xe o HaNoi --" << endl;
    findLocal(a);
    return 0;
}