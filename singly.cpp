#include <bits/stdc++.h>
using namespace std;
#include <vector>
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
    Node(int data,Node * next){
        this->data=data;
        this->next=next;
    }
};
Node * convert(vector<int> v){
    Node * head=new Node(v[0]);
    Node * mover=head;
    for(int i=1;i<v.size();i++){
        Node * temp=new Node(v[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void display(Node * head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node * insertHead(Node * head,int x){
        Node * temp=new Node(x);
        temp->next=head;
        return temp;
}
Node * insertAtEnd(Node * head,int x){
    Node *temp=head;
    Node * newNode=new Node(x);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
Node * insertIndex(Node * head,int x,int k){
    if(head==NULL){
        return new Node(x);
    }
    if(k==1){
        return insertHead(head,x);
    }
    int count=0;
    Node * temp=head;
    while(temp!=NULL){
        count++;
        if(count==(k-1)){
            Node * newNode=new Node(x);
            newNode->next=temp->next;
            temp->next=newNode; 
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main (){
    vector<int> v={1,2,3,4,5,6,7};
    Node * head=convert(v);
    // display(head);
    // head=insertHead(head,50);
    // display(head);
    // head=insertAtEnd(head,100);
    display(head);
    head=insertIndex(head,500,1);
    display(head);
    return 0;
}