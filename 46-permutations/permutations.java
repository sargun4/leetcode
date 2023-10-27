class Solution {
    public void helper(int[] nums,List<Integer> ds,boolean[] isvalid,List<List<Integer>> ans){
        if(ds.size()==nums.length){
            List<Integer> list=new ArrayList<>();
            for(int i=0;i<ds.size();i++){
                list.add(ds.get(i));
            }
            ans.add(list);
            return;
        }for(int i=0;i<nums.length;i++){
            if(isvalid[i]==false){
                ds.add(nums[i]);
                isvalid[i]=true;
                helper(nums,ds,isvalid,ans);
                //backtracking
                isvalid[i]=false;
                ds.remove(ds.size()-1);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();    
        List<Integer> ds=new ArrayList<>();
        boolean[] isvalid=new boolean[nums.length]; //false
        helper(nums,ds,isvalid,ans);
        return ans;
    }
}