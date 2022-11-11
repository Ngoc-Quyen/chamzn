#include "List.h"

List::List()
{
    this->p = nullptr;
    this->len = 0;
}
List::List(ThueXe *t, int len)
{
    this->len = len;
    this->p = new ThueXe[this->len];
    for (int i = 0; i < this->len; i++)
    {
        *(this->p + i) = *(t + i);
    }
}
List::List(const List &t)
{
    this->len = t.len;
    this->p = new ThueXe[this->len];
    for (int i = 0; i < this->len; i++)
    {
        *(this->p + i) = *(t.p + i);
    }
}
List::~List()
{
    delete[] this->p;
}
List List::operator=(const List &t)
{
    this->len = t.len;
    this->p = new ThueXe[this->len];
    for (int i = 0; i < this->len; i++)
    {
        *(this->p + i) = *(t.p + i);
    }
    return *this;
}
int List::getLength()
{
    return this->len;
}
void List::Add(Motobike &m)
{
    if (this->len == 0)
    {
        this->p = new ThueXe[this->len + 1];
        (*(this->p)).Moto = m;
    }
    else
    {
        ThueXe *tmp = new ThueXe[this->len];
        for (int i = 0; i < this->len; i++)
        {
            *(tmp + i) = *(p + i);
        }
        delete[] this->p;
        this->p = new ThueXe[this->len + 1];
        for (int i = 0; i < this->len; i++)
        {
            *(this->p + i) = *(tmp + i);
        }
        (*(this->p + this->len)).Moto = m;
        (*(this->p + this->len)).Number = 0;
        delete[] tmp;
    }
    this->len++;
}
int List::CheckBienso(Motobike &moto)
{
    for (int i = 0; i < this->len; i++)
    {
        if ((this->p + i)->Moto.getBienso().compare(moto.getBienso()) != 0)
        {
            continue;
        }
        else
            cout << "Xe da co trong he thong\n";
        return 0;
    }
    cout << "Them xe thanh cong\n";
    return 1;
}
bool List::CheckCmnd(Person &per)
{
    int count = 0;
    for (int i = 0; i < this->len; i++)
    {
        if ((per.getCMND()).compare((this->p + i)->Per.getCMND()) == 0)
        {
            count++;
        }
    }
    if (count == 1)
        ;
    return true;
    return false;
}
void List::ShowBike()
{
    cout << "\tDanh sach xe trong he thong\n";
    for (int i = 0; i < this->len; i++)
    {
        cout << "Motobike " << i + 1 << ":\n";
        (*(p + i)).Moto.Show();
    }
}
Date getTimeNow()
{
    time_t now = time(0);
    tm *dt = localtime(&now);
    Date d(dt->tm_mday, dt->tm_mon + 1, dt->tm_year + 1900);
    return d;
}
void List::UpdateRental(int n)
{
    if (n > this->len)
    {
        // do
        // {
        cout << "\tSo luong xe muon thue ko hop le! Vui long nhap lai \n";
        cout << "Nhap so luong xe muon thue: ";
        cin >> n;
        this->UpdateRental(n);

        // } while(n > this->len);
    }
    else
    {
        int cmp = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "\tMotobike " << i + 1 << endl;
            string bs;
            cout << "Nhap bien so xe muon thue: ";
            cin >> bs;
            int k = indexOf(bs);
            if ((this->p + k)->Moto.getIsRend() != 1 && k >= 0 && k < this->len)
            {
                cin.ignore();
                cin >> (this->p + k)->Per;
                if (CheckCmnd((this->p + k)->Per))
                {
                    Date d1;
                    d1 = getTimeNow();
                    (*(this->p + k)).DateRetal = d1;
                    cout << "\tNhap so ngay muon thue: ";
                    cin >> (this->p + k)->Number;
                    (*(this->p + k)).Moto.setIsRend(1);
                    system("cls");
                    //  (this->p + k)->ShowBill();
                    (this->p + k)->ShowTT();
                }
                else
                {
                    Person p;
                    (this->p + k)->Per = p;
                    cout << "\tBan dang thue mot xe khac trong he thong\n";
                }
            }
            else
            {
                do
                {
                    cout << "\tXe da duoc nguoi khac thue hoac khong co trong he thong\n";
                    cmp = 1;
                    cout << "Ban co muon thue xe khac khong? y/n\n";
                    char ch;
                    cout << "Nhap lua chon: ";
                    cin >> ch;
                    if (ch == 'n') 
                    {
                        cout << "Cam on quy khach\n";
                        cmp = 0;
                       // system("pause");
                    }
                        
                    else
                    {
                        for (int i = 0; i < n; i++)
                        {
                            cout << "\tMotobike " << i + 1 << endl;
                            string bs;
                            cout << "Nhap bien so xe muon thue: ";
                            cin >> bs;
                            int k = indexOf(bs);
                            if ((this->p + k)->Moto.getIsRend() != 1 && k >= 0 && k < this->len)
                            {
                                cin.ignore();
                                cin >> (this->p + k)->Per;
                                if (CheckCmnd((this->p + k)->Per))
                                {
                                    Date d1;
                                    d1 = getTimeNow();
                                    (*(this->p + k)).DateRetal = d1;
                                    cout << "\tNhap so ngay muon thue: ";
                                    cin >> (this->p + k)->Number;
                                    (*(this->p + k)).Moto.setIsRend(1);
                                    system("cls");
                                    //  (this->p + k)->ShowBill();
                                    (this->p + k)->ShowTT();
                                    cmp = 0;
                                }
                                else
                                {
                                    Person p;
                                    (this->p + k)->Per = p;
                                    cout << "\tBan dang thue mot xe khac trong he thong\n";
                                }
                            }
                        }
                    }
                } while(cmp);
            }
        }
    }
}
int List::isMaching(string t1, string t2)
{
    for (int i = 0; i < t2.length(); i++)
    {
        if (t2[i] == t1[0])
        {
            int count = 0;
            for (int j = 0; j < t1.length(); j++)
            {
                if (t2[j + i] == t1[j])
                    count++;
            }
            if (count == t1.length())
                return i;
        }
    }
    return -1;
}
int List::indexOf(string Bienso)
{
    for (int i = 0; i < this->len; i++)
    {
        if (isMaching(Bienso, (this->p + i)->Moto.getBienso()) != -1)
        {
            return i;
        }
    }
    return -1;
}
