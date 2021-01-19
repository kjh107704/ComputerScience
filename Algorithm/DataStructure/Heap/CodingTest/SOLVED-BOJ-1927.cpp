/**
 * [BOJ] 1927 최소 힙
 * 
 * @link https://www.acmicpc.net/problem/1927
 * @author Juhui Kim
 * 
 * 1st - runtime error : vector 사용 때문 예측, 배열로 바꿈
 * 2nd - wrong answer : line92 index 부등호 틀린 것 고침, 디버그 때문에 vector로 바꿈
 * 3rd - runtime error : vector 사용 때문 예측, 배열로 바꿈
 * 4th - correct answer
 */

#include <iostream>
#include <cmath>
#define INF 1ULL<<31
#define MAX 100001
using namespace std;

struct MinHeap{

    private:
        int heap[MAX];
        int heapsize;

    public:

    MinHeap(){
        heap[0] = 0;
        heapsize = 0;
    }

    /**
     * 현재 heap size를 반환하는 함수
     */
    int getHeapSize(){
        return heapsize;
    }

    /**
     * heap size를 설정하는 함수
     * @param {int} x 새롭게 설정할 heap size
     */

    void setHeapSize(int x){
        heapsize = x;
        return ;
    }

    /**
     * 현재 노드의 왼쪽 자식 노드의 인덱스 값을 반환하는 함수
     * @param {int} x 현재 노드의 인덱스 값
     */
    int getLeft(int x){
        return 2*x;
    }

    /**
     * 현재 노드의 왼쪽 자식 노드의 인덱스 값을 반환하는 함수
     * @param {int} x 현재 노드의 인덱스 값 
     */
    int getRight(int x){
        return 2*x + 1;
    }
    
    /**
     * 현재 노드의 부모 노드의 인덱스 값을 반환하는 함수
     * @param {int} x 현재 노드의 인덱스 값
     */
    int getParent(int x){
        return floor(x/2);
    }

    /**
     * 힙의 최소 원소값을 반환하는 함수 
     */
    int heapMin(){
        return heap[1];
    }

    /**
     * 어떤 노드의 key 값을 줄이는 함수
     * @param {int} i 값을 줄이고자 하는 노드의 인덱스 값
     * @param {int} key 설정하고자 하는 값
     */
    void decreaseKey(int i, int key){
        if(heap[i] < key){
            printf("current one = %d", heap[i]);
            throw invalid_argument("The new key must be smaller than the current one.");
        }

        heap[i] = key;

        while(i >= 2 && heap[getParent(i)] > heap[i]){
            swap(heap[getParent(i)], heap[i]);
            i = getParent(i);
        }
    }

    /**
     * 새로운 값을 힙에 삽입하는 함수
     * @param {int} x 삽입하고자 하는 값
     */
    void insert(int x){
        setHeapSize(getHeapSize() + 1);

        // 원래는 INF 값으로 initialize 해야 하지만, vector의 type이 int 이므로 INF-1 삽입.
        heap[getHeapSize()] = (INF) - 1;
        
        decreaseKey(getHeapSize(), x);
    }

    /**
     * 힙이 최소 힙의 성질을 만족하도록 하는 함수
     * @param {int} x 최소 힙 성질을 만족하는지 테스트하기 위한 노드
     */
    void minHeapify(int x){
        int l = getLeft(x);
        int r = getRight(x);

        int smallest = x;
        if(l <= getHeapSize() && heap[x] > heap[l])
            smallest = l;

        if(r <= getHeapSize() && heap[smallest] > heap[r])
            smallest = r;
        
        if(smallest != x){
            swap(heap[smallest], heap[x]);
            minHeapify(smallest);
        }
    }

    /**
     * 힙에서 최소 값을 반환하고, 힙에서 그 값을 삭제하는 함수
     */
    int extractMin(){

        if(getHeapSize() < 1){
            throw invalid_argument("heap underflow");
        }

        int min = this->heapMin();
        heap[1] = heap[getHeapSize()];
        setHeapSize(getHeapSize()-1);

        minHeapify(1);

        return min;
    }
};

int main()
{
    // 연산의 개수
    int N;
    scanf("%d", &N);

    MinHeap minHeap;
    
    int x;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);

        if(x > 0){
            // 배열에 x라는 값을 넣는 연산 (insert)
            minHeap.insert(x);
        }
        else{
            // 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거함 (pop)
            // 배열이 비어 있을 경우, 0을 출력
            printf("%d\n", minHeap.getHeapSize() == 0 ? 0 : minHeap.extractMin());
        }
    }
    return 0;
}