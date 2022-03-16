struct Node
{
	int Value;
	Node* next = NULL;
	Node* prev = NULL;

	Node(int val)
	{
		Value = val;
	}
};

struct DoublyLinkedList
{
	unsigned int Count = 0;
	Node* Head = NULL;
	Node* Tail = NULL;

	void AddTail(Node* newNode)
	{
		if (Head == NULL)
		{
			Head = Tail = newNode;
			Count++;
			return;
		}

		Node* temp = Tail;
		Tail = Tail->next = newNode;
		Tail->prev = temp;
		Count++;
	}

	void AddHead(Node* newNode)
	{
		if (Head == NULL)
		{
			Head = Tail = newNode;
			Count++;
			return;
		}

		Head->prev = newNode;
		newNode->next = Head;
		Head = newNode;
		Count++;
	}

	void Print()
	{
		if (Head == NULL)
			return;
		Node* temp = Head;
		cout << temp->Value << " ";
		while (temp->next)
		{
			temp = temp->next;
			cout << temp->Value << " ";
		}
	}

	Node* ElementAt(int index)
	{
		if (index < 0 || index >= Count)
			return NULL;

		Node* temp;
		if (index <= (Count - 1) / 2)
		{
			temp = Head;
			for (int i = 0; i < index; i++)
				temp = temp->next;
		}
		else
		{
			temp = Tail;
			for (int i = Count - 1; i > index; i--)
				temp = temp->prev;
		}

		return temp;
	}

	void RemoveAt(int index)
	{
		if (index < 0 || index >= Count)
			return;

		Node* temp = ElementAt(index);
		if (temp->prev != NULL)
			temp->prev->next = temp->next;
		if (temp->next != NULL)
		temp->next->prev = temp->prev;

		if (temp == Head)
			Head = temp->next;
		else if (temp == Tail)
			Tail = temp->prev;

		delete temp;
		Count--;
	}

	void SwapElement(int index1, int index2)
	{
		if (index1 >= Count || index2 >= Count || index1 < 0 || index2 < 0 || index1 == index2)
			return;
		
		//make sure index2 > index1
		if (index1 > index2)
		{
			int temp = index1;
			index1 = index2;
			index2 = temp;
		}
		Node* ele1 = ElementAt(index1);
		Node* ele2 = ElementAt(index2);

		if (index2 - index1 == 1) //if i1 is next to i2
		{
			ele1->prev->next = ele2;
			ele1->next = ele2->next;
			ele2->prev = ele1->prev;
			ele1->prev = ele2;
			ele2->next = ele1;
			ele1->next->prev = ele1;
		}
		else
		{
			//Store the path
			Node* temp = new Node(0);
			temp->next = ele1->next;
			temp->prev = ele1->prev;

			//ele1 replaces ele2
			ele1->next = ele2->next;
			ele1->prev = ele2->prev;
			if (ele1->prev)
				ele1->prev->next = ele1;
			if (ele1->next)
				ele1->next->prev = ele1;

			//ele2 fills ele1's old position
			ele2->next = temp->next;
			ele2->prev = temp->prev;
			if (ele2->next)
				ele2->next->prev = ele2;
			if (ele2->prev)
				ele2->prev->next = ele2;
			//Release memory
			delete temp;
		}

		//Redirect Head and Tail
		if (ele1 == Head)
			Head = ele2;
		else if (ele2 == Head)
			Head = ele1;
		if (ele1 == Tail)
			Tail = ele2;
		else if (ele2 == Tail)
			Tail = ele1;
	}

	void InsertAt(int index, Node* newNode)
	{
		if (index <= 0)
		{
			AddHead(newNode);
			return;
		}
		if (index >= Count)
		{
			AddTail(newNode);
			return;
		}

		Node* tempPrev = ElementAt(index - 1);
		Node* tempNext = tempPrev->next;
		tempNext->prev = tempPrev->next = newNode;
		newNode->next = tempNext;
		newNode->prev = tempPrev;
		Count++;
	}
};