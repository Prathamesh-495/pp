#include<iostream>
#define size 10
using namespace std;
int n;
template<class T>
void sel(T A[size]){
    int i,j,min;
    T temp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[min])
            min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nsorted array : ";
    for(i=0;i<n;i++){
        cout<<" "<<A[i];
    }
}
int main(){
    int A[size];
    float B[size];
    int i;
    int ch;
    do{
        cout<<"\n-----Menu----";
        cout<<"\n1)int value : ";
        cout<<"\n2)float value : ";
        cout<<"\n3)exit";

        cout<<"\nenter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:
                    cout<<"enter total no of int elements : ";
                    cin>>n;
                    cout<<"enter int elements : ";
                    for(i=0;i<n;i++){
                        cin>>A[i];

                    }
                    sel(A);
                    break;

            case 2:
                    cout<<"\nenter total no of float elements : ";
                    cin>>n;
                    cout<<"\nenter float elements : ";
                    for(i=0;i<n;i++){
                        cin>>B[i];
                    }
                    sel(B);
                    break;

            case 3:
                    cout<<"end of program !!";
                    break;
        }
    }while(ch!=3);
    return 0;
}