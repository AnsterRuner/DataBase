#include <bits/stdc++.h>
#include <cstring>
#include <math.h>

using namespace std;

#define ll long long
#define LF double
const int MAXN = 10007;

int a[MAXN],b[MAXN],c[MAXN+7];                          //加数1,加数2,结果

int main()
{
    system("cls");
    //预处理
    string s1,s2;                                       //输入与创建加数
    cin>>s1>>s2;
    int l1=s1.size(),l2=s2.size(),l=max(l1,l2);                      //统计长度
    for(int i=0;i<=l1;++i) a[l1-i-1]=s1[i]-48;
    for(int i=0;i<=l2;++i) b[l2-i-1]=s2[i]-48;             //将数字反转以对齐数位
    
    //加
    for(int i=0;i<=l;++i){
        c[i]=a[i]+b[i];
    }

    //处理进位
    for(int i=0;i<=l;++i){
        if(c[i]>=10){
            c[i]%=10;
            c[i+1]++;
        }
    }

    //细节与输出
    if(c[l]!=0) l++;                                       //如果最高位进位,更新长度
    for(int i=l-1;i>=0;--i) printf("%d",c[i]);              //输出
    return 0;
}