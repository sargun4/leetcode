/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/
 
void SortedStack ::sort() {
    vector<int> arr;
    while(!s.empty()){
        arr.push_back(s.top());
        s.pop();
    }
    std::sort(arr.rbegin(),arr.rend());//desc order
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        s.push(arr[i]);
    }
}