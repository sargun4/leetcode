<h2><a href="https://www.geeksforgeeks.org/problems/leaves-to-dll/1">Leaves to DLL</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.</span><br>
<br>
<span style="font-size:18px"><strong>Note:&nbsp;</strong>The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    </span>

<span style="font-size:18px"><strong>Output: </strong>
Modified Tree :
        1
      /   \
     2     3</span>

<span style="font-size:18px">Doubly Link List :
4 &lt;-&gt; 5 &lt;-&gt; 6 &lt;-&gt; 7</span>

<span style="font-size:18px"><strong>Explanation:</strong>
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
        1
      /   \
     2     3
    / \   
   4   5 </span>

<span style="font-size:18px"><strong>Output: </strong>
Modified Tree :
        1
      /   
     2    </span>

<span style="font-size:18px">Doubly Link List :
4 &lt;-&gt; 5 &lt;-&gt; 3</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>convertToDLL()</strong> which takes the root of the given tree as input parameter and returns the head of the doubly link list.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(height of tree)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10^4</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Linkedin</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;