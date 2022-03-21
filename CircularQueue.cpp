template <class T>
class CircularQueue
{
private:
	int front = 0, rear = -1;
	T data[100];

	bool IsFull()
	{
		return Size == sizeof(data) / sizeof(T);
	}

public:
	int Size = 0;

	void Enqueue(const T&);
	void Dequeue();
	T Front();
	T Back();
	bool IsEmpty();
};

template <class T>
void CircularQueue<T>::Enqueue(const T& newData)
{
	if (!IsFull())
	{
		rear = (rear + 1) % (sizeof(data) / sizeof(T));
		data[rear] = newData;
		Size++;
	}
}

template <class T>
void CircularQueue<T>::Dequeue()
{
	if (Size > 0)
	{
		front = (front + 1) % (sizeof(data) / sizeof(T));
		Size--;
	}
}

template <class T>
T CircularQueue<T>::Front()
{
	if (Size > 0)
		return data[front];
	return NULL;
}

template <class T>
T CircularQueue<T>::Back()
{
	if (Size > 0)
		return data[rear];
	return NULL;
}

template <class T>
bool CircularQueue<T>::IsEmpty()
{
	return Size == 0;
}
