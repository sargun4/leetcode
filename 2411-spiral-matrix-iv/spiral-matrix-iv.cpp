class Solution {
	public:
		vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
			vector<vector<int>> mat(m,vector<int>(n,-1));
			ListNode* curr=head;
			int top=0;
			int left=0;
			int bottom=m-1;
			int right=n-1;
			while(curr!=NULL){
				for(int j=left;j<=right && curr!=NULL;j++){
					int i=top;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				top++;
				for(int i=top;i<=bottom && curr!=NULL;i++){
					int j=right;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				right--;
				for(int j=right;j>=left && curr!=NULL;j--){
					int i=bottom;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				bottom--;
				for(int i=bottom;i>=top && curr!=NULL;i--){
					int j=left;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				left++;
			}
			return mat;
		}
	};