#include <bits/stdc++.h>
#include <cmath>
#include <queue>
#include <windows.h>
#include <conio.h>
using namespace std;
string USERNAME;

string zhao[9]={"��ͨ����","���⹥��","�����⹥��","��ͨ����","��ͨ����","��ͨ����","��ͨ����","��ͨ����","��ͨ����"};
string MonsterName[14]={"","С��","ʫ��","����","�õ��ϰ�","ǿ��","��ʦ","ħ��","����","����","King","����","��ʦ","��ʥ"};
int wpen[14]={0,2,3,6,8,14,12,14,16,18,26,22,24,26};
int shang[9]={5,10,14,5,5,5,5,5,5};
int ATP,HP=5,level=1,blood=5,coin=20,atk=3,QQ=15,save=0;

inline void pause();
inline void gameover();
inline bool cheak(int x);
int Kill(int hp1,int hp2,string name);
inline void gameover1();

inline void pause(){
	system("pause");
	system("cls");
}

inline void gameover(){
	pause();
	printf("You lost!\n");
	HP--;
}

inline void gameover1(){
	pause();
	printf("You Win!\n");
}

inline bool cheak(int x){
	if(x<=0) return true;
	return false;
}

bool kill(int hp1,int hp2,string name){
	int in;
    ATP=100;
	system("cls");
	int cnt=0;
	while(true){
		system("cls");
		int r=rand()%9;
		ATP+=10;
		cnt++;
		printf("�غ�%d\tATP:%d\n",cnt,ATP);
		printf("%s:%d\t%s:%d\n",USERNAME.c_str(),hp1,name.c_str(),hp2);
		printf("��Ҫʹ��:\n1.��ͨ����(10 ATP);\n2.���⹥��(50 ATP)\n3.�ȱ�\n����:");
		cin>>in;
		if(in==1){
			if(ATP>=10){
				system("cls");
				printf("%sʹ������ͨ����\n",USERNAME.c_str());
				if(rand()%6==1){
					printf("�� %s ����\n",name.c_str());
					pause();
				}
				else{
					printf("���%d�˺�\n",atk);
					hp2-=atk;
        			ATP-=10;            
					if(cheak(hp2)){
					  gameover1();
					  pause();
					  return 1;
					  }
					pause();
				}
			}
			else{
				cout<<"����\n";
				pause();
			}
		}
		else if(in==2){
			if(ATP>=50){
				system("cls");
				printf("%sʹ�������⹥��\n",USERNAME.c_str());
				if(rand()%6==1){
					printf("�� %s ����\n",name.c_str());
					pause();
					continue;
				}
				else{
					printf("���%d�˺�\n",10);
					hp2-=10;
                    ATP-=50;
					if(cheak(hp2)){
					  gameover1();
					  pause();
					  return 1;
					  }
					pause();
				}
			}
			else{
				cout<<"����\n";
				pause();
			}
		}
		else if(in==3){
			if(cheak(save)){
				cout<<"error\n";
				pause();
				continue;
			}
			else{
				cout<<"С��֧Ԯ�ɹ�!!\n";
				hp1+=3;
				ATP+=15;
				save--;
				pause();
				continue;
			}
		}
		else{
			cout<<"Error\n";
			pause();
		}
		printf("%sʹ����%s\n��%s�����%d�˺�\n\n",name.c_str(),zhao[r].c_str(),USERNAME.c_str(),shang[r]);							//Error Point
		hp1-=shang[r];
		if(cheak(hp1)){
			gameover();
			pause();
			return 0;
		}
		pause();
	}
}

void ad(int level){
	system("cls");
	if(level==1){
		
	}
	else if(level==2){
			
	}
	else if(level==3){
			
	}
	else if(level==4){
			
	}
	else if(level==5){
			
	}
	else if(level==6){
			
	}
	else if(level==7){
			
	}
	else if(level==8){
			
	} 
}

void lian(){
	while(true){
	if(cheak(HP)){
		cout<<"Sorry!\nYou lost the GAME!";
		exit(0);
	}
	if(level>=14){
		cout<<"You Win The Game!!!!!!\n";
		exit(0);
	}
	system("cls");
	cout<<"HP:"<<HP<<"\tCoin:"<<coin<<endl<<"Blood:"<<blood<<endl<<"\nǰ��,��ҵ(g/s)\n";
	char in;
	cin>>in;
	if(in=='g'){
		cout<<"Level "<<level<<endl;
		ad(level);
		if(kill(blood,wpen[level],MonsterName[level].c_str())){
			level++,coin+=QQ;
		}
		else{
			coin+=7;
			cout<<"���ź�......\n������ȡ�ͱ�(7 coin)\n";
			system("pause");
			continue;
		}
	}
	else if(in=='s'){
		cout<<"\tAnswer Shop\n1.����2.�ָ�3.����4.����5.����\n";
		cin>>in;
		if(in=='1'){
			cout<<endl<<endl;
			cout<<"1.Ƥ�ﻤ��(15 coin ����10%)\n2.������(35 coin ����20%)\n3.�𻤼�(60 coin ����30%)\n";
			cin>>in;
			if(in=='1'&&coin>=15){
				cout<<"����ɹ�!\n";
				coin-=15;
				for(int i=0;i<9;i++)
					if(shang[i]!=10&&shang[i]!=14) shang[i]=4;
				pause();
				continue;
			}
			else if(in=='2'&&coin>=35){
				cout<<"����ɹ�!\n";
				coin-=35;  
				for(int i=0;i<9;i++)
					if(shang[i]!=10&&shang[i]!=14) shang[i]=3;
				pause();
				continue;
			}
			else if(in=='3'&&coin>=60){
				cout<<"����ɹ�!\n";
				coin-=60;
				for(int i=0;i<9;i++)
					if(shang[i]!=10&&shang[i]!=14) shang[i]=2;
				pause();
				continue;
			}
			else{
				cout<<"error\n";
				pause();
				continue;
			}
		}
		else if(in=='2'){
			cout<<endl<<endl;
			cout<<"1.HP++(35 coin)2.Ĭ��Ѫ��+2(35 coin)\n";
			cin>>in;
			if(in=='1'&&coin>=35){
				cout<<"�ɹ�!\n";
				coin-=35;
				HP++;
				pause();
				continue;
			}
			else if(in=='2'&&coin>=35){
				cout<<"�ɹ�!\n";
				coin-=35;
				blood+=2;
				pause();
				continue;
			}
			else{
				cout<<"error";
				pause();
				continue;
			}
		}
		else if(in=='3'){
			cout<<endl<<endl;
			cout<<"1.��Ҽӳ�(25 coin)2.�ȱ�x1(20 coin)\n";
			cin>>in;
			if(in=='1'&&coin>=25){
				cout<<"�ɹ�!!\n";
				coin-=25;
				QQ+=5;
				pause();
				continue;
			}
			else if(in=='2'&&coin>=20){
				cout<<"�ɹ�!!\n";
				coin-=20;
				save+=1;
				pause();
				continue;
			}
			else{
				cout<<"error";
				pause();
				continue;
			}
		}
		else if(in=='4'){
			cout<<endl<<endl;
			cout<<"1.ʯ��(15 coin)2.����(20 coin)3.��(35 coin)4.��ʯ��(76 coin)\n";
			cin>>in;
			if(in=='1'&&coin>=15){
				cout<<"�ɹ�!!!";
				coin-=15;
				atk=4;
				pause();
				continue;
			}
			else if(in=='2'&&coin>=20){
				cout<<"�ɹ�!!!";
				coin-=20;
				atk=5;
				pause();
				continue;
			}
			else if(in=='3'&&coin>=35){
				cout<<"�ɹ�!!!";
				coin-=35;
				atk=6;
				pause();
				continue;
			}
			else if(in=='4'&&coin>=76){
				cout<<"�ɹ�!!!";
				coin-=76;
				atk=9;
				pause();
				continue;
			}
			else{
				cout<<"error\n";
				continue;
				
			}
		}
		else if(in=='5'){
			cout<<endl<<endl;
			cout<<"��Ҫ����:\n1.С��(+20 coins)\n";
			cin>>in;
			if(in=='1'&&save>=1){
				cout<<"�ɹ�!!\n";
				save--;
				coin+=20;
			}
			else{
				cout<<"error";
			}
			pause();
			continue;
		}
		else{
			cout<<"error";
			pause();
			continue;
		}
	}
}
}

int main(){
    system("cls");
	srand((unsigned)time(NULL));
	printf("�����������!\n");
	cin>>USERNAME;
	if(USERNAME=="Liyukang_is_pig")
		coin=75,blood=10;
	cout<<"�ó̾�Ҫ��ʼ��";
	for(int i=1;i<=6;++i) cout<<'.',Sleep(200);
	Sleep(800);
	lian();
	return 0;
}