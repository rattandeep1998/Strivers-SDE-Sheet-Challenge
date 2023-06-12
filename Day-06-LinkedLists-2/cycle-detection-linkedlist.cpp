bool detectCycle(Node *head)
{
	//	Write your code here
    if (head == NULL) {
        return false;
    }

    Node *slow = head;
    Node *fast = head->next;
    
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}