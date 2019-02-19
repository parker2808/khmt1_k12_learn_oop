#include <iostream>
using namespace std;

class ARRAY{
    int *a;
    int n;
public:
    void nhap();
    void xuat();
    ARRAY operator+(ARRAY y);
    ARRAY operator-();
    ARRAY operator++();
    ARRAY operator!();
};

void ARRAY::nhap(){
    cout << "n = "; cin >> n;
    a = new int[n];
    for(int i=0; i<n; i++){
        cout  << "a[" << i << "] = ";   cin >> a[i];
    }
}

void ARRAY::xuat(){
    for(int i=0; i<n; i++)  cout << a[i] << " ";
}

//cong 2 mang
ARRAY ARRAY::operator+(ARRAY y){
    ARRAY z;
    if(n != y.n){
        z.n = 0;
        z.a = NULL;
    }
    else{
        z.n = n;
        z.a = new int[n];
        for(int i=0; i<n; i++)  z.a[i] = a[i] + y.a[i];
    }
    return z;
}

//doi dau mang
ARRAY ARRAY::operator-(){
    for(int i=0; i<n; i++)  a[i] = -a[i];
    return *this;
}

//sap mang
ARRAY ARRAY::operator++(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    return *this;
}

//tinh tbc
float ARRAY::operator!(){
    float tong = 0;
    for(int i=0; i<n; i++)  tong += a[i];
    return (float)tong/n;
}

int main(){
    ARRAY x, y;
    cout << "Nhap mang X" << endl;  x.nhap();   cout << "Nhap mang Y" << endl;  y.nhap();
    ARRAY z = x + y;    cout << "Tong Z = X + Y = ";    z.xuat();   cout << endl;
    z = -z; cout << "Mang Z sau khi doi dau: "; z.xuat();   cout << endl;
    z = ++z;    cout << "Mang Z sau khi sap tang: "; z.xuat();   cout << endl;

    
    return 0;
}