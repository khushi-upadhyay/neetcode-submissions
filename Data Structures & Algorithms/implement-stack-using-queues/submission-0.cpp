class MyStack {
private:
    queue<int> q, qu;

public:
    MyStack() {
    }

    void push(int x) {
        qu.push(x);

        // Move all existing elements behind x
        while (!q.empty()) {
            qu.push(q.front());
            q.pop();
        }

        swap(q, qu);
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// Dry Run:
// push(1): qu = [1] → swap → q = [1], qu = []
// push(2): qu = [2]
//           move 1 → qu = [2,1], q = []
//           swap → q = [2,1], qu = []
// push(3): qu = [3]
//           move 2,1 → qu = [3,2,1], q = []
//           swap → q = [3,2,1], qu = []
// top() → 3
// pop() → remove 3 → q = [2,1]
// pop() → remove 2 → q = [1]