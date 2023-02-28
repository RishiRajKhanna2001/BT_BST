#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
      this->data=data;
      this->next=NULL;
    }


    
}

void insertAtHead(Node* &head,int data)
{
    Node* temp=new Node(data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &head,int data)
{
    Node* temp=new Node(data);
    Node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=temp;
    tail=temp;
}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<"NULL";
}
bool checkCyclic(Node* head)
{
    if(head==NULL)
    {
        return true;
    }

    map<Node*,bool> mp;
    mp[head]=true;
    Node* temp=head->next;

    while(temp!=NULL)
    {
        if(mp[temp]==true)
        {
             return true;
        }
        mp[temp]=true;
        temp=temp->next;
    }

}
int main()
{
   Node* head=NULL;
   insertAtHead(head,10);

}