#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
 public:
    int key;
    BSTNode* left; 
    BSTNode* right;
 
    BSTNode(int item)
    {
        key = item;
        left = right = NULL;
    }
};

void printBT(BSTNode* root){
	if (root == NULL) {
		cout << "Empty Tree" << endl;
		return;
	}
	queue<BSTNode*> q;
    q.push(root);
	
	while (!q.empty()){
		BSTNode* temp = q.front();
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

BSTNode* search(BSTNode* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

BSTNode* insert(BSTNode* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BSTNode(value);
    }
 
    // Insert data.
    if (value > root->key)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}


void inorder(BSTNode* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->key << endl;
    inorder(root->right);
}

void preorder(BSTNode* root)
{
    if (!root) {
        return;
    }
    cout << root->key << endl;
	preorder(root->left);
    preorder(root->right);
}

void postorder(BSTNode* root)
{
    if (!root) {
        return;
    }
	postorder(root->left);
    postorder(root->right);
    cout << root->key << endl;
}

int main()
{
	/* Create the following binary search tree

                 100
              /      \
             20       500
          /    \     / 
         10    30   200
              /  \
             25  40
 			         	

    */
 
    /*create root*/
    BSTNode* root = new BSTNode(100);
    
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 500);
    root = insert(root, 40);
    root = insert(root, 25);
    root = insert(root, 200);
    
    cout << "\n";
	printBT(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    postorder(root);
    
    
    
    return 0;
}
