# Sort

정렬 문제를 풀기 위한 다양한 알고리즘이 존재한다.

정렬 문제는 다음과 같이 정의한다.

**입력:** 숫자 n개로 이루어진 수열 ![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;<a_1,a_2,...,a_n>)

**출력:** 입력 수열 ![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;<a'_1,a'_2,...,a'_n>)을  ![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;a'_1&space;\le&space;a'_2&space;\le&space;...&space;\le&space;a'_n)으로 재배치한 순열

입력은 원소 수가 n개인 배열로 주어지지만, 연결 리스트와 같이 다른 형태로 주어지기도 한다.

## 정렬이 필요한 이유

정렬은 알고리즘 연구에서 가장 기본적인 문제로 여겨진다.

- 정보를 정렬하는 것 자체가 필요한 응용 분야가 있다.
- 많은 알고리즘에서 정렬을 핵심 서브 루틴으로 사용하는 경우가 있다.
- 정렬 알고리즘은 그 종류가 다양하고, 많은 기술이 적용된다.

## 정렬 알고리즘

대표적으로 알려져 있는 정렬 알고리즘의 수행 시간 분석은 다음과 같다.

각 알고리즘의 이름을 클릭하면 해당 알고리즘의 수도코드와 수행시간 분석을 확인할 수 있다.

(최근 수정 시각: `2021-01-12`)

|알고리즘|최악의 경우 수행시간|평균/기대 수행시간
|:---|:---|:---|
|Insertion Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n^2))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n^2))|
|Merge Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n\log{n}))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n\log{n}))|
|Heap Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n\log{n}))|-|
|Quick Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n^2))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n\log{n})) (기대 수행 시간)|
|Counting Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(k&plus;n))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(k&plus;n))|
|Radix Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(d(n&plus;k)))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(d(n&plus;k)))|
|Bucket Sort|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n^2))|![equation](https://latex.codecogs.com/svg.latex?\dpi{120}&space;\theta(n)) (평균 수행 시간)|
