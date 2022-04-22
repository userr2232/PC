class Solution {
    /*
    ~zero
    ~~~~~~~one
    ~two
    ~~~~~three
    ~~~~four
    ~~~five
    ~six
    ~~seven
    ~eight
    ~~~~~~nine
    */
    
    void erase(string&& str, unordered_map<char,int>& char_count, int times) {
        for(auto&& c : str)
            char_count[c] -= times;
    }
    
    string build(int digit, unordered_map<char,int>& char_count) {
        string ans;
        int count{0};
        switch(digit) {
            case 0:
                count = char_count['z'];
                erase("zero", char_count, count);
                ans += string(count, '0');
                break;
            case 2:
                count = char_count['w'];
                erase("two", char_count, count);
                ans += string(count, '2');
                break;
            case 6:
                count = char_count['x'];
                erase("six", char_count, count);
                ans += string(count, '6');
                break;
            case 8:
                count = char_count['g'];
                erase("eight", char_count, count);
                ans += string(count, '8');
                break;
            case 7:
                count = char_count['s'];
                erase("seven", char_count, count);
                ans += string(count, '7');
                break;
            case 5:
                count = char_count['v'];
                erase("five", char_count, count);
                ans += string(count, '5');
                break;
            case 4:
                count = char_count['f'];
                erase("four", char_count, count);
                ans += string(count, '4');
                break;
            case 3:
                count = char_count['r'];
                erase("three", char_count, count);
                ans += string(count, '3');
                break;
            case 9:
                count = char_count['i'];
                erase("nine", char_count, count);
                ans += string(count, '9');
                break;
            case 1:
                count = char_count['n'];
                erase("one", char_count, count);
                ans += string(count, '1');
                break;
            default:
                cout << "WHAT!?" << endl;
                break;
        }
        return ans;
    }
    
public:
    string originalDigits(string s) {
        unordered_map<char,int> char_count;
        for(auto&& c : s) char_count[c]++;
        vector<int> digits = {0, 2, 6, 8, 7, 5, 4, 3, 9, 1};
        string ans;
        for(auto&& digit : digits) ans += build(digit, char_count);
        sort(ans.begin(), ans.end());
        return ans;
    }
};