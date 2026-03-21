#ifndef STUDENTINFORM_H
#define STUDENTINFORM_H
#include <stdio.h>

typedef struct
{
   char course[16];
   char studentID[8];
   float midtermGrade;
} studentDetails;

typedef struct {
    studentDetails student;
    char studentName[16];
    char phoneNumber[12];
} studentInfo;


void display(studentInfo studentsB[], int size){
   printf("%-9s\t" "%9s\t" "%9s\t" "%9s\t" "%9s\t\n", "Name", "Course", "Midterm Grade", "Student ID", "Phone Number");
   for(int i = 0; i < size; i++){
      printf("%-9s\t", studentsB[i].studentName);
      printf("%9s\t", studentsB[i].student.course);
      printf("%13.2f\t", studentsB[i].student.midtermGrade);
      printf("%10s\t", studentsB[i].student.studentID);
      printf("%12s\t\n", studentsB[i].phoneNumber);
   }
}

void insert(studentInfo studentsB[], int size, studentInfo insertedStudent){
     for (int i = size; i > 0; i--) {
        studentsB[i] = studentsB[i - 1];
    }
   studentsB[0] = insertedStudent;

}

void sortbyGrade(studentInfo studentsB[], int size){
   for (int i = 0; i < size; i++){
      for (int j = 0; j < size - 1 - i; j++){
           if (studentsB[j].student.midtermGrade > studentsB[j+1].student.midtermGrade){
               studentInfo temp = studentsB[j];   
               studentsB[j] = studentsB[j+1];
               studentsB[j+1] = temp;
           }
         
      }
   }
}

#endif 