#include<iostream>
#include<fstream>
using namespace std;
class employee{
    char name[20];
    int emp_id;
    float salary;
public:
    void accept(){
        cin>>name;
        cin>>emp_id;
        cin>>salary;
    }

    void display(){
        cout<<"\n"<<name<<"\t"<<emp_id<<"\t"<<salary;
    }
};
int main(){
    employee o[5];
    fstream f;
    int i,n;

    f.open("input.txt");
    cout<<"\nhow many employee info wanted to store : ";
    cin>>n;

    cout<<"\nenter info of 3 employee (name,employee id,salary) : ";
    for(i=0;i<n;i++){
        cout<<"\nEnter info of "<<i<<" employee";
        o[i].accept();
        f.write((char*)&o[i],sizeof(o[i]));
    }
    f.close();

    f.open("input.txt",ios::in);
    cout<<"\ninformation of employee are : ";
    for(i=0;i<n;i++){
        f.read((char*)&o[i],sizeof(o[i]));
        o[i].display();
    }
    f.close();


    return 0;
}