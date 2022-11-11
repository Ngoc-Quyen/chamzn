#include "ThueXe.h"

class List
{
    private:
        ThueXe *p;
        int len;
    public:
        List();
        List(ThueXe*, int = 0);
        List(const List&);
        ~List();
        List operator = (const List&);
        int getLength();
        void Add(Motobike&);
        int CheckBienso(Motobike &);
        bool CheckCmnd(Person&);
        void ShowBike();
        void UpdateRental(int = 0);
        int isMaching(string = "", string = "");
        int indexOf(string = "");
        
};