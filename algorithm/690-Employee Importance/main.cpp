/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeMap; {
            for (Employee* employee : employees) {
                employeeMap[employee->id] = employee;
            }
        }

        int totalImportance = 0;
        queue<Employee*> q;
        q.push(employeeMap[id]);
        while (!q.empty()) {
            Employee* employee = q.front();
            q.pop();

            totalImportance += employee->importance;

            for (int id : employee->subordinates) {
                q.push(employeeMap[id]);
            }
        }

        return totalImportance;
    }
};