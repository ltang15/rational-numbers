 * Project: Rational number
 * Purpose: Creating a class for rational number with the presence of friend functions, overloading operators and error handling.
            Performing four calculations between two rational numbers.
 * Notes: Inputting the option for the menu; the selection.
          Inputting the value for the number we want to change.
*/
#include <iostream>
#include "rational.h"

void print(const rational& a, const rational& b);
void print_bad (rational a, rational b);

int main() {

    cout << endl << endl;
    rational a(1,2), b(1,2);// initialize value for two numbers
    print (a,b);
    bool done = false;

    //the loop for running program, it will stop when we choose exit
    do{

        cout << "[A]     [B]      [E]xit" << endl;
        cout << "?";
        char ans;
        cin >> ans;// input the selection
        cout << ":";


        switch (ans) {
            //Input the value for rational number A
            case 'a':
            case 'A':
                cin >> a;

                // check the input for A is undefined or not
                if (a.error()) {
                    print_bad(a, b);
                    a.clear();// reset the value of A if it's undefined
                }
                else
                    print (a,b);
                break;

            //Input the value for rational number B
            case 'b':
            case 'B':
                cin >> b;
                // check the input for A is undefined or not
                if (b.error()) {
                    print_bad(a, b);
                    b.clear(); // reset the value of A if it's undefined
                }
                else
                    print (a,b);

                break;

            //Exit the program
            case 'e':
            case 'E':
                done = true;
                break;

        }

    }
    while (!done);
    cout << endl << endl << "=========END=========" << endl << endl;
    return 0;
}
void print(const rational& a, const rational& b) {
    cout << "A: " << a << "     " << "B: " << b << endl;
    cout << a << " " << '+' << " " << b << " " << '=' << " "<< a + b << endl;
    cout << a << " " << '-' << " " << b << " " << '=' << " "<< a - b << endl;
    cout << a << " " << '*' << " " << b << " " << '=' << " "<< a * b << endl;

    // Two cases for division
    if ((a/b).error())
        // when a and b are defined but the result is undefined
        cout << a << " " << '*' << " " << b << " " << '=' << " "<< (a / b).error_description() << endl;
    else
        //normal case
        cout << a << " " << '/' << " " << b << " " << '=' << " "<< a / b << endl;

}
void print_bad (rational a, rational b){
    //This function is to print the case when one of two numbers is undefined

    if (a.error()){
        cout << "A: " << a.error_description() << "     "
             << "B: " << b << endl;
        cout << a.error_description() << " " << '+' << " " << b << " " << '=' << " "<< (a + b).error_description() << endl;
        cout << a.error_description() << " " << '-' << " " << b << " " << '=' << " "<< (a - b).error_description() << endl;
        cout << a.error_description() << " " << '*' << " " << b << " " << '=' << " "<< (a * b).error_description() << endl;
        cout << a.error_description() << " " << '/' << " " << b << " " << '=' << " "<< (a / b).error_description()<< endl;
    }
    else if (b.error()){
        cout << "A: " << a << "     "
             << "B: " << b.error_description()  << endl;
        cout << a << " " << '+' << " " << b.error_description()  << " " << '=' << " "<< (a + b).error_description() << endl;
        cout << a << " " << '-' << " " << b.error_description()  << " " << '=' << " "<< (a - b).error_description() << endl;
        cout << a << " " << '*' << " " << b.error_description()  << " " << '=' << " "<< (a * b).error_description() << endl;
        cout << a << " " << '/' << " " << b.error_description()  << " " << '=' << " "<< (a / b).error_description() << endl;
    }

}
