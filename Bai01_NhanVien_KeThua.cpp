#include <bits/stdc++.h>
using namespace std;

class CongTy {
    private:
        string id;
        string HoTen;
        float LuongCB;
        float LuongHT;
    public:
        CongTy();
        CongTy(string, string, float, float);
        string getId();
        string getHoTen();
        float getLuongCB();
        float getLuongHT();
        void setId(string);
        void setHoTen(string);
        void setLuongCB(float);
        friend class VanPhong;
        friend class SanXuat;
        void Nhap();
        void Xuat();
        void NhanVienLuongCaoNhat();
        void TimMaNhanVien();
        void CapNhatLuongCB();
};

string CongTy::getId() {
    return id;
}

string CongTy::getHoTen() {
    return HoTen;
}

float CongTy::getLuongCB() {
    return LuongCB;
}

float CongTy::getLuongHT() {
    return LuongHT;
}

void CongTy::setId(string id) {
    this->id = id;
}

void CongTy::setHoTen(string HoTen) {
    this->HoTen = HoTen;
}

void CongTy::setLuongCB(float LuongCB) {
    this->LuongCB = LuongCB;
}

CongTy::CongTy() {
    id = "";
    HoTen = "";
    LuongCB = 0;
    LuongHT = 0;
}

CongTy::CongTy(string id, string HoTen, float LuongCB, float LuongHT) {
    this->id = id;
    this->HoTen = HoTen;
    this->LuongCB = LuongCB;
    this->LuongHT = LuongHT;
}

void CongTy::Nhap() {
    cin >> id;
    cin >> HoTen;
    cin >> LuongCB;
}

void CongTy::Xuat() {
    cout << id;
    cout << HoTen;
    cout << LuongHT;
}

void CongTy::NhanVienLuongCaoNhat() {
    VanPhong VP;
    SanXuat SX;
    VP.TimNhanVienVPLuongCaoNhat();
    SX.TimNhanVienSXLuongCaoNhat();
    if (VP.getLuongHT() > SX.getLuongHT()) {
        VP.XuatNVVP();
    }
    else {
        SX.XuatNVSX();
    }
}

void CongTy::TimMaNhanVien() {
    vector<CongTy> NV;
    cin >> id;
    for (int i = 0; i < NV.size(); i++)
    {
        if (NV[i].getId() == id) {
            NV[i].Xuat();
        }
    }
}

void CongTy::CapNhatLuongCB() {
    vector<CongTy> NV;
    float newLuongCB;
    cin >> id;
    for (int i = 0; i < NV.size(); i++)
    {
        if (NV[i].getId() == id) {
            cin >> newLuongCB;
            NV[i].setLuongCB(newLuongCB);
        }
    }
}

class VanPhong : public CongTy {
    private:
        int SoNgay;
    public:
        VanPhong() {SoNgay = 0;};
        VanPhong(string, string, float, float, int);
        void NhapNVVP();
        void XuatNVVP();
        void TimNhanVienVPLuongCaoNhat();
};

VanPhong::VanPhong(string Id, string HoTen, float LuongCB, float LuongHT, int SoNgay) : CongTy(id, HoTen, LuongCB, LuongHT) {
    this->SoNgay = SoNgay;
}

void VanPhong::NhapNVVP() {
    Nhap();
    cin >> SoNgay;
    LuongHT = LuongCB + SoNgay * 250000;
    if (SoNgay < 15) {
        LuongHT = LuongCB + SoNgay * 250000 + SoNgay * 250000 * 0.2;
    }
}

void VanPhong::XuatNVVP() {
    Xuat();
}

void NhapVP() {
    vector<VanPhong> NVVP;
    int VP;
    cin >> VP;
    for (int i = 0; i < VP; i++) {
        NVVP[i].NhapNVVP();
        NVVP.push_back(NVVP[i]);
    }
}

void XuatVP() {
    vector<VanPhong> NVVP;
    for (int i = 0; i < NVVP.size(); i++)
    {
        NVVP[i].XuatNVVP();
    }
}

void VanPhong::TimNhanVienVPLuongCaoNhat() {
    vector<VanPhong> NVVP;
    for (int i = 0; i < NVVP.size(); i++)
    {
        if (NVVP[i].LuongHT > NVVP[i + 1].LuongHT)
        {
            NVVP[i].XuatNVVP();
        }
        else
        {
            NVVP[i + 1].XuatNVVP();
        }
    }
}

class SanXuat : public CongTy {
    private:
        int SoSp;
    public:
        SanXuat() {SoSp = 0;};
        SanXuat(string, string, float, float, int);
        void NhapNVSX();
        void XuatNVSX();
        void TimNhanVienSXLuongCaoNhat();
        void TimNhanVienItSpNhat();
};

SanXuat::SanXuat(string id, string HoTen, float LuongCB, float LuongHT, int SoSp) : CongTy(id, HoTen, LuongCB, LuongHT) {
    this->SoSp = SoSp;
}

void SanXuat::NhapNVSX() {
    Nhap();
    cin >> SoSp;
    LuongHT = LuongCB + SoSp * 175000;
    if (LuongHT > 10e6) {
        LuongHT += LuongHT * 0.1;
    }
    if (SoSp < 10) {
        LuongHT = LuongCB + SoSp * 175000 + SoSp * 175000 * 0.3;    
    }
}

void NhapSX() {
    vector<SanXuat> NVSX;
    int SX;
    cin >> SX;
    for (int i = 0; i < SX; i++) {
        NVSX[i].NhapNVSX();
        NVSX.push_back(NVSX[i]);
    }
}

void SanXuat::XuatNVSX() {
    Xuat();
}

void XuatSX() {
    vector<SanXuat> NVSX;
    for (int i = 0; i < NVSX.size(); i++) {
        NVSX[i].XuatNVSX();
    }
}

void SanXuat::TimNhanVienSXLuongCaoNhat() {
    vector<SanXuat> NVSX;
    for (int i = 0; i < NVSX.size(); i++)
    {
        if (NVSX[i].LuongHT > NVSX[i + 1].LuongHT)
        {
            NVSX[i].XuatNVSX();
        }
        else
        {
            NVSX[i + 1].XuatNVSX();
        }
    }
}

void SanXuat::TimNhanVienItSpNhat() {
    vector<SanXuat> NVSX;
    for (int i = 0; i < NVSX.size(); i++)
    {
        if (NVSX[i].SoSp < NVSX[i + 1].SoSp)
        {
            NVSX[i].XuatNVSX();
        }
        else
        {
            NVSX[i + 1].XuatNVSX();
        }
    }
}

int main() {
    CongTy CT;
    VanPhong VP;
    SanXuat SX;
    CT.TimMaNhanVien();
    CT.CapNhatLuongCB();
    CT.NhanVienLuongCaoNhat();
    SX.TimNhanVienItSpNhat();
    return 0;
}



