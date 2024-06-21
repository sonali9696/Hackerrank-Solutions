/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    if ( (head == nullptr) || (head->next == nullptr) ){
        return false;   
    }
    
    while(fastPtr != nullptr && fastPtr->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr != nullptr &&  fastPtr != nullptr && slowPtr == fastPtr) return true;
    }
    
    return false;
}