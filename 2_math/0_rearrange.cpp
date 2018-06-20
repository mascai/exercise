/*
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]

Lets say N = size of the array. Then, following holds true :
All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer

Hint:

Now, we will do a slight trick to encode 2 numbers in one index. 
This trick assumes that N * N does not overflow.

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.
Given a number as

   A = B + C * N   if ( B, C < N )
   A % N = B -- last val
   A / N = C -- answer
*/

void Solution::arrange(vector<int> &Vec) {
    int N = Vec.size();
        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] + (Vec[Vec[i]]%N) * N;
        }

        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] / N;
        }
}
