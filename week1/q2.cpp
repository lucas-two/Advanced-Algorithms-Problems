/*
2. Implement in C++ a quick algorithm for deciding if two line segments are parallel
(without using any divisions).
*/
#include <iostream>
using namespace std;

struct point
{
    float x, y;
};
struct line
{
    point p1, p2;
};

bool isParallel(line lin1, line lin2);

int main()
{
    line line1, line2;
    // Line 1
    line1.p1.x = 1;
    line1.p1.y = 2;
    line1.p2.x = 3;
    line1.p2.y = 4;
    // Line 2
    line2.p1.x = 1;
    line2.p1.y = 2;
    line2.p2.x = 3;
    line2.p2.y = 4;

    if (isParallel(line1, line2))
    {
        cout << "Lines are parallel" << endl;
    }
    else
    {
        cout << "Lines are NOT parallel" << endl;
    }
    return 0;
};

bool isParallel(line lin1, line lin2)
{
    // Instead of dY1/dX1 == dY2/dX2
    // We have done dY1 * dX2 == dy2 * dX1 to avoid using division
    // Division could be problematic if we have a divide by 0
    float grad1 = (lin1.p2.y - lin1.p1.y) * (lin2.p2.x - lin2.p1.x);
    float grad2 = (lin2.p2.y - lin2.p1.y) * (lin1.p2.x - lin1.p1.x);

    // If gradiants are equal -> they are parallel
    if (grad1 == grad2)
    {
        return true;
    }
    return false;
};