class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = -1;
        int j = -1;
        int m = nums1.size();
        int n = nums2.size();
        int m_n = m + n;
        int cnt = 0;
        int median1 = 0;
        int median2 = 0;
        double res;
        
        if (m_n % 2 == 0) {
            while ((cnt * 2 < m_n) && (i < m || j < n)) {
                cnt++;
                if (i == m - 1) {
                    j++;
                    if (cnt * 2 == m_n) {
                        median1 = nums2[j];
                    }    
                } else if (j == n - 1) {
                    i++;
                    if (cnt * 2 == m_n) {
                        median1 = nums1[i];
                    }
                } else {
                    if (nums1[i + 1] < nums2[j + 1]) {
                        i++;
                        if (cnt * 2 == m_n) {
                            median1 = nums1[i];
                        }
                    } else {
                        j++;
                        if (cnt * 2 == m_n) {
                            median1 = nums2[j];
                        }
                    }
                }
                
                // For median2
                if (cnt * 2 == m_n) {
                    cnt++;
                    if (i == m - 1) {
                        j++;
                        median2 = nums2[j];  
                    } else if (j == n - 1) {
                        i++;
                        median2 = nums1[i];
                    } else {
                        if (nums1[i + 1] < nums2[j + 1]) {
                            i++;
                            median2 = nums1[i];
                        } else {
                            j++;
                            median2 = nums2[j];
                        }
                    }
                }
                
            }
            
            
            
        }

        if (m_n % 2 != 0) {
            while ((cnt * 2 < m_n) && (i < m || j < n)) {
                cnt++;
                if (i == m - 1) {
                    j++;
                    if (cnt * 2 > m_n) {
                        median1 = nums2[j];
                    }    
                } else if (j == n - 1) {
                    i++;
                    if (cnt * 2 > m_n) {
                        median1 = nums1[i];
                    }
                } else {
                    if (nums1[i + 1] < nums2[j + 1]) {
                        i++;
                        if (cnt * 2 > m_n) {
                            median1 = nums1[i];
                        }
                    } else {
                        j++;
                        if (cnt * 2 > m_n) {
                            median1 = nums2[j];
                        }
                    }
                }
                
            }
            
            median2 = median1;
        }
        
        cout << median1 << endl;
        cout << median2 << endl;
        
        res = ((double)median1 + (double)median2) / 2;
        
        return res;
        
    }
};