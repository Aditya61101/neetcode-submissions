class DLL {
public:
    int val;
    DLL* prev,*next;
    DLL(int x):val(x), prev(nullptr), next(nullptr) {}
};

class MyCircularQueue {
    int sz,n;
    DLL* head, *tail;
public:
    MyCircularQueue(int k) {
        sz=k; n=0;
        head=tail=nullptr;
    }
    
    bool enQueue(int value) {
        if(sz==n) return false;
        DLL* node = new DLL(value);
        node->prev=tail;
        node->next=head;
        if(head) head->prev=node;
        if(tail) tail->next=node;
        tail=node;
        if(!head) head=node;
        n+=1;
        return true;

    }
    
    bool deQueue() {
        if(n==0) return false;
        DLL* temp = head;
        if(n==1) {
            head=tail=nullptr;
        } else {
            head = head->next;
            head->prev=tail;
            tail->next=head;
        }
        delete temp;
        n-=1;
        return true;
    }
    
    int Front() {
        if(n==0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(n==0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return n==0;
    }
    
    bool isFull() {
        return n==sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */