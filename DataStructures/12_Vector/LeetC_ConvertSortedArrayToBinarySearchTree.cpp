#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *BuildTree(vector<int> &nums, int l, int h)
{
    if (l <= h)
    {
        int mid = (h + l) / 2;
        TreeNode *head = new TreeNode(nums[mid]);
        head->left = BuildTree(nums, l, mid - 1);
        head->right = BuildTree(nums, mid + 1, h);
        return head;
    }
    return nullptr;
}

int main()
{
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    vector<int> nums = {0, 1, 2, 3, 4, 5};
    BuildTree(nums, 0, nums.size() - 1);

    return 0;
}
