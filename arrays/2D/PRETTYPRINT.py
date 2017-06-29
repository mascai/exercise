/*


Print concentric rectangular pattern in a 2d matrix.
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 

Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 

The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.

*/

class Solution:
    # @param A : integer
    # @return a list of list of integers
 
    def prettyPrint(self, A):
        size = 2*A -1
        array = [[0 for x in xrange(size)] for y in xrange(size)]
        for i in xrange(0,size):
            for j in xrange(i, size-i):
                array[i][j] = A -i
                array[j][i] = A -i
                array[size-1-i][j]=A-i
                array[j][size-1-i]=A -i 
        return array
