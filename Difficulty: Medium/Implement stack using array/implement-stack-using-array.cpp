class myStack {
  public:
  int *arr;
  int top;
  int size;
    myStack(int n) {
        // Define Data Structures
     arr = new int[n];
     top = -1;
     size = n;
    }

    bool isEmpty() {
        return top==-1;
        // check if the stack is empty
    }

    bool isFull() {
        return top == size-1;
        // check if the stack is full
    }

    void push(int x) {
        if(isFull())
        return;
        top++;
        arr[top]= x;
        // inserts x at the top of the stack
    }

    void pop() {
        if(isEmpty())
        return;
        top--;
        // removes an element from the top of the stack
    }

    int peek() {
        if(isEmpty())
        return -1;
        return arr[top];
        // Returns the top element of the stack
    }
};