<h2><a href="https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&company=Microsoft&sortBy=submissions">Parenthesis Checker</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an expression string <strong>x</strong>. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.<br>For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).</span></p>
<p><strong><span style="font-size: 18px;">Note: </span></strong><span style="font-size: 18px;">The drive code prints "balanced" if function return true, otherwise it prints "not balanced".</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
{([])}
<strong>Output</strong>: 
true
<strong>Explanation</strong>: 
<span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff322b;" data-darkreader-inline-color="">{</span> <span style="color: rgb(0, 255, 0); --darkreader-inline-color: #50ff3e;" data-darkreader-inline-color="">(</span> <span style="color: rgb(0, 0, 205); --darkreader-inline-color: #7cafff;" data-darkreader-inline-color="">[</span> <span style="color: rgb(0, 0, 205); --darkreader-inline-color: #7cafff;" data-darkreader-inline-color="">]</span> <span style="color: rgb(0, 255, 0); --darkreader-inline-color: #50ff3e;" data-darkreader-inline-color="">)</span> <span style="color: rgb(255, 0, 0); --darkreader-inline-color: #ff322b;" data-darkreader-inline-color="">}.&nbsp;</span>Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
()
<strong>Output</strong>: 
true
<strong>Explanation</strong>: 
<span style="color: rgb(0, 255, 0); --darkreader-inline-color: #50ff3e;" data-darkreader-inline-color="">()</span><span style="color: rgb(0, 0, 0); --darkreader-inline-color: #ffffff;" data-darkreader-inline-color="">. </span>Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 3:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
([]
<strong>Output</strong>: 
false
<strong>Explanation</strong>: 
<span style="color: rgb(0, 255, 0); --darkreader-inline-color: #50ff3e;" data-darkreader-inline-color="">(</span><span style="color: rgb(0, 0, 205); --darkreader-inline-color: #7cafff;" data-darkreader-inline-color="">[]</span>.<span style="color: rgb(0, 0, 0); --darkreader-inline-color: #ffffff;" data-darkreader-inline-color=""> </span>Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>This is a <strong>function </strong>problem. You only need to complete the function <strong>ispar()&nbsp;</strong>that takes a&nbsp;<strong>string </strong>as a&nbsp;<strong>parameter </strong>and returns a boolean value&nbsp;<strong>true </strong>if <strong>brackets </strong>are <strong>balanced </strong>else <strong>returns false</strong>. The <strong>printing </strong>is done <strong>automatically </strong>by the <strong>driver code</strong>.</span><br><br><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>: O(|x|)<br><strong>Expected Auixilliary Space</strong>: O(|x|)</span><br><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |x| ≤ </span><span style="font-size: 18px;">32000</span></p>
<p>&nbsp;</p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>Oracle</code>&nbsp;<code>Walmart</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<code>Yatra.com</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Stack</code>&nbsp;<code>STL</code>&nbsp;<code>Data Structures</code>&nbsp;