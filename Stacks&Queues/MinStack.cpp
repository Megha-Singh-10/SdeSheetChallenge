155. Min Stack
/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function. */

TC->O(1)
SC->O(2N)

class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
            s.push({val,val});
        else
            s.push({val,min(val,s.top().second)});
    }
    
    void pop() {
         if(!s.empty())
         {      
             s.pop();
         }   
    }
    
    int top() {
        if(!s.empty())
            return s.top().first;
        else
            return -1;
    }
    
    int getMin() {
        if(!s.empty())
            return s.top().second;
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 b) TC->O(1)
    SC->O(2N)

    class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {        
        // vector<int> s;
        // int top=-1;
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty() || val<=getMin())
            mins.push(val);
        // s[++top]=val;
    }
    
    void pop() {
        if(s.top()==getMin())
            mins.pop();
        s.pop();
        // top--;
    }
    
    int top() {
        return s.top();
        // return s[top];
    }
    
    int getMin() {
        return mins.top();
    }
};