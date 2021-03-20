#include <cstdio>
#include <deque>

//f, b: 커서를 기준으로 각각 앞, 뒤를 저장할 스택
//출력 시 시간을 절약하기 위해 deque로 선언
std::deque<char> f, b;

int main()
{
    //입력에 사용할 버퍼
    char buf;
    //문자열에 가할 명령의 수
    int tc;

    //우선 문자열의 맨 앞글자를 입력받은 뒤
    scanf("%c", &buf);
    //해당 문자열이 공백이 아니라면 f에 push한다
    //이 과정을 buf에 \n이 들어올 때까지 반복한다
    while(buf != '\n')
    {
        f.push_back(buf);
        scanf("%c", &buf);
    }
    //문자열에 가할 명령의 수를 입력받는다
    scanf("%d\n", &tc);
    
    //각 명령에 대해
    while(tc--)
	{
        //명령은 한 글자로 이루어져 있으니 char타입 변수로 명령을 처리할 수 있다
        scanf("%c", &buf);
        //각 명령이 무엇인지 알아내어
		switch (buf)
		{
        //명령이 L이라면
		case('L'):
            //f가 비어있지 않을 때 f의 top을 b로 옮긴다
            if(!f.empty())
            {
                b.push_back(f.back());
                f.pop_back();
            }
			break;
        //명령이 D라면
		case('D'):
            //b가 비어있지 않을 때 b의 top을 f로 옮긴다
            if(!b.empty())
            {
                f.push_back(b.back());
                b.pop_back();
            }
			break;
        //명령이 B라면
		case('B'):
            //f에 값이 있는 경우 f의 top을 pop한다
            if(!f.empty()) f.pop_back();
			break;
        //명령이 P라면
		case('P'):
            //문자열에 넣을 문자를 입력받아 f에 push한다
            scanf(" %c", &buf);
            f.push_back(buf);
			break;
		}
        scanf("%c", &buf);
	}

    //f를 front부터 차례로 출력하며 pop한다
    while(!f.empty())
    {
        if(f.front() != '\n') printf("%c", f.front());
        f.pop_front();
    }

    //b를 back부터 차례로 출력하며 pop한다
    while(!b.empty())
    {
        if(b.back() != '\n') printf("%c", b.back());
        b.pop_back();
    }

    //모든 동작을 끝마쳤으므로 개행 문자를 출력한다
    printf("\n");

    return 0;
}