# INTERVAL SCHEDULING AND ACTIVITY SELECTION (GREEDY ALGORITHMS)

## 1. Project Overview & Team Division

- **Course code:** 261DASA240179E_02FIE
- **Instructor:** Huỳnh Xuân Phụng

* **Team member**
  - **Trần Nguyễn Hoàng Huy** - MSSV: 25110024 - Github: Huy090107
  - **Phạm Văn Tuấn Đạt** - MSSV: 25110016 - Github: alkasmxd

### Detailed Division of Labor

| **Member** | **Assign responsibilities**                                                                                                                                                                                                                                                                                                         | **Contribution** |
| :--------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------: |
|  **Huy**   | - Implemented the Greedy algorithm (`GreedyAlgorithm.c`)<br>- Generated 100,000 intervals<br>- Developed execution time measurement for the Greedy algorithm on 100,000 intervals (`Benchmark/Benchmark.c`)<br>- Analyzed the time and space complexity of the Greedy algorithm                                                     |       100%       |
|  **Đạt**   | - Implemented the Brute Force algorithm (`BruteForce.c`)<br>- Built the automated test suite (`Test/RunTest.c`)<br>- Created 20 main test cases and edge cases<br>- Conducted Hand-Trace verification for the Brute Force algorithm (`Test/HandTrace.txt`)<br>- Analyzed the time and space complexity of the Brute Force algorithm |       100%       |

## 2. Problem Statement

Given a set of $n$ activities, each represented by a start time $s_i$ and a finish time $f_i$, select the maximum number of mutually compatible activities (non-overlapping).<br>
The project fulfills all core requirements:

- Implemented Greedy Activity Selection Algorithm ($O(N \log N)$).
- Implemented Exact Solver via Brute Force / Dynamic Programming ($O(2^N)$).
- Automated test suite covering 20+ realistic scenarios and edge cases.
- Performance evaluation using 100,000 activities.
- Formal Exchange Argument correctness proof.
- Full Time & Space complexity analysis.

## 3. Algorithm Design

### 3.1. Greedy Algorithm (Implemented by Huy)

### 3.2. BruteForce Algorithm (Implemented by Đạt)

## 4. Correctness Proof (Exchange Argument) (Huy)

## 5. Complexity Analysis

### 5.1. Greedy Algorithm (Huy)

### 5.2. BruteForce Algorithm (Đạt)

## 6. Implementation & Execution Guide (Huy)

### 6.1. Project Structure

### 6.2. Compilation and Execution Guide

## 7. Testing and Experimental Results

### 7.1. Automated 20+ Test Scenarios (Đạt)

### 7.2. Hand-Traceable Example

To demonstrate and compare the step-by-step mechanics of both algorithms, we trace **Test 01** from `Test/TestCase.txt` containing $N = 6$ activities.

#### Sample Input Dataset

- $A_0 = (1, 4)$
- $A_1 = (4, 5)$
- $A_2 = (0, 6)$
- $A_3 = (5, 7)$
- $A_4 = (3, 9)$
- $A_5 = (5, 9)$

#### 1. Greedy Algorithm (Huy)

- **Step 1 (Sort):** Sort activities in ascending order by finish time:
  - `arr[0]`: $(1, 4)$
  - `arr[1]`: $(4, 5)$
  - `arr[2]`: $(0, 6)$
  - `arr[3]`: $(5, 7)$
  - `arr[4]`: $(3, 9)$
  - `arr[5]`: $(5, 9)$
- **Step 2 (Initialization):** Select `arr[0]` $(1, 4)$. Set `count = 1`, `FinishTime = 4`.
- **Step 3 (Iteration):**
  - Check `arr[1]` $(4, 5)$: Start $4 \ge 4 \rightarrow$ Valid. Select. Update `count = 2`, `FinishTime = 5`.
  - Check `arr[2]` $(0, 6)$: Start $0 < 5 \rightarrow$ Overlap. Skip.
  - Check `arr[3]` $(5, 7)$: Start $5 \ge 5 \rightarrow$ Valid. Select. Update `count = 3`, `FinishTime = 7`.
  - Check `arr[4]` $(3, 9)$: Start $3 < 7 \rightarrow$ Overlap. Skip.
  - Check `arr[5]` $(5, 9)$: Start $5 < 7 \rightarrow$ Overlap. Skip.
- **Greedy Result:** **3** activities selected ($A_0, A_1, A_3$).

#### 2. BruteForce Algorithm (Đạt)

- **Step 1 (Subsets Generation):** Evaluate $2^6 = 64$ possible combinations using bitmasks ($0$ to $63$).
- **Step 2 (Overlap Validation):**
  - **Mask `11` (`001011`):** Selects $A_0(1,4)$, $A_1(4,5)$, and $A_3(5,7)$. No overlapping pairs. Maximum valid set size = **3**.
  - **Mask `63` (`111111`):** Selects all activities. Multiple overlaps detected (e.g., $A_0$ and $A_2$). Invalid set.
- **BruteForce Result:** **3** activities selected.

### 7.3. Large-Scale Performance Test (100,000 Activities) (Huy)

### 7.4. Edge Cases Handling (Đạt)

## 8. Self-Explanation (Huy and Đạt)

## 9. AI Usage Log (Huy and Đạt)

## 10. Conclusion (Huy)
