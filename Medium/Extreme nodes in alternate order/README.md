<h2><a href="https://www.geeksforgeeks.org/problems/extreme-nodes-in-alternate-order/1?page=6&category=Tree&sortBy=difficulty">Extreme nodes in alternate order</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree, print nodes of extreme corners of each level but in alternate order.</span></p>

<p><span style="font-size:18px">Example:<br>
<img alt="" src="https://contribute.geeksforgeeks.org/wp-content/uploads/extremeNode.png" style="height:302px; width:600px"></span></p>

<p><span style="font-size:18px">For the above tree, the output is</span></p>

<p><span style="font-size:18px"><strong>1 2 7 8 31</strong><br>
– print rightmost node of 1st level<br>
– print leftmost node of 2nd level<br>
– print rightmost node of 3rd level<br>
– print leftmost node of 4th level<br>
– print rightmost node of 5th level</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
&nbsp;      </strong>1
&nbsp;    /  \
&nbsp;   2    3<strong>
Output: </strong>1 2
<strong>Explanation: </strong>This represents a tree
with 3 nodes and 2 edges where root
is 1, left child of 1 is 3 and
right child of 1 is 2.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't have to take any input. Just complete the&nbsp;function<strong>&nbsp;ExtremeNodes()&nbsp;</strong>that takes root&nbsp;<strong>node&nbsp;</strong>as&nbsp;<strong>paramter&nbsp;&nbsp;</strong>and return the answer (as vector in&nbsp;<strong>cpp,&nbsp;</strong>as ArrayList in&nbsp;<strong>Java,&nbsp;</strong>as list in python)<br>
<br>
<strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ Number of nodes ≤ 100<br>
1 ≤ Data of a node ≤ 1000</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;