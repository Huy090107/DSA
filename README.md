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

### 7.2. Hand-Traceable Example

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

## 8. Self-Explanation

### 8.1. Implementation of Greedy and Brute Force (Requirements 1 & 2)

- **Greedy Activity Selection:** The algorithm sorts all activities in ascending order of finish time using (`qsort`), with a time complexity of (O(N log N)). It then scans the sorted activities and selects an activity if its start time is greater than or equal to the finish time of the previously selected activity. This selection process takes (O(N)) time. By prioritizing activities that finish earliest, the algorithm leaves as much time as possible for subsequent activities.

- **Brute Force:** A brute-force algorithm is implemented to evaluate possible combinations of activities and identify the maximum number of mutually compatible activities. This solver provides an exact solution for small input datasets and serves as a reference for verifying the results produced by the Greedy algorithm.

### 8.2. Verification on Small Datasets (Requirement 3)

We generated 20 realistic scheduling scenarios containing activity intervals with different start and finish times. Both the Greedy and Brute Force algorithms were executed on all 20 test cases. The results matched in every case, confirming that the Greedy algorithm consistently produced the same maximum number of compatible activities as the exact solver for the tested inputs.

### 8.3. . Large-Scale Performance Evaluation (Requirement 4)

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

| Week       | AI                                 | Prompt                                                                                                                                                                                                                                                                                                                                                                                | AI Assistance / Suggestions                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | Processing & Improvement                                                                                                                                                                                                                                                                                                                                               |
| :--------- | :--------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Tuần 1** | **ChatGPT**<br>_(ChatGPT-6)_       | 1. Guidance on Greedy algorithm problem topics.<br>2. Reviewing Greedy algorithm code.                                                                                                                                                                                                                                                                                                | • Outline 10 steps for implementing the project.<br>• Identify 2 logic errors: incorrect initialization of `count = 0` and failure to handle an empty array ($n = 0$).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 | • Set `count = 1` (since the first activity is always selected).<br>• Add a condition to check for an empty list ($n = 0$).                                                                                                                                                                                                                                            |
| **Tuần 1** | **Gemini**<br>_(Gemini 3.6 Flash)_ | 1. Brute Force code review.<br>2. Guide on combining two algorithms to run together.                                                                                                                                                                                                                                                                                                  | • Identify the error in the time-overlap check logic.<br>• Warn about compilation errors caused by directly `#include`-ing `.c` files; suggest using Header Guards (`#ifndef`).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        | • Added a limit check for $N$ and corrected the logic for overlapping time intervals.<br>• Created a header file, `StructActivity.h`, to be shared by both algorithms.                                                                                                                                                                                                 |
| **Tuần 2** | **Gemini**<br>_(Gemini 3.6 Flash)_ | 1. Instructions for measuring execution time (benchmarking with 100k data points).<br>2. Fix the "Cannot open file" error & verify edge cases/test cases.<br>3. Review and optimize the automated test suite (`RunTest.c`).                                                                                                                                                           | • Suggest using `clock()` from `<time.h>`.<br>• Identified issues: incorrect file path for `Input100k.txt` and attempting to assign the result of a `void` function.<br>• Recommended adding 2 edge cases (start = finish, start = 0).<br>• Flagged critical errors: improper type casting (using `%`), failure to check the return value of `fscanf`, and resource leaks (memory/file leaks).                                                                                                                                                                                                                                                                                         | • • Change the return type of the `Greedy` function from `void` to `int`.<br>• Correct the file path in `fopen("Benchmark/Input100k.txt", "r")`.<br>• Add two edge cases to the test suite.<br>• Fix type-casting errors, memory leaks, and the handling of test case return codes.                                                                                    |
| **Tuần 3** | **Gemini**<br>_(Gemini 3.6 Flahs)_ | 1. 1. Summary of sections to be included to complete the `README.md` file.<br>2. Markdown formatting guidelines for the structure of the `README.md` file.<br>3. Fix for the issue in `Benchmark.c` (within the `Benchmark/` directory) where `GreedyAlgorithm.h` could not be found.<br>4. Explanation for the anomalous $18\text{ ms}$ result observed during the 5 benchmark runs. | •Outlined a 10-section standard structure for the `README.md` file (covering Project Overview, Problem Statement, Algorithm Design, Proof, Complexity, Execution Guide, Results, Self-Explanation, AI Log, and Conclusion) along with guidelines for Markdown formatting (headers, tables, code blocks, and `<details>` tags).<br>• Identified the cause of the missing header error in `Benchmark.c` (located in the `Benchmark/` subdirectory) and recommended updating the path to `#include "../GreedyAlgorithm.h"`.<br>• Analyzed the 18 ms result, attributing it to CPU cache hits and OS scheduling; advised retaining the 5-run measurement set (with an average of 24.8 ms). | • Implemented the 10-section structure and Markdown formatting in `README.md`.<br>• Corrected the `#include "../GreedyAlgorithm.h"` path in `Benchmark.c`, enabling successful compilation.<br>• Retained the 5 performance measurement runs and updated the average to 24.8 ms.<br>• Completed the Self-Explanation (Section 8) and Conclusion (Section 10) sections. |

## 10. Conclusion

This project successfully implemented, verified, and benchmarked the Greedy Algorithm for the Interval Scheduling / Activity Selection Problem.

Key achievements include:

- **Correctness & Verification:** The Greedy approach was mathematically proven optimal using the _Exchange Argument_. Empirical testing across 20 small-scale scenarios confirmed 100% agreement between the Greedy solver and the exact Brute Force solver.
- **Scalability & Performance:** Benchmark tests on large-scale datasets ($N = 100,000$) demonstrated exceptional computational speed, achieving an average execution time of **$24.8 \text{ ms}$** across 5 independent runs under dynamic gcc `-O2` optimization.
- **Algorithmic Insight:** The empirical evaluation confirms that sorting activities by earliest finish time $O(N \log N)$ provides an optimal, highly efficient, and scalable solution suitable for real-time scheduling applications.
