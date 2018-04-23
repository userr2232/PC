#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int TC,p,s,n,c;
	cin >> TC; c = 0;
	while(TC--){
		c++;
		scanf("%d",&p);
		s = 0; 
		while(p--){
			scanf("%d",&n);
			s = max(n,s);
		}
		printf("Case %d: %d\n",c,s);
	}
}
