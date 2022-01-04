#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * 本周是单调栈周吗？
 * 据说是可以利用二叉搜索树的性质实现 O(h) 的空间复杂度。
 * 话说回来，这道题不需要用到单调栈。
 * 不过呢，在把节点的左孩子依次推进栈中，并在使用值之后推出并推进右孩子的过程，其实相当于维护了一个**单调递减**的单调栈。
 */

/**
 * 实现一个二叉搜索树迭迭代器类。
 */
class BSTIterator {
    stack<TreeNode*> st;

   public:
    BSTIterator(TreeNode* root) { pushIn(root); }

    int next() {
        TreeNode* curr = st.top();
        st.pop();
        pushIn(curr->right);
        return curr->val;
    }

    bool hasNext() { return !st.empty(); }

   private:
    void pushIn(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
};