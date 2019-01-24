#include <iostream>
using namespace std;

class phanso{
    int tu, mau;
public:
    void nhap(){
        cout << "Tu = ";    cin >> tu;
        cout << "Mau = ";   cin >> mau;
    }
    void xuat(){
        cout << tu << "/ " << mau;
    }
    phanso operator+(phanso y){
        phanso tg;
        tg.tu = tu*y.mau + mau*y.tu;
        tg.mau = mau*y.mau;
        return tg;
    }
    phanso operator-(){
        // dung trung gian
        phanso tg;
        tg.tu = -tu;
        tg.mau = mau;
        return tg;

        // khong dung trung gian
        /*tu = -tu;
        return *this;*/
    }
    float operator!(){
        return (float)tu/mau;
    }
};

int main(){
    phanso p, q;
    p.nhap();   q.nhap();
    phanso k = p + q;
    p.xuat();   cout << " + ";  q.xuat();   cout << " = ";  k.xuat();   cout << endl;
    cout << "-k = ";    k = -k; k.xuat();   cout << endl;
    cout << " = " << !k << endl;
    return 0;
}