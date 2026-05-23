class LinkedList {

private:
    struct node {
        int data;
        node *next;
    } *head;
    
public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        node *temp = head;
        if(temp==nullptr) {
            return -1;
        }

        for(int i=0; i<index; i++) {
            temp = temp->next;
            if(temp==nullptr) {
                return -1;
            }
        }
        return temp->data;
    }

    void insertHead(int val) {
        if (head == nullptr) {
            head  = new node;
            head->data = val;
            head->next = nullptr;
        }
        else {
            node *temp = new node;
            temp->data = val;
            temp->next = head;
            head = temp;
        }
    }
    
    void insertTail(int val) {
        if(head==nullptr) {
            head  = new node;
            head->data = val;
            head->next = nullptr;
        }
        else {
            node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new node;
            temp = temp->next;
            temp->data = val;
            temp->next = nullptr;
        }
    }

    bool remove(int index) {
        node *before, *temp = head;
        
        if(temp==nullptr) {
            return false;
        }

        if(index==0) {
            head = head->next;
            delete temp;
            return true;
        }

        for(int i=0; i<index; i++) {
            before = temp;
            temp = temp->next;
            if(temp==nullptr) {
                return false;
            }
        }
        
        before->next = temp->next;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        node *temp = head;
        while(temp!=nullptr) {
            values.push_back(temp->data);
            temp = temp->next;
        }
        return values;
    }

    ~LinkedList() {
        node *temp = head;
        while(temp!=nullptr) {
            head = temp->next;
            delete temp;
            temp = head;
        }
    }
};
