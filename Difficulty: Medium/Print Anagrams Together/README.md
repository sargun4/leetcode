<h2><a href="https://www.geeksforgeeks.org/problems/print-anagrams-together/1?page=3&company=Goldman%20Sachs&sortBy=submissions">Print Anagrams Together</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.</span></p>

<p><strong><span style="font-size:18px">Note: The final output will be in&nbsp;lexicographic order.</span></strong></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
words[] = {act,god,cat,dog,tac}
<strong>Output:
</strong>act cat tac<strong> 
</strong>god dog<strong>
Explanation:
</strong>There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
words[] = {no,on,is}
<strong>Output: 
</strong>is
no on<strong>
Explanation:
</strong>There are 2 groups of
anagrams "is" makes group 1.
"no", "on" make group 2.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>Anagrams()</strong> that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*|S|*log|S|), where |S| is the length of the strings.<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*|S|), where |S| is the length of the strings.</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=100</span></p>

<p><span style="font-size:18px">1&lt;=|S|&lt;=10</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;