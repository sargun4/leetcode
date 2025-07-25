<h2><a href="https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Minimum Cost Path</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a square <strong>grid </strong>of size <strong>N</strong>, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.<br>From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Note:&nbsp;</strong>It is assumed that negative cost cycles do not exist in the input matrix.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
<strong>Output: </strong>43
<strong>Explanation: </strong>The grid is-
<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">9 4 </span>9 9
6 <span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">7 </span>6 4
8 <span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">3 3 7</span>
7 4 9 <span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">10</span>
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{4,4},{3,7}}
<strong>Output: </strong>14
<strong>Explanation: </strong>The grid is-
<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">4 </span>4
<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff2423;" data-darkreader-inline-color="">3 7
</span>The minimum cost is- 4 + 3 + 7 = 14.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>minimumCostPath()&nbsp;</strong>which takes grid as input parameter and returns the minimum cost to react at bottom right&nbsp;cell&nbsp;from top left cell.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Compelxity:&nbsp;</strong>O(n<sup>2</sup>*log(n))<br><strong>Expected Auxiliary Space: </strong>O(n<sup>2</sup>)&nbsp;</span><br>&nbsp;</p>
<p><strong><span style="font-size: 18px;">Constraints:</span></strong><br><span style="font-size: 18px;">1 ≤ n ≤ 500<br>1 ≤ cost of cells ≤ 1000</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Greedy</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;