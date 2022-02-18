/***********************************
메모리 초과 이슈
***********************************/

#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        bool visited[10000] = { false, }; 
        char how[10000] = { '\0', }; 
        int from[10000] = { 0, };

        int start, end;
        cin >> start >> end;

        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty())
        {
            int input;
            input = q.front(); q.pop();

            int num = input * 2 % 10000;
            if (visited[num] == 0)
            {
                from[num] = input;
                q.push(num);
                visited[num] = 1;
                how[num] = 'D';
            }

            num = (num - 1) < 0 ? 9999 : input - 1;
            if (visited[num] == 0)
            {
                from[num] = input;
                q.push(num);
                visited[num] = 1;
                how[num] = 'S';
            }

            num = (input % 1000) * 10 + input / 1000;
            if (visited[num] == 0)
            {
                from[num] = input;
                q.push(num);
                visited[num] = 1;
                how[num] = 'L';
            }

            num = (input / 10) + (input%10) * 1000;
            if (visited[num] == 0)
            {
                from[num] = input;
                q.push(num);
                visited[num] = 1;
                how[num] = 'R';
            }
            string ans = "";
            while (end != start)
            {
                ans += how[end];
                end = from[end];
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
        }
    }

    return 0;
}