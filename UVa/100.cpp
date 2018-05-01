#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int returnLength(int x){
    int c= 1;
    while(x!=1){
        c++;
        if(x%2==0){
            x /= 2;
            continue;
        }
        x = 3*x+1;
    }
    return c;
}

vector<pair<int,int> > v(1000005);

int main(){

    int a,b,maxlength;
    while(scanf("%d%d",&a,&b)!= EOF){
        maxlength = 0;
        for(int i = min(a,b); i <= max(a,b);i++){
            if(v[i].first == 0){
                v[i].first = i;
                v[i].second = returnLength(i);
            }
            maxlength = max(maxlength,v[i].second);
        }
        printf("%d %d %d\n",a,b,maxlength);
    }
    return 0;
}
