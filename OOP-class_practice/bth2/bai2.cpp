#include <iostream>
using namespace std;

class SX{
    int n;
    int *a;
public:
    void nhap(){
        cout << "Nhap n = "; cin >> n;
        a = new int[n];
        cout << "Nhap mang:" << endl;
        for(int i=0; i<n; i++){
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    void sort(){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i]>a[j]){
                    int tg = a[i];  a[i] = a[j];    a[j] = tg;
                }
            }
        }
    }
    void xuat(){
        for(int i=0; i<n; i++){
            cout << a[i] << ", ";
        }
        cout << endl;
    }    
};

int main(){
    SX a;
    a.nhap();
    a.sort();
    cout << "Mang sau khi sap tang la: ";
    a.xuat();
    return 0;
}