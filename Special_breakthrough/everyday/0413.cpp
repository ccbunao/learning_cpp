#include<iostream>
#include<cstring>
using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
};

string s;
int i;

TreeNode* create(){
    char ch = s[i++];
    if( ch == '#' ) return nullptr;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = ch;
    root->left = create();
    root->right = create();
    return root;
}
void InorderV(TreeNode* root){
    if(root == nullptr) return;
    InorderV(root->left);
    if(root->val!='#') cout<<root->val<<" ";
    InorderV(root->right);
}

int main(){
    
    cin>>s;
    
    TreeNode* r = create();
    InorderV(r);
    return 0;
}