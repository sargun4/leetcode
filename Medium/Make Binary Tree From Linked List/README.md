<h2><a href="https://www.geeksforgeeks.org/problems/make-binary-tree/1?page=5&category=Tree&sortBy=difficulty">Make Binary Tree From Linked List</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.</span><br><span style="font-size: 18px;"><strong>Note : </strong>The&nbsp;complete binary tree is represented as a linked list&nbsp;in a way where if root node is stored at position&nbsp;i, its left, and right children are stored at position&nbsp;<strong>2*i+1</strong>, <strong>2*i+2</strong> respectively.</span><br><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 5
K = 1-&gt;2-&gt;3-&gt;4-&gt;5
<strong>Output: </strong>1 2 3 4 5<strong>
Explanation: </strong>The tree would look like
&nbsp; &nbsp;   1
  &nbsp; /&nbsp;  \
 &nbsp; 2&nbsp;  &nbsp; 3
 /&nbsp;&nbsp;\
4&nbsp; &nbsp;5
Now, the level order traversal of
the above tree is 1 2 3 4 5.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 5
K = 5-&gt;4-&gt;3-&gt;2-&gt;1
<strong>Output: </strong>5 4 3 2 1<strong>
Explanation: </strong>The tree would look like</span>
<span style="font-size: 18px;">&nbsp; &nbsp;  5
&nbsp; &nbsp;/&nbsp; \
 &nbsp;4&nbsp; &nbsp; 3
 /&nbsp;\
2&nbsp; &nbsp; 1
Now, the level order traversal of
the above tree is 5 4 3 2 1.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>The task is to complete the function <strong>convert</strong>() which takes head of linked list and <strong>root </strong>of the tree as the reference. The driver code prints the level order.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span><br><span style="font-size: 18px;"><strong>Note: </strong>H is the height of the tree and this space is used implicitly for recursion stack.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>5</sup><br>1 &lt;= K<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Queue</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;