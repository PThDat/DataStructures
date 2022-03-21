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

    Node(const T& val)
    {
        Data = val;
    }
};

template <class T>
class SinglyLinkedList
{
    Node<T>* Head = NULL;
    Node<T>* Tail = NULL;

public:
    int Count = 0;

    void AddHead(const T &newData)
    {
        if (Head == NULL)
        {
            Head = Tail = new Node<T>(newData);
            Count++;
            return;
        }

        Node<T>* temp = new Node<T>(newData);
        temp->next = Head;
        Head = temp;
        Count++;
    }

    void AddTail(const T &newData)
    {
        if (Head == NULL)
        {
            Head = Tail = new Node<T>(newData);
            Count++;
            return;
        }

        Tail = Tail->next = new Node<T>(newData);
        Count++;
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

    void InsertAt(int index, const T &newData)
    {
        if (index <= 0)
        {
            AddHead(newData);
            return;
        }
        if (index >= Count)
        {
            AddTail(newData);
            return;
        }

        Node<T>* tempPrev = ElementAt(index - 1);
        Node<T>* temp = new Node<T>(newData);
        temp->next = tempPrev->next;
        tempPrev->next = temp;
        Count++;
    }
};
