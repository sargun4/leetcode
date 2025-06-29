<h2><a href="https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Root to Leaf Paths</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a Binary Tree of size N, you need to find&nbsp;all the possible paths&nbsp;from root node to all the leaf&nbsp;node's of the binary tree.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
       1
    /     \
   2       3
<strong>Output: </strong>1 2&nbsp;#1 3&nbsp;#
<strong>Explanation: </strong>
All possible paths:
1-&gt;2
1-&gt;3
</span>
</pre>

<p dir="ltr"><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:
&nbsp;        </strong>10
&nbsp;      /    \
&nbsp;     20    30
&nbsp;    /  \
&nbsp;   40   60<strong>
Output: </strong>10 20 40 #10 20 60 #10 30 #
</span>
</pre>

<p dir="ltr"><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete the function&nbsp;<strong>Paths()</strong>&nbsp;that takes the root node as an argument and return all the possible path. (All the path are printed '#' separated by the driver's code.)</span></p>

<p dir="ltr"><strong><span style="font-size:18px">Note:&nbsp;</span></strong><span style="font-size:18px">The return type<br>
<strong>cpp:&nbsp;</strong>vector<br>
<strong>java:&nbsp;</strong>ArrayList&gt;<br>
<strong>python:&nbsp;</strong>list of list</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(H).</span><br>
<span style="font-size:18px"><strong>Note:&nbsp;</strong>H is the height of the tree.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=10<sup>3</sup></span>.</p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;