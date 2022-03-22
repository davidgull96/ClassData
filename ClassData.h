#include <iostream>
using namespace std;

class Data
{

private:
    int giorno;
    int mese;
    long anno;
    long DataFormat();

public:
    Data(int a, int b, int c);
    Data();
    bool checkData(int, int, int);
    friend Data operator+(Data c, int right);
    friend Data operator-(Data c, int right);
    friend bool operator>(Data, Data);
    friend bool operator<(Data, Data);
    friend ostream &operator<<(ostream &a, Data &b);
    friend istream &operator>>(istream &a, Data &b);
    friend bool operator==(Data a, Data b);
    bool bisestile(long);
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);
    int getMaxDay(short, long);
    void AggiugniGiorni(long a);
    void LevaGiorni(long a);
    bool DataMaggiore(Data);
    bool SameDay(Data b);
    bool SameMonth(Data b);
    bool SameYear(Data b);
};