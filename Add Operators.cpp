class Solution {
  long long compute(const string &s) {

    stack<long long> s1;
    stack<char> s2;

    for (int i = 0; i < s.size();) {
      if (!isdigit(s[i])) {
        char op = s[i];
        while (!s2.empty() && (s2.top() == '*' || op == '+' || op == '-')) {
          char c = s2.top();
          s2.pop();
          long long v2 = s1.top();
          s1.pop();
          switch (c) {
            case '*': {
              s1.top() = s1.top() * v2;
              break;
            }
            case '+':s1.top() = s1.top() + v2;
              break;
            case '-':s1.top() = s1.top() - v2;
              break;
          }
        }
        s2.push(op);
        i++;
        continue;
      }
      long long tmp = 0;
      while (isdigit(s[i])) {
        tmp *= 10;
        tmp += s[i] - '0';
        i++;
      }
      s1.push(tmp);
    }

    while (!s2.empty()) {
      char op = s2.top();
      s2.pop();
      long long v2 = s1.top();
      s1.pop();
      switch (op) {
        case '*': {
          s1.top() = s1.top() * v2;
          break;
        }
        case '+':s1.top() = s1.top() + v2;
          break;
        case '-':s1.top() = s1.top() - v2;
          break;
      }
    }

    long long result = s1.empty() ? LONG_LONG_MAX : s1.top();
//    cout << "compute : " << s << " =" << result << endl;
    return result;
  }

  void work(const string &num, int index, int target, vector<string> &result, string path) {
    for (int i = index; i < num.size() && index - i < 11; i++) {
      path.push_back(num[i]);
      if (i + 1 == num.size()) {
        if (compute(path) == target) {
          result.push_back(path);
        }
      } else {
        for (char c : oper) {
          path.push_back(c);
          work(num, i+1, target, result, path);
          path.pop_back();
        }
      }

      if(num[index] == '0'){break;}
    }
  }
  char oper[3] = {'+', '-', '*'};
 public:
  /*
   * @param num: a string contains only digits 0-9
   * @param target: An integer
   * @return: return all possibilities
   */
  vector<string> addOperators(string &num, int target) {
    // write your code here
    vector<string> result;
    work(num, 0, target, result, "");
    return result;
  }
};
