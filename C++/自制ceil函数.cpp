#include<bits/stdc++.h>
using namespace std;

inline int roand(double x){
  return x+0.5;	
} 

int main()
{	
  double n,b=1;
  int i;
  cin>>n;
  /*if(n<1)
  {
    cout<<"1";
    return 0;
  }*/
  for(i=1;; i++)
  {
    if(i*b>n)
      break;
  }
  if(n-(i-1)*b==0)
    cout<<n;
  else
    cout<<-(n-n-(i-1)*b)+1;//把+1去掉可改成floor函数;
  return 0;
}
