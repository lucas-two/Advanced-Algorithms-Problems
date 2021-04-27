### Graham Scan Algorithm

- Pick the `bottom most point` (on y axis).
- Find the **angles** between the `bottom most point` and each `point` (relative to the bottom most point's horizontal line).
- **Sort** each `point` based on its angle (lowest -> highest). This should be between 0 and 180 degrees.
- **Loop** over the sorted points.

  - **Push current point to stack** if it makes a CCW (counterclockwise) turn to the next point.
  - **Pop previous point off stack** if the current point does not make a CCW turn to the next point.

[Helpful video explaining the algorithm](https://youtu.be/B2AJoQSZf4M)

Points being used in Q8:
![Q8 Points Used](imgs/q8_points.JPEG)
