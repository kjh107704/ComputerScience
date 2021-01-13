# Heap Sort

## Pseudo Code

### LEFT, RIGHT, PARENT

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

### MAX-HEAPIFY

max heap 특성을 유지할 수 있도록 하는 함수

parent node가 child node보다 작은 경우, parent node를 max heap 특성을 만족할 때 까지 아래로 계속 내린다.

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

### BUILD-MAX-HEAP

배열 A[1, ..., n]를 max heap으로 만드는 함수

```
BUILD-MAX-HEAP(A)

    A.heap-size = A.length

    for i = floor(A.length/2) downto 1
        MAX-HEAPIFY(A, i)
```

### HEAP-SORT

```
HEAP-SORT(A)

    BUILD-MAX-HEAP(A)

    for i = A.length downto 2
        exchange A[1] with A[i]
        A.heap-size = A.heap-size - 1
        MAX-HEAPIFY(A, 1)
```

## 수행 시간 분석

### LEFT, RIGHT, PARENT

모두 상수 시간 내에 수행이 완료되므로, ![equation](https://latex.codecogs.com/svg.latex?O(1)).

### MAX-HEAPIFY

높이가 h인 node에서 `MAX-HEAPIFY`를 call 할 경우를 생각해 보자.

최악의 경우 높이 h부터 leafnode에 도달할 때 까지 MAX-HEAPIFY를 재귀적으로 호출할 수 있다.

따라서, 높이가 h인 node에서 `MAX-HEAPIFY` 수행 시간의 상한은 ![equation](https://latex.codecogs.com/svg.latex?O(h)).

### BUILD-MAX-HEAP

#### 단순 분석

단순하게 생각할 경우, node의 개수가 n개인 heap에서 `MAX-HEAPIFY`는 한 번의 call 마다 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 이 걸린다고 볼 수 있다. 왜냐하면, node의 개수가 n인 heap의 최대 높이가 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n}))이기 때문이다.

![equation](https://latex.codecogs.com/svg.latex?O(\log{n}))의 수행 시간을 가지는 `MAX-HEAPIFY`를 `BUILD-MAX-HEAP`이 ![equation](https://latex.codecogs.com/svg.latex?O(n))번 call 하게 되므로, 

`BUILD-MAX-HEAP`을 단순 분석했을 때 수행 시간의 상한은

![equation](https://latex.codecogs.com/svg.latex?O(\log{n})\times&space;O(n)&space;=&space;O(n\log{n}))

하지만, `MAX-HEAPIFY`의 수행 시간이 node의 높이에 따라 다르고, node 대부분의 높이가 다른 점을 고려하여 수행 시간을 개선할 여지가 있다.

#### 정확한 분석

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

### HEAP-SORT

`BUILD-MAX-HEAP`이 ![equation](https://latex.codecogs.com/svg.latex?O(n)) 시간이 걸린다.

여기에 ![equation](https://latex.codecogs.com/svg.latex?O(\log{n})) 시간이 걸리는 `MAX-HEAPIFY`를 n-1번 실행한다.

따라서, `HEAP-SORT`의 수행 시간의 상한은

![equation](https://latex.codecogs.com/svg.latex?O(n)&plus;O(\log{n})\times&space;(n-1)=O(n\log{n}))

![equation](https://latex.codecogs.com/svg.latex?O(n\log{n})) 임을 알 수 있다.