// Solution.h
#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    ListNode* ny_addTwoNumbers(ListNode* l1, ListNode* l2);

	int ny_lengthOfLongestSubstring(string s);

     int lengthOfLongestSubstring(string s);

    int lengthOfLongestSubstringOptimize(string s);


    void insertTreeNode(TreeNode *&p, int val);

    void traverseTree(TreeNode *t);

    void sortArray(TreeNode *t, std::vector<int> &v);

    
    double medianOfSortedArray(vector<int>& nums);

    double ny_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    /// sortArrayMinimum

    void sortArrayMinimum(TreeNode *t, std::vector<int> &v, int &min);

    vector<vector<int>> minimumAbsDifference(vector<int>& arr);
};

#endif
