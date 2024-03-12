<h2><a href="https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1?page=6&category=Tree,DFS,BFS&sortBy=submissions">Check if two Nodes are Cousins</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given the binary Tree of and&nbsp;two-node values. Check&nbsp;whether the two-node values&nbsp;are cousins of each other or not.<br><br></span><span style="font-size: 18px;"><strong>Note:</strong> Two nodes of a binary tree are&nbsp;<strong>cousins</strong> if they have the same depth with different parents.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:
&nbsp;     </strong><span style="font-size: 18px;">1
&nbsp;   /   \
</span><strong style="font-size: 18px;">   </strong><span style="font-size: 18px;">2     3
a = 2, b = 3</span><strong style="font-size: 18px;">
Output: </strong><span style="font-size: 18px;">false<br><strong>Explanation</strong>: Here, nodes 2 and 3 are
at the same level but have same
parent nodes.<br></span></span></pre>
<pre>&nbsp;</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp;1
&nbsp; &nbsp; &nbsp;/&nbsp;  \&nbsp;
&nbsp;  &nbsp;2&nbsp; &nbsp;  3
&nbsp;  /&nbsp; &nbsp; &nbsp;&nbsp;&nbsp;\
<strong>  </strong>5&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;4<strong>&nbsp;
</strong>a = 5, b = 4<strong>
Output: </strong>True<strong>
Explanation: </strong>Here, nodes 5 and 4 are
at the same level and have different
parent nodes. Hence, they both are cousins&nbsp;</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size: 18px;"><strong> isCousins() </strong>that takes the root node<strong>&nbsp;</strong>of the tree (having all nodes distinct)<strong>, </strong>and two integers 'a' and 'b' as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(Number of Nodes).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(Number of Nodes).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= Number of Nodes &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;