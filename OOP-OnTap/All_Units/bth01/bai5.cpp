#include <iostream>
using namespace std;

class list{
    int n;
    int *a;
public:
    void nhap(){
        cout << "n = "; cin >> n;
        while(n>100){
            cout << "Yeu cau n <=100, moi nhap lai: ";  cin >> n;
        }
        a = new int[n];
        cout << "Nhap danh sach n." << endl;
        for(int i=0; i<n; i++){
            cout << "a[" << i << "] = ";    cin >> a[i];
        }
    }
    void xuat(){
        for(int i=0; i<n; i++)  cout << a[i] << ", ";
        cout << endl;
    }
    int tongDc(){
        int tongDuongChan = 0;
        for(int i=0; i<n; i++){
            if(a[i]>0 && a[i]%2==0) tongDuongChan+=a[i];
        }
        return tongDuongChan;
    }
    void sapXep(){
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(a[j]>a[j+1]){
                    int tg = a[j];  a[j] = a[j+1]; a[j+1] = tg;
                }
            }
        }
    }
};

int main(){
    list a;
    cout << "Nhap danh sach:" << endl;  a.nhap();
    cout << "Danh sach vua nhap: ";  a.xuat();
    cout << "Tong cac so duong chan trong danh sach: " << a.tongDc() << endl;
    a.sapXep();
    cout << "Danh sach sap xep tang dan: "; a.xuat();
    return 0;
}