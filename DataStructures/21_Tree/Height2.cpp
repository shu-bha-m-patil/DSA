#include <iostream>
#include <queue>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to build a binary tree from a vector input (level-order)
TreeNode* buildTree(const vector<int*>& nodes) {
    if (nodes.empty() || nodes[0] == nullptr) return nullptr;

    // Create the root node
    TreeNode* root = new TreeNode(*nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Add left child
        if (nodes[i] != nullptr) {
            current->left = new TreeNode(*nodes[i]);
            q.push(current->left);
        }
        i++;

        // Add right child
        if (i < nodes.size() && nodes[i] != nullptr) {
            current->right = new TreeNode(*nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to print tree in inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int getheight(TreeNode* root, bool &isBalance){
        if(!root) return 0;
        int lh = getheight(root->left, isBalance);
        int rh = getheight(root->right, isBalance);
        abs(lh - rh) < 2 ? isBalance = true : isBalance = false;
        return std::max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool hb = true;
        int lh = getheight(root, hb);
        return hb;
    }

int main() {
    // Input tree in level-order format (nullptr represents null nodes)
    vector<int*> input = {new int(1), new int(2), new int(3), new int(4), new int(5), nullptr, new int(6), new int(7), nullptr, nullptr, nullptr, nullptr, new int(8)};
    
    // Build the tree
    TreeNode* root = buildTree(input);

    // Print inorder traversal to verify the tree structure
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    bool he = isBalanced(root);
    return 0;
}
