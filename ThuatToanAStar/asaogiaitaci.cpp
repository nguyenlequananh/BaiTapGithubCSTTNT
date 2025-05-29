#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <climits>
#include <sstream>  // Thêm thu vi?n stringstream
using namespace std;

int n;
int a[20][20], b[20][20]; // Ma tr?n ban d?u và dích
int dx[] = {-1, 0, 0, 1}; // Các hu?ng di chuy?n (lên, ph?i, trái, xu?ng)
int dy[] = {0, -1, 1, 0};

// C?u trúc luu thông tin tr?ng thái c?a bài toán
struct Node {
    int board[20][20];  // Ma tr?n c?a tr?ng thái hi?n t?i
    int x, y;           // V? trí c?a ô tr?ng (0)
    int g, h;           // g: chi phí t? ban d?u, h: giá tr? heuristic
    string state;       // Bi?u di?n tr?ng thái du?i d?ng chu?i d? so sánh

    bool operator<(const Node &other) const {
        return (g + h) > (other.g + other.h); // Dùng hàng d?i uu tiên min-heap
    }
};

// Hàm chuy?n d?i s? thành chu?i (s? d?ng stringstream thay vì to_string)
string toString(int board[20][20]) {
    stringstream ss;  // T?o m?t d?i tu?ng stringstream
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ss << board[i][j] << ",";  // Dùng << d? n?i các s? vào chu?i
    return ss.str();  // Tr? v? chu?i dã n?i
}

// Hàm heuristic tính s? ô sai gi?a ma tr?n hi?n t?i và dích
int heuristic(int board[20][20]) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] != b[i][j]) cnt++;
    return cnt;
}

// Ki?m tra xem ma tr?n hi?n t?i dã d?t tr?ng thái dích chua
bool isGoal(int board[20][20]) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] != b[i][j]) return false;
    return true;
}

// Sao chép ma tr?n t? m?t tr?ng thái này sang tr?ng thái khác
void copyBoard(int from[20][20], int to[20][20]) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            to[i][j] = from[i][j];
}

// Hàm d?c d? li?u t? file
void inp() {
    ifstream fin("taci1.txt"); // Ð?c d? li?u t? file
    fin >> n; // Ð?c kích thu?c ma tr?n
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j]; // Ð?c ma tr?n ban d?u
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> b[i][j]; // Ð?c ma tr?n dích
    fin.close();
}

// Hàm gi?i bài toán TACI s? d?ng thu?t toán A*
void taci() {
    priority_queue<Node> pq; // Hàng d?i uu tiên (min-heap)
    set<string> visited;     // Set luu các tr?ng thái dã tham

    int x0, y0;
    // Tìm v? trí ô tr?ng (0) trong ma tr?n ban d?u
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0) {
                x0 = i;
                y0 = j;
            }

    Node start;
    // Kh?i t?o tr?ng thái ban d?u
    copyBoard(a, start.board);
    start.x = x0;
    start.y = y0;
    start.g = 0; // Chi phí ban d?u
    start.h = heuristic(start.board); // Heuristic ban d?u
    start.state = toString(start.board);

    pq.push(start);
    visited.insert(start.state);

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        // N?u tr?ng thái hi?n t?i là tr?ng thái dích, k?t thúc
        if (isGoal(curr.board)) {
            cout << "Ðã gi?i du?c bài toán sau " << curr.g << " bu?c!" << endl;
            return;
        }

        // Th? di chuy?n ô tr?ng d?n các v? trí xung quanh
        for (int i = 0; i < 4; i++) {
            int xTemp = curr.x + dx[i];
            int yTemp = curr.y + dy[i];

            if (xTemp >= 1 && xTemp <= n && yTemp >= 1 && yTemp <= n) {
                // Di chuy?n ô tr?ng
                swap(curr.board[curr.x][curr.y], curr.board[xTemp][yTemp]);
                curr.x = xTemp;
                curr.y = yTemp;

                // Tính chi phí và heuristic m?i
                curr.g = curr.g + 1;
                curr.h = heuristic(curr.board);
                curr.state = toString(curr.board);

                // N?u chua tham tr?ng thái này, thêm vào hàng d?i
                if (visited.find(curr.state) == visited.end()) {
                    pq.push(curr);
                    visited.insert(curr.state);
                }

                // Khôi ph?c l?i tr?ng thái ban d?u
                swap(curr.board[curr.x][curr.y], curr.board[xTemp][yTemp]);
                curr.x = xTemp;
                curr.y = yTemp;
            }
        }
    }

    cout << "Không th? gi?i du?c bài toán!" << endl;
}

int main() {
    inp();  // Ð?c d? li?u t? file
    taci(); // Gi?i bài toán
    return 0;
}

