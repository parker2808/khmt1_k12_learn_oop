#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class ELECTRONIC{
protected:
    float congSuat, dienAp;
public:
    ELECTRONIC(float cS, float dA){
        congSuat = cS;
        dienAp = dA;
    }
};

class MAYGIAT : public ELECTRONIC{
    float dungTich;
    int loai;
public:
  MAYGIAT(float cS, float dA, float dT, int l) : ELECTRONIC(cS, dA){
      dungTich = dT;
      loai = l;
  }
  void xuat(){
      cout << setw(20) << congSuat << setw(15) << dienAp << setw(15) << dungTich << setw(15) << loai << endl;
  }
};

class TULANH : public ELECTRONIC{
    float dungTich;
    int soNgan;
public:
    TULANH(float cS, float dA, float dT, int soN) : ELECTRONIC(cS, dA){
        dungTich = dT;
        soNgan = soN;
    }
    void xuat(){
        cout << setw(20) << congSuat << setw(15) << dienAp << setw(15) << dungTich << setw(15) << soNgan << endl;
    }
};

int main(){
    MAYGIAT x(220, 20, 200, 1);
    cout << endl << setw(40) << "Thong Tin May Giat" << endl;
    cout << setw(20) << "CongSuat" << setw(15) << "DienAp" << setw(15) << "DungTich" << setw(15) << "Loai" << endl; x.xuat();

    cout << endl;

    TULANH y(300, 50, 500, 3);
    cout << endl << setw(40) << "Thong Tin Tu Lanh" << endl;
    cout << setw(20) << "CongSuat" << setw(15) << "DienAp" << setw(15) << "DungTich" << setw(15) << "SoNgan" << endl; y.xuat();
    return 0;
}