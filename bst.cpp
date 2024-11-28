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
Node * createTree(Node * root){
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node (data);
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=createTree(root->right);
}
bool searchbst(Node * root,int x){
    Node * temp=root;
    if(temp==NULL){
        return false;
    }
    if(temp->data==x){
        return true;
    }
    if(x<temp->data){
        return searchbst(temp->left,x);
    }
    if(x>temp->data){
        return searchbst(temp->right,x);
    }
}
int findCeil(Node * root,int key){
    int ceil=-1;
    if(root->data==key){
        ceil=root->data;
        return ceil;        
    }
    if(key>root->data){
        root=root->right;
    }
    else{
        ceil=root->data;
        root=root->left;
    }
    return ceil;
}
int main (){
    Node * root=NULL;
    root=createTree(root);
    bool res=searchbst(root,14);
    if(res){
        cout<<"found in bst "<<endl;
    }
    else{
        cout<<"Not found in bst"<<endl;
    }
    int ans=findCeil(root,8);
    cout<<ans<<endl;
    return 0;
}