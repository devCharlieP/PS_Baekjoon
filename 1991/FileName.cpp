#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

class Node
{
public:
	char data;
	Node* left;
	Node* right;
};

void preorder(Node* root)
{
	if (root != nullptr)
	{
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

void postorder(Node* root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Node> vec(N);

	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;

		vec[a - 'A'].data = a;
		
		if (b != '.')
		{
			vec[a - 'A'].left = &vec[b - 'A'];
		}
		else
		{
			vec[a - 'A'].left = nullptr;
		}

		if (c != '.')
		{
			vec[a - 'A'].right = &vec[c - 'A'];
		}
		else
		{
			vec[a - 'A'].right == nullptr;
		}
	}

	Node* root = &vec[0];

	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);

	return 0;
}