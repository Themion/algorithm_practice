#include <iostream>
#include <string>

using namespace std;

// 조합의 결과를 저장
string C[101][101] = {{ "", }};

// 매우 긴 두 수를 string 형태로 저장해 더한다
string add(string a, string b)
{
    // 두 수의 각 자리를 더했을 때 10 이상이면 true, 아니라면 false
    bool carry = false;
    // 두 수의 각 자리를 더한 값
    int add_ = 0;
    // 두 수를 더한 값
    string ret = "";

    // 두 수 a와 b의 자리수를 맞춘다
    if (a.size() > b.size())    b = string(a.size() - b.size(), '0') + b;
    else                        a = string(b.size() - a.size(), '0') + a;

    // 두 수의 각 자리를 더해 그 결과를 ret에 차례로 저장
    for (int i = a.size() - 1; i >= 0; i--)
    {
        add_ = (a[i] - '0') + (b[i] - '0') + carry;
        ret = (char)((add_ % 10) + '0') + ret;
        carry = add_ / 10;
    }

    // 두 수의 맨 앞자리를 더했을 때 carry가 생긴다면 자릿수를 1 늘린다
    if (carry) ret = '1' + ret;

    return ret;
}

string get_C(int n, int r)
{
    // 조합의 특성상 nCr은 nC(n-r)와 같다
    if (r > n - r) return get_C(n, n - r);

    // nCr을 아직 구하지 않았다면
    if (C[n][r] == "")
    {
        // nC0은 항상 1
        if (r == 0) C[n][r] = "1";
        // nCr = (n-1)C(r-1) + (n-1)Cr
        else C[n][r] = add(get_C(n - 1, r - 1), get_C(n - 1, r));
    }

    return C[n][r];
}

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    cout << get_C(n, m) << '\n';

    return 0;
}