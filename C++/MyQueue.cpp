#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    std::stack<int> queue;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        queue = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        queue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = queue.top();
        queue.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return queue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue.empty();
    }
};