#include <bits/stdc++.h>
using namespace std;
#pragma once
class Motobike
{
    private:
        string NameBike;
        string BienSo;
        int PhanKhoi;
        string Mau;
        long Gia;
        int isRend;
    public:
        Motobike(string = "", string = "", int = 0, string = "", long = 0, int = 0);
        Motobike(const Motobike& );
        ~Motobike();
        void setNameBike(string);
        string getNameBike();
        void setBienso(string );
        string getBienso();
        void setPhanKhoi(int);
        int getPhanKhoi();
        void setMau(string);
        string getMau();
        void setGia(long);
        long getGia();
        void setIsRend(int);
        int getIsRend();
        void Show();
        friend istream& operator >> (istream&, Motobike&);
        friend ostream& operator << (ostream&, Motobike);
        

};