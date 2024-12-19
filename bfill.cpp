#include<graphics.h>
#include<iostream>
using namespace std;
void boundary_fill(int x,int y,int f_color,int b_color)
{
 if (getpixel(x,y)!=b_color&&getpixel(x,y)!=f_color)
 {
  putpixel(x,y,f_color);
  boundary_fill(x+1,y,f_color,b_color);
  boundary_fill(x,y+1,f_color,b_color);
  boundary_fill(x-1,y,f_color,b_color);
  boundary_fill(x,y-1,f_color,b_color);
 }
}
int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 int top,left,bottom,right;
 left=top=50;
 bottom=right=300;
 rectangle(left,top,right,bottom);
 int x=51;
 int y=51;
 boundary_fill(x,y,6,15);
 delay(100);
 getch();
 closegraph();
 return 0;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
