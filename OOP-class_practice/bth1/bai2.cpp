#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class HCN{
    float d, r;
public:
    void nhap(){
        cout << "Chieu dai HCN: ";  cin >> d;
        cout << "Chieu rong HCN: "; cin >> r;
    }
    void ve(){
        for(int i=0; i<r; i++){
            for(int j=0; j<d; j++)  cout << " * ";
            cout << endl;
        }
    }
    float dientich(){
        return d*r;
    }
    float chuvi(){
        return (d+r)*2;
    }
};

int main(){
    HCN x;
    x.nhap();
    cout << endl << "Ve hinh chu nhat: " << endl;
    x.ve();
    cout << endl;
    cout << "Dien tich hinh chu nhat la: " << x.dientich() << endl;
    cout << "Chu vi hinh chu nhat la: " << x.chuvi() << endl;
    return 0;
}
