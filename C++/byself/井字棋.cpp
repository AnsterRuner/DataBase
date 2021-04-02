/*
	Name:¾®×ÖÆå; 
	Copyright:Zhangty 
	Date: 21/11/2020 08:30
*/
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
int Map[5][5];    //0:NULL,1:player,2:computer
int key;

inline void computer(){
	int num=0;
	while(1){
		num++;
		int x=rand()%3+1,y=rand()%3+1;
		if(Map[x][y]==0){
			Map[x][y]=2; 
			break;
		}
		if(num>=100) break;
		else continue;
	}
}

inline void print(){
	system("cls");
	cout<<"X:player,O:computer\n";
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(Map[i][j]==0)
				cout<<' ';
			else if(Map[i][j]==1)
				cout<<'X';
			else if(Map[i][j]==2)
				cout<<'O';
			if(j!=3)	
			cout<<'|';			
		}
		if(i!=3)
		cout<<endl<<"------"<<endl;
	}
	cout<<endl;
}

inline int win(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(!(i==3&&j==1)&&!(i==3&&j==3)&&!(i==1&&j==1)&&!(i==1&&j==3)){
				if((Map[i][j]==1)&&((Map[i][j+1]==1&&Map[i][j-1]==1)||(Map[i+1][j]==1&&Map[i-1][j]==1))){
					return 1;
				}
				else if(Map[i][j]==2&&((Map[i][j+1]==2&&Map[i][j-1]==2)||(Map[i+1][j]==2&&Map[i-1][j]==2))){
					return 2;
				}
				else if((Map[1][1]==1&&Map[2][2]==1&&Map[3][3]==1)||(Map[1][3]==1&&Map[2][2]==1&&Map[3][1]==1)){
					return 1;
				}
				else if((Map[1][1]==2&&Map[2][2]==2&&Map[3][3]==2)||(Map[1][3]==2&&Map[2][2]==2&&Map[3][1]==2)){
					return 2;
				}
				int add=0;
				for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(Map[i][j]!=0) add++;
					}
				}
				if(add==9){
					return 3;
				}
			}
		}
	}
	return 0;
}

inline void play(){
	system("pause");
	system("cls");
	cout<<"Play Again(y/n)?\n";
	char in;
	cin>>in;
	if(in=='y'){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				Map[i][j]=0;
			}
		}
	}
	else{
		exit(0);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	while(1){				
		print();
		int in,in2;
		cin>>in>>in2;
		if(Map[in][in2]==0) Map[in][in2]=1;
		computer();
		print();		
		int winch=win();
		if(winch==1){
			cout<<"player win!!!\n";
			play();
		}
		else if(winch==2){
			cout<<"computer win!!!\n";
			play();
		}
		else if(winch==3){
			cout<<"full!!!\n";
			play();
		}
	}
	return 0;
}
