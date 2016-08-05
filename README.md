# Suffix-Trees

**suffix_tree.cpp**
An easy way to build suffix trees for the input string.  To show that the suffix tree is built in a correct way, the strings that label the edges of the suffix trees are printed out. This code file can work well with long strings. And the string itself can contain any symbol except for one special symbol used to mark the end of the string like '$'.

* Input: A string Text ending with a “$” symbol.

* output: The strings labeling the edges of SuffixTree(Text) in any order.

###Example:

####Input:
```
A$
```
####Output:
```
A$
$
```

**non_shared_substring.cpp**
This is an application of suffix tree to find the shortest substring of one string that does not appear in another string.
* Input: Strings Text1 and Text2.
* Output: The shortest (non-empty) substring of Text1 that does not appear in Text2.

###Example:

####Input:
```
CCAAGCTGCTAGAGG
CATGCTGGGCTGGCT
```
####Output:
```
AA
```
