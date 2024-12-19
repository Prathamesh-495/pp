#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class ddacircle
{ 
 float xi,yi;
 public:
  void mycircle(float xc,float yc,float r);
  };
  void ddacircle::mycircle(float xc,float yc, float r)
  {
   float startx,starty,e,v;
   startx = r;
   starty = 0;
   xi = startx;
   yi = starty;
   int i=0;
   
   do
   { 
    v = pow(2,i);
    i++;
    }while(v<r);
    e = 1/pow(2,i-1);
    cout<<e;
    do
    {
     xi = xi+(e*yi);
     yi = yi-(e*xi);
     putpixel (xc+xi,yc+yi,RED);
     delay(200);
     }while((yi-starty)<e||(startx-xi)>e);

    }
    
     int main()
     { 
      ddacircle d;
      int xc,yc,r;
      int gd = DETECT,gm;
      initgraph(&gd,&gm,NULL);
      cout<<"Enter coordinates of center of circle(x,y)";
      cin>>xc>>yc;
      cout<<"Enter the radius of circle";
      cin>>r;
      d.mycircle(xc,yc,r);
      getch();
      closegraph();
      return 0;
      }
      
      
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
                                                                                                                                                                                         
