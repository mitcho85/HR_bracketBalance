#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
	stack<char>symbols;
	for (int i = 0; i < expression.size(); ++i) {
		char curBracket = expression[i];
		//if(curBracket == '\0') return true;
		if (curBracket == '{') symbols.push(curBracket);
		else if (curBracket == '(') symbols.push(curBracket);
		else if (curBracket == '[') symbols.push(curBracket);
		else if (symbols.size() == 0) return false;
		else if (curBracket == '}') {
			if (symbols.top() == '{') symbols.pop();
			else return false;
		}
		else if (curBracket == ')') {
			if (symbols.top() == '(') symbols.pop();
			else return false;
		}
		else if (curBracket == ']') {
			if (symbols.top() == '[') symbols.pop();
			else return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		string expression;
		cin >> expression;
		bool answer = is_balanced(expression);
		if (answer)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
