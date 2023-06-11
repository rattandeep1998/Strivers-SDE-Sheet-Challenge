pair<LinkedListNode<int> *, LinkedListNode<int> *> reverseLinkedListHelper(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL) {
        return make_pair(head, head);
    }

    pair<LinkedListNode<int> *, LinkedListNode<int> *> reversedLL = reverseLinkedListHelper(head->next);

    reversedLL.second -> next = head;

    head->next = NULL; 

    return make_pair(reversedLL.first, head);
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head->next == NULL) {
        return head;
    }

    return reverseLinkedListHelper(head).first;
}