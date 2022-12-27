#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
 public:
    int key;
    TreeNode* left; 
    TreeNode* right;
 
    TreeNode(int item)
    {
        key = item;
        left = right = NULL;
    }
};

TreeNode* insertNode(TreeNode* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = new TreeNode(data);
	        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<TreeNode*> q;
    q.push(root);
 
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = new TreeNode(data);
	            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = new TreeNode(data);
	            return root;
        }
    }
}

void printBT(TreeNode* root){
	if (root == NULL) {
		cout << "Empty Tree" << endl;
		return;
	}
	queue<TreeNode*> q;
    q.push(root);
	
	while (!q.empty()){
		TreeNode* temp = q.front();
        q.pop();
        cout << "\t\tp: " << temp->key << " \n";
        if (temp->left != NULL){
        	q.push(temp->left);
        	cout << "\tl: " << temp->left->key;
		}
		else
            cout << "\tl: NULL";
        if (temp->right != NULL){
            q.push(temp->right);
            cout << "\t\tr: " << temp->right->key << endl;
        }
		else
            cout << "\tr: NULL" << endl;
	}
} 

int main()
{
	/* Create the following tree

               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL

    */
 
    /*create root*/
    TreeNode* root = new TreeNode(1);
    
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    
    printBT(root);
    
    return 0;
}
