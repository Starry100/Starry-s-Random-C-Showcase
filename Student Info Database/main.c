#include <stdio.h>
#include <string.h>
#include "studentInfo.c"


int main()
{   
   studentInfo student1 = {{"Math", "ab12", 3.0},"James", "01001"};
   studentInfo student2 = {{"English", "zb3a", 2.0},"Charles", "0354"};
   studentInfo student3 = {{"Science", "vm0d", 5.0},"Justin", "2254"};
   studentInfo student4 = {{"Chemistry", "lb43", 1.0},"Lucas", "01001"};

    
   studentInfo studentsA[6] = {student1, student2, student3, student4};

   studentInfo student5 = {{"Science", "ab33", 4.0}, "Audrey", "12023"};
   insert(studentsA, sizeof(studentsA)/sizeof(studentsA[0]), student5);

   studentInfo student6 = {{"Science", "ab33", 2.0}, "Budrey", "1493"};
   insert(studentsA, sizeof(studentsA)/sizeof(studentsA[0]), student6);
   
   sortbyGrade(studentsA, sizeof(studentsA)/sizeof(studentsA[0]));

   display(studentsA, sizeof(studentsA)/sizeof(studentsA[0]));
   
   


   return 0;
}