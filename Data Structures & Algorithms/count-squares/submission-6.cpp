class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;

    CountSquares() {
        
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        points[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        // Try every point having the same x-coordinate
        for (auto &p : points[x]) {
            int y2 = p.first;

            int side = y2 - y;
            if(side==0){
                continue;
            }
            int x3=x+side,x4=x-side;
            int count=p.second;
            // Square to the right
            int right =count* points[x3][y] *
                        points[x3][y2];

            // Square to the left
            int left =count* points[x4][y] *
                       points[x4][y2];

            ans += right + left;
        }

        return ans;
    }
};