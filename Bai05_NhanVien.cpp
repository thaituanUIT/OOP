#include <iostream>
using namespace std;

class NhanVien {
    private:
        int id;
        string HoTen;
        double LuongCB;
        int SP;
        double LuongHT;
    public:
        NhanVien() {
            id = 0;
            HoTen = "";
            LuongCB = 0;
            SP = 0;
            LuongHT = 0;
        }
        NhanVien(int id, string HoTen, float LuongCB, int SP) {
            this->id = id;
            this->HoTen = HoTen;
            this->LuongCB = LuongCB;
            this->SP = SP;
            this->LuongHT = LuongCB + SP * 175000;
        }

        int getId() {
            return id;
        }

        string getHoTen() {
            return HoTen;
        }

        float getLuongCB() {
            return LuongCB;
        }

        int getSP() {
            return SP;
        }

        float getLuongHT() {
            return LuongHT;
        }

        void setId(int newId) {
            id = newId;
        }

        void setHoTen(string newHoTen) {
            HoTen = newHoTen;
        }

        void setLuongCB(float newLuongCB) {
            LuongCB = newLuongCB;
        }

        void setSP(int newSP) {
            SP = newSP;
            LuongHT = LuongCB + SP * 175000;
        }

        //nhap thong tin NhanVien
        void NhapThongTin() {
            cout << endl;
            cout << "Nhap ID: ";
            cin >> id;
            cout << "Nhap HoTen: ";
            cin >> HoTen;
            cout << "Nhap Luong co ban: ";
            cin >> LuongCB;
            cout << "Nhap SP: ";
            cin >> SP;
            cout << endl;
            LuongHT = LuongCB + SP * 175000;
        }

        //xuat thong tin NhanVien
        void XuatThongTin() {
            cout << "ID: " << id << endl;
            cout << "HoTen: " << HoTen << endl;
            cout << "Luong co ban: " << LuongCB << endl;
            cout << "SP: " << SP << endl;
            cout << "Luong hang thang: " << LuongHT << endl;
            if (LuongHT > 10000000) {
                cout << "Luong hang thang: " << LuongHT + LuongHT * 0.1 << endl;
            }
        }

        //tim NhanVien theo id
        void TimNV(int id) {
            if (this->id == id) {
                cout << "ID: " << id << endl;
                cout << "HoTen: " << HoTen << endl;
                cout << "Luong co ban: " << LuongCB << endl;
                cout << "SP: " << SP << endl;
                cout << "Luong hang thang: " << LuongHT << endl;
                if (LuongHT > 10000000) {
                    cout << "Luong hang thang: " << LuongHT + LuongHT * 0.1 << endl;
                }
            }
        }

        //tim NhanVien co luong cao nhat
        void TimNVCoLuongCaoNhat(NhanVien NV[], int& size) {
             NhanVien max = NV[0];
            for (int i = 1; i < size; i++) {
                if (NV[i].getLuongHT() > max.getLuongHT()) {
                    max = NV[i];
                }
            }
            cout << "ID: " << max.getId() << endl;
            cout << "HoTen: " << max.getHoTen() << endl;
            cout << "Luong hang thang: " << max.getLuongHT() << endl;
            if (max.getLuongHT() > 10000000) {
                cout << "Luong hang thang: " << max.getLuongHT() + max.getLuongHT() * 0.1 << endl;
            }
        }

        //tim NhanVien co it SP nhat
        void TimNVItSPNhat(NhanVien NV[], int& size) {
             NhanVien min = NV[0];
            for (int i = 1; i < size; i++) {
                if (NV[i].getSP() < min.getSP()) {
                    min = NV[i];
                }
            }
            cout << "ID: " << min.getId() << endl;
            cout << "HoTen: " << min.getHoTen() << endl;
            cout << "San pham: " << min.getSP() << endl;
        }

        //tim 10 NV co luong cao nhat
        void Tim10NVcoLuongCaoNhat(NhanVien NV[], int& size) {
             NhanVien max[10];
            for (int i = 0; i < 10; i++) {
                max[i] = NV[i];
            }
            for (int i = 10; i < size; i++) {
                for (int j = 0; j < 10; j++) {
                    if (NV[i].getLuongHT() > max[j].getLuongHT()) {
                        max[j] = NV[i];
                        break;
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                cout << "ID: " << max[i].getId() << endl;
                cout << "HoTen: " << max[i].getHoTen() << endl;
                cout << "Luong hang thang: " << max[i].getLuongHT() << endl;
                if (max[i].getLuongHT() > 10000000) {
                    cout << "Luong hang thang: " << max[i].getLuongHT() + max[i].getLuongHT() * 0.1 << endl;
                }
            }
        }
        
        //cap nhat luong NhanVien
        void CapNhatLuongNhanVien(NhanVien NV[], int size, int id, int SP) {
            for (int i = 0; i < size; i++) {
                if (NV[i].getId() == id) {
                    NV[i].setSP(SP);
                    break;
                }
            }
        }
};

int main()
{
    NhanVien NV[200];
    int n, option;

    cout << "Nhap so luong NV: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        NV[i].NhapThongTin();
    }

    cout << endl;
    cout << "1. Xuat tat ca NV" << endl;
    cout << "2. Tim NV theo ID" << endl;
    cout << "3. Tim NV co luong cao nhat" << endl;
    cout << "4. Tim NV co it san pham nhat" << endl;
    cout << "5. Tim 10 NV co luong cao nhat" << endl;
    cout << "6. Cap nhat luong nhan vien theo ID" << endl;
    cout << "Nhap option: ";
    cin >> option;

    if (option == 1)
    {
        for (int i = 0; i < n; i++)
        {
            NV[i].XuatThongTin();
            cout << endl;
        }
    }
    else if (option == 2)
    {
        int id;
        cout << " Nhap ID de tim: ";
        cin >> id;
        for (int i = 0; i < n; i++)
        {
            NV[i].TimNV(id);
        }   
    }
    else if (option == 3)
    {
        NV[0].TimNVCoLuongCaoNhat(NV, n);
    }
    else if (option == 4)
    {
        NV[0].TimNVItSPNhat(NV, n);
    }
    else if (option == 5)
    {
        NV[0].Tim10NVcoLuongCaoNhat(NV, n);
    }
    else if (option == 6)
    {
        int identity, SP;
        cout << " Nhap ID de cap nhat luong: ";
        cin >> identity;
        cout << " Nhap so SP: ";
        cin >> SP;
        NV[0].CapNhatLuongNhanVien(NV, n, identity, SP);
    }
    for (int i = 0; i < n; i++)
    {
        NV[i].XuatThongTin();
        cout << endl;
    }

    return 0;
}
