#include <iostream>
#include <cmath>
using namespace std;

class ToaDo {
    private:
        int x;
        int y;
    public:
        ToaDo();
        ToaDo(int, int);
        void NhapToaDo(ToaDo&);
        void XuatToaDo(ToaDo);
        void TinhTien(ToaDo&, int, int);
        int getx()
        {
            return x;
        }
        int gety()
        {
            return y;
        }
        int ThayDoiX(int);
        int ThayDoiY(int);
        float KhoangCach(ToaDo, ToaDo);
        ToaDo TrungDiem(ToaDo, ToaDo);
        ToaDo SaoChep(ToaDo);
        ToaDo TimKhoangCachGanTamNhat(ToaDo[], int);
        void XoaToaDo(ToaDo td[], int n)
        {
            for (int i = 0; i < n; i++)
            {
                if (td[i].x == 0 && td[i].y == 0)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        td[j] = td[j + 1];
                    }
                    n--;
                }
            }
        }
};

//1. Khoi tao ToaDo
ToaDo::ToaDo()
{
    x = 0;
    y = 0;
}
ToaDo::ToaDo(int x, int y)
{
    this->x = x;
    this->y = y;
}

//2. Nhap va xuat toa do
void ToaDo::NhapToaDo(ToaDo &td)
{
    cout << "Nhap x: ";
    cin >> td.x;
    cout << "Nhap y: ";
    cin >> td.y;
}

void ToaDo::XuatToaDo(ToaDo td)
{
    cout << "(" << td.x << ", " << td.y << ")" << endl;
}

//3. Tinh tien toa do
void ToaDo::TinhTien(ToaDo &td, int dx, int dy)
{
    td.x += dx;
    td.y += dy;
}

//4. Thay doi x va y
int ToaDo::ThayDoiX(int x)
{
    this->x = x;
    return x;
}

int ToaDo::ThayDoiY(int y)
{
    this->y = y;
    return y;
}

//5. Khoang cach giua hai toa do
float ToaDo::KhoangCach(ToaDo td1, ToaDo td2)
{
    return sqrt(pow(td1.x - td2.x, 2) + pow(td1.y - td2.y, 2));
}

//6. Tim trung diem cua hai toa do
ToaDo ToaDo::TrungDiem(ToaDo td1, ToaDo td2)
{
    ToaDo td;
    td.x = (td1.x + td2.x) / 2;
    td.y = (td1.y + td2.y) / 2;
    return td;
}

//7. Sao chep toa do
ToaDo ToaDo::SaoChep(ToaDo td)
{
    ToaDo td1;
    td1.x = td.x;
    td1.y = td.y;
    return td1;
}

//8. Tim toa do co khoang cach gan tam nhat
ToaDo ToaDo::TimKhoangCachGanTamNhat(ToaDo td[], int n)
{
    ToaDo tam;
    tam.x = 0;
    tam.y = 0;
    float min = KhoangCach(td[0], tam);
    for (int i = 1; i < n; i++)
    {
        if (KhoangCach(td[i], tam) == min)
        {
            return td[i];
        }
        else if (KhoangCach(td[i], tam) < min)
        {
            min = KhoangCach(td[i], tam);
        }
    }
}

int main() 
{
    ToaDo td1, td2, td[1000];
    int n, option, subOption, dx, dy;

    cout << "1. Nhap hai toa do" << endl; 
    cout << "2. Nhap nhieu toa do" << endl;
    cout << "Chon option: " << endl;
    cin >> option;

    if (option == 1)
    {
        cout << "Nhap toa do thu nhat: " << endl;
        td1.NhapToaDo(td1);
        cout << "Nhap toa do thu hai: " << endl;
        td2.NhapToaDo(td2);

        cout << "1. Tinh tien toa do" << endl;
        cout << "2. Thay doi toa do" << endl;
        cout << "3. Khoang cach giua hai toa do" << endl;
        cout << "4. Trung diem cua hai toa do" << endl;
        cout << "5. Sao chep toa do" << endl;
        cout << "6. Xuat toa do" << endl;
        cout << "Chon subOption: " << endl;
        cin >> subOption;

        if (subOption == 1)
        {
            cout << "Nhap dx: ";
            cin >> dx;
            cout << "Nhap dy: ";
            cin >> dy;
            td1.TinhTien(td1, dx, dy);
            td2.TinhTien(td2, dx, dy);
            cout << "Toa do sau khi tinh tien: " << endl;
            td1.XuatToaDo(td1);
            td2.XuatToaDo(td2);
        }
        else if (subOption == 2)
        {
            cout << "Nhap x: ";
            cin >> dx;
            cout << "Nhap y: ";
            cin >> dy;
            td1.ThayDoiX(dx);
            td1.ThayDoiY(dy);
            td2.ThayDoiX(dx);
            td2.ThayDoiY(dy);
            cout << "Toa do sau khi thay doi: " << endl;
            td1.XuatToaDo(td1);
            td2.XuatToaDo(td2);
        }
        else if (subOption == 3)
        {
            cout << "Khoang cach giua hai toa do: " << td1.KhoangCach(td1, td2) << endl;
        }
        else if (subOption == 4)
        {
            ToaDo trungDiem = td1.TrungDiem(td1, td2);
            cout << "Trung diem cua hai toa do: ";
            trungDiem.XuatToaDo(trungDiem);
        }
        else if (subOption == 5)
        {
            ToaDo td1Copy = td1.SaoChep(td1);
            ToaDo td2Copy = td2.SaoChep(td2);
            cout << "Toa do sau khi sao chep: " << endl;
            td1Copy.XuatToaDo(td1Copy);
            td2Copy.XuatToaDo(td2Copy);
        }
        else if (option == 6)
        {
            cout << "Toa do thu nhat: ";
            td1.XuatToaDo(td1);
            cout << "Toa do thu hai: ";
            td2.XuatToaDo(td2);
        }
    }   

    else if (option == 2)
    {
        cout << "Nhap so luong toa do: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap toa do thu " << i + 1 << ": " << endl;
            td[i].NhapToaDo(td[i]);
        }

        cout << "1. Xuat tat ca toa do" << endl;
        cout << "2. Tim toa do co khoang cach gan tam nhat" << endl;
        cout << "3. Sao chep toa do" << endl;
        cout << "4. Xoa toa do" << endl;
        cout << "Chon subOption: " << endl;
        cin >> subOption;

        if (subOption == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Toa do thu " << i + 1 << ": ";
                td[i].XuatToaDo(td[i]);
                cout << endl;
            }
        }
        else if (subOption == 2)
        {
            ToaDo toaDoGanTamNhat = td[0].TimKhoangCachGanTamNhat(td, n);
            cout << "Toa do co khoang cach gan tam nhat: ";
            toaDoGanTamNhat.XuatToaDo(toaDoGanTamNhat);
        }
        else if (subOption == 3)
        {
            int i;
            cout << "Nhap toa do can sao chep: ";
            cin >> i;
            ToaDo tdCopy = td[i].SaoChep(td[i]);
            cout << "Toa do sau khi sao chep: " << endl;
            tdCopy.XuatToaDo(tdCopy);
        }
        else if (subOption == 4)
        {
            int j;
            cout << "Nhap toa do can xoa: ";
            cin >> j;
            td[j].XoaToaDo(td, n);
            cout << "Toa do sau khi xoa: " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "Toa do thu " << i + 1 << ": ";
                td[i].XuatToaDo(td[i]);
                cout << endl;
            }
        }
    }
    
    return 0;
}

