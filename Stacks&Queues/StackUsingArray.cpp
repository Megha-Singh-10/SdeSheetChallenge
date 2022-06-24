(Coding Ninja) Stack Implementation Using Array
/*
Problem Statement
Stack is a data structure that follows the LIFO (Last in First out) principle. Design and implement a stack to implement the following functions:
1. Push(num): Push the given number in the stack if the stack is not full.
2. Pop: Remove and print the top element from the stack if present, else print -1.
3. Top: Print the top element of the stack if present, else print -1.
4. isEmpty: Print 1 if the stack is empty, else print 0.
5. isFull: Print 1 if the stack is full, else print 0.
You have been given ‘M’ operations which you need to perform in the stack. Your task is to implement all the functions of the stack.*/

TC->O(N)
SC->O(N)

// Stack class.
class Stack {
    int *s;
    int tops;
    int size;
public:
    Stack(int capacity) {
        // Write your code here.
        tops=-1;
        s=new int[capacity];
        size=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(!isFull())
        {
            tops++;
            s[tops]=num;
        }   
       
    }

    int pop() {
        // Write your code here.
        if(!isEmpty())
        return s[tops--];
        else
        {   
        return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(!isEmpty())
        return s[tops];
        else
        {
           
            return -1;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(tops==-1)
            return 1;
        else
            return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(tops==size-1)
            return 1;
        else
            return 0;
    }
    
};