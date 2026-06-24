class myQueue {
    int *a,f=0,r=-1,s=0,c;
public:
    myQueue(int n){
        c=n;
        a=new int[n];
    }

    bool isEmpty(){ return !s; }
    bool isFull(){ return s==c; }

    void enqueue(int x){
        if(isFull()) return;
        a[r=(r+1)%c]=x;
        s++;
    }

    void dequeue(){
        if(isEmpty()) return;
        f=(f+1)%c;
        s--;
    }

    int getFront(){ return isEmpty()?-1:a[f]; }
    int getRear(){ return isEmpty()?-1:a[r]; }
};