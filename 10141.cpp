#include <iostream>
#include <cstdio>
#include <cfloat>

using namespace std;

int main(){

    int n,p,reqMet,s,count=0;
    string trash,name;
    double tmp,price;
    while(scanf("%d%d",&n,&p), n||p){
        count++;
        cin.get();
        while(n--){
            getline(cin,trash);
        }
        reqMet = 0; price = DBL_MAX;
        while(p--){
            getline(cin,trash);
            scanf("%lf%d",&tmp,&s);
            cin.get();
            if(s >= reqMet){
                if(s > reqMet){
                    name = trash;
                    reqMet = s;
                    price = tmp;
                }
                else if(price > tmp){
                    name = trash;
                    reqMet = s;
                    price = tmp;
                }
            }
            while(s--){
                getline(cin,trash);
            }
        }
        if(count > 1)cout << endl;
        cout << "RFP #" << count << endl;
        cout << name << endl;
    }
    return 0;
}
