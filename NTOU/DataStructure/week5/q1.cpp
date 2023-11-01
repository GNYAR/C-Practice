#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int x, y, value;
} element;

enum key
{
    x,
    y
};

void sort(element *a, int count, key sortBy)
{
    bool isX = (sortBy == key::x);
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int v1 = isX ? a[i].x : a[i].y;
            int v2 = isX ? a[j].x : a[j].y;
            if (v2 < v1)
            {
                element e = a[j];
                a[j] = a[i];
                a[i] = e;
            }
        }
    }
}

void transpose(element *matrix, int n, int count, element *result)
{
    int *starts = new int[n + 2]{0};
    for (int i = 0; i < count; i++)
        starts[matrix[i].y + 1]++;

    for (int i = 2; i < n + 1; i++)
        starts[i] += starts[i - 1];

    for (int i = 0; i < count; i++)
    {
        element e = matrix[i];
        int t = e.x;
        e.x = e.y;
        e.y = t;
        result[starts[e.x]++] = e;
    }
}

int main()
{
    int count;
    cin >> count;
    element *a = new element[count], *b = new element[count];
    int n = 0;
    for (int i = 0; i < count; i++)
    {
        char ch;
        cin >> ch >> a[i].x >> ch >> a[i].y >> ch >> ch >> a[i].value;
        n = max(n, max(a[i].x, a[i].y));
    }

    sort(a, count, key::y);
    sort(a, count, key::x);
    transpose(a, n, count, b);

    element *c = new element[count * 2];
    int cnt = 0;
    for (int i = 0; i < count; i++)
    {
        int j = 0;
        while (b[j].x < a[i].y)
            j++;
        while (b[j].x == a[i].y)
        {
            element e;
            e.x = a[i].x;
            e.y = b[j].y;
            e.value = a[i].value * b[j].value;
            c[cnt++] = e;
            j++;
        }
    }

    sort(c, cnt, key::y);
    sort(c, cnt, key::x);
    element temp = c[0];
    for (int i = 1; i < cnt; i++)
    {
        if (c[i].x == temp.x && c[i].y == temp.y)
            temp.value += c[i].value;
        else
        {
            cout << temp.x << ' ' << temp.y << ' ' << temp.value << endl;
            temp = c[i];
        }
    }
    cout << temp.x << ' ' << temp.y << ' ' << temp.value << endl;

    delete[] a, b, c;
    return 0;
}
