int maxProfit(int* prices, int pricesSize) {

    int highest_seen_so_far = 0;
    int cur_profit = 0;
    int max_profit = 0;
    for(int i=(pricesSize - 1); i >=0; i--) {
        cur_profit = highest_seen_so_far - prices[i];
        if(cur_profit > max_profit) {
            max_profit = cur_profit;
        }
        if(prices[i] > highest_seen_so_far) {
            highest_seen_so_far = prices[i];
        }
    }

    return max_profit;   
}