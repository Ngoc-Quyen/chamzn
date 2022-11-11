#include <bits/stdc++.h>
using namespace std;
#pragma once

class Person
{
    private:
        string Name;
        int Age;
        string CMND;
        string SDT;
        string Add;
    public:
        Person(string = "", int = 0, string = "", string = "", string = "");
        Person(const Person&);
        ~Person();
        void setName(string );
        string getName();
        void setAge(int );
        int getAge();
        void setCMND(string );
        string getCMND();
        void setSDT(string );
        string getSDT();
        void setAdd(string );
        string getAdd();
        void Show();
        friend istream& operator >> (istream&, Person&);
        friend ostream& operator << (ostream&, Person);
        
};