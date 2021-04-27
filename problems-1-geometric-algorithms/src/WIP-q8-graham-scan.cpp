/*
8. In C++ implement the Graham Scan algorithm for finding the convex hull of a set of 
points.
*/
#include <iostream>
#include <cmath>
using namespace std;
#define PI (2 * acos(0.0))
#define noOfPoints 9 // Number of points being used

struct point
{
    float x, y;
    float angle = 0;
};

int ccw(point, point, point);
void findBottomPoint(point[noOfPoints]);
float calculateAngle(point, point);
void sortByAngle(point[noOfPoints]);
int compare(const void *, const void *);

int main()
{
    // Initialise Points
    point points[noOfPoints];
    points[0].x = 1;
    points[0].y = 4;
    points[1].x = 1;
    points[1].y = 2;
    points[2].x = 2;
    points[2].y = 3;
    points[3].x = 2;
    points[3].y = 2;
    points[4].x = 2;
    points[4].y = 1;
    points[5].x = 3;
    points[5].y = 5;
    points[6].x = 3;
    points[6].y = 3;
    points[7].x = 3;
    points[7].y = 1;
    points[8].x = 4;
    points[8].y = 3;

    findBottomPoint(points);
    sortByAngle(points);

    for (int i = 0; i < noOfPoints; i++)
    {
        cout << "Point (" << points[i].x << "," << points[i].y << ") has angle: " << points[i].angle << endl;
    }
}

void findBottomPoint(point ps[noOfPoints])
/* 
Find the bottom most point and swap it with point at index 0.
(It dosen't really matter, but if two points have the same y it will just pick one of them.)
*/
{
    int bottomPointIndex = 0;
    for (int i = 1; i < noOfPoints; i++)
    {
        if (ps[i].y < ps[bottomPointIndex].y)
        {
            bottomPointIndex = i;
        }
    }
    swap(ps[bottomPointIndex], ps[0]);
}

/* Sort the points based on their angle to the bottom point*/
void sortByAngle(point ps[noOfPoints])
{
    for (int i = 1; i < noOfPoints; i++)
    {
        cout << "ITERATION: " << i << endl;
        ps[i].angle = calculateAngle(ps[0], ps[i]);
    }
    // BUG: Tiny bug... if there are angles equal to our bottom point,
    // the algorithm may put them at index 0. I don't think this will cause
    // issues, but the inconsistency is annoying.
    qsort(ps, noOfPoints, sizeof(point), compare);
}

/* Check for counterclockwise turns */
int ccw(point a, point b, point c)
{
    float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area < 0)
        return -1; // clockwise
    if (area > 0)
        return 1; // counterclockwise
    return 0;     // collinear
}

/* Calculate angle between two points */
float calculateAngle(point a, point b)
{
    // NOTE: The way this calculates angles is groovy
    // center point is at 0' anything to its left becomes negative.
    // so it's basically from the range -90 -> 0 -> 90+
    // thus, we will be looking for the largest angle value
    float deltaX = b.x - a.x;
    float deltaY = b.y - a.y;
    float angle = atan2(deltaX, deltaY);
    float angle_deg = ((angle * 180) / PI);
    cout << "Degree between (" << a.x << "," << a.y << ") and (" << b.x << "," << b.y << "): ";
    cout << angle_deg << endl;
    // We return 90 minus the angle because of the groovy calculating. This makes it normal.
    return 90 - angle_deg;
}

/* Compare method for qsort */
int compare(const void *a, const void *b)
{
    const point *pointA = (point *)a;
    const point *pointB = (point *)b;

    if (pointA->angle > pointB->angle)
    {
        return 1;
    }
    else if (pointA->angle < pointB->angle)
    {
        return -1;
    }
    return 0;
};