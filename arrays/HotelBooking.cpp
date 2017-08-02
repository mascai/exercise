/*


A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.

Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 


*/
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector<pair<int, int>>v; // pair<come_date, in/out_flag>
    for (int i = 0; i < arrive.size(); i++){
        v.push_back(make_pair(arrive[i], 1));
        v.push_back(make_pair(depart[i], 0));
    }
    sort(begin(v), end(v));
    int currActive = 0, maxVal = 0;
    for (int i = 0; i < v.size(); i++){
        if (v[i].second == 1){
            currActive++;
            maxVal = max(maxVal, currActive);
        } else {
            currActive--;
        }
        if (maxVal > k){
            return false;
        }
    }
    return true;
}
