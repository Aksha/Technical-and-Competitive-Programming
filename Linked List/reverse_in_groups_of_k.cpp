// get group, reverse, append approach

//  int val; LinkedListNode* next;
void getGroup( LinkedListNode* &head, int k, LinkedListNode* &gHead, LinkedListNode* &gTail ) { 
    gHead = gTail = head;
    while( --k>0 && gTail->next ) gTail = gTail->next;
    head = gTail->next;
    gTail->next = NULL;
} 

void reverseList( LinkedListNode* head ) { 
    LinkedListNode *prev = NULL, *next = NULL;
    while( head ) { 
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    } 
} 

void append( LinkedListNode* &aHead, LinkedListNode* &aTail, 
             LinkedListNode* &bHead, LinkedListNode* &bTail ) { 
    if( !aHead ) aHead = bHead;
    else aTail->next = bHead;
    aTail = bTail;
} 

LinkedListNode* reverse_linked_list_in_groups_of_k( LinkedListNode* head, int k ) {
    if( !head || !head->next || k==1 ) return head;
    
    LinkedListNode *gHead = NULL, *gTail = NULL;
    LinkedListNode *aHead = NULL, *aTail = NULL;
    
    while( head ) {
        getGroup( head, k, gHead, gTail );
        reverseList( gHead );
        append( aHead, aTail, gTail, gHead );
    } 
    
    return aHead;
}
