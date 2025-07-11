<h2><a href="https://practice.geeksforgeeks.org/problems/probability-of-knight5529/1">Probability of Knight</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an NxN chessboard and a Knight at position (x, y). The Knight has to take exactly K steps, where at each step it chooses any of the 8 directions uniformly at random. Find&nbsp;the probability that the Knight remains in the chessboard after taking K steps, with the condition that it cant enter the board again once it leaves it.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>N = 8, x = 0, y = 0, K = 3
<strong>Output: </strong>0.125000</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 4, x = 1, y = 2, k = 4
<strong>Output: </strong>0.024414</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;</strong><br>
You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>findProb()&nbsp;</strong>which takes N, x, y and K as input parameter and returns the probability.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity :&nbsp;</strong>O(N <sup>3</sup>)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(N<sup>3</sup>)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 100<br>
0 &lt;= x, y &lt;= N</span></p>

<p><span style="font-size:18px">0 &lt;= K &lt;= N</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Directi</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;