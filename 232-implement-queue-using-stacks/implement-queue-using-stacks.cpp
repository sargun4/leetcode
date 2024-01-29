 // Time complexity:
// Enqueue (push): O(n)O(n)O(n)
// Dequeue (pop): O(1)O(1)O(1)
// Peek (peek): O(1)O(1)O(1)
// Empty Check (empty): O(1)O(1)O(1)

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {} 
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};
 
// Initialization: 
// We have two stacks, s1 and s2, where s1 acts as the primary stack for enqueue operations, and s2 helps in reversing the order of elements for efficient dequeuing.
// Enqueue Operation (Push):

// When a new element is pushed into the queue (push operation):
// All elements from s1 are popped and pushed onto s2. This effectively reverses the order of elements.
// The new element is pushed onto the now-empty s1.
// Finally, elements are popped from s2 and pushed back onto s1 to maintain the original order.
// Dequeue Operation (Pop):

// When an element is dequeued (pop operation):
// The top element from s1 is directly popped.
// Peek Operation:

// The top element of s1 is returned for the peek operation.
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */