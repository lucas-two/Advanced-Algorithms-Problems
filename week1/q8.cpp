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
};

int ccw(point, point, point);
void findBottomPoint(point[]);
float calculateAngle(point, point);
void sortByAngle(point[]);
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
    cout << points[0].x << "," << points[0].y << endl;
    calculateAngle(points[0], points[1]);
    sortByAngle(points);
}

void findBottomPoint(point ps[])
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

void sortByAngle(point ps[])
{
    float angles[noOfPoints];

    angles[0] = 0; // Our origin point
    for (int i = 1; i < noOfPoints; i++)
    {
        cout << "ITERATION: " << i << endl;
        angles[i] = calculateAngle(ps[0], ps[i]);
    }
}

int ccw(point a, point b, point c)
{
    float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area < 0)
        return -1; // clockwise
    if (area > 0)
        return 1; // counterclockwise
    return 0;     // collinear
}

float calculateAngle(point a, point b)
{
    float deltaX = a.x - b.x;
    float deltaY = a.y - b.y;
    float angle = atan2(deltaX, deltaY);
    float angle_deg = ((angle * 180) / PI);
    cout << "Degree between (" << a.x << "," << a.y << ") and (" << b.x << "," << b.y << "): ";
    cout << angle_deg << endl;
    return angle_deg;
}