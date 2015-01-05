#include<vector>
#include<unordered_set>
#include"util.h"
using namespace std;
//0.Maximum Gap
int maxGap();
//15.3Sum
vector<vector<int> > threeSum(vector<int>&);
//21.Merge Two Sorted List
ListNode* mergeTwoLists(ListNode*, ListNode*);
//26.Remove Duplicates from Sorted Array
int removeDuplicates(int[], int);
//27.Remove Element
int removeElement(int[], int, int);
//41.First Missing Positive
int firstMissingPositive(int[], int);
//46.Permutations
vector<vector<int> > permute(vector<int>&);
//55.Jump Game
bool canJump(int[], int);
//57.Insert Interval
vector<Interval> insert(vector<Interval>&, Interval);
//69.Sqrt(x)
int sqrt(int);
//77.Combinations
vector<vector<int> > combine(int, int);
//84.Largest Rectangle in Histogram
int largestRectangleArea(vector<int>&);
//86.Partitiion List
ListNode* partition(ListNode*, int);
//93.Restore IP Address
vector<string> restoreIpAddresses(string);
//94.Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode*);
//95.Unique Binary Search Tree II
vector<TreeNode *> generateTrees(int);
//100.Same Tree
bool isSameTree(TreeNode*, TreeNode*);
//102.Binary Tree Level Order Traversal
vector<vector<int> > levelOrder(TreeNode*);
//104.Maximum Depth of Binary Tree
int maxDepth(TreeNode*);
//107.Binary Tree Level Order Traversal II
vector<vector<int> > levelOrder2(TreeNode*);
//108.Convert Sorted Array to Binary Search Tree
TreeNode* sortedArrayToBST(vector<int>&);
//109.Convert Sorted List to Binary Search Tree
TreeNode *sortedListToBST(ListNode*);
//110.Balanced Binary Tree
bool isBalanced(TreeNode*);
//111.Minimum Depth of Bianry Tree
int minDepth(TreeNode*);
//112.Path Sum
bool hasPathSum(TreeNode*, int);
//113.Path Sum II
vector<vector<int> > pathSum(TreeNode*, int);
//114.Flatten Binary Tree to Linked List
void flatten(TreeNode*);
//115.Distinct Subsequence
int numDistinct(string S, string T);
//119.Pascal's Triangle II
vector<int> getRow(int);
//127.Word Ladder
int ladderLength(string, string, unordered_set<string>&);
//128.Longest Consecutive Sequence
int longestConsecutive(vector<int>&);
//129.Sum Root to Leaf Numbers
int sumNumbers(TreeNode*);
//141.Linked List Cycle
bool hasCycle(ListNode*);
//142.Linked List Cycle II
ListNode* detectCycle(ListNode*);
//143.Reorder List
void reorderList(ListNode*);
//145.Binary Tree Postorder Tranversal
vector<int> postorderTraversal(TreeNode*);
//147.Insertion Sort List
ListNode* insertionSortList(ListNode*);
//148.Sort List
ListNode* sortList(ListNode*);
//153.Find Minimum in Routated orted Array
int findMin(vector<int>&);
//154.Find Minimum in Routated orted Array II
int findMin2(vector<int>&);
//160.Intersection of Two Linked Lists
ListNode* getIntersectionNode(ListNode*, ListNode*);
//166.Fraction to Recurring Decimal
string fractionToDecimal(long long, long long);
//169.Majority Element
int majorityElement(vector<int>&);
//172.Factorial Trailing Zeroes
int trailingZeroes(int);