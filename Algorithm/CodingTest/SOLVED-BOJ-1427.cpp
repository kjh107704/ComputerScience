/**
 * [BOJ] 1427 소트인사이드
 * 
 * @link https://www.acmicpc.net/problem/1427
 * 
 * 1st - solved
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const int a, const int b)
{
    return a > b;
}

int main()
{
    int N;
    scanf("%d", &N);

    vector<int> arr;

    while(N != 0)
    {
        arr.push_back(N%10);
        N /= 10;
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < arr.size(); i++)
        printf("%d",arr[i]);
}