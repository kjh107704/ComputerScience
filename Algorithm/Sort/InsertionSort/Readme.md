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

직관적으로 보았을 때, 어떠한 입력이 들어오더라도 중첩된 `for loop`을 모두 돌아야 하므로 ![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n^2))의 시간이 걸린다.

>   T. Cormen, C. Leiserson, R. Rivest and C. Stein, 『Introduction to Algorithms』, 문병로, 심규석, 이충세 옮김, 한빛아카데미(2014), p16-p42<br>
> CLRS Solutions, "Introduction to Algorithms solution", https://sites.math.rutgers.edu/~ajl213/CLRS/CLRS.html, (2021.01.14)