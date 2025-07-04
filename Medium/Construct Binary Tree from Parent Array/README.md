<h2><a href="https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1?page=5&category=Tree&sortBy=difficulty">Construct Binary Tree from Parent Array</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of size <strong>N</strong> that can be used to&nbsp;represents a tree. The&nbsp;array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be <strong>-1</strong> as there is no parent for root. Construct the standard linked representation of Binary Tree from this array representation.</span></p>

<p><strong><span style="font-size:18px">Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child.&nbsp;</span></strong></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 7
parent[] = {-1,0,0,1,1,3,5}
<strong>Output: </strong>0 1 2 3 4 5 6<strong>
Explanation: </strong>the tree generated
will have a structure like 
&nbsp;       &nbsp; 0
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  /&nbsp;&nbsp; \
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  1&nbsp;&nbsp;&nbsp;&nbsp; 2
&nbsp;&nbsp;&nbsp;&nbsp;  / \
&nbsp;&nbsp;&nbsp;  3&nbsp;&nbsp; 4
&nbsp;&nbsp;  /
&nbsp;  5
 /
6</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 3
parent[] = {2, 0, -1}
<strong>Output: </strong>2 0 1<strong>
Explanation: </strong>the tree generated will
have a sturcture like
&nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;&nbsp; &nbsp;  2
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; /&nbsp;&nbsp; 
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;0&nbsp;  &nbsp;  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; /&nbsp;&nbsp; 
&nbsp; &nbsp; &nbsp; &nbsp;  1   &nbsp; </span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything.&nbsp;The task is to complete the function <strong>createTree()&nbsp;</strong>which takes 2 arguments&nbsp;<strong>parent[]</strong>&nbsp;and <strong>N</strong>&nbsp;and returns the root node of the constructed tree.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>3</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;