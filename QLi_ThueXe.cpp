
#include "List.h"
void Menu()
{
    cout << "\tMENU\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. Nhap du lieu khach hang\n";
    cout << "2. Nhap du lieu Motorbike\n";
    cout << "3. Xuat Bill\n";
    cout << "4. In so ngay cua thang\n";
    cout << "5. Them xe vao he thong\n";
    cout << "6. Xuat danh sach xe trong he thong\n";
    cout << "7. Thue xe\n";
}
int main()
{

    Person per1("ngoc quyen", 19, "2627", "6557", "Quang Nam");
    Person per2("van a", 24, "2728", "6778", "DN");
    Motobike moto1("vision", "92F1-01540", 50, "den", 150, 0);
    Motobike moto2("honda", "43F2-1234", 150, "nau", 200, 1);
    Date d1(d1.getTimeNow());
    ThueXe tx1(per1, moto1, 2);
    ThueXe tx2(per2, moto2, 3);
    int cmt;
    List t;
    t.Add(moto1);
    t.Add(moto2);
    do
    {
        Menu();
        cout << "Nhap lua chon: ";
        cin >> cmt;
        switch (cmt)
        {
        case 1:
        {
            Person per;
            cin.ignore();
            cin >> per;
            system("pause");
        }
        break;
        case 2:
        {
            Motobike moto;
            cin.ignore();
            cin >> moto;
            system("pause");
        }
        break;
        case 3:
        {

            tx1.ShowBill();
            tx2.ShowBill();
            system("pause");
        }
        break;
        case 4:
        {
            Date da;
            // cin >> da;
            da.ShowRental();
            da.ShowReturn(3);
            system("pause");
        }
        break;
        case 5:
        {
            int n;
            cout << "Nhap so luong xe muon them: ";
            cin >> n;
            if (n < 1)
                break;
            for (int i = 0; i < n; i++)
            {
                cout << "Nhap thong tin xe\n";
                Motobike moto;
                cin.ignore();
                do
                {
                    cin >> moto;
                } while (!t.CheckBienso(moto));
                t.Add(moto);
            }
            system("pause");
        }
        break;
        case 6:
        {
            t.ShowBike();
            system("pause");
        }
        break;
        case 7:
            {
                t.ShowBike();
                int n;
                cout << "Nhap so luong xe muon thue: "; 
                cin >> n;
                t.UpdateRental(n);
                system("pause");
            }
            break;
        }
    } while (cmt != 0);
    // time_t now = time(0);
    // tm *dt = localtime(&now);
    // cout << dt->tm_mday << "/" << dt->tm_mon << "/" << dt->tm_year;
    return 0;
}
