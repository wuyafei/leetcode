class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        int rt;
        if(q1.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            rt=q2.front();
            q1.push(rt);
            q2.pop();
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            rt=q1.front();
            q2.push(rt);
            q1.pop();
        }
        return rt;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};