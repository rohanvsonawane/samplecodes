#include<bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node *left;
	node *right;
};

node *getnode(int a) {
	node *n = new node();
	n->data = a;
	n->left = NULL;
	n->right = NULL;
}


int search(int inorder[], int s, int e, int ans) {

	for(int i  = s; i <=e; i++) {
		if(inorder[i] == ans)
			return i;
	}
	return -1;
}
node* buildTree(int in[], int pre[], int s, int e) {
	
	static int preindex = 0;
	
	if(s > e)
		return NULL;
	int ans = pre[preindex];
	node *root = getnode(pre[preindex++]);
	if(s == e)
		return root;
	
	int inindex = search(in, s, e, ans);
	root->left = buildTree(in, pre, s, inindex-1);
	root->right = buildTree(in, pre, inindex+1, e);
	return root;
}

void getlevel(node *root) {
	if(root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node *a = q.front();
		q.pop();
		cout << a->data << " ";
		if(a->left) {
			q.push(a->left);
		}
		if(a->right) {
			q.push(a->right);
		}
	}
}




int main() {

	int inorder[] = {1, 2, 3, 4, 5, 6, 7};
	int preorder[] = {4, 2, 1, 3, 6, 5, 7};
	node* root = buildTree(inorder, preorder, 0, 6);

	getlevel(root);
	return 0;
}