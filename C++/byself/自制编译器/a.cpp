#include <iostream>
#include <windows.h>
#include <cstring>
#include <ctime>
using namespace std;

int main()
{
	int i;
	string str,str1,path;
	cout<<"Note:�뽫���ļ�������ļ�����ͬһ·����\n��ק�����ļ����˴�\n·��:";
	cin>>str;
	cout<<"������......\n������Ŀ¼��......\n";
	Sleep(500);
	for(i=strlen(str.c_str());i>=1;--i){
		if(str[i]=='\\') break;
	}
	cout<<"����·��......\n";
	Sleep(500);
	str1=path=str;
	str1=str1.substr(i+1, strlen(str1.c_str()));
	path=path.substr(0, i);
	cout<<"����·�����ļ���......\n";
	path+='\\';
	str='\"'+str+'\"';
	path='\"'+path+'\"';
	 cout<<"���ɱ���ű�......\n";
	 Sleep(900);
	//cout<<str1<<endl<<path<<endl<<i<<endl;
	str="cd "+path+" & "+"g++ "+str+" -o "+str1.substr(0, strlen(str1.c_str())-4);
	//cout<<str<<endl;
	 cout<<"����g++......\n";
	system(str.c_str());
	 cout<<"���������ű�......\n"; 
	 Sleep(900);
	string run="cd "+path+"&"+str1;
	run=run.substr(0, strlen(run.c_str())-3);
	 cout<<"�滻����......\n"; 
	run+="exe";
	cout<<"����ɹ�,�����������\n";
	system("pause");
	system("cls");
	//cout<<run;
	system(run.c_str());
	cout<<endl;
	system("pause");
	return 0;
} 
