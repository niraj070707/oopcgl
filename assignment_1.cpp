/*
Assignment 1
Name : Niraj Satish Karande
Roll no : 21335
Batch : F3 [SE-3]
Implement  a  class  Complex  which represents  the  Complex Number  data  type.  
Implement  the  following  
1.  Constructor (including  a  default  constructor  which  creates  the  complex number  0+0i).  
2.  Overload  operator+  to  add  two  complex numbers.  
3.  Overload  operator*  to  multiply  two  complex numbers.  
4.  Overload  operators  <<  and  >>  to  print  and  read Complex Numbers.
*/

#include<iostream>
using namespace std;

class Complex{
    private:
        float x, y;

    public:
        Complex(){
            x = 0;
            y = 0;
        }
        Complex operator+(Complex);
        Complex operator*(Complex);
        friend ostream & operator<<(ostream &, Complex &);
        friend istream & operator>>(istream &, Complex &);
};

/*multiplication operator overloading*/
Complex Complex :: operator*(Complex obj){
    Complex temp;
    temp.x = (x * obj.x) - (y * obj.y);
    temp.y = (x * obj.y) + (y * obj.x);
    return temp;
}

/*plus operator overloading*/
Complex Complex :: operator+(Complex obj){
    Complex temp;
    temp.x = x + obj.x;
    temp.y = y + obj.y;
    return temp;
} 

/*extraction operator overloading*/
istream & operator>>(istream &in, Complex &obj){
    cout << "Real part : ";
    in >> obj.x;
    cout << "Imaginary part : ";
    in >> obj.y;
    return in;
}

/*insertion operator overloading*/
ostream & operator<<(ostream &dout, Complex &obj){
    dout << obj.x << " + " << obj.y << "i" << endl;
    return dout;
}

int main(){
    Complex n1, n2, n3, n4;
    cin >> n1;
    cout << n1;

    cin >> n2;
    cout << n2;

    n3 = n2 + n1;
    cout << "Addition : ";
    cout << n3;

    n4 = n1 * n2;
    cout << "Multiplication : ";
    cout << n4;
    return 0;
}