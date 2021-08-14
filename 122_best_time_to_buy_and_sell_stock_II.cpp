#include <algorithm>
#include <iostream>
#include <vector>
    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profits = 0;
        //Check to make sure enough prices to buy AND sell
        if(prices.size() < 2){
            return profits;
        }
        //Check to see if price is larger second day otherwise profit is 0
        else if(prices.size() == 2){
            if(prices[0] < prices[1]){
                profits += prices[1] - prices[0];
            }
            return profits;
        }
        else{
            //Get first smallest element in prices (This is how we will find our buying prices)
            vector<int>::iterator buy_price = min_element(prices.begin(),prices.end());
            vector<int>::iterator sell_price = buy_price;
            //Check for the closes maxima (This is how we will find our selling prices)
            for(vector<int>::iterator ptr = buy_price+1; ptr < prices.end(); ptr++){
                //If the price is larger or equal to previous days then set new sell price
                if(*ptr >= *sell_price){
                    sell_price = ptr;
                }
                //otherwise losing value so break out of loop for profits
                else{
                    break;
                }
            }
            //Get subvector of prices before the buy_price iterator
            vector<int> front_vector(prices.begin(),buy_price);
            //Get subvector of prices after the sell_price itereator
            vector<int> back_vector(sell_price+1,prices.end());
            //Calculate profits and call maxProfit recursively on subvectors from prices
            profits += *sell_price - *buy_price + maxProfit(front_vector) + maxProfit(back_vector);
        }
        return profits;
    }
    
};