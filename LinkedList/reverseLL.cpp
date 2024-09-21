/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prevNode , *curNode , *nextNode;
    curNode = NULL;
    nextNode = head;
    while(nextNode != NULL){
        prevNode = curNode;
        curNode = nextNode;
        nextNode = nextNode ->next;
        curNode->next = prevNode;
    }
    return curNode;
}
