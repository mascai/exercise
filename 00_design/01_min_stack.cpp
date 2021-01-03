/* https://leetcode.com/explore/featured/card/top-interview-questions-easy/98/design/562/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (not data_.empty()) {
            curMin_.push_back(min(curMin_.back(), x));
        } else {
            curMin_.push_back(x);
        }
        data_.push_back(x);
    }
    
    void pop() {
        data_.pop_back();
        curMin_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        return curMin_.back();
    }
private:
    vector<int> data_;
    vector<int> curMin_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
