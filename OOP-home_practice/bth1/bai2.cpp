#include <iostream>
using namespace std;

class HCN{
    float d, r;
public:
    void nhap(){
        cout << "Nhap chieu dai: ";     cin >> d;
        cout << "Nhap chieu rong: ";    cin >> r;
    }
    void ve(){
        for(int i=0; i<r; i++){
            for(int j=0; j<d; j++)  cout << " * ";
            cout << endl;
        }
    }
    float DIENTICH(){
        return d*r;
    }
    float CHUVI(){
        return (d+r)*2;
    }
};

int main(){
    HCN a;
    a.nhap();
    cout << "Ve hinh chu nhat: " << endl << endl;
    a.ve();
    cout << endl << "Dien tich hinh chu nhat la: " << a.DIENTICH() << endl;
    cout << "Chu vi hinh chu nhat la: " << a.CHUVI() << endl;
    return 0;
}
