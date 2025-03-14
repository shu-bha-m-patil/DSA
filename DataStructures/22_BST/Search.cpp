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

bool SearchInTree(BST* iRoot, int iVal)
{
    if(iRoot == nullptr) return false;

    if(iVal < iRoot->_data)
        return SearchInTree(iRoot->_left, iVal);
    else if(iRoot->_data < iVal)
        return SearchInTree(iRoot->_left, iVal);
    else
        return true;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    int searchKey = 41;
    if(SearchInTree(root, searchKey))
        std::cout << "The key is present." << std::endl;
    else
        std::cout << "The key is not present." << std::endl;
};