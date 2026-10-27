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

### 3.1. Greedy Algorithm

### 3.2. BruteForce Algorithm

The exact solver utilizes a bitmask-based subset generation technique to guarantee an optimal solution by exhaustively evaluating all possible activity combinations:
* **Subset Generation:** Uses an unsigned 64-bit integer (`unsigned long long`) as a bitmask to represent subsets. A bitmask ranges from $0$ to $2^N - 1$, covering all $2^N$ possible combinations.
* **Pruning:** Before validating a subset for overlaps, the algorithm counts the number of selected activities (`current_count`). The overlap check is only executed if `current_count` is strictly greater than the current `max_count`, skipping unnecessary validations for smaller, suboptimal subsets.
* **Overlap Validation:** For qualifying subsets, a nested loop checks every pair of selected activities ($i$ and $j$). An overlap is detected if `arr[i].start < arr[j].finish` and `arr[j].start < arr[i].finish`. If an overlap is found, the subset is immediately marked invalid and discarded.

## 4. Correctness Proof (Exchange Argument)

## 5. Complexity Analysis

### 5.1. Greedy Algorithm

### 5.2. BruteForce Algorithm

* **Time Complexity:** $O(N^2 \cdot 2^N)$
  The outer loop generates $2^N$ subsets. In the worst-case scenario (where a subset has more activities than `max_count`), evaluating the subset requires iterating through all selected activity pairs to check for overlaps, which takes $O(N^2)$ time.
* **Space Complexity:** $O(1)$ Auxiliary
  The algorithm evaluates activities strictly in place using integer variables and a 64-bit mask for state tracking, requiring no additional data structures. The space complexity is constant, excluding the input array itself.

## 6. Implementation & Execution Guide

### 6.1. Project Structure

### 6.2. Compilation and Execution Guide

## 7. Testing and Experimental Results

### 7.1. Automated 20+ Test Scenarios

The `Test/RunTest.c` suite dynamically handles test execution and algorithmic validation:
* **Dynamic Memory & Parsing:** Reads raw data files (`TestCase.txt` and `EdgeCase.txt`), allocating memory dynamically via `malloc` based on the specified $N$ size of each test case. Memory is safely freed after each test iteration to prevent leaks.
* **A/B Output Verification:** Executes both `ActivitySelection` (Greedy) and `BruteForceActivitySelection` on identical input arrays.
* **Success Criteria:** A test passes exclusively if the result of the Greedy algorithm matches the optimal result produced by the Brute Force algorithm. The runner outputs a detailed CLI trace for each test and calculates a final success rate percentage.

### 7.2. Hand-Traceable Example

To demonstrate and compare the step-by-step mechanics of both algorithms, we trace **Test 01** from `Test/TestCase.txt` containing $N = 6$ activities.

#### Sample Input Dataset

- $A_0 = (1, 4)$
- $A_1 = (4, 5)$
- $A_2 = (0, 6)$
- $A_3 = (5, 7)$
- $A_4 = (3, 9)$
- $A_5 = (5, 9)$

#### 1. Greedy Algorithm

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

#### 2. BruteForce Algorithm

- **Step 1 (Subsets Generation):** Evaluate $2^6 = 64$ possible combinations using bitmasks ($0$ to $63$).
- **Step 2 (Overlap Validation):**
  - **Mask `11` (`001011`):** Selects $A_0(1,4)$, $A_1(4,5)$, and $A_3(5,7)$. No overlapping pairs. Maximum valid set size = **3**.
  - **Mask `63` (`111111`):** Selects all activities. Multiple overlaps detected (e.g., $A_0$ and $A_2$). Invalid set.
- **BruteForce Result:** **3** activities selected.

### 7.3. Large-Scale Performance Test (100,000 Activities)

### 7.4. Edge Cases Handling

The `EdgeCase.txt` file targets vulnerability points and extreme bounds with 9 specialized scenarios. Both algorithms maintain 100% accuracy against the following configurations:
1. **Empty Set ($N = 0$):** Tests termination and zero-state handling.
2. **Single Activity ($N = 1$):** Minimum viable input without pair comparisons.
3. **Contiguous Chain:** Activities start exactly when the previous finishes (e.g., $1-3$, $3-5$, $5-7$) to test strict vs. non-strict inequality boundaries.
4. **Identical Clones:** All activities have the exact same start and finish times ($2-6$, $2-6$, $2-6$).
5. **Enveloping Interval:** A massive activity ($0-100$) overlapping multiple smaller, valid, and disjoint activities ($1-2$, $3-4$, $5-6$).
6. **Nested / Russian Doll:** Progressively smaller nested intervals ($1-10$, $2-9$, $3-8$, $4-7$) to ensure the Greedy algorithm prioritizes the earliest finish time, not the duration.
7. **Reverse Sorted Input:** Start/Finish times arranged in descending order to test sorting dependencies.
8. **Zero-Duration Point:** An activity where start and finish times are identical ($2-2$).
9. **Zero-Index Start:** Testing index/start combinations directly at $0$ (e.g., $0-0$, $0-5$).

## 8. Self-Explanation

## 9. AI Usage Log

## 10. Conclusion
