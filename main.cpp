#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

// Binary Search Tree

class binarySearchTree
{
public:
	int data;
	binarySearchTree* left;
	binarySearchTree* right;
	binarySearchTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binarySearchTree(){
		delete left;
		delete right;
	}
	
};

void LevelOrderTraversal(binarySearchTree* root){

	if(!root) return;

	queue<binarySearchTree*> node;
	node.push(root);

	while(!node.empty()){

		int count = node.size();
		while(count--){

			binarySearchTree* ptr = node.front();
			cout<<ptr->data<<" ";
			node.pop();

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";

	}
}

binarySearchTree* builtBinaryTree(binarySearchTree* root,int key){

	if(!root) return new binarySearchTree(key);

	if( root->data > key){
		root->left = builtBinaryTree(root->left,key);
	}
	else{
		root->right = builtBinaryTree(root->right,key);
	}
	return root;
}

void inorderIterative(binarySearchTree* root){

	if(!root) return;

	stack<binarySearchTree*> node;

	binarySearchTree* cur = root;

	while( !node.empty() || cur != NULL){

		if( cur != NULL){
			node.push(cur);
			cur = cur->left;
		}
		else{
			cur = node.top();
			cout<<cur->data<<" ";
			node.pop();
			cur = cur->right;
		}
	}
}

void preorderIterative(binarySearchTree* root){

	if(!root) return;

	stack<binarySearchTree*> node;

	node.push(root);

	while(!node.empty()){

		binarySearchTree* ptr = node.top();
		cout<<ptr->data<<" ";
		node.pop();

		if(ptr->right) node.push(ptr->right);

		if( ptr->left) node.push(ptr->left);
	}
}

void postorderIterative(binarySearchTree* root){


	if(!root) return;

	stack<binarySearchTree*> node;
	stack<int> output;

	node.push(root);

	while(!node.empty()){

		binarySearchTree* ptr= node.top();
		output.push(ptr->data);
		node.pop();

		if( ptr->left) node.push(ptr->left);

		if(ptr->right) node.push(ptr->right);
	}

	while(output.size()){
		cout<<output.top()<< " ";
		output.pop();
	}
}



int main()
{
	int n;
	cin>>n;
	binarySearchTree* root = NULL;
	FOR(i,n){
		int x;
		cin>>x;
		root = builtBinaryTree(root , x);
	}

	cout<<"\n Level Order Traversal : \n";
	LevelOrderTraversal(root);

	cout<<"\n InOrder Traversal Iterative :";
	inorderIterative(root);

	cout<<"\n PreOrder Traversal Iterative :";
	preorderIterative(root);

	cout<<"\n PostOrder Traversal Iterative :";
	postorderIterative(root);

	delete root;
	return 0;
}

/*
Input :-
7
10 8 15 6 9 13 17

output:-

 Level Order Traversal : 
10 
8 15 
6 9 13 17 

 InOrder Traversal Iterative :6 8 9 10 13 15 17 
 PreOrder Traversal Iterative :10 8 6 9 15 13 17 
 PostOrder Traversal Iterative :6 9 8 13 17 15 10 

*/
