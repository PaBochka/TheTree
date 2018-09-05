#include <iostream>
#include <string>
class TreeNode;
class TreeNode {
    protected: 
    TreeNode* Left;
    TreeNode* Right;
    int cntrpt = 0;
    std::string key = "";
    public:
    TreeNode (std::string _key = "", int _cntrpt = 0, TreeNode* L = nullptr, TreeNode* R = nullptr)
    {
        key = _key;
        cntrpt = _cntrpt;
        Left = L;
        Right = R;
    }
    TreeNode* GetLeft() const
    {
        return Left;
    }
    TreeNode* GetRight() const
    {
        return Right;
    }
    std::string GetKey() const
    {
        return key;
    }
    int GetCount() const
    {
        return cntrpt;
    }
    std::ostream& print(std::ostream& os)
    {   
        if(this->GetCount() != 0)
        os << this->GetKey() << " " << this->GetCount() << std::endl;
        return os;
    }
    friend class TheTree;
};
