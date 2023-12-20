class Solution {
    public int buyChoco(int[] prices, int money) {
        int minprice=Integer.MAX_VALUE;
        int second_minprice=Integer.MAX_VALUE;
        for(int price:prices){
            if(price<minprice){
                second_minprice=minprice;
                minprice=price;
            }else{
                second_minprice=Math.min(second_minprice,price);
            }
        }
        if(minprice+second_minprice>money){
            return money;
        }
        return money-(minprice+second_minprice);
    }
}