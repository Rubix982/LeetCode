class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;
        int empties = numBottles;

        while (empties >= numExchange) {
            int new_full = empties / numExchange;
            drank += new_full;
            empties = empties % numExchange + new_full; 
        }

        return drank;        
    }
};