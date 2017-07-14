/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(A[i] == "+"){
                st.push(second+first);
            }
            else if(A[i] == "-"){
                st.push(second-first);
            }
            else if(A[i] == "*"){
                st.push(second*first);
            }
            else{
                st.push(second/first);
            }
        }
        else{
            st.push(atoi(A[i].c_str()));
        }
    }
    
    return st.top();
       
}
