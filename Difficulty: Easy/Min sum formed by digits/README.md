<h2><a href="https://www.geeksforgeeks.org/problems/min-sum-formed-by-digits3551/1?page=1&category=Heap&sortBy=submissions">Min sum formed by digits</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;">Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of the given array must be used to form the two numbers.</span></span></p>
<p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;">Any combination of digits may be used to form the two numbers to be summed. &nbsp;Leading zeroes are permitted.</span></span></p>
<p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;">If forming two numbers is impossible (i.e. when n==0) then the "sum" is the value of the only number that can be formed.</span></span></p>
<p><br>&nbsp;</p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Example 1:</strong></span></span></p>
<pre><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Input:</strong></span>
<span style="font-family: arial,helvetica,sans-serif;">N = 6</span>
<span style="font-family: arial,helvetica,sans-serif;">arr[] = {6, 8, 4, 5, 2, 3}
</span><strong><span style="font-family: arial,helvetica,sans-serif;">Output:</span></strong>
<span style="font-family: arial,helvetica,sans-serif;">604
</span><strong><span style="font-family: arial,helvetica,sans-serif;">Explanation:</span></strong>
<span style="font-family: arial,helvetica,sans-serif;">The minimum sum is formed by numbers </span>
<span style="font-family: arial,helvetica,sans-serif;">358 and 246</span></span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Example 2:</strong></span></span></p>
<pre><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Input:</strong></span>
<span style="font-family: arial,helvetica,sans-serif;">N = 5</span>
<span style="font-family: arial,helvetica,sans-serif;">arr[] = {5, 3, 0, 7, 4}</span>
<strong><span style="font-family: arial,helvetica,sans-serif;">Output:</span></strong>
<span style="font-family: arial,helvetica,sans-serif;">82</span>
<strong><span style="font-family: arial,helvetica,sans-serif;">Explanation:</span></strong>
<span style="font-family: arial,helvetica,sans-serif;">The minimum sum is formed by numbers </span>
<span style="font-family: arial,helvetica,sans-serif;">35 and 047</span></span>
</pre>
<p><br><br><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Your Task:</strong><br>You <strong>don't</strong> have to print anything, printing is done by the driver code itself. Your task is to complete the function&nbsp;<strong>minSum()</strong>&nbsp;which takes the array <strong>A[]</strong> and its size <strong>N</strong><strong> </strong>as inputs and returns the required sum.</span></span><br><br><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Expected Time Complexity: </strong>O(N. log(N))<br><strong>Expected Auxiliary Space: </strong>O(N)</span></span></p>
<p><br><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Constraints:</strong></span><br><span style="font-family: arial,helvetica,sans-serif;">1 ≤ N ≤ 35<br>0 ≤ A[] ≤ 9</span></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Heap</code>&nbsp;<code>Data Structures</code>&nbsp;