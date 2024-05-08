#include "honso.h"

int main() {
    PhanSo A(8, 3), B(10, 9);
    HonSo C(4, 5, 6), D(7, 8, 9);
    HonSo E = E.convert(A);
    PhanSo F = D.rev_convert();
    HonSo G = C + D;
    HonSo H = C - D;
    HonSo I = C * D;
    HonSo J = C / D;
    cout << E << " " << F << " " << G << " " << H << " " << I << " " << J;
    return 0;
}