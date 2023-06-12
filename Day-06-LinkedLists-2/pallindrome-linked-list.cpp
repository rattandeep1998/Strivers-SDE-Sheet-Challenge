LinkedListNode<int> * getMidModified(LinkedListNode<int> *head) {
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

pair<LinkedListNode<int> *, LinkedListNode<int> *> reverseLL(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL) {
        return make_pair(head,head);
    }

    pair<LinkedListNode<int> *, LinkedListNode<int> *> reversedLL = reverseLL(head->next);

    reversedLL.second -> next = head;
    head->next = NULL;

    reversedLL.second = reversedLL.second -> next;

    return reversedLL;
}

bool compareLL(LinkedListNode<int> *first, LinkedListNode<int> *second) {
    while(first!=NULL && second!=NULL) {
        if(first->data != second->data) {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL) {
        return true;
    }

    LinkedListNode<int> *mid = getMidModified(head);

    LinkedListNode<int> *temp = mid->next;
    mid->next = NULL;

    LinkedListNode<int> *reversedHalfHead = reverseLL(temp).first;

    return compareLL(head, reversedHalfHead);
}