#include <bits/stdc++.h>
using namespace std;

int main()
{
  int y=2000,m=1,d=1,z=6,ci=50000;
  string week[8]= {"","Monday","Tuseday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  for(int i=1; i<=ci; i++)
  {
    d++,z++;
    if(y%400==0 || ((y%4==0)&&(y%100!=0)))
      if(m==2 && d==30)
        m++,d=1;
    if(!(y%400==0 || ((y%4==0)&&(y%100!=0))))
      if(m==2 && d==29)
        m++,d=1;
    if(d==32 && (m==1||m==3||m==5||m==7||m==8||m==10||m==12))
      m++,d=1;
    else if(d==31 && !(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
      m++,d=1;
    if(m==13)
      y++,m=1;
    if(z==8)
      z=1;
    //if(d==13 && z==5)
    printf("%d.%d.%d:%s\n",y,m,d,week[z].c_str());
  }
  return 0;
}

