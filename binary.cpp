#include <iostream>
using namespace std;
class Tree{
    public:
    int data;
    Tree * left;
    Tree * right;
        Tree(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    Tree(int data,Tree * left,Tree * right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};
Tree * createTree(Tree * root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root=new Tree(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=createTree(root->right);
}
void preorder(Tree * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Tree * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(Tree * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main (){
    Tree * root=NULL;
    root=createTree(root);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}