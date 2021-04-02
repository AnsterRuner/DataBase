#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int s,j,o=0;
int xing,wen,jiank,we=0;
double q;
void jian();
void ch(int jia);
void zhuan(int ai,int bi);
void lian();
void end();
void jf();
void qlian();
void xiao();
void xue();
void bend();

void bend()
{
  cout<<"你失败了，可能因为各种原因";
  printf("%d心情 %d健康 %d钱\n",xing,jiank,q);
  sleep(1000);
}

void end()
{
  cout<<"\n\nb{{恭喜你达到了 4级!}}d\n";
  sleep(1);
  cout<<"p{{完成了这个小游戏!}}q";
  sleep(1000);
}

void lian()
{
  while(1)
  {
    if(j>=4)
      end();
    cout<<"\n\n您有"<<q<<"元    "<<j<<"级      "<<s<<"声誉度\n";
    if(rand()%12==1)
    {
      cout<<"你遇到了一个商人，他想和你谈合作:\n你想理会他么(y/n)??\n";
      char hu;
      cin>>hu;
      if(hu=='y')
      {
        if(rand()%5<=4)
          q+=rand()%100,cout<<"他给了你一些钱\n";
        else
          q=2,xing-=20,cout<<"商人欺骗了你，偷走了你所有的钱，逃走的时候落下了2块钱\n";
      }
      else if(hu=='n')
      {
        cout<<"他十分生气，一巴掌乎死了你\n";
        if(q>100){
        	cout<<"你花了100元去医院治病，活了下来\n";
        	system("pause"); 
        	return;
		}
        system("pause");
        bend();
      }
      else{
      	cout<<"你离开了这个商人\n";
      	system("pause");
      	system("cls");
	  }
      system("pause");
      system("cls");
    }
    cout<<"要抽奖(2元)，建房还是离开工作？ (c/j/e)\n";
    char m;
    cin>>m;
    if(m=='c')
      ch(2);
    else if(m=='j' && wen>=80)
      jian();
    else if(m=='e')
      break;
    else if(m=='j' && wen<80)
    {
      cout<<"文化不够，至少80\n";
      return;
    }
    else
      cout<<"error\n";
  }
  system("cls");
}

void zhuan(int ai,int bi)
{
  if(q<ai)
  {
    cout<<"不够\n";
    system("pause");
    system("cls");
    jian();
  }
  else
  {
    srand((unsigned)time(NULL));
    int f=rand()%4;
    if(f==0)
    {
      cout<<"住户评价：1星\n赚"<<bi*1.0*0.3<<"元\n";
      q=q-ai+bi*0.3;
      cout<<"你有"<<q<<"元\n";
      s-=15;
      if(s<=0)
      {
        s=0;
        if(j>=2)
          j-=1;
      }
      xing-=20;
      cout<<"扣15声誉,心情-20\n";

    }
    else if(f==1 && f==2)
    {
      cout<<"住户评价：2星\n赚"<<bi*1.0*0.65<<"元\n";
      q=q-ai+bi*0.65;
      cout<<"你有"<<q<<"元\n";
      s+=20;
      if(s>=100)
      {
        s=0;
        if(j<=3)
          j+=1;
      }
      cout<<"加20声誉\n";
    }
    else
    {
      cout<<"住户评价：3星\n赚"<<bi<<"元\n";
      q=q-ai+bi*1.0;
      cout<<"你有"<<q<<"元\n";
      s+=40;
      if(s>=100)
      {
        s=0;
        if(j<=3)
          j+=1;
      }
      cout<<"加40声誉\n";
    }
    system("pause");
    system("cls");
  }
}

void ch(int jia)
{
  int an;
  srand((unsigned)time(NULL));
  an=rand()%100;
  cout<<"开启一个宝箱？(y/n)\n";
  char c;
  cin>>c;
  if(c=='y')
    if(jia>q)
      cout<<"钱不够，要"<<jia<<"元\n";
    else if(an<=2)
    {
      cout<<"特等奖！！\n50元！(2%)\n";
      q+=50;
      q=q-jia;
      int lll=rand()%5;
      if(lll==1)
      {
        cout<<"由于你太高兴了，所以你猝死了......花了100元抢救\n";
        q-=100;
        if(q<=1)
        {
          cout<<"钱不够,you died\n";
          bend();
        }
        system("pause");
      }
    }
    else if(an>2 && an<=10)
    {
      cout<<"一等奖！！\n10元！(8%)\n";
      q+=10;
      q=q-jia;
    }
    else if(an>10 && an<=50)
    {
      cout<<"二等奖！\n5元(40%)\n";
      q+=5;
      q=q-jia;
    }
    else
    {
      cout<<"三等奖！\n3元(50%)\n";
      q+=3;
      q=q-jia;
    }
  cout<<"您有"<<q<<"元\n\n\n";
  system("pause");
  system("cls");
}

void jian()
{
  system("cls");
  int l;
  cout<<"你的建筑等级为"<<j<<"级\n";
  sleep(1);
  if(j==1)
    cout<<"可建造1.厕所(3元，最大回馈10元) 2.高级帐篷(6元，最大回馈15元) 3.池塘(15元，最大回馈20元)4.退出     (输序号建造)\n";
  else if(j==2)
    cout<<"可建造1.景观亭(20元，最大回馈27元)2.平房(30元，最大回馈39元)3.小院(37元，最大回馈45元)4.退出        (输序号建造)\n";
  else if(j==3 || j>=4)
    cout<<"可建造1.居民楼(50元，最大回馈62元)2.办公用楼(60元，最大回馈72元)3.高楼(75元，最大回馈100元)4.退出         (输序号建造)\n";
  cin>>l;
  if(j==1)
    if(l==1)
      zhuan(3,10);
    else if(l==2)
      zhuan(6,15);
    else if(l==3)
      zhuan(15,20);
    else if(l==4)
      return;
    else
    {
      cout<<"error\n";
      system("pause");
      system("cls");
      jian();
    }
  else if(j==2)
    if(l==1)
      zhuan(20,27);
    else if(l==2)
      zhuan(30,39);
    else if(l==3)
      zhuan(37,45);
    else if(l==4)
      return;
    else
    {
      cout<<"error\n";
      jian();
    }
  else if(j==3 || j==4)
    if(l==1)
      zhuan(50,62);
    else if(l==2)
      zhuan(60,72);
    else if(l==3)
      zhuan(75,100);
    else if(l==4)
      return;
    else
    {
      cout<<"error\n";
      system("pause");
      system("cls");
      jian();
    }
  else
  {
    cout<<"error\n";
    system("pause");
    system("cls");
    jian();
  }
}

void jf()
{
  if(we==1)
  {
    lian();
    return;
  }
  we++;
  cout<<we<<endl;
  s=1,j=1;
  srand((unsigned)time(NULL));
  system("cls");
  string w;
  cout<<"这是您开发的第一步：\n获取启动资金\n";
  ch(0);
  cout<<"接下来该选择可建造的建筑了\n";
  cout<<"建筑分级别\n";
  cout<<"越高级别回馈越大\n";
  system("pause");
  system("cls");
  cout<<"升级需要声誉度，可通过建设与广告增减(有可能会降低)\n";
  cout<<"终极目标是达到4级\n";
  cout<<"让我们开始吧\n\n\n";
  system("pause");
  system("cls");
  jian();
  cout<<"\n\n\n教程到此为止，发挥你的想象力吧\n";
  s=1,j=1;
  system("pause");
  system("cls");
  lian();
  return;
}

void qlian()
{
  while(1)
  {
    if(xing>50)
      xing=50;
    if(jiank>=70)
      jiank=70;
    if(wen>100)
      wen=100;
    if(xing<0)
      bend();
    if(jiank<=0)
      bend();
    if(wen<0)
      wen=0;
    if(q<=0)
      bend();
    system("cls");
    cout<<"你有"<<q<<"元  "<<xing<<"心情   "<<jiank<<"健康 "<<wen<<"文化\n ";
    if(xing<20)
      cout<<"你太沮丧了，注意心情\n\n";
    if(rand()%12==1)
    {
      cout<<"你遇到了一个商人，他想和你谈合作:\n你想理会他么(y/n)??\n";
      char hu;
      cin>>hu;
      if(hu=='y')
      {
        if(rand()%5<=4)
          q+=rand()%100,cout<<"他给了你一些钱\n";
        else
          q=2,xing-=20,cout<<"商人欺骗了你，偷走了你所有的钱，逃走的时候落下了2块钱\n";
      }
      else
      {
        cout<<"他十分生气，一巴掌乎死了你\n";
        if(q>100){
        	cout<<"你花了100元去医院治病，活了下来\n";
        	system("pause"); 
        	return;
		}
        system("pause");
        bend();
      }
      system("pause");
      system("cls");
    }
    cout<<"心情与生命+1\n";
    xing++,jiank++;
    cout<<"要干什么？抽奖&建房/消费(好心情)/学习(文化)  (a/b/c)\n";
    char y;
    cin>>y;
    if(y=='a')
      jf();
    else if(y=='b')
      xiao();
    else
      xue();
  }
}

void xiao()
{
  if(q<35)
  {
    cout<<"钱不够最少要35元\n";
    system("pause");
    system("cls");
    return;
  }
  srand((unsigned)time(NULL));
  cout<<"旅游或逛商场(a/b)\n";
  char c;
  cin>>c;
  if(c=='a')
  {
    int r=rand()%4;
    if(r==0)
    {
      cout<<"花30元，健康值扣5";
      q-=30,jiank-=5;
      if(jiank<=0)
        bend();
    }
    if(r==1)
    {
      cout<<"花10元，健康值扣5";
      q-=10,jiank-=5;
      if(jiank<=0)
        bend();
    }
    if(r==2)
    {
      cout<<"花10元，健康值扣10";
      q-=10,jiank-=10;
      if(jiank<=0)
        bend();
    }
    if(r==3)
    {
      cout<<"花30元，健康值扣10";
      q-=30,jiank-=10;
      if(jiank<=0)
        bend();
    }
    xing+=20;
    cout<<"心情+20！\n";
  }
  else
  {
    int s=rand()%2;
    if(s==0)
    {
      cout<<"花25元\n";
      q-=25;
    }
    if(s==1)
    {
      cout<<"花35元\n";
      q-=35;
    }
    cout<<"心情+15\n";
    xing+=20;
  }
  system("pause");
  system("cls");
}

void xue()
{
  cout<<"要上课还是去图书馆(a/b)\n";
  srand((unsigned)time(NULL));
  char h;
  cin>>h;
  if(h=='a')
  {
    if(q>=15)
    {
      cout<<"花15元，文化+13，心情-5\n";
      system("pause");
      q-=15,wen+=13,xing-=5;
    }
    else
    {
      cout<<"钱不够,要50\n";
      system("pause");
      system("cls");
      return;
    }
  }
  else
  {
    if(q>=10)
    {
      cout<<"花10元，文化+7\n";
      system("pause");
      q-=10;
      wen+=7;
    }
    else
    {
      cout<<"钱不够,要10\n";
      system("pause");
      system("cls");
      return;
    }
  }
}

int main()
{
  cout<<"得到了10元的你，决定出门闯荡一番";
  cout<<"\n你的梦想是当一名有名的房屋买卖者\n";
  q=10,xing=80,jiank=100,wen=0;
  system("pause");
  system("cls");
  qlian();
}
