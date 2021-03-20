#include <deque>
#include <iostream>

using namespace std;

//배열의 값들을 deque 형태로 저장한다
deque<int> arr;
//명령어를 string 형태로 저장하여 사용한다
string order;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    //tc: 테스트 케이스의 수, input: deque에 값을 넣을 때 사용할 공간
    //size: 배열의 크기, d_cnt: 명령어에서 D의 수
    int tc, input, size, d_cnt;
    //입력받은 배열에서 값만 저장하기 위해 사용
    char buf;
    //배열이 뒤집혔는지 여부를 저장한다
    bool flip;

    //테스트 케이스를 입력받은 뒤 각 케이스마다
    cin >> tc;
    while(tc--)
    {
        //변수를 초기화한다
        arr.resize(0);
        flip = false; d_cnt = 0; input = 0; 
        buf = '\0';

        //명령어와 배열의 크기를 입력받는다
        cin >> order >> size;

        //명령어 안의 D의 수, 즉 배열에서 제거될 값의 수를 계산한다
        for(int i = 0; i < order.size(); i++) if(order[i] == 'D') d_cnt++;

        //주어진 문자열에서 상수만 빼 deque에 저장한다
        while(buf != ']')
        {
            //한 글자씩 입력받아
            cin >> buf;
            
            //해당 글자가 0부터 9 사이라면 input을 10 곱한 뒤 해당 값을 더한다
            if ((buf - '0' >= 0) && (buf - '0' <= 9)) 
                input = input * 10 + (buf - '0');
            //그렇지 않고 input이 유의미한 값이라면 input을 deque에 넣고 
            //input을 0으로 초기화한다
            else if (input)
            {
                arr.push_back(input);
                input = 0;
            }
        }

        //배열의 크기보다 더 많이 pop하게 되는 경우에는 에러가 발생한다
        if(d_cnt > size)
        {
            cout << "error" << '\n';
            continue;
        }

        //명령어를 글자 단위로 실행한다
        for(int i = 0; i < order.size(); i++)
        {
            //해당 글자가 R이라면 배열을 뒤집는다
            if(order[i] == 'R') flip = !flip;
            //해당 글자가 D일 때
            else if(order[i] == 'D')
            {
                //배열이 뒤집혀있다면 배열의 back 원소를,
                //그렇지 않다면 front 원소를 제거
                if(flip) arr.pop_back();
                else     arr.pop_front();
            }
        }

        //명령어를 모두 실행했을 때 배열이 뒤집혀있다면
        if(!flip)
        {
            cout << '[';
            while(!arr.empty())
            {
                cout << arr.back();
                arr.pop_back();
                if (!arr.empty()) cout << ',';
            }
            cout << ']' << '\n';
        }
        //그렇지 않다면 배열을 정상적으로 출력한다
        else
        {
            cout << '[';
            while(!arr.empty())
            {
                cout << arr.front();
                arr.pop_front();
                if (!arr.empty()) cout << ',';
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}