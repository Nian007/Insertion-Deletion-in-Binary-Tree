//#include<bits/stdc++.h>
//using namespace std;
//struct node{
//    int data;
//    node *left=NULL,*right=NULL;
//};
//node *add(int data){
//    node *newnode=new node;
//    newnode->data=data;
//    newnode->left=newnode->right=NULL;
//    return newnode;
//}
//void pre_order(node *root){
//    if(!root)
//        return;
//    cout<<root->data<<" ";
//    pre_order(root->left);
//    pre_order(root->right);
//}
//void post_order(node *root){
//    if(!root)
//        return;
//    post_order(root->left);
//    post_order(root->right);
//    cout<<root->data<<" ";
//}
//void in_order(node *root){
//    if(!root)
//        return;
//    in_order(root->left);
//        cout<<root->data<<" ";
//    in_order(root->right);
//}
//void level_order(node *root){
//    queue<node *>q;
//    q.push(root);
//    while(!q.empty()){
//        cout<<q.front()->data<<" ";
//        if(q.front()->left!=NULL)
//            q.push(q.front()->left);
//        if(q.front()->right!=NULL)
//            q.push(q.front()->right);
//        q.pop();
//    }
//}
//int main(){
//      node *root=NULL;
////    root=add(1);
////    root->left=add(2);
////    root->right=add(3);
////    root->left->left=add(4);
////    root->left->right=add(5);
////    root->right->right=add(6);
////    cout<<"Pre Order\n";
////    pre_order(root);
////    cout<<"\nPost order\n";
////    post_order(root);
////    cout<<"\nIn order\n";
////    in_order(root);
////    cout<<"\nLevel Order\n";
////    level_order(root);
//    int n;
//    cin>>n;
//    queue<int>q;
//    for(int i=0;i<n;i++){
//        int x;
//        cin>>x;
//        q.push(x);
//    }
//    root=add(q.front());
//    q.pop();
//    while(q.size()){
//        root->left=q.front();
//        q.pop();
//        root->right=q.front();
//        q.pop()
//    }
//}
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node *addnode(int data){
    node *newnode=new node;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node *addinLorder(node *root,int data){
    if(root==NULL){
        root=addnode(data);
    }
    else{
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node *temp=q.front();
            q.pop();
            if(temp->left==NULL){
                temp->left=addnode(data);
                break;
            }
            else if(temp->right==NULL){
                q.push(temp->left);
                temp->right=addnode(data);
                break;
            }
            else{
                q.push(temp->right);
            }
        }
    }
    return root;
}
void level_order(node *root){
    queue<node *>q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        q.pop();
    }
}
node *x_rightmost(node *root){
    node *right_most;
    vector<node*>vec;
    queue<node*>q;
    q.push(root);
    vec.push_back(root);
    while(!q.empty()){
        node *temp=q.front();
        vec.push_back(temp);
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    int sz=vec.size();
    return vec[sz-1];
}
node *Alter(int x,node *root){
    if(root==NULL){
        return NULL;
    }
    if(root!=NULL){
        if(root->data==x){
            return root;
        }
        node *tmp=Alter(x,root->left);
        if(tmp==NULL)
            return Alter(x,root->right);
        else
            return tmp;
    }
}
void findparent(node *root,node *boy){
    if(root==NULL)
        return;
    if(root!=NULL){
        if(root->right&&root->right->data==boy->data){
            root->right=NULL;
        }
        if(root->left&&root->left->data==boy->data){
            root->left=NULL;
        }
        findparent(root->left,boy);
        findparent(root->right,boy);
    }
}
void deleteNode(int x,node *root){
    node *temp=Alter(x,root);
    node *rightdeepest=x_rightmost(root);
    swap(temp->data,rightdeepest->data);
    findparent(root,rightdeepest);
}
int main(){
    node *root=NULL;
    int n;
    cin>>n;
    n=n-1;
    int x;
    cin>>x;
    root=addinLorder(root,x);
    while(n--){
        int x;
        cin>>x;
        root=addinLorder(root,x);
    }
    level_order(root);
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        deleteNode(x,root);
        level_order(root);
        cout<<"\n";
    }

}
