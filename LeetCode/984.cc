class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int a_counter{0}, b_counter{0};
        string str;
        while(a > 0 || b > 0) {
            if(a_counter < 2 && b_counter < 2) {
                if(a > b) {
                    str += 'a', a--;
                    a_counter++;
                    b_counter = 0;
                }
                else {
                    str += 'b', b--;
                    b_counter++;
                    a_counter = 0;
                }
            }
            else if(a_counter < 2) {
                str += 'a', a--;
                a_counter++;
                b_counter = 0;
            }
            else {
               str += 'b', b--;
                b_counter++;
                a_counter = 0; 
            }
        }
        return str;
    }
};