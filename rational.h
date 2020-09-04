//
// Created by tangb on 3/19/2020.
//

#ifndef RATIONALNUMBER_RATIONAL_H
#define RATIONALNUMBER_RATIONAL_H
#include <iostream>
#include <string>
using namespace std;

class rational {
public:
    rational();
    rational(int num, int denom);
    rational(int w);        //whole number

    //mutators / setters
    void set(int num, int denom);
    void set_num(int n);
    void set_denom(int d);

    //accessors / getters
    int get_num() const;
    int get_denom() const;

    //error handling routines
    int error() const;      //return error state
    int is_error();   //checks for error cond and returns error code
    string error_description();
    //return a descriptive error message

    void clear();           //resets number to 0/1 and clears error state

    //will return object whose error state is set
    //   if one of the operands is in error.
    friend rational operator +(const rational &num1, const rational &num2);
    friend rational operator -(const rational &num1, const rational &num2);
    friend rational operator *(const rational &num1, const rational &num2);
    friend rational operator /(const rational &num1, const rational &num2);


    friend ostream& operator <<(ostream &outs, const rational &num);
    friend istream& operator >>(istream &ins, rational &num);

private:
    int _n;                 //numerator
    int _d;                 //denominator
    int _error;             //error code


};


#endif //RATIONALNUMBER_RATIONAL_H
