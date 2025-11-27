/*
BRUTE FORCE APPROACH
function maxSlidingWindow(nums, k):
    n = length(nums)
    ans = empty list

    for i from 0 to n - k:
        currentMax = nums[i]
        
        for j from i to i + k - 1:
            currentMax = max(currentMax, nums[j])
        
        ans.push(currentMax)

    return ans

Time Complexity

Inner loop scans k elements

Outer loop runs n - k + 1 times
➡️ TC = O(n × k)
Very slow for large arrays (n up to 10⁵).
➡️ SC = O(1) (excluding answer output)
*/



/*
OPTIMIZED APPROACH — USING DEQUE
WHY USING INDEXES IS BETTER THAN VALUES?
Indexes uniquely identify each element in relation to the window,
prevent duplicate confusion, allow proper window removal, and keep 
the deque efficient — values cannot do that.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
    list<int> dq;  // will store indexes
    vector<int> ans;
    int i = 0, j = 0;

    while (j < n) {

        // Remove all smaller elements (compare by value using nums[])
        while (!dq.empty() && nums[dq.back()] < nums[j]) {
            dq.pop_back();
        }

        dq.push_back(j);  // push index

        // If window not formed yet
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Front of list contains max index
            ans.push_back(nums[dq.front()]);       

            // Slide window: remove index i if it is at front
            if (dq.front() == i) {
                dq.pop_front();
            }

            i++;
            j++;
        }
    }

    return ans;
    }
};