#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void move(int j,int h,int &x,int &y)
{
 if(j==1)
  y-=h;
 else if(j==2)
  x+=h;
 else if(j==3)
  y+=h;
 else if(j==4)
  x-=h;
 lineto(x,y);
}
void hilbert(int u,int r,int d,int l,int i,int h,int &x,int &y)
{
if(i>0)
 {
  i--;
  hilbert(r,u,l,d,i,h,x,y);
  move(u,h,x,y);
  delay(1000);
  hilbert(u,r,d,l,i,h,x,y);
  move(d,h,x,y);
  delay(1000);
  hilbert(u,r,d,l,i,h,x,y);
  move(d,h,x,y);
  delay(1000);
  hilbert(l,d,r,u,i,h,x,y);
  delay(1000);
  }
}
int main()
{
 int n,x=50,y=150,h=10,r=2,d=3,l=4,u=1;
 int gd=DETECT,gm=0;
 initgraph(&gd,&gm,NULL);
 cout<<"enter the value of n:";
 cin>>n;
 moveto (x,y);
 hilbert(u,r,d,l,n,h,x,y);
 delay(1000);
 closegraph();
 return 0;
 }

