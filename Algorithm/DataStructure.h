#pragma once

// 1. 스택을 사용하는 방법
#include <stack>

using namespace std;

void Data001()
{
	// 1. 스택을 선언해준다.
	stack<int> myStack;

	// 2. 명령어
	// 입력
	myStack.push(1);

	// 스택의 상단을 가리키는 값
	int value = myStack.top();

	// 스택의 데이터를 삭제
	myStack.pop();

	// 데이터가 비었는지 아닌지 확인하는 함수
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
