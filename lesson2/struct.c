/*Day 3 Turing clase 2018.
1. Sorting.
2. Structure.
3. Search.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
    int id;
    int score;
} Student;

int main()
{
    Student s;
    s.id = 20181003;
    s.score = 80;
    printf("The guy whose id is %d has score %d.\n", s.id, s.score);

    return 1;

}
