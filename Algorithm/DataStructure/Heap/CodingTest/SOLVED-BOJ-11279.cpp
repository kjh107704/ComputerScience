/**
 * [BOJ] 11279 최대 힙
 * 
 * @link https://www.acmicpc.net/problem/11279
 * @author Juhui Kim
 * 
 * 1st - runtime error: line 128이 주석처리 되어있어 배열 원소 초기화가 안 된 상태에서 원소를 참조하는 경우 발생
 * 2nd - solved
 */

#include <iostream>
#include <cmath>
#define INF 0X80000000
#define MAX 100001
using namespace std;

struct MaxHeap{

    private:

    int heap[MAX];
    int heapSize;

    public:

    MaxHeap(){
        heap[0] = 0;
        heapSize = 0;
    }

    /**
     * 현재 heap의 heapSize를 반환하는 함수
     * @return 현재 heap의 heap size
     */
    int getHeapSize(){
        return heapSize;
    }

    /**
     * heap size를 설정하는 함수
     * @param {int} x 새롭게 설정할 heap size
     */
    void setHeapSize(int x){
        heapSize = x;
        return ;
    }

    /**
     * 현재 node의 left child node의 index 값을 반환하는 함수
     * @param {x} 현재 node의 index 값
     * @return left child node의 index
     */
    int getLeft(int x){
        return 2*x;
    }

    /**
     * 현재 node의 right child node의 index 값을 반환하는 함수
     * @param {x} 현재 node의 index 값
     * @return right child node의 index
     */
    int getRight(int x){
        return 2*x+1;
    }

    /**
     * 현재 node의 parent node의 index 값을 반환하는 함수
     * @param {x} - 현재 node의 index 값
     * @return parent node의 index
     */
    int getParent(int x){
        return floor(x/2);
    }

    /**
     * 현재 heap의 가장 큰 값을 반환하는 함수
     * @return heap의 maximum value
     */
    int getHeapMax(){
        return heap[1];
    }

    /**
     * 현재 node가 max heap의 특성을 만족하도록 하는 함수
     * @param {x} 현재 node의 index 값
     */
    void maxHeapify(int x){
        int l = getLeft(x);
        int r = getRight(x);

        int largest = x;
        if(l <= getHeapSize() && heap[x] < heap[l])
            largest = l;

        if(r <= getHeapSize() && heap[largest] < heap[r])
            largest = r;
        
        if(largest != x){
            swap(heap[largest], heap[x]);
            maxHeapify(largest);
        }
    }

    /**
     * 현재 node의 key값을 증가시키며 heap 특성을 만족하도록 하는 함수
     * @param {i} 현재 node의 index 값
     * @param {key} 증가시킬 새로운 key 값
     */
    void increaseKey(int i, int key){
        if(heap[i] > key){
            throw invalid_argument("The new key must be bigger than the current one.");
        }

        heap[i] = key;

        while(i >= 2 && heap[getParent(i)] < heap[i]){
            swap(heap[getParent(i)], heap[i]);
            i = getParent(i);
        }
    }

    /**
     * 새로운 node를 heap에 삽입하는 함수
     * @param {key} 새롭게 삽입할 key값
     */
    void insert(int key){
        setHeapSize(getHeapSize() + 1);

        heap[getHeapSize()] = (INF) + 1;

        increaseKey(getHeapSize(), key);        
    }

    /**
     * heap에서 max값을 출력하고 제거하는 함수
     * @return heap에 있는 max value
     */
    int extractMax(){
        int max = heap[1];

        heap[1] = heap[getHeapSize()];

        setHeapSize(getHeapSize() - 1);

        maxHeapify(1);

        return max;
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    MaxHeap heap;

    int x;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);

        if(x > 0){
            heap.insert(x);
        }
        else{
            printf("%d\n", heap.getHeapSize() == 0? 0: heap.extractMax());
        }
    }
}