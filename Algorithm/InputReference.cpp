#include "InputReference.h"
#include <iostream>

void InputExample()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// 의미 : stdio.h - iostream을 동기화 해준다
	// 버퍼 <- iostream, stdio.h

	std::cout << "My ";
	printf("Name");
}
