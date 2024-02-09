<h2><a href="https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Count ways to N'th Stair</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">There are<strong> N</strong> stairs, and a person standing at the bottom wants to reach the top. The person can climb either <strong>1 stair or 2 stairs at a time</strong>. Count the number of ways, the person can reach the top (<strong>order does not matter</strong>).<br><strong>Note:</strong> Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 4
<strong>Output: </strong>3<strong>
Explanation: </strong>You can reach 4th stair in
3 ways.
3 possible ways are:
1, 1, 1, 1
1, 1, 2
2, 2</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 5
<strong>Output: </strong>3
<strong>Explanation</strong>:
You may reach the 5th stair in 3 ways.
The 3 possible ways are:
1, 1, 1, 1, 1
1, 1, 1, 2
1, 2, 2</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>Your task is to complete the function&nbsp;<strong>countWays()&nbsp;</strong>which takes single argument(N) and returns the answer.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>: O(N)<br><strong>Expected Auxiliary Space</strong>: O(N)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;