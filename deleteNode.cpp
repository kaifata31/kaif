#include<iostream>
using namespace std;
class Node{
 public:
int data;
Node *next;

Node(int data){
    this->data=data;
    next=NULL;
}
};
Node* takeInput(){
     int data;
     
     cin>>data;
     Node *head=NULL;
     Node *tail=NULL;
     
     while(data!=-1){
      Node *newNode=new Node(data);
      if(head==NULL){
        head=newNode;
        tail=newNode;
      }else{
        tail->next=newNode;
        tail=tail->next;
        // Node *temp=head;
        // while(temp->next!=NULL){
        //     temp=temp->next;
        // }
        // temp->next=newNode;
      }
      cin>>data;
     }

     return head;

}
Node* insertNode(Node *head,int i,int data){
Node *newNode= new Node(data);
if(i==0){
    newNode->next=head;
    head=newNode;
    return  head;
}
int count=0;
Node*temp=head;  //while we travelling over a linked list use a temporary variable
while( temp!=NULL && count<i-1){  //if we are using position greter than given
temp=temp->next;
count++;
}
if(temp!=NULL){  
newNode->next=temp->next;/*This will be executed only when temp not equal to NULL*/
temp->next=newNode;
}
 return head;
}
void delNode(Node *head,int i){
    int count=0;
    Node *temp=head;
    while(count<i-1){
      temp=temp->next;
      count++;
    }
    Node *a=temp->next;
    Node *b=a->next;
    temp->next=b;
}
void print(Node *head){
    //  Node *temp=head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
   Node*head= takeInput();
    print(head);
    int i,data;
    cin>>i>>data;
   head = insertNode(head,i,data);
    print(head);
   delNode(head,i);
   print(head);
}