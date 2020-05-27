//This problem uses constant memory while solving 

SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l_a, SinglyLinkedListNode* l_b) {
    //result is not extra memory as it only holds all the values.. l_b works as a pointer that goes around and does the work and the final result is stored under result that takes the value of l_b. No extra
    SinglyLinkedListNode* result = l_b; //extra memory for the output not while solving!
    int carry = 0; 
    int sum = 0;
    while(true) // a while(true) loop will run until a break statement is issued explicitly
    {
        sum = l_a->data + l_b->data + carry;
        l_b->data = sum%10;
        carry = sum/10;
        if(l_a->next == NULL || l_b->next == NULL) { // a break statement is issued when the next element is NULL. Similar to while(l_a && l_b)
            break;
        }
        l_a = l_a->next;
        l_b = l_b->next;
    }
    //3 cases a) if there are elements in l_a and not l_b.. otherwise is not a problem. 
    if(l_a->next!=NULL && l_b->next == NULL)
        l_b->next = l_a->next;
    
    // if there is a carry, there are two things to consider: a) when l_b->next is not null, what do we do with it.
    //b) when l_b->next is null, what do we do with it. 
    
    while(carry>0 && l_b->next !=NULL) {
        l_b = l_b->next;
        sum = carry + l_b->data;
        l_b->data = sum%10;
        carry = sum/10;
    }
    
    if(carry) {
      SinglyLinkedListNode* newnode = new SinglyLinkedListNode(carry);
      l_b->next = newnode;
    }
    
    return result;
}
