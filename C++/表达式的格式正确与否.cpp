#include <bits/stdc++.h> //小括号与大括号输入的标准与否
using namespace std;

int main()
{
    int jian[10000], key = 0;
    memset(jian, 0, sizeof(jian));
    int xi = 0;
    string str;
    cin >> str;
    for (int i = 0; i <= str.length(); i++)
    {
        if ((str[i] < 48 && str[i] > 57) || (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'))
            ;
        else
            key = 1;
        if (str[i] == '/' && str[i + 1] == '0')
            key = 1;
        if (str[i] == '(')
        {
            jian[xi] = 1, xi++;
        }
        if (str[i] == ')')
        {
            if (jian[xi - 1] == 1)
            {
                jian[xi - 1] = 0;
                xi--;
            }
            else
                key = 1;
        }
        if (str[i] == '[')
        {
            jian[xi] = 2, xi++;
        }
        if (str[i] == ']')
        {
            if (jian[xi - 1] == 2)
            {
                jian[xi - 1] = 0;
                xi--;
            }
            else
                key = 1;
        }
    }
    if (key == 1 || xi != 0)
    {
        cout << "输入不符合规范";
        return 0;
    }
    if (xi == 0)
    {
        cout << "符合规范";
        return 0;
    }
    return 0;
}
