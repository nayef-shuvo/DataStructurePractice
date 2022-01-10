#include<bits/stdc++.h>
using namespace std;
#define MAX_DEGREE 100

string eqn;
int coef[MAX_DEGREE + 1]; //* It can handle an equation of maximum 100 degree
int dif[MAX_DEGREE + 1];


double power(double a, int b) {
    double res = 1.0;
    while(b--) res *= a;
    return res;
}

void differentiation() {
    for (int i = 0; i < MAX_DEGREE-1; i++) {
        dif[i] = (i+1)*coef[i+1];
    }
}


int converter(string num) {
    int res = 0;
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.size(); ++i) {
        res += (int) (num[i] - '0')*power(10, i);
    }
    return res;
}

double f(double x) {
    double res = 0.0;
    for (int i = 0; i <= MAX_DEGREE; ++i) {
        if (coef[i] == 0) continue;
        res += coef[i]*power(x, i);
    }
    return res;differentiation();
    for (int i = 0; i < 5; i++) cout << coef[i] << "\n";
    for (int i = 0; i < 5; i++) cout << dif[i] << "\n";
}

double f_prime(double x) {
    double res = 0.0;
    for (int i = 0; i <= MAX_DEGREE; ++i) {
        if (dif[i] == 0) continue;
        res += dif[i]*power(x, i);
    }
    return res;
}

double newtown_raphson(double x, double epsilon = 1e-4) {
    double h = f(x)/f_prime(x);
    if (fabs(f(x)) < epsilon) return x;
    return newtown_raphson(x-h, epsilon);
}

int main() {
    //* -4x^4 + 121x^3 - x^2 - 12x + 120
    //* x^3 + 6x^2 + 11x + 6
    getline(cin, eqn);
    string temp = "";
    for (char c : eqn) {
        if (c == ' ') continue;
        temp += c;
    }
    eqn = temp + "+";

    bool sign = true; //* true -> '+', false -> '-'
    bool flag = true; //* true -> coefficient, false -> power
    string currentNum = "";
    string currentPow = "";
    for (int i = 0; i < eqn.size(); ++i) {
        char c = eqn[i];
        //cout << c << " -> " << "  num: "<<pow currentNum << " , pow: " << currentPow << "\n";
        if (c == 'x') {
            if (i == 0) currentNum = "1";
            else if (eqn[i-1] == '+' or eqn[i-1] == '-') currentNum = "1";
            continue;
        }
        if (c == '^') {
            flag = false;
            continue;
        }
        if (c == '+' or c == '-') {
            flag = true;
            if (eqn[i-1] == 'x') currentPow = "1";
            int x = converter(currentNum);
            int y = converter(currentPow);
            if (sign) coef[y] = x;
            else coef[y] = -x;
            if (c == '+') sign = true;
            else sign = false;
            currentNum = "";
            currentPow = "";
        }
        else {
            if (flag) currentNum += c;
            else currentPow += c;
        }
    }
    //if (sign) coef[converter(currentPow)] = converter(currentNum);
    //else coef[converter(currentPow)] = -converter(currentNum);

    double a, b, epsilon = .00001;
    //cin >> a >> b;
    //cout << setprecision(10) << bisection(a, b) << "\n";

    //for (int i = 3; i >= 0; --i) cout << coef[i] << " " << i << "\n";
    differentiation();
//    for (int i = 4; i >= 0; i--) cout << coef[i] << " ";
//    cout << "\n";
//    for (int i = 3; i >= 0; i--) cout << dif[i] << " ";
    cin >> a;
    cout << newtown_raphson(a);
}
