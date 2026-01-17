# 🔹 Prefix Sum Pattern (Interview-Oriented Explanation)

The **Prefix Sum Pattern** is one of the most important DSA patterns for **SDE role interviews**. It helps optimize problems involving repeated sum calculations, especially over subarrays or ranges.

---

## 1️⃣ When Should You Use Prefix Sum?

### ✅ Recognition Keywords / Signals

You should immediately think of **Prefix Sum** when a problem involves:

### 🔑 Keywords in the Problem Statement
- **Range sum**
- **Sum of elements from L to R**
- **Multiple queries**
- **Subarray sum**
- **Continuous subarray**
- **Sum equals K**
- **Difference of sums**
- **Cumulative**
- **Prefix / Running sum**

---

### 📌 Typical Scenarios
- You are asked to compute **sum of elements repeatedly**
- The array is **static** (no frequent updates)
- You need to optimize from **O(N²) → O(N)** or **O(1) per query**
- Problems involve **subarrays**, not subsequences

---

### 🧠 Interview Thought Process
> *“If I precompute cumulative sums, can I avoid recalculating the same sum again and again?”*

If the answer is **yes**, then → **Prefix Sum**

---

## 2️⃣ Brute Force Approach (Without Prefix Sum)

### Example Problem
Given an array `arr`, answer queries of sum from index `L` to `R`.

### ❌ Brute Force Code
```cpp
int rangeSum(vector<int>& arr, int L, int R) {
    int sum = 0;
    for(int i = L; i <= R; i++) {
        sum += arr[i];
    }
    return sum;
}
```
## ⏱ Time Complexity (Brute Force)

- **Single query:** `O(N)`
- **Q queries:** `O(N × Q)` ❌ *(Leads to TLE in interviews)*

### 🚨 Interviewer Red Flag
> *“Can we do better if there are multiple queries?”*

---

## 3️⃣ How Prefix Sum Works (Core Logic)

### 💡 Key Idea
Instead of recalculating sums repeatedly, **store the cumulative sum till each index**.

### 📘 Prefix Sum Definition

### Example
```
arr = [2, 4, 6, 8]
prefix = [2, 6, 12, 20]
```
---

### 🧮 Range Sum Formula
```
Sum(L → R) = prefix[R] - prefix[L - 1]
```

> Handle `L = 0` separately.

---

## 4️⃣ Generic C++ Template (Interview-Ready)

### 🧩 Basic Prefix Sum Template
```cpp
vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}
### 📌 Range Query Using Prefix Sum

int rangeSum(vector<int>& prefix, int L, int R) {
    if(L == 0) return prefix[R];
    return prefix[R] - prefix[L - 1];
}
```
---
## 🔥 Advanced Prefix Sum (Most Asked in SDE Interviews)

### ⭐ Prefix Sum + HashMap (VERY IMPORTANT)

Used when problems involve:
- **Subarray sum equals K**
- **Count subarrays with given sum**
- **Maximum length subarray**

---

### 🧠 Core Idea
```
If:

currentSum - previousSum = K

Then:

previousSum = currentSum - K


This means if `(currentSum - K)` has appeared before, a valid subarray ending at the current index exists.

```


### 🧩 Generic Template (MUST MEMORIZE)
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // Handles subarrays starting from index 0

    int currSum = 0, count = 0;

    for(int x : nums) {
        currSum += x;

        if(mp.count(currSum - k)) {
            count += mp[currSum - k];
        }

        mp[currSum]++;
    }
    return count;
}

```
### ⏱ Time Complexity

- Time: O(N)

- Space: O(N)

💯 This problem appears in Google, Amazon, Microsoft, Flipkart, Adobe

### 5️⃣ Common Prefix Sum Variations
### 🔹 1D Prefix Sum

Range sum queries

Subarray sum equals K

### 🔹 2D Prefix Sum (Matrix)

Submatrix sum

Sum of a rectangle in a matrix
```
prefix[i][j] = sum of matrix from (0,0) to (i,j)

```

### Used in:

Image processing

Matrix-based range queries

### 6️⃣ Important Interview Problems (Practice Order)
 🟢 Easy

- **Range Sum Query – Immutable (LeetCode 303**

 - **Running Sum of 1D Array (LeetCode 1480)**

### 🟡 Medium (VERY IMPORTANT)

- **Subarray Sum Equals K (LeetCode 560) ⭐⭐⭐**

- **Continuous Subarray Sum (LeetCode 523)**

 - **Find Pivot Index (LeetCode 724)**

- **Product of Array Except Self (LeetCode 238 – Prefix idea)**

### 🔴 Hard

- **Maximum Size Subarray Sum Equals K**

- **Count Number of Nice Subarrays**

- **Submatrix Sum Equals Target (2D Prefix Sum)**
