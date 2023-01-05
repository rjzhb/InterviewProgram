#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root) {
    std::stack<TreeNode *> st;
    TreeNode *node = root;
    TreeNode *last = NULL;
    while (!st.empty() || node != NULL) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();

        if (last != NULL && last->val >= node->val) {
            return false;
        }
        last = node;
        node = node->right;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
