#include <iostream>
#include <iomanip>
using namespace std;

class NhanVien {
    protected:
        string id;
        string HoTen;
        double LuongCB;
        double LuongHT;
    public:
        virtual void Nhap() {
            cin.ignore();
            cin >> id;
            cin.ignore();
            cin >> HoTen;
            cin >> LuongCB;
        };
        virtual void Xuat() {
            cout << id;
            cout << HoTen;
            cout << LuongCB;
        };
        virtual double TinhLuong() = 0;
        virtual void setLuongCB(float LuongCB) = 0;
        virtual string getID() = 0;
};

class VanPhong : public NhanVien {
    private:
        int soNgay;
    public:
        
        void setLuongCB(float LuongCB) {
            this->LuongCB = LuongCB;
        }

        string getID() {
            return id;
        }

        double TinhLuong() {
            if (soNgay < 15) {
                LuongHT = LuongCB + soNgay * 250000 + soNgay * 250000 * 0.2;
            } else LuongHT = LuongCB + soNgay * 250000;
            return LuongHT;
        }

        void Nhap() {
            cout << "id: ";
            cin.ignore();
            cin >> id;
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout << "Luong co ban: ";
            cin >> LuongCB;
            cout << "So ngay lam viec: ";
            cin >> soNgay;
        }

        void Xuat() {
            cout << "Van Phong: " << id << " " << HoTen << " " << LuongCB << " " << soNgay << " " << setw(10) << TinhLuong();
        }
};


class SanXuat : public NhanVien {
    private:
        int soSP;
    public:
        void setLuongCB(float LuongCB) {
            this->LuongCB = LuongCB;
        }

        string getID() {
            return id;
        }

        double TinhLuong() {
            LuongHT = LuongCB + soSP * 175000;
            if (LuongHT > 10e6) {
                LuongHT += LuongHT * 0.1;
            }
            if (soSP < 10) {
                LuongHT = LuongCB + soSP * 175000 + soSP * 175000 * 0.3;    
            }
            return LuongHT;
        }

        void Nhap() {
            cout << "id: ";
            cin.ignore();
            cin >> id;
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout << "Luong co ban: ";
            cin >> LuongCB;
            cout << "So san pham: ";
            cin >> soSP;
        }

        void Xuat() {
            cout << "San Xuat: " << id << " " << HoTen << " " << LuongCB << " " << soSP << " " << setw(10) << TinhLuong();
        }
};

class CongTy {
    protected:
        int iN;
        NhanVien* nv[200];
    public:
        void Nhap() {
            cout << "Nhap so nhan vien: ";
            cin >> iN;
            int iLoai;
            for (int i = 0; i < iN; i++) {
                cout << "Loai nhan vien: ";
                cin >> iLoai;
                switch(iLoai) {
                    case 1:
                        nv[i] = new VanPhong;
                        break;
                    case 2:
                        nv[i] = new SanXuat;
                }
                nv[i]->Nhap();
            }
        }

        void Xuat() {
            for (int i = 0; i < iN; i++) {
                nv[i]->Xuat();
                cout << "\n";
            }
        }

        void LuongCaoNhat() {
            double max = nv[0]->TinhLuong();
            for (int i = 1; i < iN; i++) {
                if (nv[i]->TinhLuong() > max) {
                    max = nv[i]->TinhLuong();
                }
            }
            for (int i = 0; i < iN; i++) {
                if (nv[i]->TinhLuong() == max) {
                    nv[i]->Xuat();
                    cout << "\n";
                }
            }
        }

        void tenperson_LuongCaoNhat() {
            double max = nv[0]->TinhLuong();
            for (int i = 1; i < iN; i++) {
                if (nv[i]->TinhLuong() > max) {
                    max = nv[i]->TinhLuong();
                }
            }
            int count = 0;
            for (int i = 0; i < iN; i++) {
                if (nv[i]->TinhLuong() == max) {
                    do {
                        nv[i]->Xuat();
                        cout << "\n";
                        count++;
                    } while (count < 11);
                }
            }
        };

        void ThayDoiLuongtheoID() {
            string id;
            cout << "Nhap id: ";
            cin >> id;
            for (int i = 0; i < iN; i++) {
                if (nv[i]->getID() == id) {
                    float LuongCB;
                    cout << "Nhap luong moi: ";
                    cin >> LuongCB;
                    nv[i]->setLuongCB(LuongCB);
                    nv[i]->TinhLuong();
                    nv[i]->Xuat();
                }
            }
        }

        void TimTentheoID() {
            string id;
            cout << "Nhap id: ";
            cin >> id;
            for (int i = 0; i < iN; i++) {
                if (nv[i]->getID() == id) {
                    nv[i]->Xuat();
                }
            }
        }
};

int main() {
    CongTy ct;
    ct.Nhap();
    ct.Xuat();
    return 0;
}