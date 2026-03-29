#include "DaThuc.h"
#include <iostream>
#include <cmath>
using namespace std;
void DonThuc::Set_DT(int a,int b)
{
    iSo=a; iMu=b;
}
void DonThuc::Get_DT()
{
    if (iSo==0) cout<<0;
    else if (iSo==1)
    {
       if (iMu==0)cout<<"1";
       else if (iMu==1) cout<<"X";
       else cout<<"X^"<<iMu;
    }
    else if (iSo==-1)
    {
       if (iMu==0)cout<<" -1";
       else if (iMu==1) cout<<" -X";
       else cout<<" -X^"<<iMu;
    }
    else if (iMu==0)
    {   if (iSo<0) cout<<" ";
        cout<<iSo;
    }
    else if (iMu==1)
    {   if (iSo<0) cout<<" ";
        cout<<iSo<<"X";
    }
    else
    {   if (iSo<0) cout<<" ";
        cout<<iSo<<"X^"<<iMu;
    }
}
double DonThuc::Solve_X(int x)
{
    return iSo*pow(x,iMu);
}
void DonThuc::Derivative()
{
    if (iMu==0||iSo==0)
    {
        iMu=0;
        iSo=0;
    }
    else
    {
        iSo=iMu*iSo;
        iMu= iMu-1;
    }
}
DonThuc DonThuc::Sum(DonThuc B)
{
    DonThuc C = *(this);
    C.iSo += B.iSo ;
    return C;
}
DonThuc DonThuc::Sumrev(DonThuc B)
{
    DonThuc C = *(this);
    C.iSo -= B.iSo ;
    return C;
}

// Da Thuc o day
void DaThuc::Set_DDT()
{
    int x=0;
    for (int t=n-1;t>=0;t--)
    {
        cout<<"Nhap Co So cua So Mu "<<t<<" : "<<endl;
        cin>>x;
        A[t].Set_DT(x,t);
    }
}
void DaThuc::Get_DDT()
{ bool check = 0;
    for (int t=n-1;t>=0;t--)
    {
        if (A[t].iSo!=0)
            A[t].Get_DT();
        if (t>=1 && A[t-1].iSo>0)
        {
            cout<<" + ";
            check = 1;
        }
    }
    if (!check&&A[n-1].iSo==0) cout<<"0";
    cout<<endl;
}
DaThuc DaThuc::Cong(DaThuc B)
{
    int lineMax = B.n>n? B.n:n;
    int lineMin = B.n<=n? B.n:n;
    lineMax--;
    DaThuc C (lineMax);
    for (int t=lineMax;t>=0;t--)
    {
        if (B.n<=n&&t>=lineMin) C.A[t] = A[t];
        else if (t>=lineMin) C.A[t] = B.A[t];
        else if (t<lineMin)
        {
            C.A[t] = A[t].Sum(B.A[t]);
        }
    }
    return C;
}
DaThuc DaThuc::Tru(DaThuc B)
{
    int lineMax = B.n>n? B.n:n;
    int lineMin = B.n<=n? B.n:n;
    lineMax--;
    DaThuc C (lineMax);
    for (int t=lineMax;t>=0;t--)
    {
        if (B.n<=n&&t>=lineMin) C.A[t] = A[t];
        else if (t>=lineMin) C.A[t] = B.A[t];
        else if (t<lineMin)
        {
            C.A[t] = A[t].Sumrev(B.A[t]);
        }
    }
    return C;
}
double DaThuc::Tinh_X(int X)
{
    double S = 0;
    for (int t=n-1;t>=0;t--)
    {
        S += A[t].Solve_X(X);
    }
    return S;
}
