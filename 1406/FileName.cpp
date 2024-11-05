#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	char c;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Node* head = new Node;

	Node* ptr = head;

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (ptr == head)
		{
			Node* n = new Node;

			head->right = n;
			n->left = head;
			n->c = s[i];

			ptr = n;
		}
		else
		{
			Node* n = new Node;

			ptr->right = n;
			n->left = ptr;
			n->c = s[i];

			ptr = n;
		}
	}

	Node* tail = new Node;
	ptr->right = tail;
	tail->left = ptr;

	ptr = tail->left;

	int M;
	cin >> M;

	char c;

	for (int i = 0; i < M; i++)
	{
		cin >> c;

		if (c == 'L')
		{	
			if (ptr != head)
			{
				ptr = ptr->left;
			}
		}
		else if (c == 'D')
		{
			if (ptr != tail->left)
			{
				ptr = ptr->right;
			}
		}
		else if (c == 'B')
		{
			if (ptr != head)
			{
				ptr->left->right = ptr->right;
				ptr->right->left = ptr->left;
				ptr = ptr->left;
			}
		}
		else
		{
			char ch;
			cin >> ch;

			Node* n = new Node;
			n->c = ch;

			n->left = ptr;
			n->right = ptr->right;

			n->left->right = n;
			n->right->left = n;

			ptr = ptr->right;
		}
	}

	ptr = head->right;

	while (ptr != tail)
	{
		cout << ptr->c;
		ptr = ptr->right;
	}

	return 0;
}