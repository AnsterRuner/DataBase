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
  cout<<"��ʧ���ˣ�������Ϊ����ԭ��";
  printf("%d���� %d���� %dǮ\n",xing,jiank,q);
  sleep(1000);
}

void end()
{
  cout<<"\n\nb{{��ϲ��ﵽ�� 4��!}}d\n";
  sleep(1);
  cout<<"p{{��������С��Ϸ!}}q";
  sleep(1000);
}

void lian()
{
  while(1)
  {
    if(j>=4)
      end();
    cout<<"\n\n����"<<q<<"Ԫ    "<<j<<"��      "<<s<<"������\n";
    if(rand()%12==1)
    {
      cout<<"��������һ�����ˣ��������̸����:\n���������ô(y/n)??\n";
      char hu;
      cin>>hu;
      if(hu=='y')
      {
        if(rand()%5<=4)
          q+=rand()%100,cout<<"��������һЩǮ\n";
        else
          q=2,xing-=20,cout<<"������ƭ���㣬͵���������е�Ǯ�����ߵ�ʱ��������2��Ǯ\n";
      }
      else if(hu=='n')
      {
        cout<<"��ʮ��������һ���ƺ�������\n";
        if(q>100){
        	cout<<"�㻨��100ԪȥҽԺ�β�����������\n";
        	system("pause"); 
        	return;
		}
        system("pause");
        bend();
      }
      else{
      	cout<<"���뿪���������\n";
      	system("pause");
      	system("cls");
	  }
      system("pause");
      system("cls");
    }
    cout<<"Ҫ�齱(2Ԫ)�����������뿪������ (c/j/e)\n";
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
      cout<<"�Ļ�����������80\n";
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
    cout<<"����\n";
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
      cout<<"ס�����ۣ�1��\n׬"<<bi*1.0*0.3<<"Ԫ\n";
      q=q-ai+bi*0.3;
      cout<<"����"<<q<<"Ԫ\n";
      s-=15;
      if(s<=0)
      {
        s=0;
        if(j>=2)
          j-=1;
      }
      xing-=20;
      cout<<"��15����,����-20\n";

    }
    else if(f==1 && f==2)
    {
      cout<<"ס�����ۣ�2��\n׬"<<bi*1.0*0.65<<"Ԫ\n";
      q=q-ai+bi*0.65;
      cout<<"����"<<q<<"Ԫ\n";
      s+=20;
      if(s>=100)
      {
        s=0;
        if(j<=3)
          j+=1;
      }
      cout<<"��20����\n";
    }
    else
    {
      cout<<"ס�����ۣ�3��\n׬"<<bi<<"Ԫ\n";
      q=q-ai+bi*1.0;
      cout<<"����"<<q<<"Ԫ\n";
      s+=40;
      if(s>=100)
      {
        s=0;
        if(j<=3)
          j+=1;
      }
      cout<<"��40����\n";
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
  cout<<"����һ�����䣿(y/n)\n";
  char c;
  cin>>c;
  if(c=='y')
    if(jia>q)
      cout<<"Ǯ������Ҫ"<<jia<<"Ԫ\n";
    else if(an<=2)
    {
      cout<<"�صȽ�����\n50Ԫ��(2%)\n";
      q+=50;
      q=q-jia;
      int lll=rand()%5;
      if(lll==1)
      {
        cout<<"������̫�����ˣ������������......����100Ԫ����\n";
        q-=100;
        if(q<=1)
        {
          cout<<"Ǯ����,you died\n";
          bend();
        }
        system("pause");
      }
    }
    else if(an>2 && an<=10)
    {
      cout<<"һ�Ƚ�����\n10Ԫ��(8%)\n";
      q+=10;
      q=q-jia;
    }
    else if(an>10 && an<=50)
    {
      cout<<"���Ƚ���\n5Ԫ(40%)\n";
      q+=5;
      q=q-jia;
    }
    else
    {
      cout<<"���Ƚ���\n3Ԫ(50%)\n";
      q+=3;
      q=q-jia;
    }
  cout<<"����"<<q<<"Ԫ\n\n\n";
  system("pause");
  system("cls");
}

void jian()
{
  system("cls");
  int l;
  cout<<"��Ľ����ȼ�Ϊ"<<j<<"��\n";
  sleep(1);
  if(j==1)
    cout<<"�ɽ���1.����(3Ԫ��������10Ԫ) 2.�߼�����(6Ԫ��������15Ԫ) 3.����(15Ԫ��������20Ԫ)4.�˳�     (����Ž���)\n";
  else if(j==2)
    cout<<"�ɽ���1.����ͤ(20Ԫ��������27Ԫ)2.ƽ��(30Ԫ��������39Ԫ)3.СԺ(37Ԫ��������45Ԫ)4.�˳�        (����Ž���)\n";
  else if(j==3 || j>=4)
    cout<<"�ɽ���1.����¥(50Ԫ��������62Ԫ)2.�칫��¥(60Ԫ��������72Ԫ)3.��¥(75Ԫ��������100Ԫ)4.�˳�         (����Ž���)\n";
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
  cout<<"�����������ĵ�һ����\n��ȡ�����ʽ�\n";
  ch(0);
  cout<<"��������ѡ��ɽ���Ľ�����\n";
  cout<<"�����ּ���\n";
  cout<<"Խ�߼������Խ��\n";
  system("pause");
  system("cls");
  cout<<"������Ҫ�����ȣ���ͨ��������������(�п��ܻή��)\n";
  cout<<"�ռ�Ŀ���Ǵﵽ4��\n";
  cout<<"�����ǿ�ʼ��\n\n\n";
  system("pause");
  system("cls");
  jian();
  cout<<"\n\n\n�̵̳���Ϊֹ�����������������\n";
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
    cout<<"����"<<q<<"Ԫ  "<<xing<<"����   "<<jiank<<"���� "<<wen<<"�Ļ�\n ";
    if(xing<20)
      cout<<"��̫��ɥ�ˣ�ע������\n\n";
    if(rand()%12==1)
    {
      cout<<"��������һ�����ˣ��������̸����:\n���������ô(y/n)??\n";
      char hu;
      cin>>hu;
      if(hu=='y')
      {
        if(rand()%5<=4)
          q+=rand()%100,cout<<"��������һЩǮ\n";
        else
          q=2,xing-=20,cout<<"������ƭ���㣬͵���������е�Ǯ�����ߵ�ʱ��������2��Ǯ\n";
      }
      else
      {
        cout<<"��ʮ��������һ���ƺ�������\n";
        if(q>100){
        	cout<<"�㻨��100ԪȥҽԺ�β�����������\n";
        	system("pause"); 
        	return;
		}
        system("pause");
        bend();
      }
      system("pause");
      system("cls");
    }
    cout<<"����������+1\n";
    xing++,jiank++;
    cout<<"Ҫ��ʲô���齱&����/����(������)/ѧϰ(�Ļ�)  (a/b/c)\n";
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
    cout<<"Ǯ��������Ҫ35Ԫ\n";
    system("pause");
    system("cls");
    return;
  }
  srand((unsigned)time(NULL));
  cout<<"���λ���̳�(a/b)\n";
  char c;
  cin>>c;
  if(c=='a')
  {
    int r=rand()%4;
    if(r==0)
    {
      cout<<"��30Ԫ������ֵ��5";
      q-=30,jiank-=5;
      if(jiank<=0)
        bend();
    }
    if(r==1)
    {
      cout<<"��10Ԫ������ֵ��5";
      q-=10,jiank-=5;
      if(jiank<=0)
        bend();
    }
    if(r==2)
    {
      cout<<"��10Ԫ������ֵ��10";
      q-=10,jiank-=10;
      if(jiank<=0)
        bend();
    }
    if(r==3)
    {
      cout<<"��30Ԫ������ֵ��10";
      q-=30,jiank-=10;
      if(jiank<=0)
        bend();
    }
    xing+=20;
    cout<<"����+20��\n";
  }
  else
  {
    int s=rand()%2;
    if(s==0)
    {
      cout<<"��25Ԫ\n";
      q-=25;
    }
    if(s==1)
    {
      cout<<"��35Ԫ\n";
      q-=35;
    }
    cout<<"����+15\n";
    xing+=20;
  }
  system("pause");
  system("cls");
}

void xue()
{
  cout<<"Ҫ�Ͽλ���ȥͼ���(a/b)\n";
  srand((unsigned)time(NULL));
  char h;
  cin>>h;
  if(h=='a')
  {
    if(q>=15)
    {
      cout<<"��15Ԫ���Ļ�+13������-5\n";
      system("pause");
      q-=15,wen+=13,xing-=5;
    }
    else
    {
      cout<<"Ǯ����,Ҫ50\n";
      system("pause");
      system("cls");
      return;
    }
  }
  else
  {
    if(q>=10)
    {
      cout<<"��10Ԫ���Ļ�+7\n";
      system("pause");
      q-=10;
      wen+=7;
    }
    else
    {
      cout<<"Ǯ����,Ҫ10\n";
      system("pause");
      system("cls");
      return;
    }
  }
}

int main()
{
  cout<<"�õ���10Ԫ���㣬�������Ŵ���һ��";
  cout<<"\n��������ǵ�һ�������ķ���������\n";
  q=10,xing=80,jiank=100,wen=0;
  system("pause");
  system("cls");
  qlian();
}
