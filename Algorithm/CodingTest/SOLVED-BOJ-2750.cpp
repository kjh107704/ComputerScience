/**
 * 
 * [BOJ] 2750 수 정렬하기
 * 
 * @link https://www.acmicpc.net/problem/2750
 * 
 * compare 함수를 만들어서 sort함
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