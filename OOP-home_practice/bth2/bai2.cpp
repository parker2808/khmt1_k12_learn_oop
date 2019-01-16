#include <iostream>
using namespace std;

class SX{
    int n;
    int *a;
public:
    void nhap(){
        cout << "Nhap vao so phan tu mang: ";   cin >> n;
        a=new int[n];
        cout << "Nhap mang: " << endl;
        for(int i=0; i<n; i++){
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    void sort(){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i]>a[j]){
                    int tg=a[i];    a[i]=a[j];  a[j]=tg;
                }
            }
        }
    }
    void xuat(){
        cout << "Mang ban vua nhap sau khi sap tang dan la: ";
        for(int i=0; i<n; i++){
            cout << a[i] << ", ";
        }
    }
};

int main(){
    SX a;
    a.nhap();
    a.sort();
    a.xuat();
    cout << endl;
    return 0;
}
