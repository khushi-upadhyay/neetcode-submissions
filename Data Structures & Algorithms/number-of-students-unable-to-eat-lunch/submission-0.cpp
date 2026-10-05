class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int x : students ){
            q.push(x);
        }

        int n = students.size();
        for(int i =0 ; i < n; i++ ){
            int size = q.size();
            bool move = true;

            for(int j = 0 ; j < size && move ; j++){
                int next = q.front();
                q.pop();

                if(next == sandwiches[i]){
                    move = false;
                    break;
                }
                else{
                    q.push(next);
                }
            }
            if(q.size() == size){
                return size;
            }
        }
        return 0;
    }
};