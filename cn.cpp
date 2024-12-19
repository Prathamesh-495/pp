#include<iostream>
using namespace std;
class Complex
{
 
float real,img;
public:
Complex() //default constructor
{}
Complex operator +(Complex); //member function
Complex operator *(Complex);
friend ostream & operator <<(ostream&,Complex&); //non member function or friend 
friend istream & operator >>(istream&,Complex&); //non member function or friend 
};

Complex Complex::operator +(Complex obj)
{
cout<<endl<<"real is="<<real<<endl
    <<"obj.real is="<<obj.real<<endl
    <<"img is ="<<img<<endl
    <<"obj.img is="<<obj.img<<endl;
Complex temp;
temp.real=real+obj.real;
temp.img=img+obj.img;
return temp;
}

Complex Complex::operator *(Complex obj)
{
cout<<endl<<"real is="<<real<<endl
<<"obj.real is="<<obj.real<<endl
<<"img is ="<<img<<endl<<"obj.img is="
<<obj.img<<endl;

Complex temp;
temp.real=real*obj.real-img*obj.img;
temp.img=real*obj.img+img*obj.real;
return temp;
}

//definition of istream
//Return type functionname symbol  argumets
istream& operator >>(istream& is,Complex& obj)  //istream-- >>(cin)  obj-->a
{
 //cin>>obj.real;
 is>>obj.real;
 //cin>>obj.img;
is>>obj.img;
return is;
}
//definition of ostream
ostream& operator <<(ostream& os,Complex& obj)//ostream <<(cout)   obj-->b
{
//cout<<obj.real;
os<<obj.real;
//cout<<obj.img;   a+bi
os<<"+"<<obj.img<<"i";
return os;
}


int main()
{
Complex a,b,c,d,e; //created objects for complex class 
int a1;
cout<<endl<<"enter 1st no"<<endl;
cout<<"enter real and img. no = "<<endl;
cin>>a; //call to extraction operator function
cout<<endl<<"enter 2nd no"<<endl;
cout<<"enter real and img. no = "<<endl;
cin>>b; //call to extraction operator function
cout<<endl<<"arithmatic operations are"<<endl;
c=a+b; //call to operator + function
cout<<"addition is= "<<c<<endl;  //call to insertion operator function
d=a*b; //call to operator multiplication function
cout<<"multiplication is ="<<d<<endl<<endl; //call to insertion operator function


return 0;
}