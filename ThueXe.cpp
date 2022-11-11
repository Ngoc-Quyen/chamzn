#include "ThueXe.h"
ThueXe::ThueXe() {}
ThueXe::ThueXe(const Person& p, const Motobike& m,/* const Date& d1, const Date &d2, */int d) 
{
    this->Per = p;
    this->Moto =  m;
    // this->DateRetal = d1;
    // this->DateReturn = d2;
    this->Number = d;
}
ThueXe::~ThueXe() {}
void ThueXe::Show()
{
    this->Per.Show();
    this->Moto.Show();
    this->DateRetal.ShowRental();
    this->DateReturn.ShowReturn(this->Number);
    if (this->GetMoney() > 0)
    {
        cout << "So ngay thue: " << this->Number << endl;
        cout << "So tien thanh toan: " << this->GetMoney() << endl;
    }
}
long long ThueXe::GetMoney()
{
    return this->Moto.getGia() * this->Number;
}
void ThueXe::ShowTT()
{
    this->Per.Show();
    this->Moto.Show();
    this->DateRetal.ShowRental();
    cout << "Cam on quy khach da su dung dich vu cua chung toi\n";
}
void ThueXe::ShowBill()
{
    cout << "\t\t Hoa Don Cua Ban \t\t\n";
    this->Per.Show();
    this->Moto.Show();
    this->DateRetal.ShowRental();
    this->DateRetal.ShowReturn(this->Number);
    cout << "So ngay thue: " << this->Number << endl;
    cout << "Tong tien thanh toan: " << this->GetMoney() << endl;
    cout << "-------------Hen Gap Lai----------------" << endl;
}
ThueXe& ThueXe::operator= (const ThueXe& tx)
{
    this->Per = tx.Per;
    this->Moto = tx.Moto;
    this->DateRetal = tx.DateRetal;
    this->DateReturn = tx.DateReturn;
    this->Number = tx.Number;
}