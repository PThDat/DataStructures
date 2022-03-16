template <class T>
class Stack
{
	T data[1000];

public:
	int Size = 0;

	void Push(Type newData)
	{
		if (Size <= (sizeof(data) / sizeof(T)))
		{
			data[Size] = newData;
			Size++;
		}
	}

	void Pop()
	{
		if (Size > 0)
			Size--;
	}

	T Top()
	{
		return data[Size - 1];
	}

	bool IsEmpty()
	{
		return Size == 0;
	}
};
