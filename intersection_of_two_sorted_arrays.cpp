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
