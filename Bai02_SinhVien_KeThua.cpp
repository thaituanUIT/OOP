#include <iostream>
#include <string>
using namespace std;

class SinhVien {
    private:
        string Id;
        string HoTen;
        string DiaChi;
        int TinChi;
        float DiemTB;
    public:
        SinhVien();
        SinhVien(string, string, string, int, float);
        string getId() {
            return Id;
        };
        string getHoTen() {
            return HoTen;
        };
        string getDiaChi() {
            return DiaChi;
        };
        int getTinChi() {
            return TinChi;
        };
        float getDiemTB() {
            return DiemTB;
        };
        void setId(string newId) {
            Id = newId;
        };
        void setHoTen(string newHoTen) {
            HoTen = newHoTen;
        };
        void setDiaChi(string newDiaChi) {
            DiaChi = newDiaChi;
        };
        void setTinChi(int newTinChi) {
            TinChi = newTinChi;
        };
        void setDiemTB(float newDiemTB) {
            DiemTB = newDiemTB;
        };
        virtual void NhapSV();
        virtual void XuatSV();
        friend class DaiHoc;
        friend class VB2;
        /*SinhVien TimDiemTBCaoNhat(VB2 vb2[], DaiHoc dh[]) {
            SinhVien sv1, sv2;
            VB2 vbmax = vb2[0];
            DaiHoc dhmax = dh[0];
            for (int i = 0; i < sizeof(VB2)/sizeof(VB2[0]); i++) {
                if (vb2[i].getDiemTB() > vbmax.getDiemTB()) {
                    sv1 = vbmax;
                }
            }
            for (int i = 0; i < sizeof(DaiHoc)/sizeof(DaiHoc[0]); i++) {
                if (dh[i].getDiemLV() > dhmax.getDiemTB()) {
                    sv2 = dhmax;
                }
            }
            if (sv1.getDiemTB() > sv2.getDiemTB()) {
                return sv1;
            } else {
                return sv2;
            }
        };*/
};

SinhVien::SinhVien() {
    Id = "";
    HoTen = "";
    DiaChi = "";
    TinChi = 0;
    DiemTB = 0;
}

SinhVien::SinhVien(string Id, string HoTen, string DiaChi, int TinChi, float DiemTB) {
    this->Id = Id;
    this->HoTen = HoTen;
    this->DiaChi = DiaChi;
    this->TinChi = TinChi;
    this->DiemTB = DiemTB;
}

void SinhVien::NhapSV() {
    cout << "Id: ";
    cin >> Id;
    cout << "Ho ten: ";
    cin >> HoTen;
    cout << "Dia chi: ";
    cin >> DiaChi;
    cout << "Tin chi: ";
    cin >> TinChi;
    cout << "Diem trung binh: ";
    cin >> DiemTB;
}

void SinhVien::XuatSV() {
    cout << "Id: " << Id << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Dia chi: " << DiaChi << endl;
    cout << "Tin chi: " << TinChi << endl;
    cout << "Diem trung binh: " << DiemTB << endl;
}

class VB2 : public SinhVien {
    private:
        float DiemThi;
    public:
        VB2() : SinhVien() {
            DiemThi = 0;
        };
        VB2(string, string, string, int, float, float);
        float getDiemThi() {
            return DiemThi;
        };
        void setDiemThi(float newDiemThi) {
            DiemThi = newDiemThi;
        };
        void NhapSV() override;
        void XuatSV() override;
        bool checkTotNghiepVB2();
        void XuatChuaTotNghiepVB2(VB2[]);
        void XuatDaTotNghiepVB2(VB2[]);
        VB2 TimDiemTBThapNhat(VB2[]);
};

VB2::VB2(string Id, string HoTen, string DiaChi, int TinChi, float DiemTB, float DiemThi) : 
SinhVien(Id, HoTen, DiaChi, TinChi, DiemTB) {
    this->DiemThi = DiemThi;
}

void VB2::NhapSV() {
    SinhVien::NhapSV();
    cout << "Diem thi: ";
    cin >> DiemThi;
}

void VB2::XuatSV() {
    SinhVien::XuatSV();
    cout << "Diem thi: " << DiemThi << endl;
    if(checkTotNghiepVB2()) {
        cout << "Tot nghiep" << endl;
    } else {
        cout << "Chua tot nghiep" << endl;
    }
}

bool VB2::checkTotNghiepVB2() {
    if (DiemTB >= 5 && DiemThi >= 5 && TinChi >= 84) {
        return true;
    }
    return false;
}

void VB2::XuatChuaTotNghiepVB2(VB2 vb2[]) {
    for (int i = 0; i < sizeof(vb2)/sizeof(vb2[0]); i++) {
        if (!vb2[i].checkTotNghiepVB2()) {
            cout << vb2[i].getHoTen() << endl;
        }
    }
}

void VB2::XuatDaTotNghiepVB2(VB2 vb2[]) {
    for (int i = 0; i < sizeof(vb2)/sizeof(vb2[0]); i++) {
        if (vb2[i].checkTotNghiepVB2()) {
            cout << vb2[i].getHoTen() << endl;
        }
    }
}

VB2 VB2::TimDiemTBThapNhat(VB2 vb2[]) {
    VB2 min = vb2[0];
    for (int i = 0; i < sizeof(vb2)/sizeof(vb2[0]); i++) {
        if (vb2[i].getDiemTB() < min.getDiemTB()) {
            min = vb2[i];
        }
    }
    return min;
}

class DaiHoc : public SinhVien {
    private:
        string LuanVan;
        float DiemLV;
    public:
        DaiHoc() : SinhVien() {
            LuanVan = "";
            DiemLV = 0;
        };
        DaiHoc(string, string, string, int, float, string, float);
        string getLuanVan() {
            return LuanVan;
        };
        float getDiemLV() {
            return DiemLV;
        };
        void setLuanVan(string newLuanVan) {
            LuanVan = newLuanVan;
        };
        void setDiemLV(float newDiemLV) {
            DiemLV = newDiemLV;
        };
        void NhapSV() override;
        void XuatSV() override;
        void XuatDaTotNghiep(DaiHoc[]);
        void XuatChuaTotNghiep(DaiHoc[]);
        bool checkTotNghiepDH();
        DaiHoc TimDiemTBCaoNhat(DaiHoc[]);
};

DaiHoc::DaiHoc(string Id, string HoTen, string DiaChi, int TinChi, float DiemTB, string LuanVan, float DiemLV) : 
SinhVien(Id, HoTen, DiaChi, TinChi, DiemTB) {
    this->LuanVan = LuanVan;
    this->DiemLV = DiemLV;
}

void DaiHoc::NhapSV() {
    SinhVien::NhapSV();
    cout << "Luan van: ";
    cin >> LuanVan;
    cout << "Diem luan van: ";
    cin >> DiemLV;
}

void DaiHoc::XuatSV() {
    SinhVien::XuatSV();
    cout << "Luan van: " << LuanVan << endl;
    cout << "Diem luan van: " << DiemLV << endl;
    if (checkTotNghiepDH()) {
        cout << "Tot nghiep" << endl;
    } else {
        cout << "Chua tot nghiep" << endl;
    }
}

bool DaiHoc::checkTotNghiepDH() {
    if (DiemTB >= 5 && DiemLV >= 5 && TinChi >= 120) {
        return true;
    }
    return false;
}

void DaiHoc::XuatChuaTotNghiep(DaiHoc dh[]) {
    for (int i = 0; i < 3; i++) {
        if (!dh[i].checkTotNghiepDH()) {
            cout << dh[i].getHoTen() << endl;
        }
    }
}

void DaiHoc::XuatDaTotNghiep(DaiHoc dh[]) {
    for (int i = 0; i < sizeof(dh)/sizeof(dh[0]); i++) {
        if (dh[i].checkTotNghiepDH()) {
            cout << dh[i].getHoTen() << endl;
        }
    }
}

DaiHoc DaiHoc::TimDiemTBCaoNhat(DaiHoc dh[]) {
    DaiHoc max = dh[0];
    for (int i = 0; i < sizeof(dh)/sizeof(dh[0]); i++) {
        if (dh[i].getDiemTB() > max.getDiemTB()) {
            max = dh[i];
        }
    }
    return max;
}

int main() {

    DaiHoc dh[1000];
    int n;
    cout << "So sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        dh[i].NhapSV();
    }
    cout << "Danh sach sinh vien da nhap: " << endl;
    for (int i = 0; i < n; i++) {
        dh[i].XuatSV();
    }
    cout << "Danh sach sinh vien chua tot nghiep: " << endl;
    dh[0].XuatChuaTotNghiep(dh);
    cout << "Danh sach sinh vien tot nghiep: " << endl;
    dh[0].XuatDaTotNghiep(dh);
    cout << "Sinh vien co diem trung binh cao nhat: " << endl;
    dh[0].TimDiemTBCaoNhat(dh).XuatSV();

    cout << endl;

    VB2 vb2[1000];
    int m;
    cout << "So sinh vien: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        vb2[i].NhapSV();
    }
    cout << "Danh sach sinh vien da nhap: " << endl;
    for (int i = 0; i < m; i++) {
        vb2[i].XuatSV();
    }
    cout << "Danh sach sinh vien chua tot nghiep: " << endl;
    vb2[0].XuatChuaTotNghiepVB2(vb2);
    cout << "Danh sach sinh vien tot nghiep: " << endl;
    vb2[0].XuatDaTotNghiepVB2(vb2);
    cout << "Sinh vien co diem trung binh cao nhat: " << endl;
    vb2[0].TimDiemTBThapNhat(vb2).XuatSV();
    
    return 0;
}