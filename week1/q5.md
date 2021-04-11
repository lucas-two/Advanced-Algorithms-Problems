## 5. What does the intersect function return when called with two copies of the same line segment?

```
bool intersect(line a, line b)
{
    if (ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2) > 0) {
        return false;
    }
    else if (ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2) > 0) {
        return false;
    }
    else {
        return true;
    }
}
```

It would seem that if we input two copies of the same line segment it would always return `false`. This is because the CCW results will always be the same. Thus, if the CCWs are -/ve, since they multiply together, the result will be positive, and if it's positive it will stay positive. Hence, it will always return false.
