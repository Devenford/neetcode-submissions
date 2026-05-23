class Deque {
private:
    struct node{
        int val;
        node *next, *prev;
        
        node(int value) {
            val = value;
            next = nullptr;
            prev = nullptr;
        }
    } *head, *tail;
public:
    Deque() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return tail==nullptr;
    }

    void append(int value) {
        node *temp = new node(value);

        if(tail==nullptr) {
            tail = temp;
            head = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void appendleft(int value) {
        node *temp = new node(value);
        if(head==nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    int pop() {
        if (tail==nullptr) {
            return -1;
        }
        else {
            int val = tail->val;
            node *temp = tail;
            tail = tail->prev;
            if(tail==nullptr) {
                head = nullptr;
            }
            else {
                tail->next = nullptr;
            }
            delete temp;
            return val;
        }
    }

    int popleft() {
        if (head==nullptr) {
            return -1;
        }
        else {
            int val = head->val;
            node *temp = head;
            head = head->next;
            if(head==nullptr) {
                tail = nullptr;
            }
            else {
                head->prev = nullptr;
            }
            delete temp;
            return val;
        }
    }
};
