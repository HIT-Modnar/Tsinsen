// Source : http://www.tsinsen.com/A1085
// Author : Modnar
// Date   : 2019-04-08

#include <iostream>
#include <cmath>
#include <vector>

// Note:
//   Because of the Tsinsen doesn't provide service now, I can not submit my code
//   to the online judge. Therefore, I can only get the source code from other
//   place. 
//
// Code source:
//   https://github.com/imageslr/tsinsen/blob/master/1085/1085.c

using namespace std;
int cnt = 0;

bool issafe(vector<vector<int> > pic, vector<int> pos, int row) {
    for(int i = 0; i < row; i++) {
        if(pos[i] == pos[row] || abs(i - row) == abs(pos[i] - pos[row]))
            return false;
    }
    return true;
}

void blackdfs(vector<vector<int> > blackpic, vector<int> blackpos, int n, int blackrow) {
    c++;
    if(blackrow == n) {
        cnt++;
        return ;
    }
    for(blackpos[blackrow] = 0; blackpos[blackrow] < n; blackpos[blackrow]++) {
        if(blackpic[blackrow][blackpos[blackrow]] == 1 && issafe(blackpic, blackpos, blackrow)) {
            blackdfs(blackpic, blackpos, n, blackrow + 1);
        }
    }
}


void dfs(vector<vector<int> > pic, vector<int> pos, int n, int row) {
    c++;
    if(row == n) {
        vector<vector<int> > blackpic(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                blackpic[i][j] = pic[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            blackpic[i][pos[i]] = 0;
        }
        vector<int> blackpos(n);
        blackdfs(blackpic, blackpos, n, 0);
        return ;
    }
    for(pos[row] = 0; pos[row] < n; pos[row]++) {
        if(pic[row][pos[row]] == 1 && issafe(pic, pos, row)) {
            dfs(pic, pos, n, row + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > pic(n, vector<int>(n));
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> pic[i][j];
        }
    }
    dfs(pic, pos, n, 0);
    cout << cnt<<" c:"<<c<<endl;
    return 0;
}

/**
 * 参考标准程序实现，略微改动。
 * 主要改动点为：vector<vector<int> > blackpic(pic); 使用pic直接初始化blackpic，
 * 而不是先声明然后遍历复制。
 */

// #include <iostream>
// #include <cmath>
// #include <vector>
// 
// using namespace std;
// 
// int cnt = 0;
// int n;
// 
// bool isSafe(vector<int> pos, int row)
// {
//     int i;
//     for(i = 0;i < row;i++)
//     {
//         if(pos[i] == pos[row] || abs(row-i) == abs(pos[row]-pos[i]))
//             return false;
//     }
//     return true;
// }
// 
// void blackdfs(vector<vector<int> > blackpic, vector<int> blackpos, int row)
// {
//     if(row == n)
//     {
//         cnt++;
//         return;
//     }
//     for(blackpos[row] = 0; blackpos[row] < n; blackpos[row]++)
//     {
//         if(blackpic[row][blackpos[row]] == 1 && isSafe(blackpos, row))
//             blackdfs(blackpic, blackpos, row + 1);
//     }
// }
// 
// void dfs(vector<vector<int> > pic, vector<int> pos, int row)
// {
//     if(row == n)
//     {
//         vector<vector<int> > blackpic(pic);
//         for(int i = 0; i < n; i++) {
//             blackpic[i][pos[i]] = 0;
//         }
//         vector<int> blackpos(n);
//         blackdfs(blackpic, blackpos, 0);
//         return ;
//     }
//     for(pos[row] = 0; pos[row] < n; pos[row]++)
//     {
//         if(pic[row][pos[row]] == 1 && isSafe(pos, row))
//             dfs(pic, pos, row + 1);
//     }
// }
// 
// int main()
// {
//     cin >> n;
//     vector<vector<int> > pic(n, vector<int>(n));
//     vector<int> pos(n);
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> pic[i][j];
//         }
//     }
//     dfs(pic, pos, 0);
//     cout << cnt <<endl;
//     return 0;
// }
