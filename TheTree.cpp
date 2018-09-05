#include <iostream>
#include "TheTree.h"
#include <string>
TheTree::TheTree (std::string key, int cntrpt, TreeNode* L, TreeNode* R)
{
    Root = new TreeNode(key, cntrpt, L, R);
    Current = Root;
    CurrPos = 0;
}
void TheTree::DeleteTree (TreeNode* node)
{
    if (node != nullptr)
    {
        DeleteTree(node->Left);
        DeleteTree(node->Right);
    }
    delete node;
}
TheTree::~TheTree()
{
    DeleteTree(Root);
}
TreeNode* TheTree::insert (std::string key, int cntrpt, TreeNode* ptr)
{
    if (ptr != nullptr)
    {
        if (key == ptr->key)
        {
            ++ptr->cntrpt;
        }
        if (key < ptr->key)
        {
            ptr->Left = insert(key, cntrpt, ptr->Left);
            if (ptr->Left == nullptr)
            {
                ptr->Left = new TreeNode(key, cntrpt, nullptr, nullptr);
            }
        }
        if (key > ptr->key)
        {
            ptr->Right = insert(key, cntrpt, ptr->Right);
            if (ptr->Right == nullptr)
            {
                ptr->Right = new TreeNode(key, cntrpt, nullptr, nullptr);
            }
        }
    }
    return ptr;
}
void TheTree::delRec (std::string key, TreeNode* rec)
{
    TreeNode* node = FindRecord(key);
    if ((node->Left) && (node->Right))
    {
        node = node->Right;
        while (node->Left != nullptr)
        {
            node = node->Left;
        }
       rec->cntrpt = node->cntrpt;
       rec->key = node->key;
       node->key = "";
       node->cntrpt = 0;
       delete node;
       node = nullptr;
    }
    if (node != nullptr)
    {
         if ((node->Left == nullptr) && (node->Right == nullptr))
            {
                rec->cntrpt = 0;
                rec->key = "";
                delete rec;
            }
        if ((node->Left != nullptr) || (node->Right != nullptr))
        {
            if ((node->Left == nullptr) && (node->Right != nullptr))
            {
                node = node->Right;
                rec->cntrpt = 0;
                rec->key = "";
                delete rec;
            }
            if ((node->Right == nullptr) && (node->Left != nullptr))
            { 
                node = node->Left;
                rec->cntrpt = 0;
                rec->key = "";
                delete rec;
            }
        }
    }
}
TreeNode* TheTree::FindRecord (std::string key)
{
    TreeNode* node = Root;
    TreeNode* res = node;
    while ((node->key != key) && (node != nullptr))
    {
        if(key < node->key)
        {
            node = node->Left;
        }
        if(key > node->key)
        {
            node = node->Right;
        }
    }
    if (node->key == key)
    {
        res = node;
        Current = res;
    }
    if (node == nullptr)
    {
        res = nullptr;
        std::cout << "NOT SEARCH" << std::endl;
    }
    return res;
}
void TheTree::print_tree (std::ostream &os, TreeNode* node, int lvl)
{
    if (node != nullptr)
    {
        if (node->cntrpt != 0)
        {
            std::cout << lvl << " ";
        }
        node->print(os);
        print_tree(os, node->Left, lvl + 1);
        print_tree(os, node->Right, lvl + 1);
    }
}
TreeNode* TheTree::GetRoot () const
{
    return Root;
}
TreeNode* TheTree::GetCurrent () const
{
    return Current;
}
std::string TheTree::getkey () const
{
    return Current->GetKey();
}
int TheTree::getcnt () const
{
    return Current->GetCount();
}