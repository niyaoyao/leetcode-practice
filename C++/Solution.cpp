// Solution.cpp
#include "Solution.h"
#include <cmath>

void printMap (std::map<char, int> stringMap) {
	for (auto &v : stringMap) {
		cout << v.first;
	}
    cout << "\n";
    for (auto &v : stringMap) {
        cout << v.second << " ";
    }
	cout << "\n" << endl;
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    std::vector<int> result;
    std::map<int, int> temp;
    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
    {
        int diff = target - *i;
        cout << "diff:" << diff << " = " << target << "-" << *i << endl;
        // vector<int>::iterator ite1 = find(nums.begin(), nums.end(), *i);
        // auto index = std::distance(std::begin(nums), ite1);
        int index = i - nums.begin();

        if (temp.find(diff) != temp.end()) {
            int key = temp[diff];
            cout << "Found:" << " nums[" << index << "] = " << *i << " + " << nums[key]  << "=" << target << endl;
            
            if (nums[key] + *i == target)
            {
                result.push_back(key);
                result.push_back(index);
                return result;
            } else {
                continue;
            }
        }

        temp[*i] = index;
        cout << "*i" << ":" << *i << " temp["<< diff <<"]:" << temp[diff] << " index:" << index << endl;

        
    }
    return result;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *p = l1; 
    ListNode *q = l2; 
    ListNode *current = dummyHead;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
        if (p != NULL)
        {
            p = p->next;
        }

        if (q != NULL)
        {
            q = q->next;
        }
    }

    if (carry > 0)
    {
        current->next = new ListNode(carry);
    }
    return current;
}

ListNode* Solution::ny_addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p = l1;
    ListNode *q = p;
    ListNode *k = l2;
    ListNode *j = k;
    ListNode *l = NULL;
    ListNode *h = l;
    ListNode *w = h;
    int upNum = 0;
    while(p != NULL || k != NULL || upNum > 0) {
        int sum = 0;
        sum += upNum;
        upNum = 0;
        if (p != NULL) {
            sum += p->val;
            q = p;
            p = p->next;
        }

        if (k != NULL) {
            sum += k->val;
            j = k;
            k = k->next;
        }

        int value = sum;
        if (sum >= 10) {
            upNum = sum / 10;
            int left = sum - upNum * 10;
            left = abs(left);
            value = left;
        }

        ListNode *n = new ListNode(value);

        if (l == NULL) {
            l = n;
            h = l;
            w = h;
        } else {
            h->next = n;
            w = h;
            h = h -> next;
        }
    }

    return l;
}

int Solution::ny_lengthOfLongestSubstring(string s) {
	
	int maxLength = 0;
	std::map<char, int> stringMap;
	int sameIndex = 0;
    cout << "NY String:" << s << endl;
	for (int i = 0; i < s.length(); i++) {
        cout << "\nCurrent: s[i]=" << s[i] << endl;
        
		if (stringMap[s[i]])
		{
			sameIndex = stringMap[s[i]];
			i = sameIndex;
			stringMap = map<char, int>();
		} else {
			stringMap[s[i]] = i;
		}
		maxLength = stringMap.size() > maxLength ? stringMap.size() : maxLength;

	}

    return maxLength;
}

 int  Solution::lengthOfLongestSubstring(string s) {
    
    int maxLength = 0, i = 0, j = 0;
    std::set<char> characterSet;
    cout << "\nString: " << s << endl;
    while (i < s.length() && j < s.length()) {
        cout << "Current: s[i]=" << s[i] << " Current s[j]=" << s[j] << endl;
        if (!(characterSet.find(s[j]) != characterSet.end()))
        {
            cout << "Not Contain Character" << endl;
            characterSet.insert(s[j++]);
            maxLength = max(maxLength, j-i);
        } else {
            characterSet.erase(s[i++]);
        }
        set<char>::iterator it;
        for(it = characterSet.begin(); it != characterSet.end(); it++) 
            cout << (*it);
        cout << " " << endl;
    }
    return maxLength;
}

int  Solution::lengthOfLongestSubstringOptimize(string s) {
    
    int maxLength = 0;
    std::map<char, int> charMap;
    cout << "\nString: " << s << endl;
    int n = s.length();
    for (int i = 0, j = 0; j < n; j++)
    {
        cout << "\nCurrent: s[i("<<i<<")]=" << s[i] << " Current s[j("<<j<<")]=" << s[j] << endl;
        if (charMap.find(s[j]) != charMap.end())
        {
            cout << "Contain:" << s[j] << " charMap["<< s[j] <<"]=" << charMap[s[j]] << " i=" << i << endl;
            i = max(charMap[s[j]], i);
        }
        maxLength = max(maxLength, j - i + 1);
        cout << "Max Length:" << maxLength << endl;
        charMap[s[j]] = j + 1;

    }
    return maxLength;
}


void  Solution::insertTreeNode(TreeNode *&p, int val) {
    cout << "Insert:" << val << endl;
    if (p == NULL) {
        p = new TreeNode(val);
    } 
    else if (val <= p->val) {           
        insertTreeNode(p->left, val);
    }
    else {
        insertTreeNode(p->right, val);
        return;
    }
}

void Solution::traverseTree(TreeNode *t) {
    if (t != NULL)
    {   // In-Order Traversal
        traverseTree(t->left);
        cout << t->val << "/";
        traverseTree(t->right);
    }
}

void Solution::sortArray(TreeNode *t, std::vector<int> &v) {
    if (t != NULL)
    {
        sortArray(t->left, v);
        v.push_back(t->val);
        sortArray(t->right, v);
    }
}


double Solution::medianOfSortedArray(vector<int>& nums) {
    double result = 0.0;

    if (nums.size() % 2 == 1)
    {
        
        int index = (nums.size() + 1) / 2 - 1;
        result = (double)nums.at(index);
        cout << "Odd Number:" << nums.at(index) << endl;
    } else {
        int i0 = nums.size() / 2 - 1;
        int i1 = nums.size() / 2;

        double sum = (double)nums.at(i0) + (double)nums.at(i1);
        cout << "sum: " << sum << endl;
        result = (double)(sum) / 2.0;

        cout << "Even Number: 1/2*(" << nums.at(i0) << "+" << nums.at(i1) << ") = " << result << endl;
    }

    return result;
}

double Solution::ny_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result = 0.0;
    std::vector<int> unsortVector;
    unsortVector.insert(unsortVector.end(), nums1.begin(), nums1.end());
    unsortVector.insert(unsortVector.end(), nums2.begin(), nums2.end());
    TreeNode *t = NULL;
    for (std::vector<int>::iterator i = unsortVector.begin(); i < unsortVector.end(); ++i)
    {
        insertTreeNode(t, *i);
    }
    std::vector<int> sortedArray;

    sortArray(t, sortedArray);
    cout << "====== Finish Sort ======" << endl;
    for (std::vector<int>::iterator i = sortedArray.begin(); i != sortedArray.end(); ++i)
    {
     cout << *i << " ";
    }

    result = medianOfSortedArray(sortedArray);
    return result;
}


double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result = 0.0;
    std::vector<int> unsortVector;
    unsortVector.insert(unsortVector.end(), nums1.begin(), nums1.end());
    unsortVector.insert(unsortVector.end(), nums2.begin(), nums2.end());
    TreeNode *t = NULL;
    for (std::vector<int>::iterator i = unsortVector.begin(); i < unsortVector.end(); ++i)
    {
        insertTreeNode(t, *i);
    }
    std::vector<int> sortedArray;

    sortArray(t, sortedArray);
    
    result = medianOfSortedArray(sortedArray);
    return result;
}

/// sortArrayMinimum

void Solution::sortArrayMinimum(TreeNode *t, std::vector<int> &v, int &min) {
    if (t != NULL)
    {
        sortArrayMinimum(t->left, v, min);
        if (v.size() > 0 && (t->val - v.back() < min)) {
                min = t->val - v.back();
                cout << "sort min:" << min << endl;
        }
        v.push_back(t->val);
        sortArrayMinimum(t->right, v, min);
    }
}

vector<vector<int>> Solution::minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> v;

    TreeNode *t = NULL;
    int maxDiff = 0;
    for (std::vector<int>::iterator i = arr.begin(); i < arr.end(); ++i)
    {
    	insertTreeNode(t, *i);
    	if (i != arr.begin()) {
    		int diff = (*i - *(i-1));
    		if (diff > maxDiff) {
    			maxDiff = diff;
    		}
    	}
    }

    std::vector<int> sortedArray;

    int minDiff = maxDiff;
    cout << "min:" << minDiff << endl;

    sortArrayMinimum(t, sortedArray, minDiff);

    cout << "min:" << minDiff << endl;
    for (std::vector<int>::iterator i = sortedArray.begin(); i != sortedArray.end(); ++i)
    {
    	cout << "" << *i << " ";

    	std::vector<int> pair;
    	if (i != sortedArray.begin()) {
    		int diff = *i - *(i-1);
    		if ( diff <= minDiff ) {
    			pair.push_back(*(i-1));
    			pair.push_back(*(i));
    			v.push_back(pair);
    		}
    	}
    }

    cout << "\n" << endl;

    for (std::vector<vector<int>>::iterator i = v.begin(); i != v.end(); ++i)
    {
    	std::vector<int> temp = *i;
    	cout << "[";
    	for (std::vector<int>::iterator j = temp.begin(); j != temp.end(); ++j)
    	{
    		cout << *j;
    		cout << ",";
    	}
    	cout << "]";
    }

    return v;
}

/**
* Longest Palindrome
*/


string longestPalindrome(string s) {
	string result;
	return  result;
}


int Solution::maxScore(string s) {
    int maxScore = 0;
    int leftScore = 0;
    int leftOneCount = 0;
    int rightScore = 0;
    int zeroCount = 0;
    int oneCount = 0;
    char one = '1';
    char zero = '0';

    printf("1:%d 0:%d \n", one, zero);
    for (int i = 0; i < s.length(); ++i)
    {
        printf("%c\t", s[i]);
        char c = s[i];
        if (c == zero)
        {
            zeroCount++;
        } else if (c == one) {
            oneCount++;
        }

    }
    printf("\nCount one:%d zero:%d \n", oneCount, zeroCount);

    int leftStringCount, rightStringCount = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];

        if (c == zero)
        {
            leftScore++;  
            leftStringCount++;     
        } else if (c == one) {
            leftOneCount++;
        }
        leftStringCount = i + 1;
        rightStringCount = s.length() - leftStringCount;
        int currentScore = 0;
        if ((leftStringCount > 0 && leftStringCount < s.length()) || (rightStringCount > 0 && rightStringCount < s.length()))
        {
            rightScore = oneCount - leftOneCount;
            int currentScore = leftScore + rightScore;
            maxScore = currentScore > maxScore ? currentScore : maxScore;
        }
        printf("current:%c leftScore:%d rightScore:%d leftOneCount:%d currentScore:%d maxScore:%d leftString:%d right:%d \n", s[i], leftScore, rightScore, leftOneCount, currentScore, maxScore, leftStringCount, rightStringCount);
    }

    return maxScore;
}

int Solution::singleNumber(vector<int>& nums) {
    int result;
    std::map<int, int> charMap;
    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
    {
        if (!charMap[*i])
        {
            charMap[*i] = 1;
        } else {
            charMap[*i] += 1;
        }
    }


    for (auto &v : charMap) {
        if (v.second == 1)
        {
            result = v.first;
        }
    }

    return result;
}

bool Solution::isHappy(int n) {
    cout << "n:" << n << endl;
    std::map<int, int> numberMap;
    while(n > 1 && numberMap[n] == 0) {
        numberMap[n] = n;
        n = perfectDigitalInvariant(n, 10);
        cout << "number: " << n << endl;
    }

    return n == 1;
}

int Solution::perfectDigitalInvariant(int number, int base) {
    int total = 0;
    while(number > 0) {
        total = total + pow(number % base, 2);
        cout << "total:" << total << endl;
        number = number / base;
    }
    return total;
}

int Solution::maxSubArray(vector<int>& nums) {
    int sum = 0;
    return sum;
}

