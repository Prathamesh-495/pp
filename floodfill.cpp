#include<graphics.h>
#include<iostream>
using namespace std;
void floodfill(int x,int y,int new_c,int old_c)
{
 if(getpixel(x,y)==old_c)
 {
  putpixel(x,y,new_c);
  floodfill(x+1,y,old_c,new_c);
  floodfill(x,y+1,old_c,new_c);
  floodfill(x-1,y,old_c,new_c);
  floodfill(x,y-1,old_c,new_c);
  floodfill(x+1,y+1,old_c,new_c);
  floodfill(x-1,y-1,old_c,new_c);
  floodfill(x+1,y-1,old_c,new_c);
  floodfill(x-1,y+1,old_c,new_c);
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
 int new_c=12;
 int old_c=0;
 floodfill(x,y,new_c,old_c);
 delay(100);
 getch();
 closegraph();
 return 0;
} 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
