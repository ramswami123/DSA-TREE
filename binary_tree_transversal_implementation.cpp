#include<iostream>
using namespace std;
//DFT IMPLEMENTATION
struct node{
    int data;
    struct node* r;
    struct node* l;
    node(int val){
        data=val;
        l=r=NULL;
    }
};
void postoder(struct node* node){
    if(node == NULL){return;}
    postoder(node->l);
    postoder(node->r);
    cout<<node->data<<" ";
}
void preoder(struct node* node){
    //left right root/node data
    if(node==NULL){return;}
    cout<<node->data<<" ";
    preoder(node->l);
    preoder(node->r);
}
void inoder(struct node* node){
    //left data right
    if(node==NULL){return;}
    inoder(node->l);
    cout<<node->data<<" ";
    inoder(node->r);
}
int main(){
    //creating tree;
    struct node* root;
    root=new node(5);
    root->l=new node(4);
    root->l->r=new node(3);
    root->l->l=new node(2);
    root->l->l=new node(1);
    root->r=new node(8);
    root->r->r=new node(9);

    preoder(root);
    cout<<"\n";
    inoder(root);
    cout<<"\n";
    postoder(root);
    cout<<"\n";
    return 0;
}
/*5 4 1 3 8 9 
1 4 3 5 8 9
1 3 4 9 8 5*/