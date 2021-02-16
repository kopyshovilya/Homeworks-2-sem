#include <iostream>
#include <numeric>



class fraction{
public:
    fraction(){
        numerator = 0;
        denominator = 1;
    }
    fraction(int a, int b){
        numerator = a;
        denominator = b;
    }
    fraction(fraction &a){
        numerator = a.numerator;
        denominator = a.denominator;
    }
//////////////////////////      Алгебраические операторы        ///////////////////////////////////
    fraction operator +(const fraction &b){
        fraction rez = fraction(numerator * b.denominator + b.numerator * denominator, denominator * b.denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator +(const int b){
        fraction rez = fraction(numerator + b * denominator, denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator -(const fraction &b){
        fraction rez = fraction(numerator * b.denominator - b.numerator * denominator, denominator * b.denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator -(const int b){
        fraction rez = fraction(numerator - b * denominator, denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator *(const fraction &b){
        fraction rez = fraction(numerator * b.numerator, denominator * b.denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator *(const int b){
        fraction rez = fraction(numerator * b, denominator);
        reduction(&rez);
        return rez;
    }

    fraction operator /(const fraction &b){
        if(b.numerator == 0){
            std::cout << "The operation was not completed\n";
            return *this;
        }
        fraction rez = fraction(numerator * b.denominator, denominator * b.numerator);
        reduction(&rez);
        return rez;
    }

    fraction operator /(const int b){
        if(b == 0){
            std::cout << "The operation was not completed\n";
            return *this;
        }
        fraction rez = fraction(numerator, denominator * b);
        reduction(&rez);
        return rez;
    }
//////////////////////////          Унарные операторы         ///////////////////////////////////
    fraction operator -(){
        fraction rez = fraction(-numerator, denominator);
        reduction(&rez);
        return rez;
    }
//////////////////////////      Операторы присваивания        ///////////////////////////////////
    fraction& operator =(const fraction &b){
        numerator = b.numerator;
        denominator = b.denominator;
        return *this;
    }

    fraction& operator +=(const fraction &b){
        *this = *this + b;
        return *this;
    }

    fraction& operator -=(const fraction &b){
        *this = *this - b;
        return *this;
    }

    fraction& operator *=(const fraction &b){
        *this = *this * b;
        return *this;
    }

    fraction& operator /=(const fraction &b){


        *this = *this / b;
        return *this;
    }
//////////////////////////      Операторы ввода/вывода        ///////////////////////////////////
    friend std::ostream& operator<<(std::ostream &out, const fraction &b){
        out << b.numerator << "/" << b.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream &in, fraction &a){
        in >> a.numerator;
        in >> a.denominator;
        return in;
    }
//////////////////////////      Остальные методы класса        ///////////////////////////////////
    double frac2dec(){
        return double (numerator) / double (denominator);
    }

private:
    int numerator, denominator;
    void reduction(fraction* a){
        int nod = std::gcd((*a).numerator, (*a).denominator);
        (*a).numerator /= nod;
        (*a).denominator /= nod;
    }
};



int main()
{
    return 0;
}
