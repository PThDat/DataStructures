class Node
{
	int value;
public:
	Node* left = NULL;
	Node* right = NULL;

	int GetValue()
	{
		return value;
	}

	Node(int val)
	{
		value = val;
	}
};

class BinarySearchTree	
{
public:
	Node* Root = NULL;

	void Insert(int, Node*&);
	Node* Search(int, Node*&);
	void InorderTraversal(Node*);
	void PreorderTraversal(Node*);
	void PostorderTraversal(Node*);
};

void BinarySearchTree::Insert(int newValue, Node* &root)
{
	if (root == NULL)
	{
		root = new Node(newValue);
		return;
	}

	if (newValue == root->GetValue())
		return;
	if (newValue < root->GetValue())
		Insert(newValue, root->left);
	else Insert(newValue, root->right);
}

Node* BinarySearchTree::Search(int target, Node*& root)
{
	if (root == NULL)
		return NULL;

	if (root->GetValue() == target)
		return root;

	if (target < root->GetValue())
		return Search(target, root->left);
	else return Search(target, root->right);
}

void BinarySearchTree::InorderTraversal(Node* node)
{
	stack<Node*> stack;
	Node* curr = node;

	while (curr || !stack.empty())
	{
		while (curr)
		{
			stack.push(curr);
			curr = curr->left;
		}

		curr = stack.top();
		//Add method here
		stack.pop();

		curr = curr->right;
	}
}

void BinarySearchTree::PreorderTraversal(Node* node)
{
	Node* curr = node;
	stack<Node*> preCurr;

	while (curr)
	{
		//Add method here
		if (curr->right && curr->left)
		{
			preCurr.push(curr->right);
			curr = curr->left;
		}
		else if (!curr->left && curr->right)
			curr = curr->right;
		else curr = curr->left;
		if (!curr && !preCurr.empty())
		{
			curr = preCurr.top();
			preCurr.pop();
		}
	}
}

void BinarySearchTree::PostorderTraversal(Node* node)
{
	if (node == NULL)
		return;

	Node* curr = node;
	stack<Node*> s;
	stack<Node*> out;
	s.push(curr);

	while (!s.empty())
	{
		Node* curr = s.top();
		s.pop();
		out.push(curr);
		if (curr->left)
			s.push(curr->left);
		if (curr->right)
			s.push(curr->right);
	}

	while (!out.empty())
	{
		//Add method here
		out.pop();
	}
}