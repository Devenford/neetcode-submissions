#include<vector>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;

        for(int i=0; i<tokens.size(); i++) {
            string ele = tokens[i];
            if (isdigit(ele[ele.size()-1])) {
                s.push(ele);
            }
            else {
                int op1 = stoi(s.top());
                s.pop();
                int op2 = stoi(s.top());
                s.pop();
                if (ele == "+") {
                    s.push(to_string(op2 + op1));
                }
                else if (ele == "-") {
                    s.push(to_string(op2 - op1));
                }
                else if (ele == "*") {
                    s.push(to_string(op2 * op1));
                }
                else{
                    s.push(to_string(op2 / op1));
                }
            }
        }
        return stoi(s.top());
    }
};
