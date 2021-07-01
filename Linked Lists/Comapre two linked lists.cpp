
    
// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  
  //the idea is that corresponding values of both lists must be same and they must end at the same time( i.e they must be of same length)
    
    
    while(head1!=NULL&&head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    if(head1==NULL&&head2==NULL)
       return true;
    else return false;   
}

