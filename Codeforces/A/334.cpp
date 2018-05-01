#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n*n/2; i++){
        if((i-1)%(n/2)==0){
            printf("\n");
        }
        printf("%d %d ", i,n*n+1-i);
    }
}
