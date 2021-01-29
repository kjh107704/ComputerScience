/**
 * [BOJ] 10989 수 정렬하기 3
 * 
 * @link https://www.acmicpc.net/problem/10989
 * 
 * 1st - 메모리 초과
 * 2nd - 런타임 에러 (Segfault)
 * 3rd - 런타임 에러 (Segfault)
 * 4th - 런타임 에러 (Segfault)
 * 5th - solved
 */

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

bool compare(const int a, const int b)
{
    return a <= b;
}

int main()
{
    int N;
    scanf("%d", &N);

    // 정렬할 배열
    int distinct_num[MAX] = {0};
    // 서로 다른 숫자의 개수
    int distinct_cnt = 0;
    // cnt[i] = x -> 숫자 i가 x번 나타남
    int cnt[MAX] = {0};

    for(int i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);

        if(cnt[input] != 0)
        {
            cnt[input] += 1;
            continue;
        }
        
        cnt[input] = 1;
        distinct_num[distinct_cnt] = input;
        distinct_cnt += 1;
    }

    sort(distinct_num, distinct_num+distinct_cnt, compare);

    for(int i = 0; i < distinct_cnt; i++)
        for(int j = 0; j < cnt[distinct_num[i]]; j++)
            printf("%d\n", distinct_num[i]);
}