# Heap

- [Heap](#heap)
  - [Heap의 기본 개념](#heap의-기본-개념)
    - [Heap 객체 구성 요소](#heap-객체-구성-요소)
    - [Heap index 계산](#heap-index-계산)
      - [LEFT, RIGHT, PARENT](#left-right-parent)
    - [Heap의 종류](#heap의-종류)
    - [Heap의 높이](#heap의-높이)
  - [Heap의 기본 프로시저](#heap의-기본-프로시저)
    - [MAX-HEAPIFY](#max-heapify)
      - [Pseudo Code](#pseudo-code)
      - [수행 시간 분석](#수행-시간-분석)
    - [BUILD-MAX-HEAP](#build-max-heap)
      - [Pseudo Code](#pseudo-code-1)
      - [수행 시간 분석](#수행-시간-분석-1)
        - [단순 분석](#단순-분석)
        - [정확한 분석](#정확한-분석)
  - [생각해 볼 문제](#생각해-볼-문제)

****

## Heap의 기본 개념

(binary) heap 자료구조는 **complete binary tree**특성을 가지는 배열 객체이다.

### Heap 객체 구성 요소

heap을 나타내는 배열 A는 다음 두 개의 인자를 가진다.
1. A.length
   
   배열 A의 모든 원소의 개수를 나타낸다.

2. A.heap-size

    배열 A의 원소 중 heap에 속하는 원소의 개수를 나타낸다. 단, ![equation](https://latex.codecogs.com/svg.latex?0\leq&space;A.heap-size\leq&space;A.length)을 만족한다.

    배열 A의 모든 원소가 heap에 속하지 않을 수 있다. ![equation](https://latex.codecogs.com/svg.latex?A[1..A.length])의 값들 중, ![equation](https://latex.codecogs.com/svg.latex?A[1..A.heap-size])에 속한 값만 heap 내부에 있는 원소이다. 

### Heap index 계산

tree index의 편의를 위해, tree의 root는 A[1]이다.

heap에 속한 어떤 node의 index i가 주어지면, parent node, left-child node, right-child node의 index를 아래의 방법으로 쉽게 계산할 수 있다.

#### LEFT, RIGHT, PARENT

heap의 i번째 node의 left child, right child, parent의 index를 return 하는 함수

```
LEFT(i)

    return 2*i
```

```
RIGHT(i)

    return 2*i + 1
```

```
PARENT(i)

    return floor(i/2)
```

위의 계산들은 2를 곱하거나 나누는 연산들이므로, bit shift 연산으로 쉽게 해결할 수 있다.

### Heap의 종류

binary heap는 크게 **max-heap**, **min-heap** 두 종류로 나눌 수 있다. heap의 종류에 따라 heap 특성이 달라진다.

1. max-heap
   
   root node를 제외한 모든 node에 대해 다음을 만족한다.

   ![equation](https://latex.codecogs.com/svg.latex?A[Parent(i)]]&space;\geq&space;A[i])

   **즉, max-heap에서 최댓값은 root에 있다.**

2. min-heap

    root node를 제외한 모든 node에 대해 다음을 만족한다.

    ![equation](https://latex.codecogs.com/svg.latex?A[Parent(i)]]&space;\leq&space;A[i])

    **즉, min-heap에서 최솟값은 root에 있다.**

### Heap의 높이

1. node의 높이

    해당 node에서 leaf node에 이르는 하향 경로 중, 가장 긴 것의 간선의 수
    
2. Heap의 높이

    root node의 높이와 같다

heap은 complete binary tree를 기반으로 하므로, 원소 개수가 n인 heap의 높이는 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 이다.

## Heap의 기본 프로시저

### MAX-HEAPIFY

max heap 특성을 유지할 수 있도록 하는 함수이다.

parent node가 child node보다 작은 경우, parent node를 max heap 특성을 만족할 때 까지 아래로 계속 내린다.

#### Pseudo Code

```
MAX-HEAPIFY(A, i)

    l = LEFT(i)
    r = RIGHT(i)

    if l < A.heap-size and A[l] > A[i]
        largest = l
    else
        largest = i

    if r < A.heap-size and A[r] > A[i]
        largest = r

    if largest != i
        exchange A[i] with A[largest]
        MAX-HEAPIFY(A, largest)
```

#### 수행 시간 분석

높이가 h인 node에서 `MAX-HEAPIFY`를 call 할 경우를 생각해 보자.

최악의 경우 높이 h부터 leafnode에 도달할 때 까지 MAX-HEAPIFY를 재귀적으로 호출할 수 있다.

따라서, 높이가 h인 node에서 `MAX-HEAPIFY` 수행 시간의 상한은 ![equation](https://latex.codecogs.com/svg.latex?O(h)).

### BUILD-MAX-HEAP

배열 A[1, ..., n]를 max heap으로 만드는 함수이다.

`MAX-HEAPIFY` 프로시저를 heap의 leaf node를 제외한 나머지 node에 대해 바닥에서부터 시작하여 위로 올라가며 적용한다.

![equation](https://latex.codecogs.com/svg.latex?A[(\left&space;\lfloor&space;\frac{n}{2}&space;\right&space;\rfloor&plus;1)...n])의 원소는 모두 tree의 leaf node이므로, 원소의 개수가 하나인 heap이라고 볼 수 있다. 따라서, leaf node를 제외한 나머지 node들에 대하여 `MAX-HEAPIFY`를 적용한다.

#### Pseudo Code

```
BUILD-MAX-HEAP(A)

    A.heap-size = A.length

    for i = floor(A.length/2) downto 1
        MAX-HEAPIFY(A, i)
```

#### 수행 시간 분석

##### 단순 분석

단순하게 생각할 경우, node의 개수가 n개인 heap에서 `MAX-HEAPIFY`는 한 번의 call 마다 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 이 걸린다고 볼 수 있다. 왜냐하면, node의 개수가 n인 heap의 최대 높이가 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n}))이기 때문이다.

![equation](https://latex.codecogs.com/svg.latex?O(\log{n}))의 수행 시간을 가지는 `MAX-HEAPIFY`를 `BUILD-MAX-HEAP`이 ![equation](https://latex.codecogs.com/svg.latex?O(n))번 call 하게 되므로, 

`BUILD-MAX-HEAP`을 단순 분석했을 때 수행 시간의 상한은

![equation](https://latex.codecogs.com/svg.latex?O(\log{n})\times&space;O(n)&space;=&space;O(n\log{n}))

하지만, `MAX-HEAPIFY`의 수행 시간이 node의 높이에 따라 다르고, node 대부분의 높이가 다른 점을 고려하여 수행 시간을 개선할 여지가 있다.

##### 정확한 분석

이 분석에서는 다음을 이용한다.

1. 원소가 n개인 heap의 높이는 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor) 이다.
2. 높이가 h인 노드 수는 최대 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lceil&space;\frac{n}{2^{h&plus;1}}&space;\right&space;\rceil) 이다.

높이가 h인 node에서 호출된 `MAX-HEAPIFY`의 수행시간은 ![equation](https://latex.codecogs.com/svg.latex?O(h))이다. 

`BUILD-MAX-HEAP`은 leaf node를 제외한 모든 node에서 `MAX-HEAPIFY`를 call 한다.

따라서, `BUILD-MAX-HEAP`의 총 수행시간을 다음과 같이 나타낼 수 있다.

![equation](https://latex.codecogs.com/svg.latex?\sum_{h=0}^{\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor}\left&space;\lfloor&space;\frac{n}{2^{h&plus;1}}&space;\right&space;\rfloor&space;O(h)&space;=&space;O(n\sum_{h=0}^{\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor}\frac{h}{2^{h}}))

node의 수가 매우 많을 경우를 생각해 보면, 다음의 공식을 이용해 식을 정리할 수 있다. (단, ![equation](https://latex.codecogs.com/svg.latex?\left&space;|&space;x&space;\right&space;|&space;<&space;1))

![equation](https://latex.codecogs.com/svg.latex?\sum_{k=0}^{\infty&space;}kx^{k}=\frac{x}{(1-x)^2})

위의 식을 공식을 이용하여 정리하면,

![equation](https://latex.codecogs.com/svg.latex?O(n\sum_{h=0}^{\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor}\frac{h}{2^{h}})=O(n\sum_{h=0}^{\infty}\frac{h}{2^h})=O(2n)=O(n))

이므로, `BUILD-MAX-HEAP`의 수행 시간의 상한은 ![equation](https://latex.codecogs.com/svg.latex?O(n)) 이다.

## 생각해 볼 문제

1. **높이가 h인 heap의 최대, 최소 원소 수는 각각 얼마인가? (6.1-1)**

    binary heap 자료구조는 complete binary tree를 기반으로 한다. 

    만약, heap의 높이가 ![equation](https://latex.codecogs.com/svg.latex?h) 라면, complete binary tree 특성에 의하여 높이 ![equation](https://latex.codecogs.com/svg.latex?h-1) 까지는 모든 node가 존재한다.

    이때, 높이 ![equation](https://latex.codecogs.com/svg.latex?h-1) 까지의 node 개수는 아래의 계산에 의해 ![equation](https://latex.codecogs.com/svg.latex?2^{h}-1) 이다.

    ![equation](https://latex.codecogs.com/svg.latex?2^{0}&plus;2^{1}&plus;...&plus;2^{h-1}&space;=&space;\sum_{h=0}^{h-1}2^{h}=\frac{2^{h}-1}{2-1}=2^{h}-1)

    여기에 높이 h에는 최소 1개의 원소부터 ![equation](https://latex.codecogs.com/svg.latex?2^{h}) 개의 원소가 있을 수 있다.

    따라서 이를 조합하면, 
    
    높이가 h인 heap의 최소 원소 수는 ![equation](https://latex.codecogs.com/svg.latex?2^{h}&space;(\because&space;(2^{h}-1)&plus;1)) 이며, 
    
    최대 원소 수는 ![equation](https://latex.codecogs.com/svg.latex?2^{h&plus;1}-1(\because&space;(2^{h}-1)&plus;2^{h})) 이다.

2. **원소의 수가 n인 heap의 높이는 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor) 임을 보여라. (6.1-2)**

    m이 가능한 한 가장 큰 수일 경우, n을 다음과 같이 변형해서 쓸 수 있다.

    ![equation](https://latex.codecogs.com/svg.latex?n=2^{m}-1&plus;k)

    위 식이 뜻하는 바를 살펴보면, heap은 complete binary tree를 기반으로 하기 때문에 높이가 m-1인 full binary tree에 k개의 leaf node가 아래쪽에 추가된 꼴이다.

    따라서, 높이가 m-1인 complete binary tree에 leaf node로 높이가 1 추가되었으므로, 전체 heap의 높이는 m이 된다.

    ![equation](https://latex.codecogs.com/svg.latex?m&space;=&space;\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor) 이므로, 원소의 수가 n인 heap의 높이는 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\log{n}&space;\right&space;\rfloor) 임을 알 수 있다.

3. **max heap에서 모든 원소가 서로 다를 때 가장 작은 원소는 어디에 존재하는가? (6.1-4)**

    모든 원소가 서로 다를 때, 가장 작은 원소는 max heap의 leaf node에 존재한다.

4. **원소 수가 n개인 힙을 배열로 나타낼 때 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\frac{n}{2}&space;\right&space;\rfloor&plus;1,\left&space;\lfloor&space;\frac{n}{2}&space;\right&space;\rfloor&plus;2,...,n)번째 노드가 leaf node임을 보여라. (6.1-7)**

    leaf node는 child node가 없는 node를 뜻한다.

    따라서, 해당 index를 가진 node들이 leaf node임을 보이기 위해서는 child node가 없음을 보이면 된다.

    만약, 임의의 i번째 node를 선택한다고 가정해 보자. 단, i의 조건은 다음과 같다.

    ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\frac{n}{2}\right&space;\rfloor&plus;1\leq&space;i&space;\leq&space;n)

    i번째 node의 left child는 2i 번째 node이며, right child는 2i + 1 번째 node임을 이용한다.

    위의 식의 모든 항에 2를 곱할 경우, 아래와 같이 i는 항상 n보다 크게 됨을 알 수 있다.

    ![equation](https://latex.codecogs.com/svg.latex?n<&space;2\left&space;\lfloor&space;\frac{n}{2}\right&space;\rfloor&plus;2\leq&space;2i&space;\leq&space;2n)

    이에 따라 left child인 2i 번째 node는 heap 내부에 존재하지 않고, 마찬가지로 right child인 2i + 1 번째 node도 heap 내부에 존재하지 않는다.

    따라서, ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;\frac{n}{2}&space;\right&space;\rfloor&plus;1,\left&space;\lfloor&space;\frac{n}{2}&space;\right&space;\rfloor&plus;2,...,n) 번째 node들은 child node가 존재하지 않으므로, leaf node이다.

5. **원소 ![equation](https://latex.codecogs.com/svg.latex?A[i])가 자식들보다 클 때 `MAX-HEAPIFY(A, i)`를 호출한 결과는 얼마인가? (6.2-3)**

    배열에 변화가 생기지 않는다.

6. **`MAX-HEAPIFY`의 코드를 재귀 호출을 사용하지 않고, 반복 제어 구조(루프)를 사용해 효율적인 `MAX-HEAPIFY`를 작성하라. (6.2-5)**

    ```
    ITERATIVE-MAX-HEAPIFY(A, i)

        while i < A.heap-size
            l = LEFT(i)
            r = RIGHT(i)

            if l <= A.heap-size and A[l] >= A[i]
                largest = l
            else
                largest = i

            if r <= A.heap-size and A[r] >= A[largest]
                largest = r

            if largest != i
                exchange A[largest] with A[i]
                i = largest
            else
                return A

        return A
    ```
7. `BUILD-MAX-HEAP`의 2행에서, index i를 1부터 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;A.length/2&space;\right&space;\rfloor) 까지 증가시키지 않고 ![equation](https://latex.codecogs.com/svg.latex?\left&space;\lfloor&space;A.length/2&space;\right&space;\rfloor) 부터 1까지 감소시키는 이유는 무엇인가? (6.3-2)

    `BUILD-MAX-HEAP`은 배열이 max-heap 특성을 만족하도록 바꾸는 함수이다.

    만약, 1부터 시작할 경우, 아래의 노드들이 max-heap 특성을 만족하는지를 보장할 수 없다. 

    leaf node들은 원소가 1개인 heap으로 볼 수 있으므로, max-heap 특성을 만족한다고 할 수 있다. 따라서, leaf node 바로 위에 있는 원소에서부터 시작하여 1까지 감소시켜야 한다.
