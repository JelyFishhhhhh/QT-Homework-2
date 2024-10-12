#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <cmath>
using namespace std;

class Fraction{

    private:
        int num;
        int den;

    public:
        Fraction();
        Fraction(int num, int den);

        void setNum(int num);
        void setDen(int den);
        int getNum();
        int getDen();
        
        // Unary operator
        Fraction operator-();
        
        // Binary operator
        Fraction operator+(Fraction frac2);
        Fraction operator-(Fraction frac2);
        Fraction operator*(Fraction frac2);
        Fraction operator/(Fraction frac2);

        // Relational operator
        bool operator<(Fraction frac2);
        bool operator>(Fraction frac2);
        bool operator==(Fraction frac2);
        bool operator<=(Fraction frac2);
        bool operator>=(Fraction frac2);
        bool operator!=(Fraction frac2);

        // I/O operator
        friend istream& operator>>(istream &inp, Fraction& frac);
        friend ostream& operator<<(ostream &out, Fraction& frac);

        // Increment/ Decrement operator
        Fraction operator++();
        Fraction operator--();
        Fraction operator+=(Fraction& frac);
        Fraction operator-=(Fraction& frac);

        // Assignment operator
        Fraction operator=(Fraction frac2);

        // Simplify IT !
        Fraction simplify();
};

Fraction::Fraction()
:   num(int()),
    den(1)
{

}

Fraction::Fraction(int num, int den)
:   num(num),
    den(den)
{
    if(!den){

        cout<< "Denominator Cannot be ZERO !!!\n";
        den= 1;
    }
}

void Fraction::setNum(int num){

    this->num= num;
}

void Fraction::setDen(int den){

    if(!den){
        
        cout<< "Denominator Cannot be ZERO !!!\n";
        den= 1;
        return;
    }
    this->den= den;
}

int Fraction::getNum(){

    return this->num;
}

int Fraction::getDen(){

    return this->den;
}

// Unary operator
Fraction Fraction::operator-(){

    this->num= -this->num;
    return *this;
}

// Binary operator
Fraction Fraction::operator+(Fraction frac2){

    Fraction result;
    if(den== frac2.den){

        result.num= num+ frac2.num;
        result.den= den;
    }
    else{

        result.num= num* frac2.den+ frac2.num* den;
        result.den= den* frac2.den;

        result.simplify();
    }

    return result;
}

Fraction Fraction::operator-(Fraction frac2){

    Fraction result;
    if(den== frac2.den){

        result.num= num- frac2.num;
        result.den= den;
    }
    else{

        result.num= num* frac2.den- frac2.num* den;
        result.den= den* frac2.den;

        result.simplify();
    }

    return result;
    
}

Fraction Fraction::operator*(Fraction frac2){

    Fraction result;
    result.num= num* frac2.num;
    result.den= den* frac2.den;

    return result;
}

Fraction Fraction::operator/(Fraction frac2){

    Fraction result;
    result.num= num* frac2.den;
    result.den= den* frac2.num;

    return result;
}

// Relational operator
bool Fraction::operator<(Fraction frac2){

    return (num* frac2.den< frac2.num* den);
}

bool Fraction::operator>(Fraction frac2){
    
    return (num* frac2.den> frac2.num* den);
}

bool Fraction::operator==(Fraction frac2){

    return (this->simplify().num== frac2.simplify().num)&&  (this->simplify().den== frac2.simplify().den);
}

bool Fraction::operator<=(Fraction frac2){

    return *this< frac2 || *this== frac2;
}

bool Fraction::operator>=(Fraction frac2){

    return *this> frac2 || *this== frac2;
}

bool Fraction::operator!=(Fraction frac2){

    return !(*this== frac2);
}

// I/O operator
istream& operator>>(istream &inp, Fraction& frac){

    inp>> frac.num>> frac.den;
    return inp;
}

ostream& operator<<(ostream &out, Fraction& frac){

    out<< frac.num<< "/"<< frac.den;
    return out;
}

// Increment/ Decrement operator
Fraction Fraction::operator++(){

    num+= den;
    return *this;
}

Fraction Fraction::operator--(){

    num-= den;
    return *this;
}

Fraction Fraction::operator+=(Fraction& frac){

    Fraction result;
    result= *this+ frac;

    return result;
}

Fraction Fraction::operator-=(Fraction& frac){

    Fraction result;
    result= *this- frac;

    return result;
}

// Assignment operator
Fraction Fraction::operator=(Fraction frac2){

    num= frac2.num;
    den= frac2.den;
    return *this;
}

Fraction Fraction::simplify(){

    for(int i= 2; i< sqrt(den); i++){

        if(!(num% i)){

            num/= i;
            den/= i;
        }
    }
    if(num< 0 && den< 0){

        num*= -1;
        den*= -1;
    }
    return *this;
}
#endif