# lem-in
Ant farm. Search of optimal path to exit

Program will receive the data describing the ant farm from the standard output
in the following format:

```
number_of_ants
the_rooms
the_links
```
Example:
```
3         // num of ant
##start   // signals that next line of room will be entrance
1 23 3    // room name/coord x/coord y
2 16 7
3 12 11
#comment  // comment
##end     // signals that next line of room will be exit
4 17 7
1-2       // room connection(room name/room name)
1-3
3-4
2-4
```
Result must be format ```Lx-y Lz-w Lr-o```:
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.
Result example:
```
L1-2 L2-3
L3-2 L1-4 L2-4
L3-4
```
