#include <iostream>
#include "ClassData.h"
#include <sstream>
using namespace std;

int Mesi[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Data::Data(int a, int b, int c)
{
    if (a <= 0 || a > 31)
    {
        cout << endl;
        cout << "Giorno maggiore di 0 o minore uguale a 31. Verra' impostato a 1. " << endl;
        this->giorno = 1;
    }
    else
    {
        this->giorno = a;
    }

    if (b <= 0 || b > 12)
    {
        cout << endl;
        cout << "Mese minore o uguale a 0 o maggiore 12, verra' impostato a 1. " << endl;
        this->mese = 1;
    }
    else
    {
        this->mese = b;
    }
    if (c < 0)
    {
        cout << endl;
        cout << "Anno minore di 0, verra' impostato a 0. " << endl;
        this->anno = 0;
    }
    else
    {
        this->anno = c;
    }
}
Data::Data()
{
    this->giorno = 1;
    this->mese = 1;
    this->anno = 0;
}
int Data::getDay()
{
    return this->giorno;
}
void Data::setDay(int n)
{
    this->giorno = n;
}
int Data::getMonth()
{
    return this->mese;
}
void Data::setMonth(int n)
{
    this->mese = n;
}
int Data::getYear()
{
    return this->anno;
}
void Data::setYear(int n)
{
    this->anno = n;
}

Data operator+(Data c, int right)
{
    c.AggiugniGiorni(right);
    return c;
}
Data operator-(Data c, int right)
{
    c.LevaGiorni(right);
    return c;
}
bool Data::bisestile(long a)
{
    if ((a % 4 == 0 && a % 100 == 0 && a % 400 == 0) || (a % 4 == 0 && a % 100 != 0))
    {
        return true;
    }
    return false;
}
int Data::getMaxDay(short mese, long anno)
{
    if (mese == 2)
    {
        return (bisestile(anno) ? 29 : 28);
    }
    else
    {
        return Mesi[this->mese - 1];
    }
}
ostream &operator<<(ostream &a, Data &b)
{
    a << b.giorno << "/";
    if (b.mese < 10)
    {
        cout << "0" << b.mese << "/" << b.anno;
    }
    else
    {
        cout << b.mese << "/" << b.anno;
    }
    return a;
}
istream &operator>>(istream &stream, Data &b)
{
    cout << "Inserisci giorno: ";
    do
    {
        stream >> b.giorno;
        if (b.giorno <= 0 || b.giorno > 31)
        {
            cout << endl;
            cout << "Il giorno non puo' avere meno di 1 giorno e non puo' essere maggiore di 31! Riprova:  ";
        }
    } while (b.giorno <= 0 || b.giorno > 31);
    cout << endl
         << "Inserisci mese: ";
    do
    {
        stream >> b.mese;
        if (b.mese <= 0 || b.mese > 12)
        {
            cout << endl;
            cout << "Il mese non puo' essere meno di 1 o maggiore di 12! Riprova:  ";
        }
    } while (b.mese <= 0 || b.mese > 12);
    cout << endl
         << "Inserisci anno: ";
    do
    {
        stream >> b.anno;
        if (b.anno < 0)
        {
            cout << endl;
            cout << "L'anno non puo' essere minore di 0! Riprova:  ";
        }
    } while (b.anno < 0);
    return stream;
}
bool operator==(Data a, Data b)
{
    if (a.giorno == b.giorno && a.mese == b.mese && a.anno == b.anno)
    {
        return true;
    }
    return false;
}
void Data::AggiugniGiorni(long a)
{
    long contatore = 0;
    while (contatore < a)
    {
        if (this->giorno != this->getMaxDay(this->mese, this->anno))
        {
            this->giorno++;
        }
        else
        {
            if (this->mese == 12)
            {
                this->mese = 1;
                this->anno++;
                this->giorno = 1;
            }
            else
            {
                this->mese++;
                this->giorno = 1;
            }
        }
        contatore++;
    }
}
void Data::LevaGiorni(long a)
{
    long contatore = a;
    while (contatore > 0)
    {
        if (this->giorno != 1)
        {
            this->giorno--;
        }
        else
        {
            if (this->mese == 1)
            {
                this->mese = 12;
                this->anno--;
                this->giorno = this->getMaxDay(this->mese, this->anno);
            }
            else
            {
                this->mese--;
                this->giorno = this->getMaxDay(this->mese, this->anno);
            }
        }
        contatore--;
    }
}
bool operator>(Data b, Data c)
{
    if (b.DataFormat() > c.DataFormat())
    {
        return true;
    }
}
bool operator<(Data a, Data b)
{
    if (a.DataFormat() < b.DataFormat())
    {
        return true;
    }
}
long Data::DataFormat()
{
    stringstream a;
    long c = 0;

    a << this->anno;
    if (this->mese < 10)
    {
        a << 0 << this->mese;
    }
    else
    {
        a << this->mese;
    }
    if (this->giorno < 10)
    {
        a << 0 << this->giorno;
    }
    else
    {
        a << this->giorno;
    }
    a >> c;
    cout << c << endl;
    return c;
}
bool Data::SameDay(Data b)
{
    if (this->giorno == b.giorno)
    {
        return true;
    }
    return false;
}
bool Data::SameMonth(Data b)
{
    if (this->mese == b.mese)
    {
        return true;
    }
    return false;
}
bool Data::SameYear(Data b)
{
    if (this->anno == b.anno)
    {
        return true;
    }
    return false;
}