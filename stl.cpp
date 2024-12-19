#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class record{
public:
    int item_code,quantity;
    string name;
    float cost;

    bool operator == (const record &o1){
        if(name==o1.name){
            return 1;
        }
        return 0;
    }

    bool operator < (const record &o1){
        if(item_code<o1.item_code){
            return 1;
        }
        return 0;
    }
};

vector<record>r1;

void insert();
void display();
void print1(record &r1);
void search();
void del();

void insert(){
    record o1;
    cout<<"\nenter name : ";
    cin>>o1.name;
    cout<<"\nenter item code : ";
    cin>>o1.item_code;
    cout<<"\nenter quantity : ";
    cin>>o1.quantity;
    cout<<"\nenter cost : ";
    cin>>o1.cost;

    r1.push_back(o1);
}
void display(){
    for_each(r1.begin(),r1.end(),print1);
}

void print1(record &r1){
    cout<<"name : "<<r1.name<<endl;
    cout<<"item code : "<<r1.item_code<<endl;
    cout<<"Quantity : "<<r1.quantity<<endl;
    cout<<"cost : "<<r1.cost<<endl;

}

void search(){
    record o1;
    vector<record>::iterator i;
    cout<<"\nenter name to serach : ";
    cin>>o1.name;
    i=find(r1.begin(),r1.end(),o1);
        if(i==r1.end()){
            cout<<"\nnot found";
        }
        else{
            cout<<"\nrecord found";
        }
}

bool compare(const record &r1,const record &r2){
    return r1.item_code<r1.item_code;
}

void del(){
    vector<record>::iterator i;
    record o1;
    cout<<"\nenter name of record to be deleted  : ";
    cin>>o1.name;
    i=find(r1.begin(),r1.end(),o1);
        if(i==r1.end()){
            cout<<"record not found : ";
        }
        else{
            r1.erase(i);
            cout<<"\ndeleted !!";
        }
}
int main(){
    int ch;
    do{
        cout<<"\n1)insert";
        cout<<"\n2)display";
        cout<<"\n3)search ";
        cout<<"\n4)sort";
        cout<<"\n5)delete";
        cout<<"\n6)exit";


        cout<<"enter choice : "<<endl;
        cin>>ch;

        switch(ch){
            case 1:
                    cout<<"\nenter items :";
                    insert();
                    break;

            case 2:
                    cout<<"\ndisplay : ";
                    display();
                    break;

            case 3:
                    search();
                    break;

            case 4:
                    sort(r1.begin(),r1.end(),compare);
                    cout<<"\nsorted order : ";
                    display();
                    break;

            case 5:
                    del();
                    break;

            case 6:
                    cout<<"\nwrong choice ";
                    break;

        }

    }while(ch!=6);
    return 0;
}
