#include <iostream>

using namespace std;
class PS
{
    int TS, MS;

  public:
    PS()
    {
        TS = 0;
        MS = 0;
    }
    PS(float x, float y)
    {
        TS = x;
        MS = y;
    }
    PS operator*(PS y)
    {
        PS tg;
        tg.TS = TS * y.TS;
        tg.MS = MS * y.MS;
        return tg;
    }
    double operator!()
    {
        return (double)TS / MS;
    }
    friend istream &operator>>(istream &x, PS &y);
    friend ostream &operator<<(ostream &x, PS y);
};
istream &operator>>(istream &x, PS &y)
{
    cout << "Nhap Tu so  :";
    x >> y.TS;
    cout << "Nhap Mau so :";
    x >> y.MS;
    return x;
}
ostream &operator<<(ostream &x, PS y)
{
    x << y.TS << "/" << y.MS;
    return x;
}
int main()
{
    PS a(1, 2), b(3, 4);
    cout << "Phuong thuc khoi tao" << a << "x" << b << "=" << a * b << endl;

    PS c, d;
    cout << "Nhap phan so c  :" << endl;
    cin >> c;
    cout << "Nhap phan so d :" << endl;
    cin >> d;
    cout << "- Phep nhan: " << c << " x " << d << " = " << c * d << endl;

    return 0;
}