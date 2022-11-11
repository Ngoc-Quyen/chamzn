#include <bits/stdc++.h>
using namespace std;
#pragma once

class Date
{
    private:
        int day, month, year;
    public:
        Date(int = 0, int = 0, int = 0);
        Date(const Date&);
        ~Date();
        void setDay(int );
        int getDay();
        void setMonth(int);
        int getMonth();
        void setYear(int);
        int getYear();
        friend istream& operator >> (istream&, Date&);
        friend ostream& operator << (ostream&, Date);
        void ShowRental();
        bool IsYear(int );
        int DayMonth();
        void NextDay();
        void ShowReturn(int );
        Date getTimeNow();
        Date getTimeReturn(int);

};