#include<iostream>
using namespace std;
class publication{
public:
    float price;
    string name;
    publication(){
        name = "none";
        price = 0.0;
    }

    void data(string s){
        cout<<"\nenter name of "<<s<<" : ";
        cin>>name;
        bool flag=false;
        while(flag==false){
            cout<<"\nenter price of "<<s<<" : ";
            cin>>price;
            
            try{
                if(price<=0){
                    throw price;
                }else{
                    flag=true;
                }
            }
            catch(float x){
                price=0.0;
                cout<<"\ninvalid price ";
                cout<<"\nenter valid input !";
            }
        }
    }
    inline string getname(){
        return name;
    }
    inline float getprice(){
        return price;
    }
};

class book : public publication{
public:
    int pages;
    book(){
        pages = 0;
    }
    void getpages(){
        bool flag = false;
        while(flag==false){
            cout<<"\nEnter the no of pages : ";
            cin>>pages;

            try{
                if(pages<=0){
                    throw pages;
                }else{
                    flag=true;
                }
            }
            catch(int x){
                pages=0;
                cout<<"\ninvalid!!";
                cout<<"\nenter valid input";
            }
        }
    }
    void display(){
        cout<<"\t\nbook is found ";
        cout<<"\t\ndetails of book";
        cout<<"\t\nname of book : "<<getname();
        cout<<"\t\npages of book : "<<pages;
        cout<<"\t\nprice of book : "<<getprice();

    }
};

class tape:public publication{
public:
    float time;
    tape(){
        time=0.0;
    }
    void gettime(){
        bool flag=false;
        while(flag==false){
            cout<<"\nenter playing time in minutes : ";
            cin>>time;
            try{
                if(time<=0){
                    throw time;
                }else{
                    flag = true;
                }
            }
            catch(float x){
                time=0.0;
                cout<<"\nenter valid input ";
            }
        }
    }
    void display(){
        cout<<"\t\nAudio cassette found ";
        cout<<"\t\ndetails of audio cassette : ";
        cout<<"\t\nname of tape "<<getname();
        cout<<"\t\nplaying time "<<time<<" mins";
        cout<<"\t\nprice of tape "<<getprice();
    }
};
int main(){
    int choice;
    string n;
    book objb;
    tape objt;

    cout<<"\t\nwelcome to inheritance program ";
    do{
        cout<<"\t1)insert book\n\t2)insert tape\n\t3)display book details\n\t4)display tape details\n\t5)exit";

        cout<<"\nenter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                    objb.data("book");
                    objb.getpages();
                    cout<<"\t\nbook is being searched";
                    break;

            case 2:
                    objt.data("audio tape");
                    objt.gettime();
                    cout<<"\t\ntape is being searched";
                    break;

            case 3:
                    try{
                        if(objb.getname()=="NONE"){
                            throw 3;
                        }else{
                            objb.display();
                            cout<<"\t\nvisit again!!";
                        }
                    }
                    catch(int x){
                        cout<<"\t\nno books has been serached";
                        cout<<"\t\nchoose correct option";
                    }
                    break;

            case 4:
                    try{
                        if(objt.getname()=="NONE"){
                            throw 4;
                        }else{
                            objt.display();
                            cout<<"\t\nvisit again !!";
                        }

                    }
                    catch(int x){
                        cout<<"\t\nno tape has been serached";
                        cout<<"\t\nchoose correct option";
                    }
                    break;

            case 5:
                    cout<<"\t\nVisit Again !";
                    break;

        }
    }while(choice!=5);
    return 0;
}