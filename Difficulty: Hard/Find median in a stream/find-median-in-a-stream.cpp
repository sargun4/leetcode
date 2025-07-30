// Max-Heap (left): Stores the lower half of the elements
// Min-Heap (right): Stores the upper half of the elements
// Insertion: For each new element, add it to the max-heap
// Transfer: Move the maximum element from the max-heap to the min-heap
// Balance Heaps: Ensure the max-heap either has the same number of
// elements as the min-heap or one more. If the max-heap has
// fewer elements, move the minimum element from the min-heap to the max-heap.
// Compute Median: The median is either the top of the max-heap
// (if it has more elements) or the average of the tops of both heaps 
// (if they are of equal size)
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> smallValue;//max-heap
        priority_queue<int, vector<int>, greater<int>> largeValue;//min-heap
        vector<double> ans;
        for(int it:arr){
            //Step 1: Add number to one of the heaps
            if(smallValue.empty() || it <= smallValue.top()) {
                smallValue.push(it);
            } else{
                largeValue.push(it);
            }
            // Step 2: Balance the heaps(sizes must not differ by more than 1)
            if (smallValue.size()>largeValue.size() + 1) {
                largeValue.push(smallValue.top());
                smallValue.pop();
            } else if (largeValue.size()>smallValue.size()) {
                smallValue.push(largeValue.top());
                largeValue.pop();
            }
            //Step 3: Get the median
            if(smallValue.size()==largeValue.size()) {
                ans.push_back((smallValue.top() + largeValue.top()) / 2.0);
            } else {
                ans.push_back(smallValue.top());
            }
        }
        return ans;
    }
};