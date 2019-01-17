#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

using namespace std;
class phieukk;

class tskk
{
    char tents[30] ;
    int sl;
    char tt[30];
public:
    void nhap()
    {
        cout<<"Ten tai san: "; fflush(stdin); gets(tents);
        cout<<"So luong: "; cin>>sl;
        cout<<"Tinh trang: "; fflush(stdin); gets(tt);
    }
    void xuat()
    {
        cout<<setw(20)<<tents<<setw(15)<<sl<<setw(20)<<tt<<endl;
    }
    friend class phieukk;
    friend int dem(phieukk x);
};

class nvkk
{
    char tennv[30];
    char chucvu[30];
public:
    void nhap()
    {
        cout<<"Ten NV kiem ke: "; fflush(stdin); gets(tennv);
        cout<<"Chuc vu: "; fflush(stdin); gets(chucvu);
    }
    void xuat()
    {
        cout<<"Nhan vien kiem ke: "<<tennv<<setw(20)<<"Chuc vu: "<<chucvu<<endl;
    }
};

class phong
{
    char maph[30];
    char tenph[30];
    char tentp[30];
public:
    void nhap()
    {
        cout<<"Ma phong: "; fflush(stdin); gets(maph);
        cout<<"Ten phong: "; fflush(stdin); gets(tenph);
        cout<<"Ten truong phong: "; fflush(stdin); gets(tentp);
    }
    void xuat()
    {
        cout<<"Ten phong: "<<tenph<<setw(15)<<"Ma phong: "<<maph<<endl<<"Ten truong phong: "<<tentp<<endl;
    }
    friend void check(phieukk x);
};

class phieukk
{
    char maphieu[30];
    char ngay[30];
    nvkk b;
    phong c;
    tskk *a;
    int n;
public:
    void nhap();
    void xuat();
    friend int dem(phieukk x);
    friend void check(phieukk x);
};

void phieukk::nhap()
{
    cout<<"Ma phieu: "; fflush(stdin); gets(maphieu);
    cout<<"Ngay: "; fflush(stdin); gets(ngay);
    b.nhap();
    c.nhap();
    cout<<"n= "; cin>>n;
    a=new tskk[n];
    for(int i=0; i<n; i++)
        a[i].nhap();
}

void phieukk::xuat()
{
    cout<<setw(40)<<"PHIEU KIEM KE TAI SAN"<<endl;
    cout<<"Ma phieu: "<<maphieu<<setw(15)<<"Ngay: "<<ngay<<endl;
    b.xuat();
    c.xuat();
    cout<<setw(20)<<"Ten tai san"<<setw(15)<<"So luong"<<setw(20)<<"Tinh trang"<<endl;
    for(int i=0; i<n; i++)
        a[i].xuat();
    cout<<"Tong so tai san kiem ke: "<<n<<setw(20);
    int Tongsl=0;
    for(int i=0; i<n; i++)
        Tongsl+=a[i].sl;
    cout<<"Tong so luong: "<<Tongsl<<endl;
}

int dem(phieukk x)
{
    int d=0;
    for(int i=0; i<x.n; i++)
    {
        if(x.a[i].sl>1)
        {
            d++;
        }
    }
    return d;
}

void check(phieukk x)
{
    if(strcmp(x.c.tenph,"To chuc hanh chinh"))
    {
        cout<<"Co";
    }
    else cout<<"Khong";
}

int main()
{
    phieukk x;
    x.nhap();
    x.xuat();
    cout<<dem(x)<<endl ;
    check(x);
    return 0;
}
