#include<iostream>
using namespace std;

class Node{

 public:
int data;
Node * next;
 Node* prev;

Node(int d){
this->data=d;
this->next=NULL;
this->prev=NULL;

 }
 ~Node(){
    int val=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;

    }
cout<<"memory free for node with data"<<val<<endl;
 }
};
void insertAthead(Node * &head, int d){
Node * temp=new Node(d);
temp->next=head;
head->prev=temp;
head=temp;
}
void insertAttail(Node* &tail,int d)
{
   
    Node *temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPosition(Node* & head, int position,int d){
Node * temp=head;  
    if(position==1){
        insertAthead(head,d);
        return;
        for(int i=1;i<position-1;i++){
            head=head->next;
temp->next=head;
head->prev=temp;

        }
        }

    
}
void print(Node * head){


    Node * temp=head;
    while(temp!= NULL){
         cout<<temp->data<<" ";

        temp=temp->next;
       
    }
}
void getLength(Node*head)
{
    Node * temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
    len++;
    }
    cout<<len<<" ";
  
    
}
void deleteNode(int position,Node * & head){
  if(position==1){  Node *temp= head;
    head=head->next;
    temp->next->prev=NULL;
    temp->next=NULL;
    delete temp;
  }
  else{
    Node* curr=head;
    Node * prev=NULL;
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    curr->next=NULL;
    prev->next=curr->next;
    delete curr;
  }

}
int main(){
    Node *n1= new Node(10);
    Node *n2= new Node(20);
    Node *n3= new Node(30);
    n1->next=n2;
    n2->prev=n1;
    n2->next=n3;
    n3->prev=n2;
   // print(n1);
 //   getLength(n1);
    return 0;
}