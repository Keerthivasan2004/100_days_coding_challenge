/*Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)
Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes two BST's as parameter in the form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6*/

Solution:

class Solution
{
	public static int countPairs(Node root1, Node root2, int x)
	{
		ArrayList<Integer> l1=new ArrayList();
		
		ArrayList<Integer> l2=new ArrayList();
		
		inorder(root1,l1);
		inorder(root2,l2);
		int i=0,j=l2.size()-1;
		int c=0;
		while(i<l1.size()&& j>=0){
		    int sum=l1.get(i)+l2.get(j);
		    if(sum==x){
		        c++;
		        i++;
		        j--;
		    }
		    else if(sum>x){
		        j--;
		    }
		    else{
		        i++;
		    }
		    
		}
		return c;
	}
	public static void inorder(Node root,ArrayList<Integer> list){
	    if(root==null)
	    return;
	    inorder(root.left,list);
	    list.add(root.data);
	    inorder(root.right,list);
	}
}
