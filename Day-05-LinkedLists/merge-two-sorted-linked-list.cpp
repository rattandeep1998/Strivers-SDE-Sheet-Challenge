Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *sortedLLHead = NULL;
    Node<int> *sortedLLTail = NULL;

    while(first != NULL && second != NULL) {
        if(first->data < second->data) {
            if(sortedLLTail == NULL) {
                sortedLLHead = first;
                sortedLLTail = first;
            } else {
                sortedLLTail -> next = first;
                sortedLLTail = first;
            }
            first = first->next;
        } else {
            if(sortedLLTail == NULL) {
                sortedLLHead = second;
                sortedLLTail = second;
            } else {
                sortedLLTail -> next = second;
                sortedLLTail = second;
            }
            second = second->next;
        }
    }

    if(first != NULL) {
        if(sortedLLTail == NULL) {
            sortedLLHead = first;
            sortedLLTail = first;
        } else {
            sortedLLTail->next = first;
        }
    } else if(second != NULL) {
        if(sortedLLTail == NULL) {
            sortedLLHead = second;
            sortedLLTail = second;
        } else {
            sortedLLTail->next = second;
        }
    }

    return sortedLLHead;
}
