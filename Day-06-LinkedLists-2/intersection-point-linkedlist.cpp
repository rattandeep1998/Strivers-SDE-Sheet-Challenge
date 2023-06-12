#include<bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    set<Node*> secondLLNodes;

    while(secondHead != NULL) {
        secondLLNodes.insert(secondHead);
        secondHead = secondHead->next;
    }

    while(firstHead != NULL) {
        if(secondLLNodes.find(firstHead) != secondLLNodes.end()) {
            return firstHead;
        }
        firstHead = firstHead->next;
    }
    return NULL;
}