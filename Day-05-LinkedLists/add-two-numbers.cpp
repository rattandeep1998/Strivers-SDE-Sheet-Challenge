Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *sumHead = NULL;
    Node *sumTail = NULL;

    int overflowSum = 0;

    while(num1 != NULL || num2 != NULL) {
        int tempSum = overflowSum;

        if(num1 != NULL) {
            tempSum += num1->data;
        }

        if(num2 != NULL) {
            tempSum += num2->data;
        }

        int curSum = tempSum % 10;
        overflowSum = tempSum / 10;

        Node *sumNode = new Node(curSum);

        if(sumTail == NULL) {
            sumHead = sumNode;
            sumTail = sumNode;
        } else {
            sumTail -> next = sumNode;
            sumTail = sumTail -> next;
        }

        if (num1 != NULL) {
          num1 = num1->next;
        }

        if (num2 != NULL) {
          num2 = num2->next;
        }
    }

    if(overflowSum != 0) {

        Node *sumNode = new Node(overflowSum);

        if(sumTail == NULL) {
            sumHead = sumNode;
            sumTail = sumNode;
        } else {
            sumTail -> next = sumNode;
            sumTail = sumTail -> next;
        }
    }

    return sumHead;
}
