<h2><a href="https://www.geeksforgeeks.org/problems/edit-distance3702/1?page=1&category=Dynamic%20Programming&sortBy=submissions">Edit Distance</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two strings <strong>s</strong>&nbsp;and <strong>t. </strong>Return the minimum number of operations required to convert <strong>s&nbsp;</strong>to <strong>t</strong>.<br>
The possible operations are permitted:</span></p>

<ol>
	<li><span style="font-size:18px">Insert a character at any position of the string.</span></li>
	<li><span style="font-size:18px">Remove any character from the string.</span></li>
	<li><span style="font-size:18px">Replace any character from the string with any other character.</span></li>
</ol>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
s = "geek", t = "gesek"
<strong>Output:</strong>&nbsp;1
<strong>Explanation: </strong>One operation is required 
inserting 's' between two 'e's of s.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input : </strong>
s = "gfg", t = "gfg"
<strong>Output: </strong>
0
<strong>Explanation: </strong>Both strings are same.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or&nbsp;print anything. Your task is to complete the function <strong>editDistance()&nbsp;</strong>which takes strings s and t as input parameters and returns the minimum number of operation to convert the string&nbsp;<strong>s</strong>&nbsp;to&nbsp;string<strong>&nbsp;</strong><strong>t</strong>.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(|s|*|t|)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(|s|*|t|)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Length of both strings ≤ 100<br>
Both&nbsp;the strings are in&nbsp;lowercase.</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;