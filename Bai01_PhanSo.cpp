#include <iostream>
using namespace std;

class PhanSo
{
    private:
        int TuSo;
        int MauSo;
        static int STT;
    public:
        PhanSo();
        PhanSo(int, int);
        PhanSo(int);
        void NhapPhanSo(PhanSo&);
        void XuatPhanSo(PhanSo);
        void RutGonPhanSo(PhanSo&);
        int SoSanh(PhanSo, PhanSo);
        PhanSo CongHaiPhanSo(PhanSo, PhanSo);
        PhanSo TruHaiPhanSo(PhanSo, PhanSo);
        PhanSo NhanHaiPhanSo(PhanSo, PhanSo);
        PhanSo ChiaHaiPhanSo(PhanSo, PhanSo);
        PhanSo SaoChepPhanSo(PhanSo);
        PhanSo TimPhanSoLonNhat(PhanSo[], int);
        int GetSTT()
        {
            return STT;
        }
};

int PhanSo::STT = 0;

//1. Xay dung constructor
PhanSo::PhanSo()
{
    TuSo = 0;
    MauSo = 1;
}

PhanSo::PhanSo(int TuSo)
{
    this->TuSo = TuSo;
    this->MauSo = 1;
}

PhanSo::PhanSo(int TuSo, int MauSo)
{
    this->TuSo = TuSo;
    this->MauSo = MauSo;
}

//2. Nhap va xuat phan so
void PhanSo::NhapPhanSo(PhanSo &ps)
{
    ++STT;
    cout << "Phan so thu " << string(3-to_string(STT).length(), '0') + to_string(STT) << ": " << endl;
    cout << "Nhap tu so: ";
    cin >> ps.TuSo;
    cout << "Nhap mau so: ";
    cin >> ps.MauSo;
    if (ps.MauSo == 0)
    {
        cout << "Mau so phai khac 0. Nhap lai: ";
        cin >> ps.MauSo;
    }
    RutGonPhanSo(ps);
}

void PhanSo::XuatPhanSo(PhanSo ps)
{
    cout << ps.TuSo << "/" << ps.MauSo;
    if (ps.MauSo == 1)
    {
        cout << " = " << ps.TuSo;
    }
}

//3. Rut gon phan so
int UCLN(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return UCLN(b, a % b);
}

void PhanSo::RutGonPhanSo(PhanSo &ps)
{
    int ucln = UCLN(ps.TuSo, ps.MauSo);
    ps.TuSo /= ucln;
    ps.MauSo /= ucln;
}

//4. So sanh hai phan so
int PhanSo::SoSanh(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps3;
    ps3.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
    ps3.MauSo = ps1.MauSo * ps2.MauSo;
    while (ps3.MauSo != 0)
    {
        if (ps3.TuSo == 0)
        {
            return 0; //ps1 = ps2
        }
        else if (ps3.TuSo > 0)
        {
            return 1; //ps1 > ps2
        }
        else
        {
            return -1; //ps1 < ps2
        }
    }
}

//5. Cong hai phan so
PhanSo PhanSo::CongHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps3;
    ps3.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
    ps3.MauSo = ps1.MauSo * ps2.MauSo;
    RutGonPhanSo(ps3);
    if (ps3.MauSo < 0)
    {
        ps3.TuSo *= -1;
        ps3.MauSo *= -1;
    }
    return ps3;
}

//6. Tru hai phan so
PhanSo PhanSo::TruHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps3;
    ps3.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
    ps3.MauSo = ps1.MauSo * ps2.MauSo;
    RutGonPhanSo(ps3);
    if (ps3.MauSo < 0)
    {
        ps3.TuSo *= -1;
        ps3.MauSo *= -1;
    }
    return ps3;
}

//7. Nhan hai phan so
PhanSo PhanSo::NhanHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps3;
    ps3.TuSo = ps1.TuSo * ps2.TuSo;
    ps3.MauSo = ps1.MauSo * ps2.MauSo;
    RutGonPhanSo(ps3);
    return ps3;
}

//8. Chia hai phan so
PhanSo PhanSo::ChiaHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    PhanSo ps3;
    ps3.TuSo = ps1.TuSo * ps2.MauSo;
    ps3.MauSo = ps1.MauSo * ps2.TuSo;
    RutGonPhanSo(ps3);
    return ps3;
}

//9. Sao chep phan so
PhanSo PhanSo::SaoChepPhanSo(PhanSo ps)
{
    PhanSo ps1;
    ps1.TuSo = ps.TuSo;
    ps1.MauSo = ps.MauSo;
    return ps1;
}

//10. Tim phan so lon nhat
PhanSo PhanSo::TimPhanSoLonNhat(PhanSo ps[], int n)
{
    PhanSo max = ps[0];
    for (int i = 1; i < n; i++)
    {
        if (SoSanh(max, ps[i]) == -1)
        {
            max = ps[i];
        }
    }
    return max;
}

int main()
{
    PhanSo ps[200];
    PhanSo ps1, ps2;
    int n, option, subOption;

    cout << "Chon option: " << endl;
    cout << "1. Nhap hai phan so" << endl;
    cout << "2. Nhap nhieu phan so" << endl;
    cin >> option;
    
    if (option == 1)
    {
        ps1.NhapPhanSo(ps1);
        ps2.NhapPhanSo(ps2);

        cout << endl;
        cout << "Chon subOption: " << endl;
        cout << "1. Xuat hai phan so" << endl;
        cout << "2. Cong hai phan so" << endl;
        cout << "3. Tru hai phan so" << endl;
        cout << "4. Nhan hai phan so" << endl;
        cout << "5. Chia hai phan so" << endl;
        cout << "6. So sanh hai phan so" << endl;
        cout << "Nhap subOption: ";
        cin >> subOption;

        if (subOption == 1)
        {
            ps1.XuatPhanSo(ps1);
            ps2.XuatPhanSo(ps2);
        }

        if (subOption == 2)
        {
            PhanSo ps3 = ps1.CongHaiPhanSo(ps1, ps2);
            cout << "Tong hai phan so: ";
            ps3.XuatPhanSo(ps3);
        }

        if (subOption == 3)
        {
            PhanSo ps3 = ps1.TruHaiPhanSo(ps1, ps2);
            cout << "Hieu hai phan so: ";
            ps3.XuatPhanSo(ps3);
        }

        if (subOption == 4)
        {
            PhanSo ps3 = ps1.NhanHaiPhanSo(ps1, ps2);
            cout << "Tich hai phan so: ";
            ps3.XuatPhanSo(ps3);
        }

        if (subOption == 5)
        {
            PhanSo ps3 = ps1.ChiaHaiPhanSo(ps1, ps2);
            cout << "Thuong hai phan so: ";
            ps3.XuatPhanSo(ps3);
        }

        if (subOption == 6)
        {
            if (ps1.SoSanh(ps1, ps2) == 0)
            {
                cout << "Hai phan so bang nhau" << endl;
            }
            else if (ps1.SoSanh(ps1, ps2) == 1)
            {
                cout << "Phan so 1 lon hon phan so 2" << endl;
            }
            else
            {
                cout << "Phan so 1 nho hon phan so 2" << endl;
            }
        }
    }

    else if (option == 2)
    {
        cout << "Nhap so luong phan so: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap phan so thu " << i + 1 << ": " << endl;
            ps[i].NhapPhanSo(ps[i]);
        }

        cout << endl;
        cout << "Chon subOption: " << endl;
        cout << "1. Xuat tat ca phan so" << endl;
        cout << "2. Tim phan so lon nhat" << endl;
        cout << "3. Sao chep phan so" << endl;
        cout << "Nhap subOption: ";
        cin >> subOption;
        
        if (subOption == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Phan so thu " << i + 1 << ": ";
                ps[i].XuatPhanSo(ps[i]);
                cout << endl;
            }
        }

        if (subOption == 2)
        {
            PhanSo max = ps[0].TimPhanSoLonNhat(ps, n);
            cout << "Phan so lon nhat la: ";
            max.XuatPhanSo(max);
        }

        if (subOption == 3)
        {
            int i;
            cout << "Nhap vi tri phan so can sao chep: ";
            cin >> i;
            PhanSo ps3 = ps[i].SaoChepPhanSo(ps[i]);
            cout << "Phan so sau khi sao chep: ";
            ps3.XuatPhanSo(ps3);
        }
    }

    return 0;
}