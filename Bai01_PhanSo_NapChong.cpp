#include <iostream>
using namespace std;

class PhanSo {
    private: 
        int tu, mau;
        void UocLuoc();
    public:
        //constructor
        PhanSo();
        PhanSo(long t, long m) {Set(t, m);};
        PhanSo(long t) {Set(t, 1);};
        void Set(long t, long m);
        int getTu();
        int getMau();

        //operator overloading
        friend istream& operator>>(istream& is, PhanSo& ps);
        friend ostream& operator<<(ostream& os, PhanSo ps);

        /*
        PhanSo operator+(PhanSo ps) const;
        PhanSo operator+(long b) const;
        friend PhanSo operator+(long b, PhanSo ps);

        PhanSo operator-(PhanSo ps) const;
        PhanSo operator-(long b) const;
        friend PhanSo operator-(long b, PhanSo ps);

        PhanSo operator*(PhanSo ps) const;
        PhanSo operator*(long b) const;
        friend PhanSo operator*(long b, PhanSo ps);

        PhanSo operator/(PhanSo ps) const;
        PhanSo operator/(long b) const;
        friend PhanSo operator/(long b, PhanSo ps);

        bool operator>(PhanSo ps);
        bool operator>(long b);
        friend bool operator>(long b, PhanSo ps);

        bool operator<(PhanSo ps);
        bool operator<(long b);
        friend bool operator<(long b, PhanSo ps);

        bool operator>=(PhanSo ps);
        bool operator>=(long b);
        friend bool operator>=(long b, PhanSo ps);

        bool operator<=(PhanSo ps);
        bool operator<=(long b);
        friend bool operator<=(long b, PhanSo ps);

        bool operator==(PhanSo ps);
        bool operator==(long b);
        friend bool operator==(long b, PhanSo ps);

        bool operator!=(PhanSo ps);
        bool operator!=(long b);
        friend bool operator!=(long b, PhanSo ps);
        */

        friend PhanSo operator+(PhanSo A, PhanSo B);
        friend PhanSo operator-(PhanSo A, PhanSo B);
        friend PhanSo operator*(PhanSo A, PhanSo B);
        friend PhanSo operator/(PhanSo A, PhanSo B);
        friend bool operator>(PhanSo A, PhanSo B);
        friend bool operator<(PhanSo A, PhanSo B);
        friend bool operator>=(PhanSo A, PhanSo B);
        friend bool operator<=(PhanSo A, PhanSo B);
        friend bool operator==(PhanSo A, PhanSo B);
        friend bool operator!=(PhanSo A, PhanSo B);

        //function
        long USCLN(long a, long b);

        PhanSo SaoChepHaiPhanSo(PhanSo A, PhanSo B);
        PhanSo TimPhanSoNhoNhat(PhanSo A[]);
        PhanSo TimPhanSoLonNhat(PhanSo A[]);

};

PhanSo::PhanSo() {
    tu = 0;
    mau = 1;
}

void PhanSo::UocLuoc() {
    long USC = USCLN(tu, mau);
    tu /= USC;
    mau /= USC;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    if (tu == 0)
        mau = 1;
}

void PhanSo::Set(long t, long m) {
    if (m) {
        tu = t;
        mau = m;
    UocLuoc();
    }
}

int PhanSo::getTu() {
    return tu;
}

int PhanSo::getMau() {
    return mau;
}

istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.tu;
    cout << "Nhap mau so: ";
    in >> ps.mau;
    return in;
}

ostream& operator<<(ostream& out, PhanSo ps) {
    out << ps.tu;
    if (ps.tu != 0 && ps.mau != 1)
        out << "/" << ps.mau;
    return out;
}

long PhanSo::USCLN(long a, long b) {
    long r;
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
        return 1;
    while ((r = a % b) != 0) {
        a = b;
        b = r;
    }
    return b;
}


/*
PhanSo PhanSo::operator+(PhanSo ps) const {
    return PhanSo(tu * ps.mau + ps.tu * mau, mau * ps.mau);
}

PhanSo PhanSo::operator-(PhanSo ps) const {
    return PhanSo(tu * ps.mau - ps.tu * mau, mau * ps.mau);
}

PhanSo PhanSo::operator*(PhanSo ps) const {
    return PhanSo(tu * ps.tu, mau * ps.mau);
}

PhanSo PhanSo::operator/(PhanSo ps) const {
    return PhanSo(tu * ps.mau, mau * ps.tu);
}

bool PhanSo::operator>(PhanSo ps) {
    return tu * ps.mau > ps.tu * mau;
}

bool PhanSo::operator<(PhanSo ps) {
    return tu * ps.mau < ps.tu * mau;
}

bool PhanSo::operator>=(PhanSo ps) {
    return tu * ps.mau >= ps.tu * mau;
}

bool PhanSo::operator<=(PhanSo ps) {
    return tu * ps.mau <= ps.tu * mau;
}

bool PhanSo::operator==(PhanSo ps) {
    return tu * ps.mau == ps.tu * mau;
}

bool PhanSo::operator!=(PhanSo ps) {
    return tu * ps.mau != ps.tu * mau;
}
*/

PhanSo operator+(PhanSo A, PhanSo B) {
    return PhanSo(A.tu * B.mau + B.tu * A.mau, A.mau * B.mau);
}

PhanSo operator-(PhanSo A, PhanSo B) {
    return PhanSo(A.tu * B.mau - B.tu * A.mau, A.mau * B.mau);
}

PhanSo operator*(PhanSo A, PhanSo B) {
    return PhanSo(A.tu * B.tu, A.mau * B.mau);
}

PhanSo operator/(PhanSo A, PhanSo B) {
    return PhanSo(A.tu * B.mau, A.mau * B.tu);
}

bool operator>(PhanSo A, PhanSo B) {
    return A.tu * B.mau > B.tu * A.mau;
}

bool operator<(PhanSo A, PhanSo B) {
    return A.tu * B.mau < B.tu * A.mau;
}

bool operator>=(PhanSo A, PhanSo B) {
    return A.tu * B.mau >= B.tu * A.mau;
}

bool operator<=(PhanSo A, PhanSo B) {
    return A.tu * B.mau <= B.tu * A.mau;
}

bool operator==(PhanSo A, PhanSo B) {
    return A.tu * B.mau == B.tu * A.mau;
}

bool operator!=(PhanSo A, PhanSo B) {
    return A.tu * B.mau != B.tu * A.mau;
}


PhanSo PhanSo::TimPhanSoNhoNhat(PhanSo A[]) {
    PhanSo min = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

PhanSo PhanSo::TimPhanSoLonNhat(PhanSo A[]) {
    PhanSo max = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int main() {
    PhanSo A, B;
    PhanSo C[100000];

    cin >> A >> B;

    cout << A << " + " << B << " = " << A + B << endl;
    cout << A << " - " << B << " = " << A - B << endl;
    cout << A << " * " << B << " = " << A * B << endl;
    cout << A << " / " << B << " = " << A / B << endl;
    
    std::cout << "Nhap so luong phan so:";
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    cout << C[0].TimPhanSoLonNhat(C);

    return 0;
}


