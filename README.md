# INTERVAL SCHEDULING AND ACTIVITY SELECTION (GREEDY ALGORITHMS)

## 1. Project Overview & Team Division

- **Course code:** 261DASA240179E_02FIE
- **Instructor:** Huỳnh Xuân Phụng

* **Team member:**
  - Trần Nguyễn Hoàng Huy - MSSV: 25110024 - Github: Huy090107
  - Phạm Văn Tuấn Đạt - MSSV: 25110016 - Github: alkasmxd

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

The Greedy Algorithm solves the Interval Scheduling Problem by always making the locally optimal choice at each step: **select the activity with the earliest finish time ($f_i$)** among all remaining activities that do not overlap with the previously selected set.

#### Algorithm Steps

1. **Sorting:** Sort all $N$ activities in non-decreasing order of their finish times ($f_1 \le f_2 \le \dots \le f_n$).
2. **Initialization:** Select the first activity $A_1$ and set `last_finish_time = f_1`.
3. **Iterative Selection:** Iterate through the remaining sorted activities ($i = 2 \dots N$):
   - If start time $s_i \ge \text{last\_finish\_time}$, select activity $A_i$.
   - Update `last_finish_time = f_i`.
   - Otherwise, skip activity $A_i$.

### 3.2. BruteForce Algorithm

The exact solver utilizes a bitmask-based subset generation technique to guarantee an optimal solution by exhaustively evaluating all possible activity combinations:

- **Subset Generation:** Uses an unsigned 64-bit integer (`unsigned long long`) as a bitmask to represent subsets. A bitmask ranges from $0$ to $2^N - 1$, covering all $2^N$ possible combinations.
- **Pruning:** Before validating a subset for overlaps, the algorithm counts the number of selected activities (`current_count`). The overlap check is only executed if `current_count` is strictly greater than the current `max_count`, skipping unnecessary validations for smaller, suboptimal subsets.
- **Overlap Validation:** For qualifying subsets, a nested loop checks every pair of selected activities ($i$ and $j$). An overlap is detected if `arr[i].start < arr[j].finish` and `arr[j].start < arr[i].finish`. If an overlap is found, the subset is immediately marked invalid and discarded.

## 4. Correctness Proof (Exchange Argument)

To prove that the Greedy Choice strategy (selecting the activity with the earliest finish time) yields an global optimal solution, we use the **Exchange Argument** combined with induction:

- **Base Case:** Let $g$ be the activity with the earliest finish time among all available activities. Consider an optimal solution $O$ whose first selected activity is $a$.
- **Exchange Step:** Since $g$ finishes no later than $a$ ($f(g) \le f(a)$), replacing $a$ with $g$ in $O$ preserves compatibility for all subsequent activities in $O$. Thus, $O' = (O \setminus \{a\}) \cup \{g\}$ is also valid and optimal.
- **Inductive Step:** Therefore, an optimal solution starting with $g$ exists. Removing $g$ leaves a subproblem of selecting compatible activities starting after $f(g)$. By induction on the subproblem, every Greedy choice preserves optimality.
- **Conclusion:** The Greedy Algorithm yields a globally optimal solution.

## 5. Complexity Analysis

### 5.1. Greedy Algorithm

#### Time Complexity: $O(N \log N)$

The overall time complexity is dominated by the sorting step:

1. **Sorting Step:** Sorting $N$ activities based on their finish times using Quick Sort (`qsort`) takes **$O(N \log N)$** time in the average and best cases (or $O(N^2)$ worst-case, though $O(N \log N)$ average is standard for evaluation).
2. **Greedy Iteration Step:** A single pass over the $N$ sorted activities to check compatibility and pick valid intervals takes **$O(N)$** time.

$$\text{Total Time Complexity} = O(N \log N) + O(N) = \mathbf{O(N \log N)}$$

#### Space Complexity: $O(N)$ (or $O(1)$ auxiliary)

- **Auxiliary Space:** $O(1)$ additional space if selection is performed in-place.
- **Storage Space:** $O(N)$ space to store the input array of $N$ activities and the selected output list.

$$\text{Total Space Complexity} = \mathbf{O(N)}$$

### 5.2. BruteForce Algorithm

- **Time Complexity:** $O(N^2 \cdot 2^N)$
  The outer loop generates $2^N$ subsets. In the worst-case scenario (where a subset has more activities than `max_count`), evaluating the subset requires iterating through all selected activity pairs to check for overlaps, which takes $O(N^2)$ time.
- **Space Complexity:** $O(1)$ Auxiliary
  The algorithm evaluates activities strictly in place using integer variables and a 64-bit mask for state tracking, requiring no additional data structures. The space complexity is constant, excluding the input array itself.

## 6. Implementation & Execution Guide

This section details the layout of the project files and provides straightforward commands to compile and test the implementations.

### 6.1. Project Structure

The repository is structured to maintain a clear separation between source code, test suites, and documentation:

```text
DSA/
├── .vscode/
│   └── tasks.json
├── Benchmark/
│   ├── Benchmark.c
│   ├── Benchmark.exe
│   ├── Generator.c
│   ├── Generator.exe
│   └── Input100k.txt
├── Test/
│   ├── EdgeCase.txt
│   ├── HandTrace.txt
│   ├── RunTest.c
│   ├── RunTest.exe
│   └── TestCase.txt
├── .gitignore
├── BruteForce.c
├── BruteForce.exe
├── BruteForce.h
├── DP.c
├── GreedyAlgorithm.c
├── GreedyAlgorithm.exe
├── GreedyAlgorithm.h
├── Makefile
├── README.md
└── StructActivity.h
```

### 6.2. Compilation and Execution Guide

This section provides clear, step-by-step instructions to compile and run both the automated test runner and performance benchmark modules using `gcc`.

#### Prerequisites

- **C Compiler:** `gcc` (with standard C99 or later support)
- **Environment:** Command Prompt (CMD) or PowerShell on Windows / Terminal on macOS/Linux

---

#### Step 1: Compilation

Open your terminal at the project root directory (`DSA/`) and execute the following command to compile both executables at once:<br>
gcc -O2 Test/RunTest.c BruteForce.c GreedyAlgorithm.c DP.c -o Test/RunTest.exe ; gcc -O2 Benchmark/Benchmark.c GreedyAlgorithm.c -o Benchmark/Benchmark.exe

#### Step 2: Execution

Run `RunTest`: ./Test/RunTest.exe<br>
Run `Benchmark`: ./Benchmark/Benchmark.exe

## 7. Testing and Experimental Results

### 7.1. Automated 20+ Test Scenarios

The Test/RunTest.c suite dynamically handles test execution and algorithmic validation:

- Dynamic Memory & Parsing: Reads raw data files (TestCase.txt and EdgeCase.txt), allocating memory dynamically via malloc based on the specified $N$ size of each test case. Memory is safely freed after each test iteration to prevent leaks.
- A/B Output Verification: Executes both ActivitySelection (Greedy) and BruteForceActivitySelection on identical input arrays.
- Success Criteria: A test passes exclusively if the result of the Greedy algorithm matches the optimal result produced by the Brute Force algorithm. The runner outputs a detailed CLI trace for each test and calculates a final success rate percentage.

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

**Objective:** Evaluate the scalability, execution speed, and memory stability of the Greedy Algorithm when processing a large-scale dataset ($N = 100,000$).

#### 1. Test Methodology & Environment

- **Dataset:** Generated using `Generator.c`, containing $100,000$ randomized activity intervals ($[start, finish]$) saved in `Input100k.txt`.
- **Execution Setup:** Compiled with `-O2` optimization and executed via `Benchmark/Benchmark.exe`.
- **Metric:** Total processing time measured in milliseconds ($\text{ms}$) using `clock()` / standard timing functions.

#### 2. Experimental Results

To evaluate system stability and measure average execution performance, the benchmark runner was executed across 5 independent runs on the $100,000$-activity dataset:

|    Run #    | Dataset Size ($N$) | Execution Time ($\text{ms}$) |   Status   |
| :---------: | :----------------: | :--------------------------: | :--------: |
|  **Run 1**  |     $100,000$      |          **25.00**           |  Success   |
|  **Run 2**  |     $100,000$      |          **27.00**           |  Success   |
|  **Run 3**  |     $100,000$      |          **18.00**           |  Success   |
|  **Run 4**  |     $100,000$      |          **28.00**           |  Success   |
|  **Run 5**  |     $100,000$      |          **26.00**           |  Success   |
| **Average** |   **$100,000$**    |           **24.8**           | **Stable** |

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

### 8.1. Implementation of Greedy and Brute Force (Requirements 1 & 2)

- **Greedy Activity Selection:** The algorithm sorts all activities in ascending order of finish time using (`qsort`), with a time complexity of (O(N log N)). It then scans the sorted activities and selects an activity if its start time is greater than or equal to the finish time of the previously selected activity. This selection process takes (O(N)) time. By prioritizing activities that finish earliest, the algorithm leaves as much time as possible for subsequent activities.

- **Brute Force:** A brute-force algorithm is implemented to evaluate possible combinations of activities and identify the maximum number of mutually compatible activities. This solver provides an exact solution for small input datasets and serves as a reference for verifying the results produced by the Greedy algorithm.

### 8.2. Verification on Small Datasets (Requirement 3)

We generated 20 realistic scheduling scenarios containing activity intervals with different start and finish times. Both the Greedy and Brute Force algorithms were executed on all 20 test cases. The results matched in every case, confirming that the Greedy algorithm consistently produced the same maximum number of compatible activities as the exact solver for the tested inputs.

### 8.3. Large-Scale Performance Evaluation (Requirement 4)

**Dataset and Setup:** We tested the Greedy algorithm with 100,000 activity intervals from `Input100k.txt`.

**Results:** We ran the program five times and recorded execution times of 25, 27, 18, 28, and 26 ms. The average running time was 24.8 ms.

**Explanation:** The results show that the Greedy algorithm can handle a large number of activities in a short time. Most of the processing time is spent sorting the activities by finish time, which gives the algorithm an overall time complexity of $O(N \log N)$. After sorting, the algorithm only needs to scan the activities once to select compatible intervals.

### 8.4. Proof of Optimality via Exchange Argument (Requirement 5)

**Why Earliest Finish Time Works:** The Greedy algorithm always selects the activity that finishes earliest among the available activities. This leaves more time for the remaining activities and increases the chance of selecting as many non-overlapping activities as possible.

**Exchange Argument:** Suppose an optimal solution starts with an activity $o_1$, while the Greedy algorithm chooses $g_1$. Since Greedy selects the activity with the earliest finish time, $g_1$ finishes no later than $o_1$. Therefore, we can replace $o_1$ with $g_1$ without affecting the compatibility of the remaining activities. The solution still contains the same number of activities and remains optimal.

We can apply the same reasoning to the activities that remain. At each step, the Greedy choice can replace the corresponding activity in an optimal solution without reducing the total number of selected activities. Thus, the Greedy algorithm produces an optimal solution.

**Why Other Strategies May Fail:**

- **Earliest Start Time:** Consider the intervals $[1, 100]$, $[2, 3]$, and $[4, 5]$. Choosing the earliest-starting activity $[1, 100]$ gives only one activity, while choosing $[2, 3]$ and $[4, 5]$ gives two compatible activities.
- **Shortest Duration:** Consider the intervals $[1, 5]$, $[5, 9]$, and $[4, 6]$. Choosing the shortest interval, $[4, 6]$, allows only one activity. However, choosing $[1, 5]$ and $[5, 9]$ allows two compatible activities.

These examples show that choosing the earliest finishing activity is a more reliable strategy for maximizing the number of non-overlapping activities.

## 9. AI Usage Log

| Week       | AI                                 | Prompt                                                                                                                                                                                                                                                                                                                                                                             | AI Assistance / Suggestions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | Processing & Improvement                                                                                                                                                                                                                                                                                                                                               |
| :--------- | :--------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Week 1** | **ChatGPT**<br>_(ChatGPT-6)_       | 1. Guidance on Greedy algorithm problem topics.<br>2. Reviewing Greedy algorithm code.                                                                                                                                                                                                                                                                                             | • Outline 10 steps for implementing the project.<br>• Identify 2 logic errors: incorrect initialization of `count = 0` and failure to handle an empty array ($n = 0$).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 | • Set `count = 1` (since the first activity is always selected).<br>• Add a condition to check for an empty list ($n = 0$).                                                                                                                                                                                                                                            |
| **Week 1** | **Gemini**<br>_(Gemini 3.6 Flash)_ | 1. Brute Force code review.<br>2. Guide on combining two algorithms to run together.                                                                                                                                                                                                                                                                                               | • Identify the error in the time-overlap check logic.<br>• Warn about compilation errors caused by directly `#include`-ing `.c` files; suggest using Header Guards (`#ifndef`).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        | • Added a limit check for $N$ and corrected the logic for overlapping time intervals.<br>• Created a header file, `StructActivity.h`, to be shared by both algorithms.                                                                                                                                                                                                 |
| **Week 2** | **Gemini**<br>_(Gemini 3.6 Flash)_ | 1. Instructions for measuring execution time (benchmarking with 100k data points).<br>2 Fix the "Cannot open file" error & verify edge cases/test cases.<br>3. Review and optimize the automated test suite (`RunTest.c`).                                                                                                                                                         | • Suggest using `clock()` from `<time.h>`.<br>• Identified issues: incorrect file path for `Input100k.txt` and attempting to assign the result of a `void` function.<br>• Recommended adding 2 edge cases (start = finish, start = 0).<br>• Flagged critical errors: improper type casting (using `%`), failure to check the return value of `fscanf`, and resource leaks (memory/file leaks).                                                                                                                                                                                                                                                                                         | • • Change the return type of the `Greedy` function from `void` to `int`.<br>• Correct the file path in `fopen("Benchmark/Input100k.txt", "r")`.<br>• Add two edge cases to the test suite.<br>• Fix type-casting errors, memory leaks, and the handling of test case return codes.                                                                                    |
| **Week 3** | **Gemini**<br>_(Gemini 3.6 Flash)_ | 1. Summary of sections to be included to complete the `README.md` file.<br>2. Markdown formatting guidelines for the structure of the `README.md` file.<br>3. Fix for the issue in `Benchmark.c` (within the `Benchmark/` directory) where `GreedyAlgorithm.h` could not be found.<br>4. Explanation for the anomalous $18\text{ ms}$ result observed during the 5 benchmark runs. | •Outlined a 10-section standard structure for the `README.md` file (covering Project Overview, Problem Statement, Algorithm Design, Proof, Complexity, Execution Guide, Results, Self-Explanation, AI Log, and Conclusion) along with guidelines for Markdown formatting (headers, tables, code blocks, and `<details>` tags).<br>• Identified the cause of the missing header error in `Benchmark.c` (located in the `Benchmark/` subdirectory) and recommended updating the path to `#include "../GreedyAlgorithm.h"`.<br>• Analyzed the 18 ms result, attributing it to CPU cache hits and OS scheduling; advised retaining the 5-run measurement set (with an average of 24.8 ms). | • Implemented the 10-section structure and Markdown formatting in `README.md`.<br>• Corrected the `#include "../GreedyAlgorithm.h"` path in `Benchmark.c`, enabling successful compilation.<br>• Retained the 5 performance measurement runs and updated the average to 24.8 ms.<br>• Completed the Self-Explanation (Section 8) and Conclusion (Section 10) sections. |

## 10. Conclusion

This project successfully implemented, verified, and benchmarked the Greedy Algorithm for the Interval Scheduling / Activity Selection Problem.

Key achievements include:

- **Correctness & Verification:** The Greedy approach was mathematically proven optimal using the _Exchange Argument_. Empirical testing across 20 small-scale scenarios confirmed 100% agreement between the Greedy solver and the exact Brute Force solver.
- **Scalability & Performance:** Benchmark tests on large-scale datasets ($N = 100,000$) demonstrated exceptional computational speed, achieving an average execution time of **$24.8 \text{ ms}$** across 5 independent runs under dynamic gcc `-O2` optimization.
- **Algorithmic Insight:** The empirical evaluation confirms that sorting activities by earliest finish time $O(N \log N)$ provides an optimal, highly efficient, and scalable solution suitable for real-time scheduling applications.
