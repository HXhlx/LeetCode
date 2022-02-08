// Definition for a Node.
class Node
{
public:
    int val = 0;
    Node *child = nullptr, *left = nullptr, *next = nullptr, *prev = nullptr, *random = nullptr, *right = nullptr;
    std::vector<Node *> neighbors, children;
    Node() = default;
    Node(int _val) : val(_val) {}
    Node(int _val, std::vector<Node *> cn) : val(_val), neighbors(cn), children(cn) {}
    Node(int _val, Node *_left, Node *_right) : val(_val), left(_left), right(_right) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};