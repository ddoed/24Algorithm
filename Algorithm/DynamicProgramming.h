#pragma once
#include <vector>
#define DEFAULT -1
// 예시 1. 피보나치 수를 찾는 문제
// 첫번째 수가 0이고, 두번째 수가 1인 수열이 있다
// 세번째부터는 첫번째 수와 두번째 수의 합으로 이루어진 수열을 피보나치 수열이라고 한다
// n번째에 해당하는 수는?

int Fibonacci(int n);

int Fibonacci_DP(int n);


// 예시 2. 계단의 층에는 각각 점수가 주어진다
// 목표 층까지 도달할 때 가장 높은 점수로 계단을 밟고 지나가는 경우의 수를 구하라
// 가장 높은 점수가 무엇인가?
// 규칙1. 계단은 한번에 1개 또는 2개씩만 오를 수 있다
// 규칙2. 연속해서 계단을 1개씩만 오를 수 없다
// 규칙3. 위 방식으로 최대의 값을 얻는 방식으로 계단을 오르시오

int StairCount(std::vector<int> stairs);

int max_stair_recursive(int i, std::vector<int> stairs);