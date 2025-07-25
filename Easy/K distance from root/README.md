<h2><a href="https://www.geeksforgeeks.org/problems/k-distance-from-root/1?page=9&category=Tree&sortBy=latest">K distance from root</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Tree of size <strong>n</strong> and an integer, <strong>k</strong>. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more than the height of the tree, nothing should be printed.</span></p>
<p><span style="font-size: 18px;">For example, if below is a given tree and k is 2. Output should be 4 5 6.</span></p>
<p><span style="font-size: 18px;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \<br>&nbsp;&nbsp;&nbsp;&nbsp; 2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3<br>&nbsp;&nbsp; /&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp; \<br>&nbsp; 4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5&nbsp;&nbsp;&nbsp; 6&nbsp;<br>&nbsp;&nbsp;&nbsp;&nbsp; \<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>k = 0
&nbsp;     1
&nbsp;   /   \
&nbsp;  3     2<strong>
Output: </strong>1<br><strong>Explanation: </strong>1 is the only node which is 0 distance from the root 1.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>k = 3
&nbsp;       3
&nbsp;      /
&nbsp;     2
&nbsp;      \
&nbsp;       1
&nbsp;     /  \
&nbsp;    5    3<strong>
Output: </strong>5 3<br></span><strong style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation:  </strong><span style="font-size: 18px; font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">5 and 3 are the nodes which is 3 distance from the root 3.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't have to take input. Complete the function&nbsp;<strong>Kdistance()&nbsp;</strong>that accepts&nbsp;<strong>root</strong> node<strong>&nbsp;</strong>and&nbsp;<strong>k&nbsp;</strong>as parameters and <strong>returns </strong>the&nbsp;<strong>value&nbsp;</strong>of the&nbsp;<strong>nodes&nbsp;</strong>that are at a distance k from the root. (The values are returned as a vector in <strong>cpp,&nbsp;</strong>as ArrayList in&nbsp;<strong>Java, </strong>and as list in Python)</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the Tree).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 10<sup>4</sup></span><br><span style="font-size: 18px;">0 &lt;= k &lt;= 30</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Ola Cabs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;