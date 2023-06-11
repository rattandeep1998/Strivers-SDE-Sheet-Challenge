pair<Node*, int> removeKthNodeHelper(Node* head, int K) {
    if(head==NULL) {
        return make_pair(head, 0);
    }

    pair<Node*, int> nodeAndIndexFromEnd = removeKthNodeHelper(head->next, K);

    if(nodeAndIndexFromEnd.second+1 == K) {
        return make_pair(nodeAndIndexFromEnd.first, nodeAndIndexFromEnd.second + 1);
    } else {
        head->next = nodeAndIndexFromEnd.first;
        return make_pair(head, nodeAndIndexFromEnd.second + 1);
    }
}

Node* removeKthNode(Node* head, int K)
{
    return removeKthNodeHelper(head, K).first;
}