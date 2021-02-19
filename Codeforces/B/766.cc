#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
	int n;
	bool OK;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	    scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	for(int i = 0; i < n-2; i++)
		for(int j = i+1; j < n-1; j++){
		    if(!OK) OK = true;
			for(int k = j+1; k < n; k++){
			    if(v[k] >= v[j] + v[i]){
			        OK = false;
			        break;
			    }
				if(v[i] + v[j] > v[k] and v[i] + v[k] > v[j] and v[j] + v[k] > v[i]){
					printf("YES"); return 0;
				}
			}
		}
	printf("NO");
	return 0;
}
