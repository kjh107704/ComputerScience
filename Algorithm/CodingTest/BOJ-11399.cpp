/**
 * [BOJ] 11399 ATM
 * 
 * @link https://www.acmicpc.net/problem/11399
 * 
 * sort compare 함수, 오름차순 정의
 * DP를 이용해 이전 값을 기억하도록 하여 수행시간 줄임
 * 
 * 1st - solved
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int a, const int b)
{
    return a < b;
}

int main()
{
    // 사람의 수
    int N;
    scanf("%d", &N);

    vector<int> arr;

    while(N--)
    {
        int input;
        scanf("%d", &input);
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end(), compare);

    vector<int> DP(arr.size(), 0);

    long long answer = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        DP[i] = arr[i];

        if(i != 0)
            DP[i] += DP[i-1];
        
        answer += DP[i];
    }

    printf("%d", answer);
}