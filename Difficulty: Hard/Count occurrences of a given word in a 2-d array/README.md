<h2><a href="https://www.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1?page=7&company=Paytm,Morgan%20Stanley&sortBy=submissions">Count occurrences of a given word in a 2-d array</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Find the number of occurrences of a given search word in a 2d-Array of characters where the word can go up, down, left, right, and around 90-degree bends.<br>
<strong>Note:</strong>&nbsp;While making a word you can use one cell only once.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>R = 4, C = 5
mat = {{S,N,B,S,N},
       {B,A,K,E,A},
&nbsp;      {B,K,B,B,K},
       {S,E,B,S,E}}
target = SNAKES
<strong>Output:</strong>
3
<strong>Explanation</strong>: 
<span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">S</span> <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">N</span> B <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">S N</span>
B <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">A K E</span> <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">A</span>
B <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">K</span> B B <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">K</span>
<span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">S E</span> B <span style="color: rgb(128, 0, 128); --darkreader-inline-color: var(--darkreader-text-800080, #ffa0ff);" data-darkreader-inline-color="">S E</span>
Total occurrence of the word is 3
and denoted by color.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
R = 3, C = 3 
mat = {{c,a,t},
&nbsp;      {a,t,c},
&nbsp;      {c,t,a}}
target = cat
<strong>Output:</strong>
5
<strong>Explanation</strong>: Same explanation
as first example.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findOccurrence()</strong>&nbsp;which takes the mat&nbsp;containing N*M 2-d array of characters&nbsp;and target as input parameters and returns the number of occurrences of the target.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(R*C*2<sup>2*len</sup>), Where len is the length of the target String.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ len&nbsp;≤ 15<br>
1 ≤ R, C&nbsp;≤ 50</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;