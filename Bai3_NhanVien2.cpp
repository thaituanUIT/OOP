#include <iostream>
using namespace std;

class NVVP {
    private: 
        int MaNV;
        string HoTen;
        float LuongCB;
        float LuongHT;
        int SoNgay; // Số ngày đi làm
    public:
        NVVP() {
            MaNV = 0;
            HoTen = "";
            LuongCB = 0;
            LuongHT = 0;
            SoNgay = 0;
        }
        NVVP(int MaNV, string HoTen, float LuongCB, int SoNgay) {
            this->MaNV = MaNV;
            this->HoTen = HoTen;
            this->LuongCB = LuongCB;
            this->SoNgay = SoNgay;
            this->LuongHT = LuongHT;
        }
        int getMaNV() {
            return MaNV;
        }
        string getHoTen() {
            return HoTen;
        }
        float getLuongCB() {
            return LuongCB;
        }
        float getLuongHT() {
            return LuongHT;
        }
        int getSoNgay() {
            return SoNgay;
        }
        void setMaNV(int MaNV) {
            this->MaNV = MaNV;
        }
        void setHoTen(string HoTen) {
            this->HoTen = HoTen;
        }
        void setLuongCB(float LuongCB) {
            this->LuongCB = LuongCB;
        }
        void setSoNgay(int SoNgay) {
            this->SoNgay = SoNgay;
            LuongHT = LuongCB + SoNgay * 250000;
        }

        void NhapVP() {
            cout << "Nhap ma nhan vien: ";
            cin >> MaNV;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout << "Nhap luong co ban: ";
            cin >> LuongCB;
            cout << "Nhap so ngay lam viec: ";
            cin >> SoNgay;
            LuongHT = LuongCB + SoNgay * 250000;
        }

        void XuatVP() {
            cout << "Ma nhan vien: " << MaNV << endl;
            cout << "Ho ten: " << HoTen << endl;
            cout << "Luong co ban: " << LuongCB << endl;
            cout << "So ngay lam viec: " << SoNgay << endl;
            cout << "Luong hang thang: " << LuongHT << endl;
            if (SoNgay < 15) {
                cout << "Luong hang thang: " << LuongCB + SoNgay * 250000 + 0.2 * LuongCB * 250000;
            }
        }
};

class NVSX {
    private:
        int MaNV;
        string HoTen;
        float LuongCB;
        float LuongHT;
        int SoSP; // Số sản phẩm
    public:
        NVSX() {
            MaNV = 0;
            HoTen = "";
            LuongCB = 0;
            LuongHT = 0;
            SoSP = 0;
        }
        NVSX(int MaNV, string HoTen, float LuongCB, int SoSP) {
            this->MaNV = MaNV;
            this->HoTen = HoTen;
            this->LuongCB = LuongCB;
            this->SoSP = SoSP;
            this->LuongHT = LuongHT;
        }
        int getMaNV() {
            return MaNV;
        }
        string getHoTen() {
            return HoTen;
        }
        float getLuongCB() {
            return LuongCB;
        }
        float getLuongHT() {
            return LuongHT;
        }
        int getSoSP() {
            return SoSP;
        }
        void setMaNV(int MaNV) {
            this->MaNV = MaNV;
        }
        void setHoTen(string HoTen) {
            this->HoTen = HoTen;
        }
        void setLuongCB(float LuongCB) {
            this->LuongCB = LuongCB;
        }
        void setSoSP(int SoSP) {
            this->SoSP = SoSP;
            LuongHT = LuongCB + SoSP * 175000;
        }

        void NhapSX() {
            cout << "Nhap ma nhan vien: ";
            cin >> MaNV;
            cout << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout << "Nhap luong co ban: ";
            cin >> LuongCB;
            cout << "Nhap so san pham: ";
            cin >> SoSP;
            LuongHT = LuongCB + SoSP * 175000;
        }

        void XuatSX() {
            cout << "Ma nhan vien: " << MaNV << endl;
            cout << "Ho ten: " << HoTen << endl;
            cout << "Luong co ban: " << LuongCB << endl;
            cout << "So san pham: " << SoSP << endl;
            cout << "Luong hang thang: " << LuongHT << endl;
            if (LuongHT > 10000000) {
                cout << "Luong hang thang: " << LuongHT + 0.1 * LuongHT;
            }
            if (SoSP < 10) {
                cout << "Luong hang thang: " << LuongCB + SoSP * 175000 + 0.3 * LuongCB * 175000;
            }
        }
};

class CongTy {
    private:
        NVVP *DSNVVP;
        NVSX *DSNVSX;
        int SoNVVP;
        int SoNVSX;
    public:
        void NhapNV() {
            cout << "Nhap so nhan vien van phong: ";
            cin >> SoNVVP;
            DSNVVP = new NVVP[SoNVVP];
            for (int i = 0; i < SoNVVP; i++) {
                DSNVVP[i].NhapVP();
            }
            cout << "Nhap so nhan vien san xuat: ";
            cin >> SoNVSX;
            DSNVSX = new NVSX[SoNVSX];
            for (int i = 0; i < SoNVSX; i++) {
                DSNVSX[i].NhapSX();
            }
        }

        void XuatNV() {
            cout << "Danh sach nhan vien van phong: " << endl;
            for (int i = 0; i < SoNVVP; i++) {
                DSNVVP[i].XuatVP();
            }

            cout << endl;

            cout << "Danh sach nhan vien san xuat: " << endl;
            for (int i = 0; i < SoNVSX; i++) {
                DSNVSX[i].XuatSX();
            }
        }

        void TimNVCoLuongCaoNhat() {
            NVVP max_VP = DSNVVP[0];
            for (int i = 1; i < SoNVVP; i++) {
                if (DSNVSX[i].getLuongHT() > max_VP.getLuongHT()) {
                    max_VP = DSNVVP[i];
                }
            }
    
            NVSX max_SX = DSNVSX[0];
            for (int i = 1; i < SoNVVP; i++) {
                if (DSNVSX[i].getLuongHT() > max_SX.getLuongHT()) {
                    max_SX = DSNVSX[i];
                }
            }

            if (max_VP.getLuongHT() > max_SX.getLuongHT()) {
                cout << "ID: " << max_VP.getMaNV() << endl;
                cout << "HoTen: " << max_VP.getHoTen() << endl;
                cout << "Luong hang thang: " << max_VP.getLuongHT() << endl;
                if (max_VP.getSoNgay() < 15) {
                    cout << "Luong hang thang: " << max_VP.getLuongCB() + max_VP.getSoNgay() * 250000 + 0.2 * max_VP.getLuongCB() * 250000;
                }       
            }
            else 
            {
                cout << "Ma nhan vien: " << max_SX.getMaNV() << endl;
                cout << "Ho ten: " << max_SX.getHoTen() << endl;
                cout << "Luong hang thang: " << max_SX.getLuongHT() << endl;
                if (max_SX.getLuongHT() > 10000000) {
                    cout << "Luong hang thang: " << max_SX.getLuongHT() + 0.1 * max_SX.getLuongHT();
                }
                if (max_SX.getSoSP() < 10) {
                    cout << "Luong hang thang: " << max_SX.getLuongCB() + max_SX.getSoSP() * 175000 + 0.3 * max_SX.getLuongCB() * 175000;
                }
            }
        }

        void TimNVItSPNhat() {
            NVSX min = DSNVSX[0];
            for (int i = 1; i < SoNVSX; i++) {
                if (DSNVSX[i].getSoSP() < min.getSoSP()) {
                    min = DSNVSX[i];
                }
            }
            cout << "ID: " << min.getMaNV() << endl;
            cout << "HoTen: " << min.getHoTen() << endl;
            cout << "San pham: " << min.getSoSP() << endl;
        }

        void NhanVienLuongCaoNhatVP() {
            NVVP max_VP[10];
            for (int i = 0; i < 10; i++) {
                max_VP[i] = DSNVVP[i];
            }
            for (int i = 10; i < SoNVVP; i++) {
                for (int j = 0; j < 10; j++) {
                    if (DSNVVP[i].getLuongHT() > max_VP[j].getLuongHT()) {
                        max_VP[j] = DSNVVP[i];
                        break;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                cout << "ID: " << max_VP[i].getMaNV() << endl;
                cout << "HoTen: " << max_VP[i].getHoTen() << endl;
                cout << "Luong hang thang: " << max_VP[i].getLuongHT() << endl;
                if (max_VP[i].getSoNgay() < 15) {
                    cout << "Luong hang thang: " << max_VP[i].getLuongCB() + max_VP[i].getSoNgay() * 250000 + 0.2 * max_VP[i].getLuongCB() * 250000;
                }
            }
        }

        void NhanVienLuongCaoNhatSX() {
            NVSX max_SX[10];
            for (int i = 0; i < 10; i++) {
                max_SX[i] = DSNVSX[i];
            }
            for (int i = 10; i < SoNVSX; i++) {
                for (int j = 0; j < 10; j++) {
                    if (DSNVSX[i].getLuongHT() > max_SX[j].getLuongHT()) {
                        max_SX[j] = DSNVSX[i];
                        break;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                cout << "ID: " << max_SX[i].getMaNV() << endl;
                cout << "HoTen: " << max_SX[i].getHoTen() << endl;
                cout << "Luong hang thang: " << max_SX[i].getLuongHT() << endl;
                if (max_SX[i].getLuongHT() > 10000000) {
                    cout << "Luong hang thang: " << max_SX[i].getLuongHT() + 0.1 * max_SX[i].getLuongHT();
                }
                if (max_SX[i].getSoSP() < 10) {
                    cout << "Luong hang thang: " << max_SX[i].getLuongCB() + max_SX[i].getSoSP() * 175000 + 0.3 * max_SX[i].getLuongCB() * 175000;
                }
            }
        }

};

int main() {
    CongTy CT;
    NVSX NV;
    int n;
    CT.NhapNV();
    CT.XuatNV();
    CT.TimNVCoLuongCaoNhat();
    CT.TimNVItSPNhat();
    CT.NhanVienLuongCaoNhatVP();
    CT.NhanVienLuongCaoNhatSX();
    return 0;
}

