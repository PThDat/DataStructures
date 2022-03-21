template <class T>
class CircularQueue
{
private:
	int front = 0, rear = -1;
	T data[1000];

	bool IsFull()
	{
		return Size == sizeof(data) / sizeof(T);
	}

public:
	int Size = 0;

	void Enqueue(const T& newData)
	{
		if (!IsFull())
		{
			rear = (rear + 1) % (sizeof(data) / sizeof(T));
			data[rear] = newData;
			Size++;
		}
	}

	void Dequeue()
	{
		if (Size > 0)
		{
			front = (front + 1) % (sizeof(data) / sizeof(T));
			Size--;
		}
	}

	T Front()
	{
		if (Size > 0)
			return data[front];
		return NULL;
	}

	T Back()
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
