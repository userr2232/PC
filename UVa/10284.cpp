#include <sstream>
#include <utility>
#include <cctype>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int isint(char x){ return (x >= 49 && x <= 57) ? x - 48 : 0;}

void fill(string t, map<char,int>& p, vector<bool>& b, vector<bool>& o){
    char x; int lmt;
    stringstream ss(t);
    for(int i = 0; i < 64; i++){
        ss >> x;
        if(x == '/'){--i; continue;}
        lmt = isint(x);
        if(!lmt){
        	p.insert(pair<char,int>(x,i)), o.push_back(i);
        }
        else{
            for(int j = 0; j < lmt; j++){
            	b[i] = true; i++;
            }
            --i;
        }
    }
}

int process(map<char,int>& p, vector<bool>& b, vector<bool>& o){
    int count = 0;
    for(map<char,int>::iterator it = p.begin(); it != p.end(); it++){
        char piece = tolower(it->first);
        int pos = it->second;
        int rowNum = pos/8; int rowRange[] = {rowNum*8, rowNum*9};
        bool black = (piece == it->first) ? false : true;
        switch(piece){
            int dx, dy, newpos_x, newpos_y;
            case 'r':
                for(int i = pos+1; i < rowRange[1] && !o[i]; i++){b[i] = false;}
                for(int i = pos-1; i >= rowRange[0] && !o[i]; i--){b[i] = false;}
                for(int i = pos-8; i >= 0 && !o[i]; i-=8){b[i] = false;}
                for(int i = pos+8; i < 64 && !o[i]; i+=8){b[i] = false;}
                break;
            case 'n':
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        for(int k = 0; k < 2; k++){
                            if(k){
                                dx = pow(-1,j);
                                dy = pow(-1,i)*2*8;
                                newpos_x = pos + dx;
                                newpos_y = pos + dy;
                                if(newpos_x < rowRange[1] && newpos_x >= rowRange[1] && newpos_y >= 0 && newpos_y < 64 && !o[pos+dx+dy]) b[pos+dx+dy] = false;
                            }
                            else{
                                dx = pow(-1,j)*2;
                                dy = pow(-1,i)*8;
                                newpos_x = pos + dx;
                                newpos_y = pos + dy;
                                if(newpos_x < rowRange[1] && newpos_x >= rowRange[1] && newpos_y >= 0 && newpos_y < 64 && !o[pos+dx+dy]) b[pos+dx+dy] = false;
                            }
                        }
                    }
                }
                break;
            case 'b':
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        dx = pow(-1,j);
                        dy = pow(-1,j)*8;
                        for(int k = 1; k < 8 && !o[pos+dx+dy] && pos + dx+dy*k < 64 && pos + dx +dy*k >= 0; k++){b[pos+dx+dy] = false;}
                    }
                }
                break;
            case 'q':
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        dx = pow(-1,j)*8;
                        dy = pow(-1,j)*8;
                        for(int k = 1; k < 8 && !o[pos+dx+dy] && pos + dx*k < 64 && pos + dx*k >= 0; k++){b[pos+dx+dy] = false;}
                    }
                }
                for(int i = pos+1; i < rowRange[1] && !o[i]; i++){b[i] = false;}
                for(int i = pos-1; i >= rowRange[0] && !o[i]; i--){b[i] = false;}
                for(int i = pos-8; i >= 0 && !o[i]; i-=8){b[i] = false;}
                for(int i = pos+8; i < 64 && !o[i]; i+=8){b[i] = false;}
                break;
            case 'k':
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        for(int k = 0; k < 2; k++){
                            dx = pow(-1,i)*k;
                            dy = pow(-1,j)*8*(1-k);
                            if(pos+dx+dy < 64 && pos+dx+dy >= 0 && !o[pos+dx+dy]){b[pos+dx+dy] = false;}
                        }
                    }
                }
                break;
            default: //p
                for(int i = 0; i < 2; i++){
                    dx = pow(-1,i);
                    dy = pow(-1,(black) ? 1 : 0)*8;
                    if(pos+dx+dy < 64 && pos+dx+dy >= 0 && !o[pos+dx+dy]){b[pos+dx+dy] = false;}
                }
                break;
        }
    }
    for(int i = 0; i < 64; i++){
        if(b[i]) count ++;
    }
    return count;
}

int main(){
    string tmp;
    while(!getline(cin,tmp).eof()){
        vector<bool> board(64,false);
        map<char,int> pieces;
        vector<bool> occupied;
        fill(tmp, pieces, board, occupied);
        printf("%d\n", process(pieces, board, occupied));
    }
    return 0;
}
