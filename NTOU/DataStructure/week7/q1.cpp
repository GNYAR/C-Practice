#include <iostream>

using namespace std;

void push(int* stack, int& top, int x) {
    stack[++top] = x;
}

int pop(int* stack, int& top)
{
    return stack[top--];
}

int q1()
{
    int n, * list, * stack, temp;
    cin >> n >> temp;
    list = new int[n];
    stack = new int[n];
    while (temp != -1)
    {
        list[0] = temp;
        for (int i = 1; i < n; i++)
            cin >> list[i];

        int top = -1, index = 0;
        for (int i = 1; i <= n; i++)
        {
            push(stack, top, i);
            while (top > -1 && index < n && stack[top] == list[index])
            {
                pop(stack, top);
                index++;
            }
        }
        cout << (top == -1 ? "YES" : "NO") << endl;

        cin >> temp;
    }
    return 0;
}
