template <class T>
class Stack
{
	T data[100];

public:
	int Size = 0;

	void Push(const T&);
	void Pop();
	T Top();
	bool IsEmpty();
};

template <class T>
void Stack<T>::Push(const T& newData)
{
	if (Size <= (sizeof(data) / sizeof(T)))
	{
		data[Size] = newData;
		Size++;
	}
}

template <class T>
void Stack<T>::Pop()
{
	if (Size > 0)
		Size--;
}

template <class T>
T Stack<T>::Top()
{
	return data[Size - 1];
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return Size == 0;
}
