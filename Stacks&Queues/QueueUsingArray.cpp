(Coding Ninja)Implement a Queue
/* Problem Statement
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.
You need to implement the following public functions :
1. Constructor: It initializes the data members as required.

2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.

3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.*/

TC->O(N)
SC->O(N) 

class Queue {
public:
    int size,qfront,back,qsize;
    int *q;
    Queue() {
        // Implement the Constructor
        size=0;
        qfront=0;
        back=0;
        qsize=100010;
        q=new int[qsize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==back)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(size!=qsize)
        {
            q[back++]=data;
            size++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
            return -1;
        else
        {
            int res=q[qfront];
            qfront++;
            size--;
            return res;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
            return -1;
        else
            return q[qfront];
    }
};

/* CIRCULAR QUEUE*/
TC->O(N)
SC->O(N) //Comparatively less, depending on scenario

class Queue {
public:
    int size,qfront,back,qsize;
    int *q;
    Queue() {
        // Implement the Constructor
        size=0;
        qfront=0;
        back=0;
        qsize=10010;
        q=new int[qsize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==back)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(size!=qsize)
        {
            q[back]=data;
            back=(back+1)%qsize;
            size++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
            return -1;
        else
        {
            int res=q[qfront];
            qfront=(qfront+1)%qsize;
            size--;
            return res;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
            return -1;
        else
            return q[qfront];
    }
};
