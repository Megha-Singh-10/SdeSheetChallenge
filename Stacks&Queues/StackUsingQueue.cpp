225. Implement Stack using Queues
/* Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.*/

TC->O(2N)
SC->O(2N)

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {       
    }
    
    void push(int x) {
        q2.push(x);
         while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }        
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        // while(!q1.empty())
        // {
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // q1.push(x);
        // while(!q2.empty())
        // {
        //     q1.push(q2.front());
        //     q2.pop();
        // }
    }
    
    int pop() {
        int res=q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 b) Using Only one queue
 TC->O(2N)
 SC->O(N)

 class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size=q.size()-1;
        while(size>0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    int pop() {
         int res=q.front();
         q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */