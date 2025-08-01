<h2><a href="https://www.geeksforgeeks.org/problems/burst-balloons/1">Burst Balloons</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p>You are given <strong>N</strong>&nbsp;balloons, indexed from <strong>0</strong> to <strong>n - 1</strong>. Each balloon is painted with a number on it represented by an array <strong>arr.</strong> You are asked to burst all the balloons.<br>
If you burst the <strong>i</strong><strong>th&nbsp;</strong>balloon, you will get <strong>arr[ i - 1 ] * arr[ i ] * arr[ i + 1]</strong> coins. If <strong>i - 1</strong>, or<strong> i + 1</strong> goes out of the bounds of the array, consider it as if there is a balloon with a <strong>1</strong> painted on it.<br>
Return the <strong>maximum</strong> coins you can collect by bursting the balloons wisely.</p>

<p><strong>Example 1:</strong></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #262726; --darkreader-inline-border-top: #4c4f4c; --darkreader-inline-border-right: #4c4f4c; --darkreader-inline-border-bottom: #4c4f4c; --darkreader-inline-border-left: #4c4f4c;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><strong>Input:</strong><br>
N = 4<br>
arr[ ] = {3, 1, 5, 8}<br>
<strong>Output: </strong>167<br>
<strong>Explanation:</strong>&nbsp;<br>
arr[ ] = {3, 1, 5, 8}&nbsp; - - &gt; {3, 5, 8} - - &gt; {3, 8} - - &gt; { 8} - -&gt; { }<br>
coins = 3 *1 *5,&nbsp; &nbsp; &nbsp; +&nbsp; &nbsp; &nbsp; 3*5*8&nbsp; &nbsp; &nbsp;+&nbsp; &nbsp;1*3*8&nbsp; &nbsp;+&nbsp; 1*8*1&nbsp; &nbsp;= 167<br>
&nbsp;</div>

<p>&nbsp;</p>

<p><strong>Example 2:</strong></p>

<div style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #262726; --darkreader-inline-border-top: #4c4f4c; --darkreader-inline-border-right: #4c4f4c; --darkreader-inline-border-bottom: #4c4f4c; --darkreader-inline-border-left: #4c4f4c;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="" data-darkreader-inline-border-top="" data-darkreader-inline-border-right="" data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left=""><strong>Input:</strong><br>
N = 2<br>
arr[ ] = {1, 10}<br>
<strong>Output:&nbsp;</strong>20</div>

<p>&nbsp;</p>

<p><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>maxCoins()</strong>&nbsp;which takes the&nbsp;array of&nbsp;integers&nbsp;<strong>arr </strong>and <strong>N&nbsp;</strong>as parameters and returns the maximum coin you can collect.</p>

<p><strong>Expected Time Complexity:</strong>&nbsp;O(N*N*N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*N)</p>

<p><strong>Constraints:</strong><br>
1 ≤ N ≤ 300<br>
0&nbsp;≤ arr [ i ]&nbsp; ≤ 100</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;