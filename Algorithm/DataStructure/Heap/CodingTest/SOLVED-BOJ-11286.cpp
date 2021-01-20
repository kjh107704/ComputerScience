/**
 * [BOJ] 11286 절댓값 힙
 * 
 * @link https://www.acmicpc.net/problem/11286
 * @author Juhui Kim
 * 
 * 1st - solved
 */

#include <iostream>
#include <cmath>
#include <climits>
#define MAX 100001
using namespace std;

struct AbsHeap{

    int heap[MAX];
    int heapSize;

    AbsHeap(){
        heap[0] = 0;
        heapSize = 0;
    }

    /**
     * heap에서 절댓값이 가장 작은 값을 반환하는 함수
     * @return 절댓값이 가장 작은 값
     */
    int heapMin(){
        return heap[1];
    }

    /**
     * 현재 node의 left child의 index를 반환하는 함수
     * @param {x} 현재 node의 index
     * @return left child node의 index
     */
    int getLeft(int x){
        return 2*x;
    }

    /**
     * 현재 node의 right child의 index를 반환하는 함수
     * @param {x} 현재 node의 index
     * @return right child node의 index
     */
    int getRight(int x){
        return 2*x+1;
    }

    /**
     * 현재 node의 parent node의 index를 반환하는 함수
     * @param {x} 현재 node의 index
     * @return parent node의 index
     */
    int getParent(int x){
        return floor(x/2);
    }

    /**
     * 현재 heap의 heap size를 반환하는 함수
     * @return heap size
     */
    int getHeapSize(){
        return heapSize;
    }

    /**
     * heap size를 지정하는 함수
     * @param {x} 새로운 heap size
     */
    void setHeapSize(int x){
        heapSize = x;
        return;
    }

    /**
     * abs heap의 특성을 만족하도록 하는 함수
     * @param {x} 특성을 만족하도록 할 node의 index
     */
    void absHeapify(int x){
        int l = getLeft(x);
        int r = getRight(x);

        int smallest = x;
        if(l <= getHeapSize()){
            if((abs(heap[l]) < abs(heap[x])) || (abs(heap[l]) == abs(heap[x]) && heap[l] < heap[x]))
                smallest = l;
        }
            
        
        if(r <= getHeapSize()){
            if((abs(heap[r]) < abs(heap[smallest])) || (abs(heap[r]) == abs(heap[smallest]) && heap[r] < heap[smallest]))
                smallest = r;
        }
            

        if(smallest != x){
            swap(heap[smallest], heap[x]);
            absHeapify(smallest);
        }
    }

    /**
     * 현재 node의 key 값을 감소시키는 함수
     * @param {i} key 값을 감소시킬 node의 index
     * @param {key} 새롭게 할당할 ㅏkey 값
     */
    void increaseKey(int i, int key){
        if(abs(heap[i]) < abs(key)){
            throw invalid_argument("The new key's abs must be smaller than the current one.");
        }

        heap[i] = key;

        while(i >= 2){
            if((abs(heap[getParent(i)]) > abs(heap[i])) || (abs(heap[getParent(i)]) == abs(heap[i]) && heap[getParent(i)] > heap[i])){
                swap(heap[getParent(i)], heap[i]);
                i = getParent(i);
            }else{
                break;
            }
        }
    }

    /**
     * 새로운 값을 삽입하는 함수
     * @param {key} 새롭게 삽입할 값
     */
    void insert(int key){
        setHeapSize(getHeapSize() + 1);

        heap[getHeapSize()] = INT_MAX;

        increaseKey(getHeapSize(), key);
    }

    /**
     * 최솟값을 출력하고 제거하는 함수
     * @return abs 최솟값
     */
    int extractMin(){
        int min = heapMin();

        heap[1] = heap[getHeapSize()];

        setHeapSize(getHeapSize() - 1);

        absHeapify(1);

        return min;
    }
};

int main()
{
    int N;
    scanf("%d", &N);

    AbsHeap heap;

    int x;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);

        if(x == 0){
            printf("%d\n", heap.getHeapSize() == 0 ? 0 : heap.extractMin());
        }
        else{
            heap.insert(x);
        }
    }
}