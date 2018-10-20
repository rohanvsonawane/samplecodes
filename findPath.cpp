#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 1000000

class node {
	public:
		int val;
		node *left, *right;

	node(int value) {
		left = NULL;
		right = NULL;
		val = value;
	}
};

void printPreorder(node *root) {
	if(root == NULL)
		return;
	printPreorder(root->left);
	cout << root->val;
	printPreorder(root->right);
}

int main() {
	
	long fact[MAX_LEN];
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i < MAX_LEN; i++) {
		fact[i] = (fact[i - 1] * i)%(1000000000 + 9); 
	}
	for(int i = 2; i < 100; i++) {
		cout << fact[i] << " "; 
	}
	cout << endl;
	node *root = new node(1);
	root->left = new node(3);
	root->right = new node(2);
	root->left->left = new node(4);
	root->left->right = new node(5);

	//printPreorder(root);
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	long long finalresult = 1;
	int ct = 0;
	while(!q.empty()) {
		node* temp = q.front();
		q.pop();
		
		if(temp) {
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			ct++;
		}
		else if(!temp){
			cout << ct << endl;
			finalresult = finalresult * fact[ct];
			if(!q.empty()) {
				q.push(NULL);
				
				ct = 0;
			}
		}
		
		

	}
	cout << finalresult << endl;
	return 0;
}