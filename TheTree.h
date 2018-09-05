#include <iostream>
#include <string>
#include "TreeNode.h"
#include <stack>
class TheTree {
protected:
    TreeNode* Root; // kernel
    TreeNode* Current; // current
    int CurrPos;
    std::stack<TreeNode*> Stack;
    void DeleteTree (TreeNode* Node);
public:
    int DataCount = 0;
    TheTree(std::string key = "", int cntrpt = 0, TreeNode* L = nullptr, TreeNode* R = nullptr);
    ~TheTree();
    TreeNode* FindRecord(std::string key);
    TreeNode* insert(std::string key, int cntrpt, TreeNode* ptr);
    void delRec(std::string key, TreeNode* node);
    std::string getkey() const;
    int getcnt() const;
    bool reset();
    bool is_tree_end() const;
    bool gonext();
    TreeNode* GetRoot() const;
    TreeNode* GetCurrent() const;
    void print_tree(std::ostream &os, TreeNode* node, int lvl);
};