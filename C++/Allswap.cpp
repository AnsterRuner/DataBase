#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int ans[10000],used[10000],c,ans1=0; 

inline void pt(){
	for(int i=1;i<=c;i++){
		cout<<"    "<<ans[i];
	}
	cout<<endl;
	ans1++; 
}

void dfs(int dep){
	if(dep>c){
		pt();
		return;
	}
	else{
		for(int i=1;i<=c;i++){
			if(!used[i]){
				ans[dep]=i;
				used[i]=1;
				dfs(dep+1);
				used[i]=0;
			}
		}
	}
}

int main()
{
  //freopen("cpp.in","r",stdin);
  //freopen("cpp.out","w",stdout);
  cin>>c;
  dfs(1);
  cout<<ans1;
  //fclose(stdin);
  //fclose(stdout); 
  return 0;
}
