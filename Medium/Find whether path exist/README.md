<h2><a href="https://www.geeksforgeeks.org/problems/find-whether-path-exist5238/1">Find whether path exist</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a grid of size n*n&nbsp;filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination.&nbsp;You can traverse up, down, right and left.<br>The description of cells is as follows:</span></p>
<ul>
<li><span style="font-size: 18px;">A value of cell&nbsp;<strong>1</strong>&nbsp;means Source.</span></li>
<li><span style="font-size: 18px;">A value of cell&nbsp;<strong>2</strong>&nbsp;means Destination.</span></li>
<li><span style="font-size: 18px;">A value of cell&nbsp;<strong>3</strong>&nbsp;means Blank cell.</span></li>
<li><span style="font-size: 18px;">A value of cell <strong>0&nbsp;</strong>means&nbsp;Wall.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Note</strong>: There are only a single source and a single destination.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
<strong>Output: </strong>0
<strong>Explanation: </strong>The grid is-
3 0 3 0 0&nbsp;
3 0 0 0 3&nbsp;
3 3 3 3 3&nbsp;
0 2 3 0 0&nbsp;
3 0 0 1 3&nbsp;
There is no path to reach at (3,1) i,e at 
destination from (4,3) i,e source.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{1,3},{3,2}}
<strong>Output: </strong>1
<strong>Explanation: </strong>The grid is-
<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff322b;" data-darkreader-inline-color="">1 3
</span>3<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff322b;" data-darkreader-inline-color=""> 2
</span>There is a path from (0,0) i,e source to (1,1) 
i,e destination.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function <strong>is_Possible()&nbsp;</strong>which takes the grid as input parameter and returns boolean value <strong>1</strong> if there is a path otherwise returns <strong>0</strong>.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n<sup>2</sup>)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(n<sup>2</sup>)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 500</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;