#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class PhanSo {
    protected:
        int tu;
        int mau;
    public:
        PhanSo();
        PhanSo(long t, long m) {Set(t, m);};
        PhanSo(long t) {Set(t, 1);};
        void UocLuoc();
        void Set(long, long);
        long USCLN(long, long);
        int getTu();
        int getMau();
        friend istream& operator>>(istream& in, PhanSo& ps);
        friend ostream& operator<<(ostream& out, PhanSo ps);
        friend PhanSo operator+(PhanSo, PhanSo);
        friend PhanSo operator-(PhanSo, PhanSo);
        friend PhanSo operator*(PhanSo, PhanSo);
        friend PhanSo operator/(PhanSo, PhanSo);
        friend bool operator>(PhanSo, PhanSo);
        friend bool operator<(PhanSo, PhanSo);
        friend bool operator>=(PhanSo, PhanSo);
        friend bool operator<=(PhanSo, PhanSo);
        friend bool operator==(PhanSo, PhanSo);
        friend bool operator!=(PhanSo, PhanSo);
        friend class HonSo;
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
    return this->tu;
}

int PhanSo::getMau() {
    return this->mau;
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


class HonSo : public PhanSo {
    private:
        int he;
    public:
        HonSo();
        HonSo(long h, long t, long m) {Set(h, t, m);};
        void Set(long, long, long);
        int getHe() {return he;};
        friend istream& operator>>(istream& in, HonSo& hs);
        friend ostream& operator<<(ostream& out, HonSo hs);
        friend HonSo operator+(HonSo, HonSo);
        friend HonSo operator-(HonSo, HonSo);
        friend HonSo operator*(HonSo, HonSo);
        friend HonSo operator/(HonSo, HonSo);
        friend bool operator>(HonSo, HonSo);
        friend bool operator<(HonSo, HonSo);
        friend bool operator>=(HonSo, HonSo);
        friend bool operator<=(HonSo, HonSo);
        friend bool operator==(HonSo, HonSo);
        friend bool operator!=(HonSo, HonSo);
        PhanSo rev_convert();
        HonSo convert(PhanSo);
};

HonSo::HonSo() {}

void HonSo::Set(long h, long t, long m) {
    he = h;
    PhanSo::Set(t, m);
}

istream& operator>>(istream& in, HonSo& hs) {
    in >> (PhanSo&)hs;
    cout << "He so: ";
    in >> hs.he;
    return in;
}

ostream& operator<<(ostream& out, HonSo hs) {
    out << hs.he << "|" << (PhanSo&)hs;
    return out;
}

HonSo operator+(HonSo A, HonSo B) {
    return HonSo(A.he + B.he, A.tu * B.mau + B.tu * A.mau, A.mau * B.mau);
}

HonSo operator-(HonSo A, HonSo B) {
    return HonSo(A.he - B.he, A.tu * B.mau - B.tu * A.mau, A.mau * B.mau);
}

HonSo operator*(HonSo A, HonSo B) {
    PhanSo A1, B1;
    A1 = A.rev_convert();
    B1 = B.rev_convert();
    PhanSo C = A1 * B1;
    HonSo C1 = C1.convert(C);
    return C1;
}

bool operator>(HonSo A, HonSo B) {
    if (A.he > B.he) {
        return true;
    } else {
        if (PhanSo(A.tu, A.mau) > PhanSo(B.tu, B.mau)) {
            return true;
        }
    }
    return false;
}

bool operator<(HonSo A, HonSo B) {
    if (A.he < B.he) {
        return true;
    } else {
        if (PhanSo(A.tu, A.mau) < PhanSo(B.tu, B.mau)) {
            return true;
        }
    }
    return false;
}

bool operator>=(HonSo A, HonSo B) {
    if (A.he >= B.he) {
        return true;
    } else {
        if (PhanSo(A.tu, A.mau) >= PhanSo(B.tu, B.mau)) {
            return true;
        }
    }
    return false;
}

bool operator<=(HonSo A, HonSo B) {
    if (A.he <= B.he) {
        return true;
    } else {
        if (PhanSo(A.tu, A.mau) <= PhanSo(B.tu, B.mau)) {
            return true;
        }
    }
    return false;
}

bool operator==(HonSo A, HonSo B) {
    return (A.he == B.he && PhanSo(A.tu, A.mau) == PhanSo(B.tu, B.mau));
}

bool operator!=(HonSo A, HonSo B) {
    return (A.he != B.he || PhanSo(A.tu, A.mau) != PhanSo(B.tu, B.mau));
}

HonSo operator/(HonSo A, HonSo B) {
    PhanSo A1, B1;
    A1 = A.rev_convert();
    B1 = B.rev_convert();
    PhanSo C = A1 / B1;
    HonSo C1 = C1.convert(C);
    return C1;
}

PhanSo HonSo::rev_convert() {
    PhanSo ps;
    if (he < 0)
        ps.Set(-(abs(he) * mau + tu), mau);
    else {
        ps.Set(he * mau + tu, mau);
    }
    return ps;
}

HonSo HonSo::convert(PhanSo ps) {
    HonSo hs;
    if (ps.tu < 0) {
        hs.Set(-(abs(ps.tu) / ps.mau), (abs(ps.tu) % ps.mau), ps.mau);
    } else {
        hs.Set(ps.tu / ps.mau, ps.tu % ps.mau, ps.mau);
    }
    return hs;
}