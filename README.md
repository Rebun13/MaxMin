# MaxMin

## Description

Given a list of integers, _arr_, and a single integer _k_. Creates an array of length _k_ from elements of _arr_ such that its unfairness is minimized. Calling that array _arr'_, the unfairness of an array is calculated as:
_max(arr')-min(arr')_
Where:
- max denotes the largest integer in _arr'_.
- min denotes the smallest integer in _arr'_.

 ## Returns

 - int: the minimum possible unfairness

## Input

- The first line contains an integer _n_, the number of elements in array _arr_.
- The second line contains an integer _k_.
- Each of the next _n_ lines contains an integer _arr[i]_ where _0 ≤ i < n_. 
