#pragma once

// 1. ������ ����ϴ� ���
#include <stack>

using namespace std;

void Data001()
{
	// 1. ������ �������ش�.
	stack<int> myStack;

	// 2. ���ɾ�
	// �Է�
	myStack.push(1);

	// ������ ����� ����Ű�� ��
	int value = myStack.top();

	// ������ �����͸� ����
	myStack.pop();

	// �����Ͱ� ������� �ƴ��� Ȯ���ϴ� �Լ�
	if (!myStack.empty())
	{
		int value = myStack.top();
	}
}

// 2. Queue
#include <queue>
void Data002()
{
	queue<int> myQueue;
	
	myQueue.push(1);
	myQueue.pop();
	myQueue.size();
	myQueue.front();
	myQueue.back();  
	myQueue.empty();
}

// 3. Deque
#include <deque>
void Data003()
{
	deque<int> myDeque;
	myDeque.pop_back();
	myDeque.pop_front();
	myDeque.push_back(1);
	myDeque.push_front(1);
	myDeque.front();
	myDeque.back();
	myDeque.size();
	myDeque.empty();
}