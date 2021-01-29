/**
 * [BOJ] 1655 가운데를 말해요
 * 
 * @link https://www.acmicpc.net/problem/1655
 * @author Juhui Kim
 * 
 * 단순 heap 구조는 순서대로 정렬되어 있는 것이 아님.
 * 따라서, 단순 heap 구조에서 가운데 index가 중앙값이라고 말할 수 없음.
 * 정녕 정렬이 필요한 것인가?
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#define MAX 100001
#define INF 10001
using namespace std;

struct MinHeap
{
    //int heap[MAX];
    vector<int> heap;
    int heapSize;

    MinHeap()
    {
        //heap[0] = 0;
        heap = vector<int>(1,0);
        heapSize = 0;
    }

    /**
     * 새로운 값을 heap에 집어넣음
     * @param {x} 새로 넣을 value
     */
    void insert(int x)
    {
        heapSize += 1;

        //heap[heapSize] = x;
        heap.push_back(x);

        int i = heapSize;
        while(i >= 2 && heap[(int)floor((double)i/2)] > heap[i])
        {
            swap(heap[(int)floor((double)i/2)], heap[i]);
            i = (int)floor((double)i/2);
        }
    }

    int getMid()
    {
        // 수의 개수가 짝수개이면
        if(heapSize %2 == 0)
        {
            int mid_idx = heapSize/2;
            if(heap[mid_idx] > heap[mid_idx + 1])
                return heap[mid_idx + 1];
            else
                return heap[mid_idx];
        }
        // 수의 개수가 홀수개이면
        else
        {
            return heap[(int)ceil((double)heapSize/2)];
        }
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    MinHeap heap;

    int x;
    while(N--)
    {
        scanf("%d", &x);

        heap.insert(x);
        printf("%d\n", heap.getMid());
    }
}