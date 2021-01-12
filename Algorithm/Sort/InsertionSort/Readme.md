# Insertion Sort (삽입 정렬)

## Pseudo Code

```
Insertion-Sort(A)

    for i = 2 to A.length
        key = A[i]
        j = i -1

        while j > 0 and A[j] > key
            A[j+1] = A[j]
            j = j - 1

        A[j+1] = key
```

## 수행 시간 분석

직관적으로 보았을 때, 어떠한 입력이 들어오더라도 중첩된 $for$문을 모두 돌아야 하므로 $\theta(n^2)$의 시간이 걸린다.