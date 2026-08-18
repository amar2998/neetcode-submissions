class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while( i<n && j< m)
        {
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        int size=ans.size();
        if(size % 2 ==1){
            int mid=ans.size()/2;
            return ans[mid];
        }
        else{
            int mid1=ans.size()/2;
            int mid2=mid1-1;

            return (double)(ans[mid1]+ans[mid2])/2;
        }
    }
};
