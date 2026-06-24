class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        
        ListNode() : val(0), next(nullptr), prev(nullptr) {}
        ListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
        ListNode(int val, ListNode* next, ListNode* prev) : val(val), next(next), prev(prev) {}
    };
public:
    ListNode* head;
    ListNode* tail;
    int size;

    MyLinkedList() {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        ListNode* curr;
        if (index >= size) {
            return -1;
        } else if (index * 2 > size) {
            curr = tail->prev;
            for (int i = size - 1; i > index; --i) {
                curr = curr->prev;
            }
        } else {
            curr = head->next;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* temp = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
        newNode->prev = temp;
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* curr;
        if (index > size) {
            return;
        } else if (index == size) {
            addAtTail(val);
            return;
        } else if (index == 0) {
            addAtHead(val);
            return;
        }else if (index * 2 > size) {
            curr = tail->prev;
            for (int i = size - 1; i > index; --i) {
                curr = curr->prev;
            }
        } else {
            curr = head->next;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        }
        ListNode* temp = curr->prev;
        ListNode* newNode = new ListNode(val);
        curr->prev = newNode;
        newNode->next = curr;
        newNode->prev = temp;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        ListNode* curr = head->next;
        if (index >= size) {
            return;
        } else if (index == size-1) {
            curr = tail->prev;
            ListNode* temp = curr->prev;
            tail->prev = temp;
            temp->next = tail;
        } else if (index == 0) {
            curr = head->next;
            ListNode* temp = curr->next;
            head->next = temp;
            temp->prev = head;
        }else if (index * 2 > size) {
            curr = tail->prev;
            for (int i = size - 1; i > index; --i) {
                curr = curr->prev;
            }
        } else {
            curr = head->next;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        }
        ListNode* before = curr->prev;
        ListNode* after = curr->next;
        before->next = after;
        after->prev = before;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */