#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    char tmp[3];
    int TC;
    scanf("%d", &TC);
    int cardVal = 0, Y;
    for(int k = 0; k < TC; k++){
        Y = 0;
        vector<char> cards(52*2);
        vector<char> hand;
        for(int i = 0; i < 52; i++){
            if(scanf("%s", tmp) != 1){
                return 0;
            }
            for(int j = 0; j < 2; j++){
                cards[2*i+j] = tmp[j];
            }
        }
        hand.insert(hand.end(), cards.end()-25*2, cards.end());
        cards.erase(cards.end()-25*2, cards.end());
        for(int i = 0; i < 3; i++){
            char card;
            card = cards[cards.size()-2];
            cards.erase(cards.end()-1*2, cards.end());
            if(card - 48 >= 2 && card - 48 <= 9){
                cardVal = card - 48;
            }
            else{
                cardVal = 10;
            }
            Y += cardVal;
            cards.erase(cards.end()-(10-cardVal)*2, cards.end());
        }
        cards.insert(cards.end(), hand.begin(), hand.end());
        printf("Case %d: %c%c\n", k+1, cards[(Y-1)*2], cards[(Y-1)*2+1]);
    }
    return 0;
}
