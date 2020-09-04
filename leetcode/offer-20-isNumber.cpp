/*
剑指 Offer 20. 表示数值的字符串
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

*/


#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isNumber(string s){
    string pattern{"\\s*[+|-]?(\\d+(\\.\\d*)?|\\.\\d+)([e|E][+|-]?\\d+)?\\s*"};
    regex re(pattern);
    return regex_match(s, re);
}

int main(){
    cout << stod("5") << endl;

    cout << isNumber("0") << endl;
    cout << isNumber("0 ") << endl;
    cout << isNumber("-123") << endl;
    cout << isNumber(".1") << endl;
    cout << isNumber("0.8E+0.12") << endl;
    cout << isNumber("+100") << endl;
    cout << isNumber("5e2") << endl;
    cout << isNumber("3.1416") << endl;
    cout << isNumber("-1E-16") << endl;
    cout << isNumber("0123") << endl;
    cout << isNumber("3.") << endl;
    cout << isNumber("-5.e+.3") << endl;

    cout << isNumber("332a") << endl;
    cout << isNumber("12e") << endl;
    cout << isNumber("1a3.14") << endl;    
    cout << isNumber("1.1.4") << endl;   
    cout << isNumber("+-5") << endl;     
    cout << isNumber("12e+5.4") << endl;   
    cout << isNumber("e9") << endl;
    cout << isNumber(". 1") << endl;    
}
