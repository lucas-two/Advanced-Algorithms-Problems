/*
3. Implement in C++ a quick algorithm for deciding if four line segments form a square
(without using any divisions).
*/
#include <iostream>
#include <cmath>
using namespace std;

struct point
{
    float x, y;
};
struct line
{
    point p1, p2;
};

double PI = 2 * acos(0.0);

bool isEqualLength(line seg[4]);
bool isLinked(line seg[4]);
bool isRightAngleJoined(line seg[4]);
float distance(line a);
void printSegments(line seg[4]);
void swapPoints(line &a);
void swapSegment(line &a, line &b);
bool match(line &a, line &b);

int main()
{
    line segment[4];
    // Line segment 0
    segment[0].p1.x = 1;
    segment[0].p1.y = 1;
    segment[0].p2.x = 1;
    segment[0].p2.y = 2;
    // Line segment 1
    segment[1].p1.x = 1;
    segment[1].p1.y = 2;
    segment[1].p2.x = 2;
    segment[1].p2.y = 2;
    // Line segment 2
    segment[2].p1.x = 2;
    segment[2].p1.y = 2;
    segment[2].p2.x = 2;
    segment[2].p2.y = 1;
    // Line segment 3
    segment[3].p1.x = 2;
    segment[3].p1.y = 1;
    segment[3].p2.x = 1;
    segment[3].p2.y = 1;

    // bool result = isEqualLength(segment);
    bool result = isLinked(segment);
    printSegments(segment);
    bool result2 = isRightAngleJoined(segment);
    return 0;
};

bool isEqualLength(line seg[4])
{
    /* A square has equal line lengths */
    for (int i = 0; i < 4; i++)
    {
        cout << distance(seg[i]) << endl;
    }
    return 0;
};
bool isLinked(line seg[4])
{
    swapSegment(seg[3], seg[1]);
    swapSegment(seg[2], seg[3]);
    swapPoints(seg[3]);
    swapPoints(seg[0]);

    int currentIndex = 0;
    while (currentIndex < 3)
    {
        cout << "Current index: " << currentIndex << endl;
        bool matchFound = false;
        // Check if there are any matches between the remaining segments
        for (int i = currentIndex + 1; i <= 3; i++)
        {
            cout << "Checking for matches with " << currentIndex << " and " << i << endl;
            matchFound = match(seg[currentIndex], seg[i]);
            if (matchFound)
            {
                // Swap the segment so it's next to the current index segment
                // (Unless it's already next to the current index)
                if (i != currentIndex + 1)
                {
                    cout << "Swapping with segment next to current index" << endl;
                    swapSegment(seg[currentIndex + 1], seg[i]);
                }
                break;
            }
        };
        // If no matches were found, we can conclude that it's not a square.
        if (matchFound == false)
        {
            cout << "Not a square. (Lines are not linked.)" << endl;
            exit(1);
        }
        currentIndex++;
    }
    cout << "Lines linked!" << endl;
    printSegments(seg);
    return true;
};
bool isRightAngleJoined(line seg[4])
{
    line lin1 = seg[0];
    line lin2 = seg[1];
    float grad1 = abs((lin1.p2.y - lin1.p1.y) * (lin2.p2.x - lin2.p1.x));
    float grad2 = abs((lin2.p2.y - lin2.p1.y) * (lin1.p2.x - lin1.p1.x));
    cout << "Line 1 grad: " << grad1 << endl;
    cout << "Line 2 grad: " << grad2 << endl;
    float angle = atan((grad1 - grad2) / (1 + (grad1 * grad2)));
    float angle_deg = angle * 180 / PI;
    cout << "Angle: " << angle_deg << endl;
    return 0;
};

float distance(line a)
{
    // Using 'd^2' instead of 'd' so we can avoid doing the squareroot
    return pow((a.p2.x - a.p1.x), 2) + pow((a.p2.y - a.p1.y), 2);
};

void printSegments(line seg[4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "segment " << i << ": ";
        cout << "p1: "
             << "[(" << seg[i].p1.x << "," << seg[i].p1.y << "), ";
        cout << "p2: "
             << "(" << seg[i].p2.x << "," << seg[i].p2.y << ")]" << endl;
    }
    cout << "-----------" << endl;
};

void swapPoints(line &a)
{
    swap(a.p1, a.p2);
};

void swapSegment(line &a, line &b)
{
    swap(a, b);
}

bool match(line &a, line &b)
{
    if (a.p2.x == b.p1.x && a.p2.y == b.p1.y)
    {
        cout << "Point 1 of the lines match!" << endl;
        return true;
    }
    else if (a.p2.x == b.p2.x && a.p2.y == b.p2.y)
    {
        cout << "Point 2 of the lines match!" << endl;
        cout << "(swap line B's points)" << endl;
        swapPoints(b);
        return true;
    }
    else
    {
        cout << "Lines did not match" << endl;
        cout << "point A (" << a.p2.x << "," << a.p2.y << ") !=" << endl;
        cout << "point B [(" << b.p1.x << "," << b.p1.y << ") or (" << b.p2.x << "," << b.p2.y << ")]" << endl;
    }
    return false;
}