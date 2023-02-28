Node* remove(Node* &head)
{
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=NULL)
    {
       if(curr->data==prev->data)
       {
        curr=curr->next;
       }
       prev=curr;
       curr=curr->next
    }
    prev->next=curr;

}