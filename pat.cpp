#include<stdlib.h>
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int xmax ,ymax ,xmid ,ymid;
class pt
{
protected:
int xco, yco, color;
public:
pt()
{
xco=0;
yco=0;
color=0;
}
void setco(int x,int y)
{
xco=x;
yco=y;
}
void setcolor(int c)
{
color=c;
}
void draw()
{
putpixel(xco, yco, 0);
}
};
class dline:public pt
{
int x2, y2;
public:
dline():pt()
{
x2=0;
y2=0;
}
void setline(int x, int y, int xx, int yy)
{
pt::setco(x,y);
x2=xx;
y2=yy;
}
void draw1(int color)
{
float x, y, dx, dy, length;
int i;
pt::setcolor(color);
dx=abs(x2-xco);
dy=abs(y2-yco);
if(dx>=dy)
length=dx;
else
{
length=dy;
}
dx=(x2-xco)/length;
dy=(y2-yco)/length;
x=xco+0.5;
y=yco+0.5;
i=1;
while(i<=length)
{
pt::setco(x,y);
pt::draw();
x=x+dx;
y=y+dy;
i=i+1;
}
pt:setco(x,y);
pt::draw();
}
};
class dcircle
{
private:
int x1, y1;
public:
dcircle()
{
x1=0;
y1=0;
}
void setoff(int xx, int yy)
{
x1=xx;
y1=yy;
}
void drawc(float x, float y, int r)
{
float d;
x=0, y=r;
d=3-2*r;
do
{
putpixel(x1+x, y1+y, 0);
putpixel(x1+y, y1+x, 0);
putpixel(x1+y, y1-x, 0);
putpixel(x1+x, y1-y, 0);
putpixel(x1-x, y1-y, 0);
putpixel(x1-y, y1-x, 0);
putpixel(x1-y, y1+x, 0);
putpixel(x1-x, y1+y, 0);

if(d<=0)
{
x=x+1;
d=d+(4*x)+6;
}
else
{
x=x+1;
y=y-1;
d=d+(4*x-4*y)+10;
}
}
while(x<=y);
}
};
void drawFig(int x1, int y1, int x2, int y2, int x3, int y3)
{
dline ll;
ll.setline(x1, y1, x2, y2);
ll.draw1(15);
ll.setline(x2, y2, x3, y3);
ll.draw1(15);
ll.setline(x3, y3, x1, y1);
ll.draw1(15);
}

int main()
{
int gm=VGAMAX, gd=DETECT;
initgraph(&gd, &gm, NULL);
int x1, x2, y1, y2, x3, y3;

dcircle cr;

setbkcolor(WHITE);
setcolor(0);
cout<<"\n Enter the coordinates of the triangle:\n";
cout<<"\n Enter the value of first point x1:";
cin>>x1;
cout<<"\n Enter the value of first point y1:";
cin>>y1;
cout<<"\n Enter the value of second point x2:";
cin>>x2;
cout<<"\n Enter the value of second point y2:";
cin>>y2;
cout<<"\n Enter the value of third point x3:";
cin>>x3;
cout<<"\n Enter the value of third point y3:";
cin>>y3;

drawFig(x1, y1, x2, y2, x3, y3);

double a,b,c;
a=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
b=sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
c=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
float xc=((a*x1)+(b*x2)+(c*x3))/(a+b+c);
float yc=((a*y1)+(b*y2)+(c*y3))/(a+b+c);
float inradius=0.5*sqrt(((b+c-a)*(c+a-b)*(a+b-c))/(a+b+c));
cr.setoff(xc, yc);
cr.drawc(xc, yc, inradius);

float A=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
float B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
float C=acos(((b*b)+(a*a)-(c*c))/(2*b*a));
float Xc=((x1*sin(2*A))+(x2*sin(2*B))+(x3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));
float Yc=((y1*sin(2*A))+(y2*sin(2*B))+(y3*sin(2*C)))/(sin(2*A)+sin(2*B)+sin(2*C));
float cir_radius=a/(2*sin(A));
cr.setoff(xc,yc);
cr.drawc(xc, yc, cir_radius);
getch();
closegraph();
return 0;
}
