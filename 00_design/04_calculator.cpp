/*
https://leetcode.com/problems/basic-calculator/submissions/

*/


class Solution {
public:
    int priority(char op){
        if(op == '+'||op == '-')
        return 1;
        if(op == '*'||op == '/')
        return 2;
        return 0;
    }

    // Function to perform arithmetic operations.
    int applyOp(int a, int b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return -1; // error
    }
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        
        for (int i = 0; i < s.size(); ++i) {
            if (isspace(s[i])) {
                continue;
            }
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() and isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                vals.push(num);
            } else if (s[i] == '(') {
                ops.push(s[i]);
            } else if (s[i] == ')') {
                while (not ops.empty() and ops.top() != '(') {
                    int val1 = vals.top();
                    vals.pop();
                    
                    int val2 = vals.top();
                    vals.pop();
                    
                    vals.push(applyOp(val2, val1, ops.top()));
                    ops.pop();
                }
                if (not ops.empty()) {
                    ops.pop();   
                }
            }
            else { // operation
                while (not ops.empty() and priority(ops.top()) >= priority(s[i])) {
                    int val1 = vals.top();
                    vals.pop();

                    int val2 = vals.top();
                    vals.pop();

                    vals.push(applyOp(val2, val1, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        // process final stack
        while (not ops.empty()) {
            int val1 = vals.top();
            vals.pop();
                    
            int val2 = vals.top();
            vals.pop();
                    
            vals.push(applyOp(val2, val1, ops.top()));
            ops.pop();
        }
        return vals.top();
    }
};



// Solution 2
int calculate(string s) 
{
    int i = 0;
    return f(s, i);
}

int f(string s, int &i)
{
    long long val = 0, res = 0;
    int sign = 1;

    while (i < s.size() && s[i] != ')')
    {
        if (isspace(s[i]))
            i++;
        else if (isdigit(s[i]))
        {
            val = 0;
            while (i < s.size() && isdigit(s[i]))
                val = val * 10 + s[i++] - '0';

            res += val * sign;
        }
        else if (s[i] == '+' || s[i] == '-')
            sign = (s[i++] == '+') ? 1 : -1;
        else if (s[i] == '(')
        {
            i++;  // Move past '('
            int temp = f(s, i);
            i++;  // Move past ')'

            res += temp * sign;
        }
    }

    return res;
}
