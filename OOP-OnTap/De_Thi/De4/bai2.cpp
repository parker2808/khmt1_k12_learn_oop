#include <iostream>
using namespace std;

class array{
    int n;
    double *a;
public:
    array(){
        n = 0;
        a = NULL;
    }
    void xuat(){
        for(int i=0; i<n; i++)  cout << a[i] << ", ";
        cout << endl;
    }
    array operator--(){
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(a[j] < a[j+1]){
                    double tg = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tg;
                }
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &x, array &y);
};

istream &operator>>(istream &x, array &y){
    cout << "n = "; x >> y.n;
    y.a = new double[y.n];
    for(int i=0; i<y.n; i++){
        cout << "a[" << i << "] = ";
        x >> y.a[i];
    }
    return x;
}

int main(){
    //khoi tao khong doi
    array a;
    cout << "- Khoi tao mang a" << endl;
    //nhap mang
    cout << "- Nhap mang a" << endl;    cin >> a;
    cout << "Mang a vua nhap: ";    a.xuat();
    //sap mang giam dan
    a = --a;
    cout << "Mang a sau khi sap giam: ";    a.xuat();
    return 0;
}