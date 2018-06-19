#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    while(scanf("%d%d", &m,&n), m || n){
        if(m >= 3 && n >= 3)
            printf("%d knights may be placed on a %d row %d column board.\n", (m*n+1)/2, m,n);
        else{
            if(m >= 2 && n >= 2){
                printf("%d knights may be placed on a %d row %d column board.\n", 2*(((max(m,n)+3)/4)+((max(m,n)-1+3)/4)),m,n);
            }
            else if(m >= 1 && n >= 1){
                printf("%d knights may be placed on a %d row %d column board.\n", max(m,n),m,n);
            }
            else{
                printf("%d knights may be placed on a %d row %d column board.\n", 0,m,n);
            }
        }
    }

    return 0;
}
