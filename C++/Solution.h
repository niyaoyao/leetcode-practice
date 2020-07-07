// Solution.h
#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <stack>

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
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
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
    int maxScore(string s);
    int singleNumber(vector<int>& nums);

    int perfectDigitalInvariant(int number, int base);
    bool isHappy(int n);
    
    int maxSubArray(vector<int>& nums);
    vector<int> shuffle(vector<int>& nums, int n);
    ListNode* reverseList(ListNode* head);
};

#endif
