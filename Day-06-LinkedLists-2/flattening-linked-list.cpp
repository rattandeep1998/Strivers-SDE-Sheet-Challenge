Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *result = temp; 
    
	a->next = NULL;
	b->next = NULL;

    while(a!=NULL && b!=NULL) {
        if(a->data < b->data) {
            temp->child = a; 
            temp = temp->child; 
            a = a->child; 
        }
        else {
            temp->child = b;
            temp = temp->child; 
            b = b->child; 
        }
    }

    if (a) {
    	temp->child = a;
    } else {
    	temp->child = b;
    }

    return result->child; 
}

Node *flattenLinkedListHelper(Node *head)
{
    if(head == NULL || head->next == NULL) 
    	return head; 
  
    head->next = flattenLinkedListHelper(head->next); 
  
    head = mergeTwoLists(head, head->next); 

	return head;
}

Node* flattenLinkedList(Node* head) 
{
	return flattenLinkedListHelper(head);
}
