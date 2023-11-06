/*
https://leetcode.com/problems/seat-reservation-manager/description/?envType=daily-question&envId=2023-11-06
*/


class SeatManager {
public:
    SeatManager(int n) {
        m_marker = 1;
    }
    
    int reserve() {
        if (not m_seats.empty()) {
            int seat = m_seats.top();
            m_seats.pop();
            return seat;
        }
        return m_marker++;
        
    }
    
    void unreserve(int seatNumber) {
        m_seats.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> m_seats;
    int m_marker;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
