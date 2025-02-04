#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
bool inOrderTrav(TreeNode* p, TreeNode* q){
        if((!p && q) || (p && !q))return false;
        if(!p && !p) return true;
        if(p->val != q->val) return false;
        return inOrderTrav(p->left, q->left) && inOrderTrav(p->right, q->right);
    }



int main()
{
    TreeNode* p = nullptr;
    TreeNode* q = new TreeNode(0);
            if(!p && !p) return true;
    bool isame = inOrderTrav(p, q); 
        return 0;
    }