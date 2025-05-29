#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <climits>
#include <sstream>  // Th�m thu vi?n stringstream
using namespace std;

int n;
int a[20][20], b[20][20]; // Ma tr?n ban d?u v� d�ch
int dx[] = {-1, 0, 0, 1}; // C�c hu?ng di chuy?n (l�n, ph?i, tr�i, xu?ng)
int dy[] = {0, -1, 1, 0};

// C?u tr�c luu th�ng tin tr?ng th�i c?a b�i to�n
struct Node {
    int board[20][20];  // Ma tr?n c?a tr?ng th�i hi?n t?i
    int x, y;           // V? tr� c?a � tr?ng (0)
    int g, h;           // g: chi ph� t? ban d?u, h: gi� tr? heuristic
    string state;       // Bi?u di?n tr?ng th�i du?i d?ng chu?i d? so s�nh

    bool operator<(const Node &other) const {
        return (g + h) > (other.g + other.h); // D�ng h�ng d?i uu ti�n min-heap
    }
};

// H�m chuy?n d?i s? th�nh chu?i (s? d?ng stringstream thay v� to_string)
string toString(int board[20][20]) {
    stringstream ss;  // T?o m?t d?i tu?ng stringstream
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ss << board[i][j] << ",";  // D�ng << d? n?i c�c s? v�o chu?i
    return ss.str();  // Tr? v? chu?i d� n?i
}

// H�m heuristic t�nh s? � sai gi?a ma tr?n hi?n t?i v� d�ch
int heuristic(int board[20][20]) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] != b[i][j]) cnt++;
    return cnt;
}

// Ki?m tra xem ma tr?n hi?n t?i d� d?t tr?ng th�i d�ch chua
bool isGoal(int board[20][20]) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] != b[i][j]) return false;
    return true;
}

// Sao ch�p ma tr?n t? m?t tr?ng th�i n�y sang tr?ng th�i kh�c
void copyBoard(int from[20][20], int to[20][20]) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            to[i][j] = from[i][j];
}

// H�m d?c d? li?u t? file
void inp() {
    ifstream fin("taci1.txt"); // �?c d? li?u t? file
    fin >> n; // �?c k�ch thu?c ma tr?n
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j]; // �?c ma tr?n ban d?u
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> b[i][j]; // �?c ma tr?n d�ch
    fin.close();
}

// H�m gi?i b�i to�n TACI s? d?ng thu?t to�n A*
void taci() {
    priority_queue<Node> pq; // H�ng d?i uu ti�n (min-heap)
    set<string> visited;     // Set luu c�c tr?ng th�i d� tham

    int x0, y0;
    // T�m v? tr� � tr?ng (0) trong ma tr?n ban d?u
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0) {
                x0 = i;
                y0 = j;
            }

    Node start;
    // Kh?i t?o tr?ng th�i ban d?u
    copyBoard(a, start.board);
    start.x = x0;
    start.y = y0;
    start.g = 0; // Chi ph� ban d?u
    start.h = heuristic(start.board); // Heuristic ban d?u
    start.state = toString(start.board);

    pq.push(start);
    visited.insert(start.state);

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        // N?u tr?ng th�i hi?n t?i l� tr?ng th�i d�ch, k?t th�c
        if (isGoal(curr.board)) {
            cout << "�� gi?i du?c b�i to�n sau " << curr.g << " bu?c!" << endl;
            return;
        }

        // Th? di chuy?n � tr?ng d?n c�c v? tr� xung quanh
        for (int i = 0; i < 4; i++) {
            int xTemp = curr.x + dx[i];
            int yTemp = curr.y + dy[i];

            if (xTemp >= 1 && xTemp <= n && yTemp >= 1 && yTemp <= n) {
                // Di chuy?n � tr?ng
                swap(curr.board[curr.x][curr.y], curr.board[xTemp][yTemp]);
                curr.x = xTemp;
                curr.y = yTemp;

                // T�nh chi ph� v� heuristic m?i
                curr.g = curr.g + 1;
                curr.h = heuristic(curr.board);
                curr.state = toString(curr.board);

                // N?u chua tham tr?ng th�i n�y, th�m v�o h�ng d?i
                if (visited.find(curr.state) == visited.end()) {
                    pq.push(curr);
                    visited.insert(curr.state);
                }

                // Kh�i ph?c l?i tr?ng th�i ban d?u
                swap(curr.board[curr.x][curr.y], curr.board[xTemp][yTemp]);
                curr.x = xTemp;
                curr.y = yTemp;
            }
        }
    }

    cout << "Kh�ng th? gi?i du?c b�i to�n!" << endl;
}

int main() {
    inp();  // �?c d? li?u t? file
    taci(); // Gi?i b�i to�n
    return 0;
}

