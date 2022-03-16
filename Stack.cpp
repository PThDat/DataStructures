template <class Type>
class Stack
{
	Type data[1000];

public:
	int Size = 0;

	void Push(Type newData)
	{
		if (Size <= (sizeof(data) / sizeof(Type)))
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

	Type Top()
	{
		return data[Size - 1];
	}

	bool IsEmpty()
	{
		return Size == 0;
	}
};
