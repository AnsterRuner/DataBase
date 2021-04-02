#include <iostream>/*from short to long*/
#include <ctime>/*rand mumber*/
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
int main()
{
  int c,ans=0;
  srand((unsigned)time(NULL));
  cin>>c;
  int a[c+1];
  for(int i=0; i<c; i++)
    cin>>a[i];
  for(int k=1; k<=c; k++)
    for(int j=0; j<c; j++)
      if(a[j]>a[j+1])
        swap(a[j],a[j+1]),ans++;
  for(int l=1; l<c+2; l++)
    if(!(l==c))
      cout<<a[l]<<' ';
  cout<<endl;
  return 0;
}
