class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;          // bottles already drunk (we drink all initially)
        int emptyBottles = numBottles; // empties obtained after drinking them

        // Do one exchange at a time for the current numExchange, then increase numExchange.
        while (emptyBottles >= numExchange) {
            // perform a single exchange
            emptyBottles = emptyBottles - numExchange + 1; // consume numExchange empties, get 1 full and drink it
            ans += 1;                                      // one more bottle drunk
            numExchange++;                                 // increase exchange requirement
        }

        return ans;
    }
};
