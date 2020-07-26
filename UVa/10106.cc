#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(string A, string B) {
    if(A.length() < B.length()) swap(A, B);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string res = "";
    int carry = 0;
    for(int i = 0; i < B.length(); ++i) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int s = a + b;
        if(carry) { 
            s++;
            carry--;
        }
        carry += s/10;
        res += to_string(s % 10);
    }
    for(int i = B.length(); i < A.length(); ++i) {
        int a = A[i] - '0';
        int s = 0;
        if(carry) {
            s = a + 1;
            carry--;
            carry += s / 10;
        }
        else s = a;
        res += to_string(s % 10);
    }
    if(carry) res += "1";
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string A, string B) {
    if(A == "0" || B == "0") return "0";
    string res = "0";
    for(int i = A.size() - 1; i >= 0; --i) {
        string op = "";
        int a = A[i] - '0';
        int carry = 0;
        for(int j = B.size() - 1; j >= 0; --j) {
            int b = B[j] -'0';
            int mult = a * b;
            if(carry) {
                    mult += carry;
                    carry = 0;
            }
            op += to_string(mult % 10);
            carry += mult / 10;
        }
        if(carry) op += to_string(carry);
        reverse(op.begin(), op.end());
        op += string(A.size() - 1 - i, '0');
        res = sum(res, op);
    }
    return res;
}

int main() {
    string A, B;
    while(cin >> A && cin >> B)
        cout << multiply(A, B) << endl;

    return 0;
}