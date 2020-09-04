/*
51. N 皇后
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。


上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
*/

#include <iostream>
#include <vector>

using namespace std;

// 找到一个解后，放进结果集
void handleResult(vector<vector<string>> &results, int map[], int n){
	vector<string> result;
	for (int i = 0; i < n; i++){
		string row(n, '.');
		row[map[i]] = 'Q';
		result.push_back(row);
	}
	results.push_back(result);
}

// 判断该行该列是否可以放置
bool canPlace(int map[], int row, int col){
	for(int i = row - 1; i >= 0; i--){
		if(map[i] == col || abs(col - map[i]) == abs(row - i)){
			return false;
		}
	}
	return true;
}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> results;
	int map[n];
	for(int i = 0;i < n; i++){
		map[i] = -1;
	}
	int i = 0, j = 0;
	while(i < n){
		while(j < n){
			if(canPlace(map, i, j)) {// 这一列可以放置，放置并跳出循环
				map[i] = j;	
				break;		
			}else {					//这一列不能放置，尝试下一列
				j++;
			}
		}
		if(map[i] == -1){	// 这一行不能放置
			if(i == 0){			// 当前已经是第0行，没有上一行可以回溯了，算法结束
				break;
			}
			// 回溯到上一行：从上一行原来放置点的下一列开始尝试，并撤销原来的放置
			i--;		
			j = map[i] + 1;		
			map[i] = -1;		
		}else {				
			if(i == n - 1){	// 如果已经是最后一行，则说明找到了一个解 清除该行的皇后 从下一列开始继续尝试
				handleResult(results, map, n);
				map[i] = -1;		
				j++;				
			}else {		    // 继续到下一行寻找，从下一行的第0列开始尝试
				i++;
				j=0;
			}
		}
	}
	return results;
}

void print(vector<vector<string>> vv){
	for(vector<string> v : vv){
		for(string s : v){
			cout << s << " ";
			cout << endl;
		}
		cout << "---------" << endl;
	}
}

int main(){

	cout << solveNQueens(1).size() << endl;
	cout << solveNQueens(2).size() << endl;
	cout << solveNQueens(3).size() << endl;
	cout << solveNQueens(4).size() << endl;
	cout << solveNQueens(5).size() << endl;
	cout << solveNQueens(6).size() << endl;
	cout << solveNQueens(7).size() << endl;
	cout << solveNQueens(8).size() << endl;
	cout << solveNQueens(9).size() << endl;

	// print(solveNQueens(1));
	// print(solveNQueens(2));
	// print(solveNQueens(3));
	// print(solveNQueens(4));
	// print(solveNQueens(5));
	// print(solveNQueens(8));
}