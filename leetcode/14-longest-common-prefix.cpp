/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
*    解法1：纵向连接
*/
string longestCommonPrefix_solve1(vector<string>& strs) {
    if(strs.size() == 0){
        return "";
    }else if(strs.size() == 1){
        return strs[0];
    }else {
        for(int i=0; i < strs[0].length(); i++){
            char a = strs[0][i];
            for(int j = 1 ; j < strs.size(); j++){
                char b = strs[j][i];
                if(i == strs[j].length() ||  a != b){
                    return strs[0].substr(0,i);
                }
            }

        }
    }
    return strs[0];
}

/*
*    解法2：横向连接
*/
string longestCommonPrefix_solve2(vector<string>& strs) {
    if(strs.size() == 0){
        return "";
    }else if(strs.size() == 1){
        return strs[0];
    }else {
        string prefix = strs[0];
        for(int i=1; i < strs.size(); i++){
            prefix = longestCommonPrefix_solve2(prefix, strs[i]);
            if(prefix.length() == 0){
                return "";
            }
        }
        return prefix;
    }
}
string longestCommonPrefix_solve2(const string& str1,const string& str2){
    int length = min(str1.length(), str2.length());
    int index = 0;
    while(index < length && (str1[index] == str2[index])){
        index++;
    }
    return str1.substr(0, index);
}

int main(){

    // vector<string> strs {"flower","flow","flight"};
    // vector<string> strs {"c","c"};
    vector<string> strs {"","c"};
    cout << longestCommonPrefix_solve1(strs) << endl;
    return 0;

}