# Priority Queue

- [Priority Queue](#priority-queue)
  - [Priority Queue의 정의](#priority-queue의-정의)
  - [Priority Queue의 응용](#priority-queue의-응용)
  - [Priority Queue의 기본 프로시저](#priority-queue의-기본-프로시저)
    - [MAXIMUM](#maximum)
      - [Pseudo Code](#pseudo-code)
      - [수행 시간 분석](#수행-시간-분석)
    - [EXTRACT-MAX](#extract-max)
      - [Pseudo Code](#pseudo-code-1)
      - [수행 시간 분석](#수행-시간-분석-1)
    - [INCREASE-KEY](#increase-key)
      - [Pseudo Code](#pseudo-code-2)
      - [수행 시간 분석](#수행-시간-분석-2)
    - [INSERT](#insert)
      - [Pseudo Code](#pseudo-code-3)
      - [수행 시간 분석](#수행-시간-분석-3)

****

Priority Queue는 heap의 대중적인 응용 중 하나이다.

Priority Queue에도 heap과 같이 **max-priority-queue**와 **min-priority-queue** 두 가지가 있다.

이 글에서는 max-heap을 기반으로 하여 max-priority-queue를 구현하는 프로시저에 대해 초점을 맞춘다.

## Priority Queue의 정의

Priority Queue는 key라는 값을 가진 원소들의 집합 S를 다루기 위한 자료구조이다.

## Priority Queue의 응용

Priority Queue는 다양하게 응용될 수 있다.

1. max-priority-queue

   - 공유 컴퓨터에서 작업 순서를 계획하는 것

2. min-priority-queue

    - 사건 반응형 시뮬레이터

## Priority Queue의 기본 프로시저

max-priority-queue를 기준으로, 다음과 같은 프로시저를 제공한다.

### MAXIMUM

S에서 key값이 최대인 원소를 return 한다.

#### Pseudo Code

```
HEAP-MAXIMUM(A)

    return A[1]
```

#### 수행 시간 분석

`HEAP-MAXIMUM` 함수는 ![equation](https://latex.codecogs.com/svg.latex?\theta(1)) 시간에 동작한다.

### EXTRACT-MAX

S에서 key값이 최대인 원소를 제거한다.

#### Pseudo Code

```
HEAP-EXTRACT-MAX(A)

    if A.heap-size < 1
        error "heap underflow"

    max = A[1]
    A[1] = A[A.heap-size]
    A.heap-size = A.heap-size - 1

    MAX-HEAPIFY(A, 1)

    return max
```

#### 수행 시간 분석

`HEAP-EXTRACT-MAX` 함수는 `MAX-HEAPIFY` 함수에 의하여 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 의 시간이 걸린다.

### INCREASE-KEY

원소 x의 key값을 k로 증가시킨다. 이때, k는 현재 x의 key값보다 작아지지 않는다고 가정한다.

#### Pseudo Code

```
HEAP-INCREASE-KEY(A, i, key)

    if A[i] > key
        error "새로운 키가 현재 키보다 작다"

    A[i] = key

    while i < 2 and A[Parent(i)] < A[i]
        exchange A[Parent(i)] with A[i]
        i = Parent(i)
```

#### 수행 시간 분석

최악의 경우 갱신된 node로부터 root node까지 올라가야 하기 때문에, `HEAP-INCREASE-KEY` 의 수행 시간의 상한은 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 이다.

### INSERT

S에 원소 x를 새로 넣는 연산을 지원하는 함수이다.

#### Pseudo Code

```
MAX-HEAP-INSERT(A, key)

    A.heap-size = A.heap-size + 1
    A[A.heap-size] = -inf
    HEAP-INCREASE-KEY(A, A.heap-size, key)
```

#### 수행 시간 분석

`MAX-HEAP-INSERT` 함수는 `HEAP-INCREASE-KEY` 함수에 의해 수행 시간의 상한이 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 이다.

>   T. Cormen, C. Leiserson, R. Rivest and C. Stein, 『Introduction to Algorithms, 문병로, 심규석, 이충세 옮김, 한빛아카데미(2014), p153-p171<br>