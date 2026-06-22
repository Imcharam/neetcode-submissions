class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) :  val(val), next(next) {}
    };
public:
    ListNode* head;
    ListNode* tail;
    int size;
    MyLinkedList() {
        head = new ListNode();
        tail = head;
        size = 0;
    }
    
    int get(int index) {
        if (index > size - 1) {
            return -1;
        } else {
            ListNode* curr = head->next;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            return curr->val;
        }
    }
    
    void addAtHead(int val) {
        ListNode * newHead = new ListNode(val);
        newHead->next = head->next;
        head->next = newHead;
        size++;
        if (size == 1) {
            tail = newHead;
        }
    }
    
    void addAtTail(int val) {
        ListNode * newTail = new ListNode(val);
        tail->next = newTail;
        tail = tail->next;
        size++;
        if (size == 1) {
            head->next = tail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
        } else if (index == size) {
            addAtTail(val);
        } else {
            ListNode* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }

            ListNode * insert = new ListNode(val);
            insert->next = curr->next;
            curr->next = insert;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {

        } else {
            ListNode* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            ListNode* temp = curr->next;
            curr->next = temp->next;
            if (index == size-1) {
                tail = curr;
            }
            delete temp;
            size--;
        }
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