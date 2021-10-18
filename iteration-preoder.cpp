#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class treenode{
    public:
    int data;
    treenode* r;
    treenode* l;
    treenode(int val){
        data=val;
        l=r=NULL;
    }
};
vector<int> preoder(treenode* root){
    vector<int>v;
    if(root==NULL){return v;}
    //as we need to store entire node information
    stack<treenode*>s;
    s.push(root);
    while(!s.empty()){
        treenode* temp=s.top();
        v.push_back(temp->data);
        s.pop();
        if(temp->r!=NULL){s.push(temp->r);}
        if(temp->l!=NULL){s.push(temp->l);}
    }
    return v;
}
int main(){
    treenode* root;
    root=new treenode(5);
    root->l=new treenode(4);
    root->r=new treenode(8);
    root->l->l=new treenode(2);
    root->l->r=new treenode(3);
    root->r->l=new treenode(1);
    root->r->r=new treenode(9);
    auto x=preoder(root);
    for(auto p:x){cout<<p<<" ";}
    cout<<endl;
    //5 4 2 3 8 1 9 
}
