# Quick Sort (퀵 정렬)

- [Quick Sort (퀵 정렬)](#quick-sort-퀵-정렬)
  - [Quick Sort의 특징](#quick-sort의-특징)
  - [기본적인 Quick Sort](#기본적인-quick-sort)
    - [Pseudo Code](#pseudo-code)
      - [PARTITION](#partition)
      - [QUICK-SORT](#quick-sort)
    - [수행 시간 분석](#수행-시간-분석)
      - [최악의 경우](#최악의-경우)
      - [최선의 경우](#최선의-경우)
      - [평균적인 경우](#평균적인-경우)
  - [Randomized Quick Sort](#randomized-quick-sort)
    - [Pseudo Code](#pseudo-code-1)
      - [RANDOMIZED-PARTITION](#randomized-partition)
      - [RANDOMIZED-QUICK-SORT](#randomized-quick-sort-1)
    - [수행 시간 분석](#수행-시간-분석-1)

***

## Quick Sort의 특징

- 내부 정렬을 이용한 방법이다.
- 분할 정복을 이용한다.

    1. 분할

        배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;r]) 을 두 개의 부분 배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;q-1]) 과 ![equation](https://latex.codecogs.com/svg.latex?A[q&plus;1,&space;...,&space;r]) 로 분할한다. 부분 배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;q-1]) 에는 ![equation](https://latex.codecogs.com/svg.latex?A[q]) 보다 작거나 같은 원소를, ![equation](https://latex.codecogs.com/svg.latex?A[q&plus;1,&space;...,&space;r]) 에는 ![equation](https://latex.codecogs.com/svg.latex?A[q]) 보다 크거나 같은 원소를 배치한다.

    2. 정복

        `quick sort`를 재귀 호출해서 부분 배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;q-1]) 과 ![equation](https://latex.codecogs.com/svg.latex?A[q&plus;1,&space;...,&space;r]) 를 정렬한다.

    3. 결합

        1, 2의 과정을 통해 부분 배열이 이미 정렬되어 있으므로 따로 합치는 작업이 필요하지 않다.

- `quick sort`는 기본적인 `quick sort` 방법과 랜덤화 기법을 사용하여 모든 입력에 대해 성능의 기댓값을 높이는 `randomized quick sort` 방법이 있다.


## 기본적인 Quick Sort

### Pseudo Code

#### PARTITION

배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;r]) 을 두 개의 부분 배열 ![equation](https://latex.codecogs.com/svg.latex?A[p,&space;...,&space;q-1]) 과 ![equation](https://latex.codecogs.com/svg.latex?A[q&plus;1,&space;...,&space;r]) 로 분할한다.

```
PARTITION(A, p, r)

    key = A[r]

    i = p - 1

    for j = p to r - 1
        if A[j] <= key
            i = i + 1
            swap(A[i], A[j])
    
    swap(A[i+1], A[r])

    return i+1
```

#### QUICK-SORT

```
QUICK-SORT(A, p, r)

    if p < r
        q = PARTITION(A, p, r)
        QUICK-SORT(A, p, q - 1)
        QUICK-SORT(A, q + 1, r)
```

### 수행 시간 분석

#### 최악의 경우

먼저, `PARTITION` 함수를 분석해 보자.

`PARTITION` 함수는 어떤 입력이 들어와도 내부의 `for loop`을 모두 돌아야 하므로, `PARTITION` 함수의 입력으로 들어온 부분 배열의 원소의 개수가 ![equation](https://latex.codecogs.com/svg.latex?n)개일 경우, 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n))이라 할 수 있다.

`QUICK-SORT`는 분할 정복이며, 함수의 수행 시간은 `PARTITION`을 진행 후 두 개의 부분 배열이 얼마나 균등하게 나누어졌냐에 따라 달라지게 된다.

최악의 경우, 원소의 개수가 ![equation](https://latex.codecogs.com/svg.latex?n)개인 배열을 `PARTITION`으로 분할할 때, 두 개의 부분 배열 중 하나의 부분 배열의 원소가 0개일 수 있다. 그럴 경우, 나머지 하나의 부분 배열의 원소의 개수는 ![equation](https://latex.codecogs.com/svg.latex?n-1)개 이다.

따라서, 최악의 경우 `QUICK-SORT`의 수행 시간의 점화식은 다음과 같다.

![equation](https://latex.codecogs.com/svg.latex?\begin{aligned}&space;T(n)\&=T(n-1)&plus;T(0)&plus;\Theta(n)\\\\&=T(n-1)&plus;\Theta(n)&space;\end{aligned})

위의 점화식을 풀면 `QUICK-SORT`의 최악의 경우 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n^{2}))이다.

생각해 보면, `QUICK-SORT`의 최악의 경우 수행 시간 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n^{2}))는 `INSERTION-SORT`의 평균 수행 시간과 같다. `QUICK-SORT`에서 최악의 경우가 발생하는 경우는 애초에 입력으로 들어온 배열이 거의 완전히 정렬되어 있을 때 발생한다. 그런데, 거의 완전히 정렬되어 있는 배열을 `INSERTION-SORT`를 이용하여 정렬하면 ![equation](https://latex.codecogs.com/svg.latex?O(n)) 시간에 정렬이 가능하다.

#### 최선의 경우

최선의 경우는 `PARTITION`으로 인해 나누어진 두 개의 부분 배열이 가진 원소의 수가 ![equation](https://latex.codecogs.com/svg.latex?n/2)로 같을 때이다.

이때의 `QUICK-SORT`의 수행 시간의 점화식은 다음과 같다.

![equation](https://latex.codecogs.com/svg.latex?T(n)=2T(n/2)&plus;\Theta(n))

이 점화식을 마스터 정리 경우 2로 풀면, 최선의 경우 `QUICK-SORT`의 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n\log{n}))임을 알 수 있다.

#### 평균적인 경우

평균적인 경우를 직관적으로 살펴보자.

평균적인 경우를 살펴보기 위해, 항상 균등하게 분할되는 `PARTITION`의 경우를 먼저 생각해 보자.

만약, `PARTITION`으로 인해 부분 배열의 크기가 항상 ![equation](https://latex.codecogs.com/svg.latex?1/4), ![equation](https://latex.codecogs.com/svg.latex?3/4)로 나뉘어진다면 수행 시간은 어떻게 될까? 이 경우 `QUICK-SORT`의 수행 시간의 점화식은 다음과 같을 것이다.

![equation](https://latex.codecogs.com/svg.latex?T(n)=T(n/4)&plus;T(3n/4)&plus;\Theta(n))

이를 재귀 트리를 이용하여 살펴보도록 하자. 

재귀 트리를 살펴보면, 깊이가 ![equation](https://latex.codecogs.com/svg.latex?\log_4{n}=\Theta(\log{n}))에 이를 때 까지는 트리의 각 레벨당 비용이 ![equation](https://latex.codecogs.com/svg.latex?cn)이고, 그 다음 레벨부터는 ![equation](https://latex.codecogs.com/svg.latex?cn)보다 작거나 같다. 또한, 재귀는 ![equation](https://latex.codecogs.com/svg.latex?\log_{4/3}{n}=\Theta(\log{n}))에서 끝난다.

그러므로, 재귀 트리의 각 레벨의 모든 비용을 합해 보면 평균적인 경우 `QUICK-SORT`의 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n}))이다. 

이제 평균적인 경우를 생각해 보자.

평균적인 경우라면, `PARTITION`으로 인해 부분 배열의 분할이 좋게 될 수도 있고, 나쁘게 될 수도 있다. 따라서, 재귀 트리의 각 분할에서 최악의 경우 분할과 최선의 경우 분할이 번갈아 나타난다고 가정해 보자.

그럴 경우, 재귀 트리의 각 레벨의 비용은 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n))이며, 트리의 높이는 ![equation](https://latex.codecogs.com/svg.latex?\Theta(\log{n}))이 될 것이다. 따라서, 평균적인 경우 `QUICK-SORT`의 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?O(n\log{n}))이다.

## Randomized Quick Sort

많은 알고리즘은 입력에 의해 수행시간이 좌우된다. 당장 위에서 살펴본 기본적인 quick sort만 하더라도, 대부분 정렬이 되어 있는 배열이 입력으로 들어올 경우 최악의 수행 시간인 ![equation](https://latex.codecogs.com/svg.latex?\Theta(n^{2}))를 가진다.

알고리즘에 랜덤화 기법을 적용하면 입력에 의해 수행 시간이 좌우되는 것을 막을 수 있다. 랜덤화 기법을 적용할 때는 **입력 배열을 무작위로 뒤섞거나**, **입력 배열에서 무작위로 추출된 원소를 알고리즘에서 사용**하는 방법이 있다.

`Randomized Quick sort`에서는 무작위 추출 방법을 이용하여 랜덤화를 적용한다.

이는 기본적인 `quick sort`의 `PARTITION` 프로시저에 적용된다. 위의 `PARTITION` 프로시저에서 `key`으로 입력된 배열의 가장 끝 값을 선택하였다.

이 `key`값으로 인해 `quick sort`의 수행 시간이 달라지기 때문에, 이 `key`값을 무작위로 선택하는 방법으로 랜덤화를 적용한다. 

이를 위해 전체 입력 배열에서 무작위로 하나의 원소를 추출하고, 이 값을 ![equation](https://latex.codecogs.com/svg.latex?A[r])과 `swap`하는 과정을 추가한다.

### Pseudo Code

#### RANDOMIZED-PARTITION

```
RANDOMIZED-PARTITION(A, p, r)
    i = RANDOM(p, r)

    swap(A[i], A[r])

    return PARTITION(A, p, r)
```

#### RANDOMIZED-QUICK-SORT

```
RANDOMIZED-QUICK-SORT(A, p, r)
    if p < r
        q = RANDOMIZED-PARTITION(A, p, r)
        QUICK-SORT(A, p, q - 1)
        QUICK-SORT(A, q + 1, r)
```

### 수행 시간 분석

수행 시간은 기본적인 `QUICK-SORT`와 같다.

하지만, `RANDOMIZED-QUICK-SORT`는 알고리즘의 랜덤화를 통해 `key`값을 무작위로 뽑아 알고리즘의 수행시간이 입력값에 의해 결정되지 않도록 하는데에 의의가 있다.

`RANDOMIZED-QUICK-SORT`의 경우, 확률적 분석을 통하여 평균적인 경우의 수행 시간을 분석할 수 있다.

> T. Cormen, C. Leiserson, R. Rivest and C. Stein, 『Introduction to Algorithms』, 문병로, 심규석, 이충세 옮김, 한빛아카데미(2014), p173-p191<br>