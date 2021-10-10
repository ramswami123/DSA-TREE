#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* r;
    struct node* l;
    node(int val){
        data=val;
        l=r=NULL;
    }
};
int main(){
    struct node* root;
    root=new node(5);
    root->l=new node(4);
    root->l->r=new node(3);
    root->l->l=new node(2);
    root->l->l=new node(1);
    root->r=new node(8);
    root->r->r=new node(9);
    return 0;
}
