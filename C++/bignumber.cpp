#include <bits/stdc++.h>
#include <cstring>
#include <math.h>

using namespace std;

#define ll long long
#define LF double
const int MAXN = 10007;

int a[MAXN],b[MAXN],c[MAXN+7];                          //����1,����2,���

int main()
{
    system("cls");
    //Ԥ����
    string s1,s2;                                       //�����봴������
    cin>>s1>>s2;
    int l1=s1.size(),l2=s2.size(),l=max(l1,l2);                      //ͳ�Ƴ���
    for(int i=0;i<=l1;++i) a[l1-i-1]=s1[i]-48;
    for(int i=0;i<=l2;++i) b[l2-i-1]=s2[i]-48;             //�����ַ�ת�Զ�����λ
    
    //��
    for(int i=0;i<=l;++i){
        c[i]=a[i]+b[i];
    }

    //�����λ
    for(int i=0;i<=l;++i){
        if(c[i]>=10){
            c[i]%=10;
            c[i+1]++;
        }
    }

    //ϸ�������
    if(c[l]!=0) l++;                                       //������λ��λ,���³���
    for(int i=l-1;i>=0;--i) printf("%d",c[i]);              //���
    return 0;
}