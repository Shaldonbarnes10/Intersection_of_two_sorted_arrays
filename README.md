
# Find Intersection of Two Arrays - Two Pointer Approach

## Problem Overview

You are given two arrays, `A` and `B`, both sorted in non-decreasing order. The task is to find the intersection of these two arrays, which means returning all the elements that appear in both arrays.

### Input Format

- The first input will be the number of test cases, `T`.
- For each test case:
  - The first line contains two integers, `N` and `M`, representing the sizes of the two arrays `A` and `B`.
  - The second line contains `N` integers, the elements of array `A`.
  - The third line contains `M` integers, the elements of array `B`.

### Output Format

For each test case, print the intersection of arrays `A` and `B`. The result should be in the order of the elements that appear in the original arrays. If no intersection exists, print "No intersection".

### Constraints

- `1 <= T <= 100`
- `1 <= N, M <= 10^4`
- `0 <= A[i], B[i] <= 10^5`
- Time Limit: 1 second

### Example

**Input:**
```
2
5 6
1 2 3 4 5
2 3 4 5 6 7
4 4
10 20 30 40
30 40 50 60
```

**Output:**
```
2 3 4 5
30 40
```

## Approach

The solution to this problem uses the **Two Pointer Technique**. Both arrays `A` and `B` are sorted in non-decreasing order, so we can leverage this sorted property to efficiently find the intersection.

### Steps:

1. Initialize two pointers `i` and `j` starting from the beginning of arrays `A` and `B`, respectively.
2. Compare the current elements `A[i]` and `B[j]`:
   - If they are equal, this is part of the intersection. Add it to the result and move both pointers forward.
   - If `A[i] < B[j]`, increment `i` to find a larger element in array `A`.
   - If `A[i] > B[j]`, increment `j` to find a larger element in array `B`.
3. Continue until one of the pointers exceeds the bounds of its respective array.
4. If there are any common elements, print them. If no common elements are found, print "No intersection".

### Time Complexity

- Each test case requires a linear scan through both arrays. The time complexity per test case is **O(N + M)**, where `N` and `M` are the sizes of the two arrays.
- Given `T` test cases, the total time complexity is **O(T * (N + M))**.

### Space Complexity

- The space complexity is **O(min(N, M))** for storing the intersection result.

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    
    // Traverse through both arrays to find intersection
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return ans;
}

int main() {
    int T;
    cin >> T;  // Read number of test cases
    
    while (T--) {
        int N, M;
        cin >> N >> M;  // Read sizes of the arrays
        
        vector<int> arr1(N), arr2(M);
        
        // Read first array
        for (int i = 0; i < N; i++) {
            cin >> arr1[i];
        }
        
        // Read second array
        for (int i = 0; i < M; i++) {
            cin >> arr2[i];
        }
        
        // Call the function to find the intersection
        vector<int> result = findArrayIntersection(arr1, N, arr2, M);
        
        // If result is empty, print "No intersection"
        if (result.empty()) {
            cout << "No intersection" << endl;
        } else {
            // Print the intersection elements
            for (int num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
```

## How to Run

1. Clone this repository to your local machine.
2. Compile the C++ code using a C++ compiler:

   ```bash
   g++ -o find_intersection find_intersection.cpp
   ```

3. Run the compiled program:

   ```bash
   ./find_intersection
   ```

4. Enter the input in the required format as specified in the problem description.

## Conclusion

The **Two Pointer Approach** provides an optimal solution to the "Find Intersection of Two Arrays" problem. By taking advantage of the fact that both arrays are sorted, this approach efficiently finds the common elements in linear time, making it suitable for large inputs within the given constraints.
