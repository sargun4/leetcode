<h2><a href="https://www.geeksforgeeks.org/problems/vertical-sum/1?page=7&category=Tree&sortBy=difficulty">Vertical sum</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
     <span style="font-size: 18px;">  1
    /   \
  2      3
 / \    / \
4   5  6   7
<strong>Output: </strong>4 2 12 3 7<strong>
Explanation:</strong></span>
<span style="font-size: 18px;">The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 =&gt; vertical sum is 4
Vertical-Line-2: has only one node
2=&gt; vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 =&gt; vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=&gt; vertical sum is 3
Vertical-Line-5: has only one node 7
=&gt; vertical sum is 7</span>
</pre>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong><br><span style="font-size: 18px;">You don't need to take input. Just complete the function<strong>&nbsp;verticalSum()&nbsp;</strong>that takes <strong>root </strong>node of the tree<strong>&nbsp;</strong>as parameter and returns an array containing&nbsp;the vertical sum of tree from left to right.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>: O(NlogN).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&lt;=Number of nodes&lt;=10<sup>3</sup><br>1&lt;= Node Value &lt;= 10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;