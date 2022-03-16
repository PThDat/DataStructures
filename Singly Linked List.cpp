template <class T>
class Node
{
    T Data;    

public:
    Node<T>* next = NULL;

    T GetData()
    {
        return Data;
    }

    Node(T val)
    {
        Data = val;
    }
};

template <class T>
struct SinglyLinkedList
{
    int Count = 0;
    Node<T>* Head = NULL;
    Node<T>* Tail = NULL;

    void AddHead(Node<T>* newNode)
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

    void AddTail(Node<T>* newNode)
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

        Node<T>* temp = Head;
        cout << temp->GetData() << " ";
        while (temp->next)
        {
            temp = temp->next;
            cout << temp->GetData() << " ";
        }
    }

    Node<T>* ElementAt(int index)
    {
        if (index < 0 || index >= Count)
            return NULL;

        if (index == Count - 1)
            return Tail;

        Node<T>* temp = Head;

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
            Node<T>* temp = Head;
            Head = Head->next;
            delete temp;
            Count--;
            return;
        }

        Node<T>* tempPrev = ElementAt(index - 1);
        Node<T>* elementToDelete = tempPrev->next;
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
            Node<T>* ele1 = ElementAt(index1);
            Node<T>* ele2 = ele1->next;
            Node<T>* ele2Next = ele2->next;

            ele2->next = ele1;
            ele1->next = ele2Next;

            if (index1 > 0)
                ElementAt(index1 - 1)->next = ele2;

            if (index1 == 0)
                Head = ele2;
        }
        else
        {
            Node<T>* ele1 = ElementAt(index1);
            Node<T>* ele2Prev = ElementAt(index2 - 1);
            Node<T>* ele2 = ele2Prev->next;
            Node<T>* ele2Next = ele2->next;

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

    void InsertAt(int index, Node<T>* newNode)
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

        Node<T>* tempPrev = ElementAt(index - 1);
        newNode->next = tempPrev->next;
        tempPrev->next = newNode;
        Count++;
    }
};
