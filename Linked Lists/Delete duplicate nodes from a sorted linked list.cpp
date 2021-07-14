/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *ptr=llist;
    while(ptr->next!=NULL){
        if(ptr->data==ptr->next->data)
           ptr->next=ptr->next->next;
        else ptr=ptr->next;   
    }
    
    return llist;
}
