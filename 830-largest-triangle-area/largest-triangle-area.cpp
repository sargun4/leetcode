class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double maxarea=0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double x1=points[i][0];
                    double y1=points[i][1];

                    double x2=points[j][0];
                    double y2=points[j][1];

                    double x3=points[k][0];
                    double y3=points[k][1];

                    double a=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
                    double b=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
                    double c=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
                    double s=0.5*(a+b+c);

                    double heron=sqrt(s*(s-a)*(s-b)*(s-c));
                    maxarea=max(maxarea,heron);
                }
            }
        }
        return maxarea;
    }
};