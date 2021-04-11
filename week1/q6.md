## 6. What is the maximum value achievable by count when inside is executed on a polygon with N vertices? Give an example supporting your answer.

```
int inside(point t, point p[], int N)
{
    int i, count = 0, j = 0;
    line lt,lp;
    p[0] = p[N]; p[N + 1] = p[1];
    lt.p1 = t; lt.p2 = t; lt.p2.x = INT_MAX;
    for (i = 1; i <= N; i++)
    {
        lp.p1 = p[i]; lp.p2 = p[i];
        if (!intersect(lp,lt))
        {
            lp.p2 = p[j]; j = i;
            if (intersect(lp, lt)) {
                count++;
            }
        }
    }
    return count & 1;
}
```

I am guessing that it's `(N - 1)`. This is because the method iterates while `i(initially 0) <= N` where each iteration count has a chance to increment by 1.
