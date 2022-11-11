#include "Motobike.h"

Motobike::Motobike(string name, string bienso, int phankhoi, string mau, long gia, int c) : NameBike(name), BienSo(bienso), PhanKhoi(phankhoi), Mau(mau), Gia(gia), isRend(c) {}
Motobike::Motobike(const Motobike &other)
{
    Motobike(other.NameBike, other.BienSo, other.PhanKhoi, other.Mau, other.Gia, other.isRend);
}
Motobike::~Motobike() {}
void Motobike::setBienso(string bienso)
{
    this->BienSo = bienso;
}
string Motobike::getBienso()
{
    return this->BienSo;
}
void Motobike::setNameBike(string name)
{
    this->NameBike = name;
}
string Motobike::getNameBike()
{
    return this->NameBike;
}
void Motobike::setPhanKhoi(int phankhoi)
{
    this->PhanKhoi = phankhoi;
}
int Motobike::getPhanKhoi()
{
    return this->PhanKhoi;
}
void Motobike::setMau(string mau)
{
    this->Mau = mau;
}
string Motobike::getMau()
{
    return this->Mau;
}
void Motobike::setGia(long gia)
{
    this->Gia = gia;
}
long Motobike::getGia()
{
    return this->Gia;
}
void Motobike::setIsRend(int c)
{
    this->isRend = c;
}
int Motobike::getIsRend()
{
    return this->isRend;
}
void Motobike::Show()
{
    cout << "\tTen xe: " << this->NameBike << endl;
    cout << "\tBien so xe: " << this->BienSo << endl;
    cout << "\tPhan khoi xe: " << this->PhanKhoi << "cc" << endl;
    cout << "\tMau xe: " << this->Mau << endl;
    cout << "\tGia thue: " << this->Gia << endl;
    cout << "\tTinh trang: ";
    if (this->isRend != 0) cout << "Da thue\n";
    else cout << "Chua thue\n";
}

istream& operator >> (istream& in, Motobike& moto)
{
    cout << "\tNhap Ten xe: ";
    getline(in, moto.NameBike);
   // in.ignore();
    cout << "\tNhap Bien so xe: ";
    getline(in, moto.BienSo);
   // in.ignore();
    cout << "\tNhap Phan khoi xe: ";
    in >> moto.PhanKhoi;
    cout << "\tNhap Mau xe: "; in >> moto.Mau;
    cout << "\tNhap Gia thue: "; in >> moto.Gia;
    moto.isRend = 0;
    return in;
}
ostream& operator << (ostream& out, Motobike moto)
{
    cout << "\tTen xe: " << moto.getNameBike() << endl;
    cout << "\tien so xe: " << moto.getBienso() << endl;
    cout << "\tPhan khoi xe: " << moto.getPhanKhoi() << "cc" << endl;
    cout << "\tMau xe: " << moto.getMau() << endl;
    cout << "\tGia thue: " << moto.getGia() << endl;
    cout << "\tTinh trang: ";
    if (moto.getIsRend() != 0) cout << "Da thue\n";
    else cout << "Chua thue\n";
}
