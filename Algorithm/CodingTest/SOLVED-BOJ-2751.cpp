/**
 * [BOJ] 2751 수 정렬하기 2
 * 
 * @link https://www.acmicpc.net/problem/2751
 * 
 * 1st - solved
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(const int a, const int b)
{
    return a < b;
}

int main()
{
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

    for(int i = 0; i < arr.size(); i++)
        printf("%d\n", arr[i]);
}