#ifndef DATHUC_H
#define DATHUC_H

class DonThuc
{
    public:
        DonThuc(int a=0,int b=0) {iSo=a;iMu=b;};
        void Set_DT(int a,int b);
        void Get_DT();
        double Solve_X(int X);
        void Derivative();
        DonThuc Sum(DonThuc B);
        DonThuc Sumrev(DonThuc B);

    protected:

    private:
        friend class DaThuc;
        int iSo,iMu;
};
class DaThuc
{
    public:
        DaThuc(int size_N=0) {n = size_N+1; A = new DonThuc[n];};
        void Set_DDT();
        void Get_DDT();
        DaThuc Cong(DaThuc B);
        DaThuc Tru(DaThuc B);
        double Tinh_X(int X);
    private:
        int n;
        DonThuc *A;
};

#endif // DATHUC_H
