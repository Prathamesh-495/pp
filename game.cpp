#include<iostream>;
#include<graphics.h>;
using namespace std;
class pt //base class
{
protected: int x1,y1,color;
public:
pt()
{
x1=0;y1=0;color=WHITE;
}
void setco(int x0,int y0)
{
x1=x0;
y1=y0;
}
void draw()
{
putpixel(x1,y1,color);
}
};
class dline: public pt //derived class
{
private: int x2,y2;
public:
dline():pt()
{

x2=0,y2=0;
}
void ddaline(int x0, int y0, int xx, int yy) // DDA line algo
{
pt::setco(x0,y0);
x2=xx;
y2=yy;
int x,y,dx,dy,steps,i=0;
float xinc,yinc;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
xinc=dx/(float)steps;
yinc=dy/(float)steps;
x=x1;
y=y1;
pt::setco(x,y);
pt::draw(); //putpixel(x,y,WHITE);
for(i=1;i<=steps;i++)
{
x=x+xinc;
y=y+yinc;
pt::setco(x,y);
pt::draw(); //putpixel(x,y,10);
}

}// DDA line algo ends here
void bcircle(int xc,int yc,int r) //bresenhams circle algo
{
int x = 0,y = r, d;
d = 3 -(2*r);
putpixel(x+xc,y+yc,1);
putpixel(y+xc,x+yc,2);
putpixel(x+xc,-y+yc,3);
putpixel(y+xc,-x+yc,4);
putpixel(-x+xc,-y+yc,5);
putpixel(-y+xc,-x+yc,6);
putpixel(-x+xc,y+yc,7);
putpixel(-y+xc,x+yc,8);
while(x<=y)
{
if(d <= 0)
{
d = d + (4*x) + 6;
}
else
{
d = d + (4*x) - (4*y) + 10;
y = y - 1;
}
x = x + 1;
putpixel(x+xc,y+yc,1);
putpixel(y+xc,x+yc,2);
putpixel(x+xc,-y+yc,3);

putpixel(y+xc,-x+yc,4);
putpixel(-x+xc,-y+yc,5);
putpixel(-y+xc,-x+yc,6);
putpixel(-x+xc,y+yc,7);
putpixel(-y+xc,x+yc,8);
}
} //BResenhams circle algo ends here
void animation()
{
for (int i=0; i<350; i++)
{
/***CAR BODY ******/
ddaline(50+i,370,90+i,370);
arc(110+i,370,180,360,20);
//void arc(int x, int y, int start_angle, int end_angle, int radius);
bcircle(110+i,370,17); //wheel
bcircle(240+i,370,17); //wheel
ddaline(130+i,370,220+i,370);
arc(240+i,370,180,360,20);
ddaline(260+i,370,300+i,370);
ddaline(300+i,370,300+i,350);
ddaline(300+i,350,240+i,330);
ddaline(240+i,330,200+i,300);
ddaline(200+i,300,110+i,300);
ddaline(110+i,300,80+i,330);
ddaline(80+i,330,50+i,340);
ddaline(50+i,340,50+i,370);

/***CAR Windows***/
ddaline(165+i,305,165+i,330);
ddaline(165+i,330,230+i,330);
ddaline(230+i,330,195+i,305);
ddaline(195+i,305,165+i,305);
ddaline(160+i,305,160+i,330);
ddaline(160+i,330,95+i,330);
ddaline(95+i,330,120+i,305);
ddaline(120+i,305,160+i,305);
cleardevice(); //clears the screen in graphics mode
ddaline(0,390,639,390); //ROAD
} //ends of for loop
} //animation ends here
}; //dline class ends here
int main()
{
int gd=DETECT,gm, ch;
initgraph(&gd,&gm,NULL);
dline car;
car.animation();
getch();
return 0;
} //ends of main function
