Lee algorithm
----
 ["Lee algorithm"](https://en.wikipedia.org/wiki/Lee_algorithm)

  Some description to code:

    Wavefront is a list of utmost points, after first iteration wavefront nodes are starting point
    neighbors. Wave pointer traverses all wavefront nodes. If current node has a free neighbor then
    new node added to the head of wavefront list. After all sides of current point are checked,
    current node is deleted from wavefront list, obviously because it does not have any free
    neighbors already. After end of list is reached, new iteration starts from head of list, and so
    on until final point is reached. If final point is not reached and there are no free points,
    it means that there is no path to final point.
  