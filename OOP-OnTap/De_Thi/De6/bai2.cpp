#include <iostream>
using namespace std;

class phuongTrinh{
    float a, b, c, d;
public:
    phuongTrinh(){
        a = b = c = d = 0;
    }
    void nhap(){
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
        cout << "d = "; cin >> d;
    }
    phuongTrinh operator--(){
        //sap xep a, b, c, d giam dan
        float x[4] = {a, b, c, d};
        for(int i=1; i<4; i++){
            for(int j=0; j<4-i; j++){
                if(x[j] < x[j+1]){
                    float tg = x[j];
                    x[j] = x[j+1];
                    x[j+1] = tg;
                }
            }
        }
        //gan lai gia tri cho a, b, c, d
        phuongTrinh tg;
        tg.a = x[0];
        tg.b = x[1];
        tg.c = x[2];
        tg.d = x[3];
        return tg;
    }
    friend ostream &operator<<(ostream &x, phuongTrinh y);
};

ostream &operator<<(ostream &x, phuongTrinh y){
    if(y.b>=0 && y.c>=0 && y.d>=0)
        x << y.a << "x3 + " << y.b << "x2 + " << y.c << "x + " << y.d;
    else{
        if(y.b<0 && y.c>0 && y.d>0)
            x << y.a << "x3 - " << abs(y.b) << "x2 + " << y.c << "x + " << y.d;
        else{
            if(y.b>0 && y.c<0 && y.d>0)
                x << y.a << "x3 + " << y.b << "x2 - " << abs(y.c) << "x + " << y.d;
            else{
                if(y.b>0 && y.c>0 && y.d<0)
                    x << y.a << "x3 + " << y.b << "x2 + " << y.c << "x - " << abs(y.d);
                else{
                    if(y.b<0 && y.c<0 && y.d>0)
                        x << y.a << "x3 - " << abs(y.b) << "x2 - " << abs(y.c) << "x + " << y.d;
                    else{
                        if(y.b<0 && y.c>0 && y.d<0)
                            x << y.a << "x3 - " << abs(y.b) << "x2 + " << y.c << "x - " << abs(y.d);
                        else
                            x << y.a << "x3 + " << y.b << "x2 - " << abs(y.c) << "x - " << abs(y.d);
                    }
                }
            }
        }
    }
    return x;
}

int main(){
    phuongTrinh a;
    cout << "-- Nhap cac he so cho phuong trinh --" << endl;    a.nhap();
    cout << "Phuong trinh vua nhap: " << a << endl;
    cout << "Phuong trinh vua nhap sau khi dao gia tri giam dan: " << --a << endl;
    return 0;
}