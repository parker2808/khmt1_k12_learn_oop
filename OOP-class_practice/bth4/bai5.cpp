#include <iostream>
using namespace std;

class ARRAY{
    int *value;
    int n;
public:
    // khoi tao khong doi. NULL = rong
    ARRAY(){
        n = 0;
        value = NULL;
    }
    // khoi tao co doi
    ARRAY(int x){
        n = x;
        value = new int [n];
        for(int i=0; i<n; i++){
            value[i] = 0;
        }
    }
    // giai phong bo nho
    ~ARRAY(){
        n = 0;
        delete [] value;
    }
    void nhap(){
        //truong hop khoi tao chua co n thi nhap n.
        if(n==0){
            cout << "n = "; cin >> n;
        }
        //truong hop mang value khong chua gia tri thi khai bao dong mang value theo n.
        if(value==NULL) value = new int[n];
        cout << "Nhap mang:" << endl;
        for(int i=0; i<n; i++){
            cout << "value[" << i << "] = ";
            cin >> value[i];
        }
    }
    void xuat(){
        for(int i=0; i<n; i++)  cout << value[i] << " ";
        cout << endl;
    }
};

int main(){
    cout << "Khoi tao mang a:" << endl; ARRAY a(10);
    cout << "Mang vua duoc khoi tao la: ";  a.xuat();

    int n;  cout << "n = "; cin >> n;
    cout << "Khoi tao mang b:" << endl; ARRAY b(n); b.nhap();
    cout << "Mang ban vua nhap la: ";   b.xuat();
    return 0;
}