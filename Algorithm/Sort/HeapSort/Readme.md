# Heap Sort

- [Heap Sort](#heap-sort)
  - [Pseudo Code](#pseudo-code)
  - [수행 시간 분석](#수행-시간-분석)

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