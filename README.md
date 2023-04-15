# data structure & algorithm lib

## 1. data structure
### 1.1 prefix, suffix

| Attrs | PrefixSum | SuffixSum |
| -------- | -------- | -------- |
| Definition     | **Prefix sum** of a ($a_0, a_1, a_2, ..., a_n$) is an array represent the cumulative sum of an array. With prefix sum at $i$ is the cumulative sum from $a_0$ to $a_i$.     | **suffix sum** of  a ($a_0, a_1, a_2, ..., a_n$) is an array represent the cumulative sum of an array from right to left.  With suffix sum at $i$ is the cumulative sum from $a_i$ to $a_n$.     |
| Formular     | $$prefixSum[j] = \sum_{i=0}^{j}a[i]$$     | $$suffixSum[j] = \sum_{i=j}^{n}a[i]$$     |
| Query($l,r$)     | $$sum(l,r) = prefixSum[r] - prefixSum[l-1]$$     | $$sum(l,r) = suffixSum[l] - suffixSum[r+1]$$     |

### 1.2 difference array
The main idea is to save all the update queries into an array and then update them to the original array later.<br>
Difference array at first store the relative difference between elements and then use the prefix sum to update them and will DECREASE the time of updating the query.

### 1.3 disjoint set union

### 1.4 segment tree
### 1.5 fenwick tree (binary index tree)

## 2. algorithm
### 2.1 graph traverse (bfs, dfs)
### 2.2 applied graph traverse (dijk'stra)