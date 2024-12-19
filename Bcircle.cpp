#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
void plot(int xc,int yc,int x,int y)
{
 putpixel(x+xc,y+yc,RED);
 putpixel(x+xc,-y+yc,YELLOW);
 putpixel(-x+xc,-y+yc,GREEN);
 putpixel(-x+xc,y+yc,YELLOW);
 putpixel(y+xc,x+yc,12);
 putpixel(y+xc,-x+yc,14);
 putpixel(-y+xc,-x+yc,15);
 putpixel(-y+xc,x+yc,6);
}
void Bcircle(int xc,int yc,int r)
{
 int x=0,y=r;
 int d=3-(2*r);
 plot(xc,yc,x,y);
 while(x<=y)
 {
  if(d<=0)
  {
   d=d+(4*x)+6;
  }
  else
  {
   d=d+(4*x)-(4*y)+10;
   y=y-1;
  }
  x=x+1;
  plot(xc,yc,x,y);
  }
}
int main()
{
 int xc,yc,r;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 cout<<"Enter the value of xc,yc";
 cin>>xc>>yc;
 cout<<"Enter radius:";
 cin>>r;
 Bcircle(xc,yc,r);
 getch();
 closegraph();
 return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
