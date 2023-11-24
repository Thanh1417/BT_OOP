#include <bits/stdc++.h>
using namespace std;

class Calculator {
    private:
        bool is_digit(char c) {
            return c >= '0' && c <= '9';
        }

        bool is_operator(char c) {
            return c == '+' || c == '-' || c == '*';
        }

        bool is_function(string s) {
            return s == "abs";
        }

        int uu_tien(char op) {
            if (op == '+' || op == '-') {
                return 1;
            }
            if (op == '*') {
                return 2;
            }
            return 0;
        }

        int them_dau(char op, int a, int b) {
            switch (op) {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
            }
            return 0;
        }

    public:
        int evaluate(string s) {
            int n = s.length();
            stack<int> toan_hang;
            stack<char> toan_tu;

            for (int i = 0; i < n; i++) {
                if (is_digit(s[i])) {
                    int num = 0;
                    while (i < n && is_digit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }
                    i--;
                    toan_hang.push(num);
                } else if (s[i] == '(') {
                    toan_tu.push(s[i]);
                } else if (is_operator(s[i])) {
                    while (!toan_tu.empty() && uu_tien(toan_tu.top()) >= uu_tien(s[i])) {
                        char op = toan_tu.top();
                        toan_tu.pop();
                        int b = toan_hang.top();
                        toan_hang.pop();
                        int a = toan_hang.top();
                        toan_hang.pop();
                        toan_hang.push(them_dau(op, a, b));
                    }
                    toan_tu.push(s[i]);
                } else if (s[i] == ')') {
                    while (!toan_tu.empty() && toan_tu.top() != '(') {
                        char op = toan_tu.top();
                        toan_tu.pop();
                        int b = toan_hang.top();
                        toan_hang.pop();
                        int a = toan_hang.top();
                        toan_hang.pop();
                        toan_hang.push(them_dau(op, a, b));
                    }
                    if (!toan_tu.empty()) {
                        toan_tu.pop();
                    }
                } else if (is_function(s.substr(i, 3))) {
                    i += 2;
                    int num = toan_hang.top();
                    toan_hang.pop();
                    toan_hang.push(abs(num));
                }
            }

            while (!toan_tu.empty()) {
                char op = toan_tu.top();
                toan_tu.pop();
                int b = toan_hang.top();
                toan_hang.pop();
                int a = toan_hang.top();
                toan_hang.pop();
                toan_hang.push(them_dau(op, a, b));
            }

            return toan_hang.top();
        }
};

int main() {
    string s;
    cin >> s;
    Calculator c;
    cout << c.evaluate(s) << endl;
    return 0;
}