<h2><a href="https://practice.geeksforgeeks.org/problems/number-of-root-to-leaf-paths/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Number of root to leaf paths</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
      3
    /   \
   2     4</strong></span>
<strong><span style="font-size:18px">Output:</span></strong>
<span style="font-size:18px">2 2 $</span>

<span style="font-size:18px"><strong>Explanation :</strong>
There are 2 roots to leaf paths
of length 2(3 -&gt; 2 and 3 -&gt; 4)</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:</span></strong>
     <span style="font-size:18px">   10
     /   \
    20    30
   / \    
  40  60</span>

<strong><span style="font-size:18px">Output:</span></strong>
<span style="font-size:18px">2 1 $3 2 $</span>

<span style="font-size:18px"><strong>Explanation:</strong>
There is 1 root leaf paths of
length 2 and 2 roots to leaf paths
of length 3.</span></pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong></p>

<p><span style="font-size:18px">Your task is to complete the function pathCounts that prints the path length and the number of root to leaf paths of this length separated by space.&nbsp; Every path length and number of root to leaf path should be separated by&nbsp; "$".</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 30<br>
1 &lt;= Number of nodes &lt;= 100<br>
1 &lt;= Data of a node &lt;= 1000</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;