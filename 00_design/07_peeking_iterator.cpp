/*
https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3633/

Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Example:

Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2. 
You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?

*/


/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */


class PeekingIterator : public Iterator {
public:
    int nextVal;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        nextVal = Iterator::hasNext() ? Iterator::next() : NULL;
    }

    int peek() {
        return nextVal;
    }

    int next() {
        int oldNext = nextVal;
        nextVal = Iterator::hasNext() ? Iterator::next() : NULL;
        return oldNext; 
    }

    bool hasNext() const {
        return (nextVal != NULL);
    }
};
