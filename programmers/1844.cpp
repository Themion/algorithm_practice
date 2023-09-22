#include <vector>
#include <queue>

using namespace std;

int delta[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int max_(int a, int b) { return max(a, b); }

class coord {
public:
    int r, c;
    unsigned int cost = 1;
    coord() {}
    coord(int r, int c) {
        this->r = r;
        this->c = c;
    }
    coord(int r, int c, unsigned int cost) {
        this->r = r;
        this->c = c;
        this->cost = cost;
    }
    
    coord next(int dir) {
        int* d = delta[dir];
        return coord(this->r + d[0], this->c + d[1], this->cost + 1);
    }
};

bool operator==(coord a, coord b) { return a.r == b.r && a.c == b.c; }

class board {
public:
    vector<vector<int>> brd;
    int ROW, COL;
    
    board() {}
    board(vector<vector<int>> brd) {
        this->brd = brd;
        this->ROW = this->brd.size();
        this->COL = this->brd[0].size();
    }
    
    vector<int> operator[](int i) { return brd[i]; }
    int& operator[](coord crd) { return brd[crd.r][crd.c]; }
    
    bool is_end(coord crd) { return crd.r == ROW - 1 && crd.c == COL - 1; }
    bool is_valid(coord crd) {
        return 0 <= crd.r && crd.r < ROW
            && 0 <= crd.c && crd.c < COL
            && brd[crd.r][crd.c] == 1;
    }
};

int solution(vector<vector<int>> maps) {
    board brd = board(maps);
    coord dest = coord(brd.ROW - 1, brd.COL - 1, -1);
    queue<coord> q;
    
    q.push(coord(0, 0));
    brd[q.front()] = 0;
    
    while (!q.empty() && brd[dest] == 1) {
        coord crd = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            coord crd_ = crd.next(dir);
            if (!brd.is_valid(crd_)) continue;
            brd[crd_] = 0;
            q.push(crd_);

            if (crd_ == dest && crd.cost < dest.cost)
              dest = crd_;
        }
    }
    
    return dest.cost;
}
