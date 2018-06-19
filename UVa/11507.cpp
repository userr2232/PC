#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void T(vector<int> &v, char sign, char dir){
    vector<int> vprime = v;
    if(dir == 'z'){
        swap(v[0],v[2]);
    }
    else{
        swap(v[0],v[1]);
    }
    if(vprime != v){
        if(sign == '-'){
            v[1] *= -1;
            v[2] *= -1;
            return;
        }
        v[0] *= -1;
        return;
    }
}

int main(){
    int n;
    string str;
    while(scanf("%d", &n), n){
        cin.get();
        getline(cin, str);
        vector<int> x = {1,0,0};
        for(int i  = 0; i < n-1; i++){
            if(str[i*3] != 'N') T(x, str[i*3], str[i*3+1]);
        }
        vector<char> ans = {'x','y','z'};
        for(int i = 0; i < 3; i++){
            if(x[i] != 0){
                if(x[i] > 0){
                    printf("+%c\n",ans[i]);
                    break;
                }
                printf("-%c\n",ans[i]);
                break;
            }
        }
    }
    return 0;
}
