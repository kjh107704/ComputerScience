# Heap Sort

- [Heap Sort](#heap-sort)
  - [Pseudo Code](#pseudo-code)
  - [수행 시간 분석](#수행-시간-분석)
  - [생각해 볼 문제](#생각해-볼-문제)

****

Heap sort는 heap 자료구조를 기반으로 진행한다.

이 글은 heap 자료구조의 기본 프로시저인 `MAX-HEAPIFY`, `BUILD-MAX-HEAP`의 수도코드 및 수행 시간 분석에 대한 이해를 기본으로 한다.

heap 자료구조의 기본 프로시저의 수도코드 및 수행 시간 분석은 [Heap Readme](../../DataStructure/Heap/Readme.md)에 정리되어 있으므로, 이 페이지에서는 설명을 생략한다.

## Pseudo Code

```
HEAP-SORT(A)

    BUILD-MAX-HEAP(A)

    for i = A.length downto 2
        exchange A[1] with A[i]
        A.heap-size = A.heap-size - 1
        MAX-HEAPIFY(A, 1)
```

## 수행 시간 분석

`BUILD-MAX-HEAP`이 ![equation](https://latex.codecogs.com/svg.latex?O(n)) 시간이 걸린다.

여기에 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 시간이 걸리는 `MAX-HEAPIFY`를 n-1번 실행한다.

따라서, `HEAP-SORT`의 수행 시간의 상한은

![equation](https://latex.codecogs.com/svg.latex?O(n)&plus;O(\log{n})\times&space;(n-1)=O(n\log{n}))

![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 임을 알 수 있다.

## 생각해 볼 문제

1. 오름차순으로 정렬된 n개짜리 배열 A를 힙 정렬하는데 걸리는 시간은 얼마나 되는가? 내림차순인 경우에는 어떠한가? (6.4-3)

  여기서 고려하는 heap sort는 max-heap을 이용한 오름차순 정렬이다.

  오름차순으로 정렬된 n개짜리 배열 A를 heap sort 할 경우를 살펴보자.
  
  먼저 `BUILD-MAX-HEAP`을 거치게 된다. 이 과정에서 최악의 시간이 걸리게 되므로, ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 의 시간이 걸린다.

  또한, 이후 `for loop`을 통해 `MAX-HEAPIFY`를 반복적으로 부르는 과정에서 ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 의 시간이 걸린다.

  따라서, 오름차순으로 정렬된 n개짜리 배열 A를 heap sort 할 경우

  ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})&plus;O(n\log{n})=O(n\log{n}))

  ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 의 시간이 걸린다.

  내림차순으로 정렬된 n개짜리 배열 A를 heap sort 할 경우를 살펴보자.

  `BUILD-MAX-HEAP`을 거칠 때, 이미 max-heap 특성을 만족하도록 배열이 정렬되어 있으므로 이 함수 안에서 호출되는 `MAX-HEAPIFY`가 상수 시간만에 끝나게 된다. 따라서, `BUILD-MAX-HEAP`은 ![equation](https://latex.codecogs.com/svg.latex?O(n)) 에 끝나게 된다.

  또한, 이후 'for loop'을 통해 `MAX-HEAPIFY`를 반복적으로 부르게 되고, 이 과정은 오름차순 배열 정렬 시와 마찬가지로 ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 의 시간이 걸린다.

  따라서, 내림차순으로 정렬된 n개짜리 배열 A를 heap sort 할 경우

  ![equation](https://latex.codecogs.com/svg.latex?O(n)&space;&plus;&space;O(\log{n})&space;=&space;O(\log{n}))

  ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 의 시간이 걸린다.

  사실 heap sort는 최악의 경우와 최선의 경우 모두 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 의 시간이 걸리므로, 입력 자료의 상태와 상관 없이 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 의 수행 시간이 보장되어 있다.