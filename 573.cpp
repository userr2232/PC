#include <iostream>
#include <cmath>
using namespace std;

void climb(int H, double U, int D, int F){
    double h = 0;
    int d = 1;
    double cap = U;
    while(h <= H && h >= 0){
        if(cap>0){
            h += cap;
            if(h > H){
                printf("success on day %d\n",d);
                return;
            }
        }
        h -= D;
        if(h < 0){
            printf("failure on day %d\n", d);
            return;
        }
        cap -= F*U/100.0;
        d++;
    }
}

int main() {
    int H,D,F;
    double U;
	while(scanf("%d%lf%d%d",&H,&U,&D,&F),H){
	    climb(H,U,D,F);
	}
	return 0;
}
