<h2><a href="https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?page=1&company=Goldman%20Sachs&sortBy=submissions">Get minimum element from stack</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given <strong>N</strong> operations and your task is to Implement a Stack in which you can get a minimum element in O(1) time.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>push(2)
push(3)
pop()
getMin()
push(1)
getMin()<strong>
Output: </strong>2 1<strong>
Explanation: </strong>In the first test case for
query&nbsp;
push(2)&nbsp; Insert 2 into the stack.
&nbsp;        The stack&nbsp;will be {2}
push(3)&nbsp; Insert 3 into the stack.
&nbsp;        The stack&nbsp;will be {2 3}
pop()    Remove top element from stack 
&nbsp;        Poped element will be 3&nbsp;the
&nbsp;        stack will be {2}
getMin() Return the minimum element
&nbsp;        min element will be 2&nbsp;
push(1)  Insert 1 into the stack.
         The stack&nbsp;will be {2 1}
getMin() Return the minimum element
&nbsp;        min element will be 1</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You are required to complete the three&nbsp;methods&nbsp;<strong>push()</strong>&nbsp;which takes one argument an integer <strong>'x'</strong>&nbsp;to be pushed into the stack,&nbsp;<strong>pop()</strong>&nbsp;which returns an integer&nbsp;popped out from the stack, and <strong>getMin()</strong> which returns the min element from the stack. (-1 will be returned if for&nbsp;<strong>pop() and getMin()&nbsp;</strong>the stack is empty.)</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity</strong>: O(1) for all the 3 methods.<br><strong>Expected Auxiliary Space</strong>: O(1) for all the 3 methods.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= Number of queries&nbsp;&lt;= 100<br>1 &lt;= values of the stack&nbsp;&lt;= 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>FactSet</code>&nbsp;<code>Walmart</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>SAP Labs</code>&nbsp;<code>Sapient</code>&nbsp;<code>One97</code>&nbsp;<code>GreyOrange</code>&nbsp;<code>Kuliza</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;