

class MyQueue
{
public:
	MyQueue(int QueueCapacity);
	virtual ~MyQueue;
	void clearMyQueue();
	bool QueueEmpty();
	bool QueueFull();
	int QueueLength();
	bool EnQueue();
	bool DeQueue();
	void QueueTraverse();

private:
	int *m_Queue;
	int m_QueueLen;
	int m_QueueCapacity;
	int m_Head;
	int m_Tail;
};
