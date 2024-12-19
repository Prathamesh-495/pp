#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    string state;
    float population;
    char ans = 'y';
    int choice;
    map<string,float>m;
    map<string,float>::iterator i;
    do{
        cout<<"\n---Main Menu---";
        cout<<"\n1)Insert state : ";
        cout<<"\n2)Display : ";
        cout<<"\n3)search state : ";
        cout<<"\n4)Delete state : ";

        cout<<"Enter your choice : "<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                    cout<<"enter name of state :";
                    cin>>state;
                    cout<<"\nEnter population : ";
                    cin>>population;
                    m.insert(pair<string,float>(state,population));
                    break;

            case 2:
                    cout<<"state and population :"<<endl;
                    for(i=m.begin();i!=m.end();i++){
                        cout<<"["<<(*i).first<<","<<(*i).second<<"]"<<endl;
                    }
                    break;

            case 3:
                    cout<<"enter state name for searching population : "<<endl;
                    cin>>state;
                    if(m.count(state)!=0){
                        cout<<"\npopulation is"<<m.find(state)->second<<"Cr";
                    }
                    else{
                        cout<<"state is not present "<<endl;
                    }
                    break;

            case 4:
                    cout<<"enter state name to be deleted : "<<endl;
                    cin>>state;
                    m.erase(state);
                    cout<<"state deleted !"<<endl;
                    break;
        }
        cout<<"do you want to continue(y/n)"<<endl;
        cin>>ans;

    }while(ans=='y');
    return 0;
}