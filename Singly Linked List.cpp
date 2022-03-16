struct Node
{
    int Value;
    Node* next = NULL;

    Node(int val)
    {
        Value = val;
    }
};

struct SinglyLinkedList
{
    int Count = 0;
    Node* Head = NULL;
    Node* Tail = NULL;

    void AddHead(Node* newNode)
    {
        if (Head == NULL)
        {
            Head = Tail = newNode;
            Count++;
            return;
        }

        newNode->next = Head;
        Head = newNode;
        Count++;
    }

    void AddTail(Node* newNode)
    {
        if (Head == NULL)
        {
            Head = Tail = newNode;
            Count++;
            return;
        }

        Tail = Tail->next = newNode;
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

        if (index == Count - 1)
            return Tail;

        Node* temp = Head;

        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp;
    }

    void RemoveAt(int index)
    {
        if (index < 0 || index >= Count)
            return;

        if (index == 0)
        {
            Node* temp = Head;
            Head = Head->next;
            delete temp;
            Count--;
            return;
        }

        Node* tempPrev = ElementAt(index - 1);
        Node* elementToDelete = tempPrev->next;
        tempPrev->next = elementToDelete->next;

        if (elementToDelete == Tail)
            Tail = tempPrev;
        delete elementToDelete;
        Count--;
    }

    void SwapElement(int index1, int index2)
    {
        if (index1 < 0 || index2 < 0 || index1 >= Count || index2 >= Count || index1 == index2)
            return;

        //Make sure index2 > index1
        if (index1 > index2)
        {
            int temp = index1;
            index1 = index2;
            index2 = temp;
        }

        if (index2 - index1 == 1) //if index1 is next to index2
        {
            Node* ele1 = ElementAt(index1);
            Node* ele2 = ele1->next;
            Node* ele2Next = ele2->next;

            ele2->next = ele1;
            ele1->next = ele2Next;

            if (index1 > 0)
                ElementAt(index1 - 1)->next = ele2;

            if (index1 == 0)
                Head = ele2;
        }
        else
        {
            Node* ele1 = ElementAt(index1);
            Node* ele2Prev = ElementAt(index2-1);
            Node* ele2 = ele2Prev->next;
            Node* ele2Next = ele2->next;

            ele2->next = ele1->next;
            ele2Prev->next = ele1;
            ele1->next = ele2Next;

            if (index1 > 0)
                ElementAt(index1 - 1)->next = ele2;

            if (index1 == 0)
                Head = ele2;
            if (index2 == Count - 1)
                Tail = ele1;
        }
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
        newNode->next = tempPrev->next;
        tempPrev->next = newNode;
        Count++;
    }
};