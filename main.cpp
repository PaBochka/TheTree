#include <iostream>
#include "TheTree.h"
int main()
{
    TheTree A("b", 1, nullptr, nullptr);
    TreeNode* node = A.GetRoot();
    node = A.insert("c", 1, node);
    node = A.insert("x", 1, node);
    node = A.insert("y", 1, node);
    node = A.insert("f", 1, node);
    node = A.insert("d", 1, node);
    node = A.insert("a", 1, node);
    A.print_three(std::cout, A.GetRoot(), 0);
    A.delRec("b", A.FindRecord("b"));
    A.print_three(std::cout, A.GetRoot(), 0);
    std::cin.get();
    return 0;
}
