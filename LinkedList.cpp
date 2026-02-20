#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};
void InsertAtBegining(Node* &head,int data){
      Node *nn= new Node();
    
      nn->data=20; 
      nn->next=head;
      head=nn;
}
void printList(Node* head){
    Node * temp= head;
    while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }
}
void insertAtPosition(Node* &head ,int data, int position){
    Node *nn=new Node();
    nn->data=data;
    if(position==0){
        nn->next=head;
        head=nn;
    }
    else{
        Node * curr=head;
        for(int i=0;i<position-1;i++){
            curr=curr->next;
        }
        
        nn->next=curr->next;
        curr->next=nn;

    }
}
void deleteAtPosition(Node* &head, int position){
  if(position==1){
    Node * temp=head;
    head=head->next;
    delete temp;

  }
  else{
    Node * curr=head;
    Node * prev=NULL;
 int cnt=0;
 while(cnt<position){

    prev=curr;
    curr=curr->next;
    cnt++;
 }
 prev->next=curr->next;
 delete curr;
  }
}               
int main(){
     Node* head =new Node();
     head->next=NULL;
     head->data=10;
     printList(head);
     // cout<<"Linked List created with head node data: "<<head->data<<endl;
    cout<<"After Insertion at begining: "<<endl;
         
   InsertAtBegining(head,20);
    //cout<<"New head node data after insertion: "<<head->data<<endl;
    printList(head);
    insertAtPosition(head,15,1);
    cout<<endl<<"After Insertion at position 1: "<<endl;
    cout<<"Tanaya Here" <<endl;

    printList(head);
    return 0;
}