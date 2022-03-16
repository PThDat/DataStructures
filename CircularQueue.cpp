template <class Type> class CircularQueue
{
private:
	int front = 0, rear = -1;
	Type data[4];

	bool IsFull()
	{
		return Size == sizeof(data) / sizeof(Type);
	}

public:
	int Size = 0;

	void Enqueue(Type newData)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % (sizeof(data) / sizeof(Type));
			data[rear] = newData;
			Size++;
		}
	}

	void Dequeue()
	{
		if (Size > 0)
		{
			front = (front + 1) % (sizeof(data) / sizeof(Type));
			Size--;
		}
	}

	Type Front()
	{
		if (Size > 0)
			return data[front];
		return NULL;
	}

	Type Back()
	{
		if (Size > 0)
			return data[rear];
		return NULL;
	}

	bool IsEmpty()
	{
		return Size == 0;
	}
};
