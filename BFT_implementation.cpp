#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//BFT IMPLEMENTATION
struct node{
    int data;
    struct node* r;
    struct node* l;
    node(int val){
        data=val;
        l=r=NULL;
    }
};
vector<vector<int>> bft(struct node* root){
    vector<vector<int>>v;
    queue<struct node*>q;
    if(root==NULL){return v;}
    q.push(root);
    while(!q.empty()){
        vector<int>l;
        for(int i=0;i<q.size();i++){
            struct node* node=q.front();
            q.pop();
            if(node->l != NULL) q.push(node->l);
            if(node->r != NULL) q.push(node->r);
            l.push_back(node->data);
        }
        v.push_back(l);
    }
    return v;
}
int main(){
    struct node* root;
    root=new node(5);
    root->l=new node(4);
    root->r=new node(8);
    root->l->l=new node(2);
    root->l->r=new node(3);
    root->r->l=new node(1);
    root->r->r=new node(9);
    auto x=bft(root);
    for(auto p:x){for(auto q:p){cout<<q<<" ";}}
    //output  5 4 8 2 3 1 9
}