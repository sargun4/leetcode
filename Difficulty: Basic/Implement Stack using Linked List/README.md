<h2><a href="https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?page=7&company=Microsoft&sortBy=submissions">Implement Stack using Linked List</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Let's give it a try!&nbsp;You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list.&nbsp;Your task is to use the class as shown in the comments in the code editor&nbsp;and complete&nbsp;the functions push() and pop() to implement a stack.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Example 1</strong>:</span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: 
push(2)
push(3)
pop()
push(4) 
pop()
<strong>Output</strong>: 3 4
<strong>Explanation</strong>: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
&nbsp;          the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: 
pop()
push(4)
push(5)
pop()
<strong>Output</strong>: -1 5</span></pre>

<p><strong><span style="font-size:18px">Your Task:&nbsp;</span></strong><span style="font-size:18px">You are required to complete two methods&nbsp;<strong>push() and pop(). </strong>The push() method&nbsp;takes one argument, an integer <strong>'x'</strong>&nbsp;to be pushed into the stack and&nbsp;<strong>pop()</strong>&nbsp;which returns an integer present at the top and popped out from the stack. If the stack is empty then return <strong>-1</strong> from the pop() method.</span><br>
<br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for both&nbsp;<strong>push()&nbsp;</strong>and&nbsp;<strong>pop()</strong>.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for both&nbsp;<strong>push()&nbsp;</strong>and&nbsp;<strong>pop()</strong>.</span><br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= Q &lt;= 100<br>
1 &lt;= x &lt;= 100</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>FactSet</code>&nbsp;<code>SAP Labs</code>&nbsp;<code>Codenation</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Stack</code>&nbsp;<code>Data Structures</code>&nbsp;