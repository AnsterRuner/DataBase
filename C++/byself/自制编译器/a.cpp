#include <iostream>
#include <windows.h>
#include <cstring>
#include <ctime>
using namespace std;

int main()
{
	int i;
	string str,str1,path;
	cout<<"Note:请将此文件与编译文件放在同一路径下\n拖拽编译文件到此处\n路径:";
	cin>>str;
	cout<<"运行中......\n查找子目录中......\n";
	Sleep(500);
	for(i=strlen(str.c_str());i>=1;--i){
		if(str[i]=='\\') break;
	}
	cout<<"分析路径......\n";
	Sleep(500);
	str1=path=str;
	str1=str1.substr(i+1, strlen(str1.c_str()));
	path=path.substr(0, i);
	cout<<"分离路径与文件名......\n";
	path+='\\';
	str='\"'+str+'\"';
	path='\"'+path+'\"';
	 cout<<"生成编译脚本......\n";
	 Sleep(900);
	//cout<<str1<<endl<<path<<endl<<i<<endl;
	str="cd "+path+" & "+"g++ "+str+" -o "+str1.substr(0, strlen(str1.c_str())-4);
	//cout<<str<<endl;
	 cout<<"交付g++......\n";
	system(str.c_str());
	 cout<<"生成启动脚本......\n"; 
	 Sleep(900);
	string run="cd "+path+"&"+str1;
	run=run.substr(0, strlen(run.c_str())-3);
	 cout<<"替换类型......\n"; 
	run+="exe";
	cout<<"编译成功,按任意键运行\n";
	system("pause");
	system("cls");
	//cout<<run;
	system(run.c_str());
	cout<<endl;
	system("pause");
	return 0;
} 
