#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

	int d1,d2,d3;
	scanf("%d%d%d",&d1,&d2,&d3);
	printf("%d",min(d1+d2+d3,min(min(2*(d1+d3),2*(d2+d3)),2*(d1+d2))));

	return 0;
}
