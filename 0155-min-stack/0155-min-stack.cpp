class MinStack {
public:
    vector<int> mainStack;
    vector<int> minStack;

    MinStack() {
        // Constructor initializes empty stacks
    }

    void push(int val) {
        // Push the value into the main stack
        mainStack.push_back(val);

        // Push min into min stack: either val or the current minimum
        if (minStack.empty() or val <= minStack.back()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(minStack.back());
        }
    }

    void pop() {
        // Pop from both stacks if not empty
        if (!mainStack.empty()) {
            mainStack.pop_back();
            minStack.pop_back();
        }
    }

    int top() {
        return mainStack.back();
    }

    int getMin() {
        return minStack.back();
    }
};