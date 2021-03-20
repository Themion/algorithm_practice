#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//회원의 정보를 저장할 클래스
class Person
{
public:
    int age = 0;        //회원의 나이
    int idx = 100001;   //회원의 가입 순서
    string name = "";   //회원의 이름
};

int n;
Person p[100000];

//회원의 나이 순으로, 나이가 같다면 가입일 순으로 크기 비교
bool operator< (Person a, Person b)
{
    if (a.age != b.age) return a.age < b.age;
    return a.idx < b.idx;
}

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].age >> p[i].name;
        p[i].idx = i;
    }

    //Person 클래스의 크기 비교 연산자는 위에서 정의하였다
    std::sort(p, p + n);

    //정렬된 순으로 회원 목록을 출력
    for (int i = 0; i < n; i++) cout << p[i].age << ' ' << p[i].name << '\n';

    return 0;
}