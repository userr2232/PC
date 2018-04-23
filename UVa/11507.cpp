#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int L, anglexy, anglez;
    string seq;
    while(scanf("%d",&L),L){
        anglexy = 0; anglez = 0;
        cin.get();
        getline(cin,seq);
        for(int i = 0; i < seq.size(); i+=3){
            cout << seq[i] << seq[i+1];
            if(seq[i] == 'N') continue;
            if(seq[i+1] == 'y'){
                if(seq[i] == '+'){
                    anglexy += 90;
                    continue;
                }
                anglexy += 270;
                continue;
            }
            if(seq[i] == '+'){
                anglez += 90;
                continue;
            }
            anglez += 270;
            continue;
        }
        anglez = anglez%360;
        anglexy = anglexy%360;
        if(anglez != 0 && anglez != 180){
            if(anglez == 90){
                printf("+z\n");
                continue;
            }
            printf("-z\n");
            continue;
        }
        if(anglexy == 0){
            printf("+x\n");
            continue;
        }
        if(anglexy == 90){
            printf("+y\n");
            continue;
        }
        if(anglexy == 180){
            printf("-x\n");
            continue;
        }
        printf("-y\n");
    }

    return 0;
}
