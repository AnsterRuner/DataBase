#include <bits/stdc++.h>
using namespace std;
int a[100000007];
bool v[1000007];

int main(){
	long long n,m,in;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&in);
		if(!v[in]){
			v[in]=1;
			a[in]=i;
		}
	}
	//cout<<v[1]<<a[1]<<' '<<v[2]<<a[2]<<' '<<v[3]<<a[3]<<endl;
	
	for(int i=0;i<=1000007;++i){
		if(v[i]==0) a[i]=-1;
	}
	
	for(int i=0;i<m;++i){
		scanf("%lld",&in);
		if(in<0)
			cout<<-1<<' ';
		else
			cout<<a[in]<<' ';
	}
	return 0;
}
