/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
// //dfs
// class Solution {
// public:
//     //rec to calc total imp of a given employee
//     int dfs(int id, unordered_map<int, Employee*>& empMap) {
//         Employee* emp=empMap[id];
//         int imp=emp->importance;//own val
//         for (int subempId:emp->subordinates){//visit all its subords(subtree)
//             imp+=dfs(subempId,empMap); //add imp of subordinates
//         }
//         return imp;
//     }
//     int getImportance(vector<Employee*> employees, int id) {
//         unordered_map<int, Employee*> empMap;//{id:emp}
//         for(Employee* emp:employees){
//             empMap[emp->id] = emp;
//         }
//         return dfs(id,empMap);
//     }
// };
//bfs
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> empMap; //{id:emp}
        for (Employee* emp:employees){
            empMap[emp->id]=emp;
        }
        //BFS
        int totalImp = 0;
        queue<int> q;
        q.push(id);//start frm given id
        while(!q.empty()){
            int currId=q.front();
            q.pop();
            Employee* currEmp = empMap[currId];
            totalImp += currEmp->importance;
            //push all direct subordinates into q
            for(int subId:currEmp->subordinates){
                q.push(subId);
            }
        }
        return totalImp;
    }
};