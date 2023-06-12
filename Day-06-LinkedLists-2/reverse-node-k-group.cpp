pair<Node*, Node*> reverseBlockLL(Node *head) {
	if(head==NULL || head->next==NULL) {
		return make_pair(head, head);
	}

	pair<Node*, Node*> reversedLL = reverseBlockLL(head->next);

	reversedLL.second -> next = head;
	head->next = NULL;
	reversedLL.second = reversedLL.second -> next;

	return reversedLL;
}

Node *getListAfterReverseOperationHelper(Node *head, int n, int b[], int curIndex, Node* curHead){
	if(curIndex == n) {
		return head;
	}

	if(head==NULL) {
		return head;
	}

	if(b[curIndex] == 0) {
		return getListAfterReverseOperationHelper(head, n, b, curIndex+1, curHead);
	}

	if(b[curIndex] == 1) {
		Node *temp = head->next;
		head->next = NULL;

		b[curIndex]--;

		Node *reversedSubLLHead = getListAfterReverseOperationHelper(temp, n, b, curIndex+1, temp);

		pair<Node*, Node*> reversedBlock = reverseBlockLL(curHead);

		reversedBlock.second -> next = reversedSubLLHead;
		return reversedBlock.first;
	}

	b[curIndex]--;

	Node *reversedSubLL = getListAfterReverseOperationHelper(head->next, n, b, curIndex, curHead);

    if (reversedSubLL == NULL) {
    	pair<Node *, Node *> reversedBlock = reverseBlockLL(curHead);
        reversedBlock.second->next = NULL;
        return reversedBlock.first;
    } else {
		return reversedSubLL;
	}
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return getListAfterReverseOperationHelper(head, n, b, 0, head);
}