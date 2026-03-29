#include "DaThuc.h"
#include <iostream>

using namespace std;
int main ()
{
    int n;
    cout<<"Nhap bac cua da thuc A: ";
    cin>>n;
    DaThuc A(n);
    A.Set_DDT();
    cout<<"Da thuc A: ";
    A.Get_DDT();
    cout<<endl;
    cout<<"Nhap gia tri X: ";
    cin>>n;
    cout<<"Gia tri Da thuc A voi X = "<<n<<" la ";
    cout<<A.Tinh_X(n);

    cout<<"\n\nNhap bac cua da thuc B: ";
    cin>>n;
    DaThuc B(n);
    B.Set_DDT();
    cout<<"Da thuc B: ";
    B.Get_DDT();
    cout<<endl;
    cout<<"Tong hai Da Thuc A+B = ";
    DaThuc C = A.Cong(B);
    C.Get_DDT();
    cout<<endl;
    cout<<"Hieu hai Da Thuc A-B = ";
    C = A.Tru(B);
    C.Get_DDT();
    return 0;
}
