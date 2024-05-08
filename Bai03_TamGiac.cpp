#include <iostream>
#include <cmath>
using namespace std;

class TamGiac 
{
    private:
        double a, b, c;
    public:
        TamGiac();
        TamGiac(double a, double b, double c);
        double getA();
        double getB();
        double getC();
        void setA(double newA);
        void setB(double newB);
        void setC(double newC);
        void NhapTamGiac();
        void XuatTamGiac();
        double ChuVi();
        double DienTich();
        int KiemTraTamGiac(TamGiac);
};

// Constructors
TamGiac::TamGiac() {
    a = 0;
    b = 0;
    c = 0;
}

TamGiac::TamGiac(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

// Getters
double TamGiac::getA() {
    return a;
}

double TamGiac::getB() {
    return b;
}

double TamGiac::getC() {
    return c;
}

void TamGiac::setA(double newA) {
    a = newA;
}

void TamGiac::setB(double newB) {
    b = newB;
}

void TamGiac::setC(double newC) {
    c = newC;
}

//1. Nhap thong tin tam giac
void TamGiac::NhapTamGiac() {
    cout << "Nhap canh a: ";
    cin >> a;
    cout << "Nhap canh b: ";
    cin >> b;
    cout << "Nhap canh c: ";
    cin >> c;
}

void TamGiac::XuatTamGiac() {
    cout << "Canh a: " << a << endl;
    cout << "Canh b: " << b << endl;
    cout << "Canh c: " << c << endl;
}

//2. Tinh chu vi tam giac
double TamGiac::ChuVi() {
    return a + b + c;
}

//3. Tinh dien tich tam giac
double TamGiac::DienTich() {
    double p = ChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//4. Kiem tra tam giac
int TamGiac::KiemTraTamGiac(TamGiac tg) {
    if (tg.a + tg.b > tg.c && tg.a + tg.c > tg.b && tg.b + tg.c > tg.a) {
        if (tg.a == tg.b || tg.a == tg.c || tg.b == tg.c) 
        {
            if (tg.a == tg.b && tg.a == tg.c) {
                return 1; //tam giac deu
            } else {
                return 2; //tam giac can
            }
        } 
        else if (pow(tg.a, 2) + pow(tg.b, 2) == pow(tg.c, 2) || pow(tg.a, 2) + pow(tg.c, 2) == pow(tg.b, 2) || pow(tg.b, 2) + pow(tg.c, 2) == pow(tg.a, 2)) 
        {
            if (tg.a == tg.b || tg.a == tg.c || tg.b == tg.c) {
                return 3; //tam giac vuong can
            } else {
                return 4; //tam giac vuong
            }
        } 
        else if (pow(tg.a, 2) + pow(tg.b, 2) < pow(tg.c, 2) || pow(tg.a, 2) + pow(tg.c, 2) < pow(tg.b, 2) || pow(tg.b, 2) + pow(tg.c, 2) < pow(tg.a, 2))
        {
            return 5; //tam giac tu
        }
        return 6; //tam giac thuong
    }
    return 7; //khong phai tam giac
}

int main()
{
    TamGiac tg;
    cout << "Nhap thong tin tam giac (don vi cm): " << endl;
    tg.NhapTamGiac();
    cout << "Thong tin tam giac: " << endl;
    tg.XuatTamGiac();

    cout << "Loai tam giac: ";
    if (tg.KiemTraTamGiac(tg) == 1) 
    {
        cout << "Tam giac deu" << endl;
    } 
    else if (tg.KiemTraTamGiac(tg) == 2) 
    {
        cout << "Tam giac can" << endl;
    } else if (tg.KiemTraTamGiac(tg) == 3) 
    {
        cout << "Tam giac vuong can" << endl;
    } 
    else if (tg.KiemTraTamGiac(tg) == 4) 
    {
        cout << "Tam giac vuong" << endl;
    } 
    else if (tg.KiemTraTamGiac(tg) == 5) 
    {
        cout << "Tam giac tu" << endl;
    } 
    else if (tg.KiemTraTamGiac(tg) == 6) 
    {
        cout << "Tam giac thuong" << endl;
    } 
    else 
    {
        cout << "Khong phai tam giac" << endl;
    }

    cout << "Dien tich tam giac: " << tg.DienTich() << endl;
    cout << "Chu vi tam giac: " << tg.ChuVi() << endl;
    
    return 0;
}