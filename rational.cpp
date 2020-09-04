//
// Created by tangb on 3/19/2020.
//

#include "rational.h"
#include <iostream>
using namespace std;

rational::rational(): _n(0), _d(1), _error(0){}

rational::rational(int num, int denom): _n(num), _d(denom), _error(0){
    is_error();
}

rational::rational(int w): _n(w), _d(1), _error(0){
    is_error();

}

int rational::get_num() const{
    return _n;
}

int rational::get_denom() const{
    return _d;
}


void rational::set_num(int n){
    is_error();
    _n = n;

}
void rational::set_denom(int d){
    is_error();
    _d = d;

}
void rational::set(int num, int denom){
    is_error();
    set_num (num);
    set_denom (denom);

}

int rational::error() const{
    return _error;

}
int rational::is_error(){
    // the rational number is undefined when its denominator = 0
    if (_d == 0){
        _error = 1;
    }
    return _error;

}
void rational::clear(){

    set(0,1);// reset the number
    _error = 0;

}
string rational::error_description(){
    switch (_error){
        case 1: return "Undefined";
        default:
            return "Unknown error";
    }

}
rational operator +(const rational &num1, const rational &num2){
    if (num1.error() || num2.error())
        return rational(1,0);// One of two rational number is undefined, the result is also undefined

    int newDenom = (num1._d)* (num2._d);
    int newNum = (num1._n * num2._d) + (num2._n * num1._d);

    rational sum(newNum, newDenom);
    return  sum;

}

rational operator -(const rational &num1, const rational &num2) {
    if (num1.error() || num2.error())
        return rational(1,0);

    int newDenom = (num1._d) * (num2._d);
    int newNum = (num1._n * num2._d) - (num2._n * num1._d);
    rational sub(newNum, newDenom);

    return sub;
}


rational operator *(const rational &num1, const rational &num2){
    if (num1.error() || num2.error())
        return rational(1,0);

    int newDenom = (num1._d)* (num2._d);
    int newNum = num1._n * num2._n;

    rational mul(newNum, newDenom);

    return  mul;

}
rational operator /(const rational &num1, const rational &num2){
    if (num1.error() || num2.error())
        return rational(1,0);

    int newDenom = (num1._d)* (num2._n);
    int newNum = num1._n * num2._d;
    rational div(newNum, newDenom);
    return  div;
}

ostream& operator <<(ostream &outs, const rational &num){
    outs << num.get_num() << '/' << num.get_denom();
    return outs;
}
istream& operator >>(istream &ins, rational &num){
    int n,d;

    char slash;
    ins >> n >> slash >> d;
    num = rational(n, d);
    return ins;

}





