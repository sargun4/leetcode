<h2><a href="https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1?page=1&category=Linked%20List,Binary%20Search%20Tree&status=unsolved&sortBy=accuracy">Delete nodes having greater value on right</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater.&nbsp;</span><span style="font-size: 18px;">(Not just immediate Right , but entire List on the Right)<br><br></span><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>LinkedList = 12-&gt;15-&gt;10-&gt;11-&gt;5-&gt;6-&gt;2-&gt;3
<strong>Output: </strong>15 11 6 3<strong>
Explanation: </strong>Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>LinkedList = 10-&gt;20-&gt;30-&gt;40-&gt;50-&gt;60
<strong>Output: </strong>60<br><strong>Explanation: </strong>All the nodes except the last<br>node has a greater value node on its right,<br>so all the nodes except the last node must<br>be removed.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>The task is to complete the function <strong>compute</strong>() which should modify the list as required and return the head of the modified linked list.&nbsp;<br>The <strong>printing </strong>is done by the <strong>driver </strong>code,</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ size of linked list ≤ 10<sup>5</sup><br>1 ≤ element of linked list ≤ 10<sup>5</sup><br><br><strong>Note: Try to solve the problem without using any extra space.</strong></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Data Structures</code>&nbsp;