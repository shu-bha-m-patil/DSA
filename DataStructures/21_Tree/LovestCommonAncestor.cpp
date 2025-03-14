#include <iostream>

struct BST
{
    int _data;
    BST* _left;
    BST* _right;

    BST(int iData)
    {
        _data = iData;
        _left = nullptr;
        _right = nullptr;
    }
};

void AddChild(BST*& iRoot, int iData)
{
    if(iRoot == nullptr)
    {
        iRoot = new BST(iData);
        return;
    }

    if(iData < iRoot->_data)
        AddChild(iRoot->_left, iData);
    else if(iRoot->_data < iData)
        AddChild(iRoot->_right, iData);
}

void BuildBST(BST*& iRoot, int* iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
        AddChild(iRoot, iArray[i]);
}

BST* LowestCommonAncestor(BST* iRoot, int iVal1, int iVal2)
{
    if(iRoot == nullptr) return nullptr;

    if(iVal1 < iRoot->_data && iVal2 < iRoot->_data)
        return LowestCommonAncestor(iRoot->_left, iVal1, iVal2);
    else if(iRoot->_data < iVal1 && iRoot->_data < iVal2)
        return LowestCommonAncestor(iRoot->_right, iVal1, iVal2);

    return iRoot;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    BST* rootNode = LowestCommonAncestor(root, 35, 47);
    std::cout << "The root node is " << rootNode->_data << std::endl;
}