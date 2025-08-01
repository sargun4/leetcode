<h2><a href="https://www.geeksforgeeks.org/problems/knight-walk4521/1?page=1&category=BFS&sortBy=submissions">Knight Walk</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong><br>The initial and the target position co-ordinates of&nbsp;Knight have been given accoring to 1-base indexing.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
<strong>Output:</strong>
3
<strong>Explanation:</strong>
<img src="https://media.geeksforgeeks.org/wp-content/uploads/KnightChess.jpg">
Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -&gt; (5, 3) -&gt; (3, 2) -&gt; (1, 1). </span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
<strong>Output:</strong>
4
<strong>Explanation:</strong></span>
<span style="font-size: 18px;">Knight takes 4 steps to reach from
(7, 7) to (1, 5):
(4, 5) -&gt; (6, 5) -&gt; (5, 3) -&gt; (7, 2) -&gt; (1, 5).</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>minStepToReachTarget()</strong>&nbsp;which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters&nbsp;and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N<sup>2</sup>).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N<sup>2</sup>).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 1000<br>1 &lt;= Knight_pos(X, Y), Targer_pos(X, Y)&nbsp;&lt;= N</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;