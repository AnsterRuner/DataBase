#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <queue>
#define maxn 50
using namespace std;
int dx[4]= {0,0,1,-1},dy[4]= {1,-1,0,0},step=0,bi[5][10000],key,mmx,mmy;
bool map1[maxn+10][maxn+10];
int main()
{
  int m,n,mx,my;
  cin>>m>>n;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      char ch=getchar();
      if(ch==10) ch=getchar();
      if(ch=='.')
        map1[i][j]=1;
      else
        map1[i][j]=0;
      if(ch=='S')
      {
        mmx=i,mmy=j;
        map1[i][j]=0;
      }
      else if(ch=='E')
        mx=i,my=j,map1[i][j]=1;
    }
  }
  int l=0,r=1;
  bi[2][1]=mmx,bi[3][1]=mmy;
  while(l<r)
  {
    ++l;
    int x=bi[2][l];
    int y=bi[3][l];
    for(int d=0; d<=3; ++d)
    {
      int xx=x+dx[d];
      int yy=y+dy[d];
      if(map1[xx][yy])
      {
        ++r;
        bi[1][r]=bi[1][l]+1;
        bi[2][r]=xx,bi[3][r]=yy;
        if(xx==mx&&yy==my)
        {
          cout<<bi[1][r];
          return 0;
        }
        map1[xx][yy]=0;
      }
    }
  }
  cout<<-1;
  return 0;
}