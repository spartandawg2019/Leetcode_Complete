class MinStack {
    private:
        stack<int> data;               // store elements
        stack<int> min_data;           // store the minimum elements
    public:
        /** Insert an element into the stack. */
        void push(int x) {
            data.push(x);
            if (min_data.empty() || min_data.top() >= x) {
                min_data.push(x);
            }
        }
        /** Checks whether the stack is empty or not. */
        bool isEmpty() {
            return data.empty();
        }
        /** Get the top item from the stack. */
        int top() {
            return data.top();
        }
        /** Delete an element from the stack. Return true if the operation is successful. */
        void pop() {
            if (data.top() == min_data.top()) {
                min_data.pop();
            }
            data.pop();
        }
        /** Get the minimum element from the stack. */
        int getMin() {
            return min_data.top();
        }
};