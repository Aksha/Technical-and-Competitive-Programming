//Write a program to merge two BST



v#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(NULL), right(NULL) {}
};


vector<int> merge(vector<int> first, vector<int> second) {
    int i = 0;
    int j = 0;
    int m = first.size();
    int n = second.size();
    vector<int> result;
    while(i < m  && j < n) {
        if(first[i] <= second[j])
            result.push_back(first[i++]);
        else if (first[i] > second[j])
            result.push_back(second[j++]);
    }
    while(i < m)
        result.push_back(first[i++]);
    while(j < n)
        result.push_back(second[j++]);
    return result;
}

void inOrder(Node* root, vector<int> &arr) {
    if(root == NULL)
        return;
    inOrder(root->left,arr);
    arr.push_back(root->key);
    inOrder(root->right,arr);
}

Node* sortedArrayToHBST(vector<int> result,int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        cout << "start is : " << start <<  "end is : " << end << " mid is : " << mid << " mid element is : " << result[mid] << endl;
        Node* n = new Node(result[mid]);
        n->left = sortedArrayToHBST(result,start,mid-1);
        n->right = sortedArrayToHBST(result,mid+1,end);
        return n;
}

Node* mergeTwoBSTs(Node* root1, Node* root2) {
        vector <int> arr1;
        inOrder(root1, arr1);
        vector <int> arr2;
        inOrder(root2, arr2);
        vector <int> result = merge(arr1,arr2);
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
        cout << "arr 1 size : " << arr1.size() << " arr 2 size: " << arr2.size() << " result size: " << result.size() << endl;
        Node* BST = sortedArrayToHBST(result,0,result.size()-1);
        return BST;
}


int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    Node* root2 = new Node(7);
    root2->left = new Node(6);
    root2->right = new Node(8);
    Node* root3 = mergeTwoBSTs(root1,root2);
    cout << root3->key << " : " << root3->left->key << " : " <<  root3->right->key << endl;
    return 0;
}
