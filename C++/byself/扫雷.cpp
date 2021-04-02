#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int Map[11][11];//0:未开，1：开了（包括数字），2：无，3：雷;
int xuan[11][11];//1:选择
int biao[11][11];//3:标记
int x=1,y=1;

void print()
{
  system("cls");
  int i,j,l=0,p=0;
  for(i=1; i<=10; i++)
  {
    for(j=1; j<=10; j++)
      if(xuan[i][j]==1)
        cout<<" *";
      else if(biao[i][j]==3)
        cout<<" ★";
      else if(Map[i][j]==0 || Map[i][j]==3)
        cout<<" ◆";
      else if(Map[i][j]==1)
      {
        if(Map[i][j]==1)
        {
          if(Map[i-1][j]==3) l++;
          if(Map[i+1][j]==3) l++;
          if(Map[i][j+1]==3) l++;
          if(Map[i][j-1]==3) l++;
          if(Map[i-1][j-1]==3) l++;
          if(Map[i-1][j+1]==3) l++;
          if(Map[i+1][j-1]==3) l++;
          if(Map[i+1][j+1]==3) l++;
          if(l==0)
          {
            cout<<" □ ";//open
            if(Map[i-1][j]!=3 && Map[i-1][j]!=1)  Map[i-1][j]=1,p++;
            if(Map[i+1][j]!=3 && Map[i+1][j]!=1)  Map[i+1][j]=1,p++;
            if(Map[i][j+1]!=3 && Map[i][j+1]!=1)  Map[i][j+1]=1,p++;
            if(Map[i][j-1]!=3 && Map[i][j-1]!=1)  Map[i][j-1]=1,p++;
            if(Map[i-1][j-1]!=3 && Map[i-1][j-1]!=1)  Map[i-1][j-1]=1,p++;
            if(Map[i-1][j+1]!=3 && Map[i-1][j+1]!=1)  Map[i-1][j+1]=1,p++;
            if(Map[i+1][j-1]!=3 && Map[i+1][j-1]!=1)  Map[i+1][j-1]=1,p++;
            if(Map[i+1][j+1]!=3 && Map[i+1][j+1]!=1)  Map[i+1][j+1]=1,p++;
            p=0;
          }
          else
            cout<<"  "<<l;
          l=0;
        }
      }
    cout<<endl;
  }
}

int main()
{
  int ok;
  while(1)
  {
    cout<<"选择难度(每个方块有多少分之一的概率为雷)\n";
    cout<<"输入:";
    cin>>ok;
    if(ok<=50 && ok>=3)
      break;
    else
    {
      cout<<"输入有误!\n";
      continue;
    }
  }
  int i,j,m=0,g=0;
  srand((unsigned)time(NULL));
  for(i=1; i<=10; i++)
    for(j=1; j<=10; j++)
      if(rand()%ok==0)
        Map[i][j]=3,g++;
  while(1)
  {
    print();
    int u=getch();
    if(u==72) xuan[y][x]=0,y--;
    else if(u==80) xuan[y][x]=0,y++;
    else if(u==75) xuan[y][x]=0,x--;
    else if(u==77) xuan[y][x]=0,x++;
    else if(u=='c' && Map[y][x]==3)
    {
      cout<<"You Lost!\n";
      system("pause");
      system("cls");
      //cout<<"地图:\n";
      for(int o=1; o<=10; o++)
      {
        for(int t=1; t<=10; t++)
          if(Map[o][t]==3)
            cout<<" ?";
          else
            cout<<" ■";
        cout<<endl;
      }
      return 0;
    }
    else if(u=='c') Map[y][x]=1;//b
    else ;
    if(y==0) y=1;
    if(y==11) y=10;
    if(x==0) x=1;
    if(x==11) x=10;
    for(int k=1; k<=10; k++)
      for(int h=1; h<=10; h++)
        if(Map[k][h]==3 && biao[k][h]==3)
          m++;
    if(m==g)
    {
      cout<<"You Win!\n";
      system("pause");
      system("cls");
      cout<<"************************\n";
      cout<<"***** 恭喜你完成了 *****\n";
      cout<<"***** 这个小游戏！ *****\n";
      cout<<"************************\n";
      system("pause");
      system("cls");
      cout<<"地图:\n";
      for(int o=1; o<=10; o++)
      {
        for(int t=1; t<=10; t++)
          if(Map[o][t]==3)
            cout<<" ?";
          else
            cout<<" ■";
        cout<<endl;
      }
      return 0;
    }
    m=0;
    xuan[y][x]=1;
    if(u=='x') biao[y][x]=3;
    if(u=='z' && biao[y][x]==3) biao[y][x]=0;
  }
  return 0;
}