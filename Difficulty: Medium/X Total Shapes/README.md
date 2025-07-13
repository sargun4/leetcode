<h2><a href="https://www.geeksforgeeks.org/problems/x-total-shapes3617/1?page=3&category=Graph&sortBy=submissions">X Total Shapes</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given&nbsp; a grid of <strong>n</strong>*<strong>m</strong>&nbsp;consisting<strong>&nbsp;</strong>of <strong>O<code>'s</code></strong>&nbsp;and <strong>X<code>'s</code></strong>. The task is to find the number of '<strong>X</strong>' total shapes.<br><strong>Note:&nbsp;</strong>'<strong>X</strong>' shape consists of one or more adjacent <strong>X</strong><code>'s</code>&nbsp;(diagonals not included).</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{X,O,X},{O,X,O},{X,X,X}}
<strong>Output: </strong>3
<strong>Explanation: 
</strong>The grid is-
<span style="color: rgb(238, 130, 238); --darkreader-inline-color: var(--darkreader-text-ee82ee, #ffa7ff);" data-darkreader-inline-color=""><strong>X</strong></span> O <span style="color: rgb(255, 140, 0); --darkreader-inline-color: var(--darkreader-text-ff8c00, #ffbf40);" data-darkreader-inline-color=""><strong>X</strong></span>
O <span style="color: rgb(0, 255, 0); --darkreader-inline-color: var(--darkreader-text-00ff00, #50ff3e);" data-darkreader-inline-color=""><strong>X</strong></span> O
<strong><span style="color: rgb(0, 255, 0); --darkreader-inline-color: var(--darkreader-text-00ff00, #50ff3e);" data-darkreader-inline-color="">X</span> <span style="color: rgb(0, 255, 0); --darkreader-inline-color: var(--darkreader-text-00ff00, #50ff3e);" data-darkreader-inline-color="">X</span> <span style="color: rgb(0, 255, 0); --darkreader-inline-color: var(--darkreader-text-00ff00, #50ff3e);" data-darkreader-inline-color="">X</span>
</strong>So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.</span>

</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>grid = {{X,X},{X,X}}
<strong>Output: </strong>1
<strong>Expanation: 
</strong>The grid is- 
<span style="color: rgb(238, 130, 238); --darkreader-inline-color: var(--darkreader-text-ee82ee, #ffa7ff);" data-darkreader-inline-color=""><strong>X</strong></span> <span style="color: rgb(238, 130, 238); --darkreader-inline-color: var(--darkreader-text-ee82ee, #ffa7ff);" data-darkreader-inline-color=""><strong>X</strong></span>
<strong><span style="color: rgb(238, 130, 238); --darkreader-inline-color: var(--darkreader-text-ee82ee, #ffa7ff);" data-darkreader-inline-color="">X</span> <span style="color: rgb(238, 130, 238); --darkreader-inline-color: var(--darkreader-text-ee82ee, #ffa7ff);" data-darkreader-inline-color="">X</span></strong>
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anything. Your task is to complete the function <strong>xShape()&nbsp;</strong>which takes grid as input parameter and returns the count of total X shapes.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Compelxity:&nbsp;</strong>O(n*m)<br><strong>Expected Space Compelxity:&nbsp;</strong>O(n*m)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m&nbsp;≤ 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;