Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* toBST(ListNode* head, ListNode* tail);

TreeNode* constructHBST(ListNode* head) {
    if(head == NULL)
        return NULL;
    return toBST(head, NULL);
}

TreeNode* toBST(ListNode* head, ListNode* tail) {
    if(head == tail)
        return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != tail || fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = toBST(head,slow);
    root->right = toBST(slow->next,tail);
    return root;
}

int main() {
    ListNode* one = new ListNode(-10);
    one->next= new ListNode(-3);
    one->next->next = new ListNode(0);
    one->next->next->next = new ListNode(5);
    one->next->next->next->next = new ListNode(9);

    TreeNode* root = constructHBST(one);
    cout << "    " << root->val << endl;
    cout << root->left << " " << root->right << endl;
    cout << "     \n" << root->left->right << "          " << root->right->right << endl;
    return 0;
}
