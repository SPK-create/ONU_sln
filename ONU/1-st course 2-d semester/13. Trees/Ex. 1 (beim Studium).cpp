#include <iostream> 
#include <memory> 
#include <vector> 
#include <functional> 
#include <iostream> 
#include <optional> 
#include <stack> 
#include <random> 
using namespace std;
struct tNode {
	char data;
	struct tNode* left;
	struct tNode* right;
};
// Function to create a new node 
tNode* newNode(int data) {
	tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
// Function to insert nodes in level order 
tNode* insertLevelOrder(char arr[], tNode* root, int i, int n) {
	// Base case for recursion 
	if (i < n) {
		tNode* temp = newNode(arr[i]);
		root = temp;
		// insert left child 
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
		// insert right child 
		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
	}
	return root;
}
// Function to delete the given tree 
void deleteTree(tNode* node) {
	if (node == NULL)
		return;
	/* first delete both subtrees */
	deleteTree(node->left);
	deleteTree(node->right);

	/* then delete the node */
	// std::cout << "Deleting node: " << node->data << std::endl; 
	delete node;
}
void in_order(tNode* node) {
	if (node == nullptr) return;
	in_order(node->left);
	cout << node->data;
	in_order(node->right);
}

void pre_order(tNode* node) {
	if (node == nullptr) return;
	cout << node->data;
	pre_order(node->left);
	pre_order(node->right);
}

void post_order(tNode* node) {
	if (node == nullptr) return;
	post_order(node->left);
	post_order(node->right);
	cout << node->data;
}

// Driver program to test above function 
int main() {
	char c[] = { '+', '/', '-', 'q', 'a', 'c', '*', ' ', ' ', ' ', ' ', ' ', ' ', 'd', 'q' };
	int size = 15;
	for (int i = 0; i < size; i++) {
		cout << c[i];
	}
	tNode* root = nullptr;
	root = insertLevelOrder(c, root, 0, size);

	in_order(root);
	cout << endl;
	pre_order(root);
	cout << endl;
	post_order(root);
	return 0;
}