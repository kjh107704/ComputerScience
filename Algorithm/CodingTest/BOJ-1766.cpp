/**
 * [BOJ] 1766 문제집
 * 
 * @link https://www.acmicpc.net/problem/1766
 * @author Juhui Kim
 * 
 * 1st - runtime error (OutOfBounds)
 * 2nd - solved
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // 문제의 수
    int N;

    // 정보의 개수
    int M;
    scanf("%d %d", &N, &M);

    //problem_info[a] = {b, c, d} : 문제 a를 먼저 풀어야 b, c, d를 풀 수 있음
    vector<vector<int>> problem_info(N+1, vector<int>(0));
    //problem_cnt[a] = 3 : 문제 a를 풀기 전에 먼저 풀어야 할 문제가 3개 남음
    vector<int> problem_cnt(N+1,0);

    // 문제 A를 문제 B보다 먼저 푸는 것이 좋음
    int A, B;
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);

        problem_info[A].push_back(B);
        problem_cnt[B] += 1;
    }

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i <= N; i++)
    {
        if(problem_cnt[i] == 0)
            pq.push(i);
    }

    while(!pq.empty())
    {
        int top = pq.top();
        pq.pop();
        printf("%d ", top);

        for(int i = 0; i < problem_info[top].size(); i++)
        {
            int next = problem_info[top][i];
            problem_cnt[next] -= 1;

            if(problem_cnt[next] == 0)
                pq.push(next);
        }
    }
}