<h2><a href="https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab">Print all LCS sequences</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">You are given two strings <strong>s</strong>&nbsp;and <strong>t</strong>. Now your task is to print all longest common sub-sequences in lexicographical order.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = abaaa, t = baabaca
<strong>Output: </strong>aaaa abaa baaa</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = aaa, t = a
<strong>Output: </strong>a</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read or print anything. Your task is to complete the function&nbsp;<strong>all_longest_common_subsequences()</strong>&nbsp;which takes string a and b as first and second parameter respectively and returns a list of strings which contains all possible longest common subsequences in lexicographical order.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(n<sup>4</sup>)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(K * n) where K is a constant less than n.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Length of both strings ≤ 50</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Backtracking</code>&nbsp;<code>Algorithms</code>&nbsp;