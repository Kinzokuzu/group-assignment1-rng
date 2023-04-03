/* Requirements
 * 
 * Given a set of students, S, and a set of groups, G, with 0 to 5 students NOT belonging to S,
 * assigned to each group, randomly assign the students belonging to S to the groups belonging to G so
 * that every student belongs to a group and no group has less than 3 or more than 5 members, and 
 * return a list of students in set S and which group they have been assigned to.
 */

/* Data
 *
 * Students (S)
 *  Fields: • identifier (some integer number from 0 to n, where n is the number of students - 1)
 *          • class section identifier (11 AM or 12 PM)
 *          • group identifier
 *  Structure: array, vector, or similar (It is also possible to seperate S into subsets S1 and S2 so
 *          that each subset only holds students belonging to a particular class section.)
 *
 * Groups (G)
 *  Fields: • identifier (some integer number from 0 to n, where n is the number of groups - 1)
 *          • class section identifier (11 AM for 12 PM)
 *          • number of members assigned to a particular group
 *  Structure: list of key, value pairs (map) (G may also need to be divided into subsets G1 and G2 by
 *          class section.)
 */

/* Algorithm
 * S = current set of students
 * G = current set of groups
 *
 * 1) Draw a random number j from the range 0 to |G|
 * • Let i be the ientifier of the current student (i is initially 0)
 * 2) If gj has less than 5 members:
 *    2a) Assign si to gj
 *    2b) Increment i
 * 3) Else do nothing
 * 4) Return to step 1 while i is less than |S|
 *
 */

/* Declarations/Prototypes
 *
 * Struct Student:
 *  int id
 *  int group 
 *
 * Takes a set of students (s) and a set of groups (g) and assigns each student to a group, ensuring
 * that no group has less than 3 or more than 5 students.
 * void AssignStudents(std::vector<Student> s, unordered_map<int, int> g)
 */

/* Unit Tests
 *
 */
