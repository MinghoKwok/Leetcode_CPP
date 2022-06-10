## FaceBook 

### 408. Valid Word Abbreviation

Easy	

Facebook

A string can be **abbreviated** by replacing any number of **non-adjacent**, **non-empty** substrings with their lengths. The lengths **should not** have leading zeros.

For example, a string such as `"substitution"` could be abbreviated as (but not limited to):

- `"s10n"` (`"s ubstitutio n"`)
- `"sub4u4"` (`"sub stit u tion"`)
- `"12"` (`"substitution"`)
- `"su3i1u2on"` (`"su bst i t u ti on"`)
- `"substitution"` (no substrings replaced)

The following are **not valid** abbreviations:

- `"s55n"` (`"s ubsti tutio n"`, the replaced substrings are adjacent)
- `"s010n"` (has leading zeros)
- `"s0ubstitution"` (replaces an empty substring)

Given a string `word` and an abbreviation `abbr`, return *whether the string **matches** the given abbreviation*.

A **substring** is a contiguous **non-empty** sequence of characters within a string.

 

**Example 1:**

```
Input: word = "internationalization", abbr = "i12iz4n"
Output: true
Explanation: The word "internationalization" can be abbreviated as "i12iz4n" ("i nternational iz atio n").
```

**Example 2:**

```
Input: word = "apple", abbr = "a2e"
Output: false
Explanation: The word "apple" cannot be abbreviated as "a2e".
```

 

**Constraints:**

- `1 <= word.length <= 20`
- `word` consists of only lowercase English letters.
- `1 <= abbr.length <= 10`
- `abbr` consists of lowercase English letters and digits.
- All the integers in `abbr` will fit in a 32-bit integer.



边界情况极多 需复盘

[ Accepted](https://leetcode.com/submissions/detail/712209626/)

```c++
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string abbr_word = "";
        int num = 0;
        int w = 0; // index of word
        
        for (int i = 0; i < strlen(abbr.c_str()); i++) {
            if (w == strlen(word.c_str()))
                return false;
            
            if (abbr[i] <= '9' && abbr[i] >= '0') {
                if (num == 0 && abbr[i] == '0')
                    return false;
                
                num = num * 10 + abbr[i] - '0';
                
                if (i == strlen(abbr.c_str()) - 1) {
                    w += num;
                }
                
                
            } else {
                if (num != 0) {
                    w += num;
                    num = 0;
                }
                
                if (word[w] != abbr[i])
                    return false;
                w++;
            }
        }
        
        
        if (w != strlen(word.c_str()))
            return false;
        
        
        return true;
        
    }
};
```





### 88. Merge Sorted Array

Easy

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be *stored inside the array* `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

 

**Example 1:**

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

**Example 2:**

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```

**Example 3:**

```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

 

**Constraints:**

- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-109 <= nums1[i], nums2[j] <= 109`



https://leetcode.com/problems/merge-sorted-array/solution/

Approach 3: Three Pointers (Start From the End)

- Time complexity: \mathcal{O}(n + m)O(*n*+*m*).

  Same as Approach 2.

- Space complexity: \mathcal{O}(1)O(1).

  Unlike Approach 2, we're not using an extra array.

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (p1 < 0) {
                nums1[i] = nums2[p2];
                p2--;
                continue;
            }
            
            if (p2 < 0) {
                nums1[i] = nums1[p1];
                p1--;
                continue;
            }
            
            if (nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
        }
    }
};
```



### 162. Find Peak Element

Medium

61573765Add to ListShare

A peak element is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`.

You must write an algorithm that runs in `O(log n)` time.

 

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

**Example 2:**

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `-231 <= nums[i] <= 231 - 1`
- `nums[i] != nums[i + 1]` for all valid `i`.



#### My C++  O(n) Linear Scan

```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[len - 1] > nums[len - 2])
            return len - 1;
        
        for (int i = 1; i < len - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        
        return -1;
    }
};
```



#### Recursive Binary Search

O(log n)

To find the largest number

```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0; 
        int r = nums.size() - 1;
        return findMaxElement(nums, l, r);
    }
    
    int findMaxElement(vector<int>& nums, int l, int r) {
        if (l == r)
            return l;
        
        int mid = (l + r) / 2;
        if (nums[mid] < nums[mid + 1])
            return findMaxElement(nums, mid + 1, r);
        else 
            return findMaxElement(nums, l, mid);
    }
};
```



​	