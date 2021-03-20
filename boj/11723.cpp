#include <cstdio>

int main()
{
    bool S[21] = { false, };
    char cmd[7];
    int M, num;

    scanf("%d", &M);

    while (M--)
    { 
        scanf("%s", cmd);

        if (cmd[0] == 'a' && cmd[1] == 'l') // all
            for (int i = 1; i <= 20; i++) S[i] = true;
        else if (cmd[0] == 'e')             // empty
            for (int i = 1; i <= 20; i++) S[i] = false;
        else                                // else
        {
            scanf("%d", &num);
            if (cmd[0] == 'a')      S[num] = true;          // add
            else if (cmd[0] == 'r') S[num] = false;         // remove
            else if (cmd[0] == 'c') printf("%d\n", S[num]); // check
            else if (cmd[0] == 't') S[num] = !S[num];       // toggle
        }
    }

    return 0;
}
/*  string 방식
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    bool S[21] = { false, };
    string cmd;
    int M, num;

    cin >> M;
    
    while (M--)
    {
        cin >> cmd;
        if (cmd == "all") 
            for (int i = 1; i <= 20; i++) S[i] = true;
        else if (cmd == "empty") 
            for (int i = 1; i <= 20; i++) S[i] = false;
        else
        {
            cin >> num;
            if (cmd == "add")           S[num] = true;
            else if (cmd == "remove")   S[num] = false;
            else if (cmd == "check")    printf("%d\n", S[num]);
            else if (cmd == "toggle")   S[num] = !S[num];
        }
    }

    return 0;
} 
*/