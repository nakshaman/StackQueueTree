#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node * createBSt(Node * root){
    int data;
    cout<<"Enter the value of data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter the value for left of data "<<endl;
    root->left=createBSt(root->left);
    cout<<"Enter the value for right of data "<<endl;
    root->right=createBSt(root->right);
}
void preorder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
bool searchBst(Node * root,int x){
    if(root==NULL){
        return ;
    }
    if(root->data==x){
        return true;
    }
    if(x>root->data){
        return searchBst(root->right,x);
    }
    if(x<root->data){
        return searchBst(root->left,x);
    }
}
int main (){
    Node * root=NULL;
    root=createBSt(root);
    bool res=searchBst(root,8);
    if(res){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}