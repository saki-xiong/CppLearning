#include"MyQueue.h"
#include<iostream>
using namespace std;


MyQueue::MyQueue(int QueueCapacity)
{
	m_QueueCapacity = QueueCapacity;
	m_Head = 0;
	m_Tail = 0;
	m_QueueLen = 0;
	m_Queue = new int[m_QueueCapacity];
}

MyQueue::~MyQueue()
{
	delete [] m_Queue;
	m_Queue = NULL;
}

void MyQueue::clearMyQueue()
{
	m_Head = 0;
	m_Tail = 0;
	m_QueueLen = 0;
}


bool MyQueue::QueueEmpty()
{
	return m_QueueLen == 0 ? true : false;
}


bool MyQueue::QueueFull()
{
	return m_QueueLen == m_QueueCapacity ? true : false;
}


int MyQueue::QueueLength()
{
	return m_QueueLen;
}

