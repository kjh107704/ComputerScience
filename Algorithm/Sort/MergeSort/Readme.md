# Merge Sort (삽입 정렬)

- [Merge Sort (삽입 정렬)](#merge-sort-삽입-정렬)
  - [Pseudo Code](#pseudo-code)
    - [MERGE](#merge)
    - [MERGE-SORT](#merge-sort)
  - [수행 시간 분석](#수행-시간-분석)

***

- 외부 정렬 방법이다.
- 분할 정복을 이용한다.

## Pseudo Code

### MERGE

**결합** 단계에서 정렬된 두 부분 수열을 병합하는 프로시저이다.

```
MERGE(A, p, q, r)

    n1 = q - p + 1
    n2 = r - q

    create L[1, ..., n1 + 1], R[1, ..., n2 + 1]

    for i = 1 to n1
        L[i] = A[p + i - 1]

    for j = 1 to n2
        R[j] = A[q + j]

    L[n1 + 1] = INF
    R[n2 + 1] = INF

    i = 1
    j = 1

    for k = p to r
        if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
```

### MERGE-SORT

```
MERGE-SORT(A, p, r)

    if p < r
        q = floor((p + r)/2)
        MERGE-SORT(A, p, q)
        MERGE-SORT(A, q+1, r)
        MERGE(A, p, q, r)
```

## 수행 시간 분석

n개의 수를 정렬하는 merge sort에서 수행시간 ![equation](https://latex.codecogs.com/svg.latex?T(n))을 다음과 같이 추론할 수 있다.

원소의 개수가 1개일 때, merge sort는 상수 시간이 걸린다.

또한, 원소의 개수 n이 ![equation](https://latex.codecogs.com/svg.latex?n<&space;1)일 때에는 수행시간을 다음과 같이 나눌 수 있다.

1. 분할
   
   분할 단계에서는 부분 배열의 중간 위치를 계산한다.
   
   (MERGE-SORT 함수에서 `q = floor((p + r)/2)` 부분을 의미)

   이는 상수 시간이 걸리므로, ![equation](https://latex.codecogs.com/svg.latex?\theta(1))의 시간이 걸린다.

2. 정복

    두 개의 부분 문제를 재귀적으로 풀어 나가는데, 각 부분 문제의 크기가 ![equation](https://latex.codecogs.com/svg.latex?n/2)이므로 ![equation](https://latex.codecogs.com/svg.latex?2T(n/2))의 수행시간이 걸린다.

3. 결합

    n개의 원소에 대해 MERGE 프로시저는 ![equation](https://latex.codecogs.com/svg.latex?\theta(n))의 시간이 걸린다.

따라서, merge sort의 수행시간 ![equation](https://latex.codecogs.com/svg.latex?T(n))에 대한 점화식은 다음과 같다.

![equation](https://latex.codecogs.com/svg.latex?T(n)=&space;\begin{cases}&space;\theta(1),&space;&&space;\text{if}\&space;n=1&space;\\&space;2T(n/2)&plus;cn,&space;&&space;\text{if}\&space;n>1&space;\end{cases})

위 점화식을 마스터 정리 경우 2를 이용하여 풀면, ![equation](https://latex.codecogs.com/svg.latex?T(n)=\theta(n\log{n}))이므로, n개의 수를 정렬하는 merge sort의 수행 시간은 ![equation](https://latex.codecogs.com/svg.latex?\theta(n\log{n}))이다.

마스터 정리에 대해서는 [여기](https://velog.io/@kjh107704/%EC%A0%90%ED%99%94%EC%8B%9D%EC%9D%84-%ED%92%80%EA%B8%B0-%EC%9C%84%ED%95%9C-%EB%B0%A9%EB%B2%95%EB%93%A4)를 참고할 것.