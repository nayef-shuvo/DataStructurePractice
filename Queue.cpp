///Implementation of Queue, using C++

#include <iostream>

using namespace std;

template <typename Type>
class Queue {
    int MAX_SIZE = 1e6;
    int last = -1;
    Type *arr = new Type[MAX_SIZE];
public:
    void push(Type val) {
        ++last;
        arr[last] = val;
    }
    void pop() {
        --last;
        for (int i = 0; i <= last; ++i) {
            arr[i] = arr[i+1];
        }
    }
    Type front() {
        return arr[0];
    }
    int size() {
        return last+1;
    }
    bool empty() {
        if (last == -1) return true;
        return false;
    }
};

int main() {
    Queue <int> Q;
    Q.push(10);
    Q.push(12);
    Q.push(6);
    Q.push(8);
    Q.push(11);
    cout << "Size is: " << Q.size() << "\n";
    cout << "Elements are:\n";
    while (!Q.empty()) {
        cout << Q.front() << endl;
        Q.pop();
    }
}

