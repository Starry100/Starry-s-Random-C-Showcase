#ifndef STUDENTINFORM_H
#define STUDENTINFORM_H
#include <stdio.h>
// This file contains all the functions needed for main.


typedef struct
{
   // Stores the student's course, ID number, their midterm Grade, and final Grade. 
   // The weighted average will not take an input and instead be calculated later on.
   char course[16];
   char studentID[8];
   float midtermGrade;
   float finalGrade;
   float weightedAverage;
} studentDetails;

typedef struct {
   // Stores the student details, their name, and phone number.
    studentDetails student;
    char studentName[16];
    char phoneNumber[12];
} studentInfo;


void display(studentInfo studentsB[], int size){
   // Table header 
   printf("%-9s\t" "%9s\t" "%9s\t" "%9s\t" "%9s\t" "%9s\t" "%9s\t\n", "Name", "Course", "Midterm Grade", "Final Grade", "Weighted Average", "Student ID", "Phone Number");

   // Table row, including all the necessary data.
   for(int i = 0; i < size; i++){
      printf("%-9s\t", studentsB[i].studentName);
      printf("%9s\t", studentsB[i].student.course);
      printf("%13.1f\t", studentsB[i].student.midtermGrade);
      printf("%11.1f\t", studentsB[i].student.finalGrade);
      printf("%16.1f\t", studentsB[i].student.weightedAverage);
      printf("%10s\t", studentsB[i].student.studentID);
      printf("%12s\t\n", studentsB[i].phoneNumber);
   }
}

void finalAverage(studentInfo studentsB[], int size){
   // Calculates for the weighted average of all students.
   for (int i = 0; i < size; i++){
      studentsB[i].student.weightedAverage =  studentsB[i].student.midtermGrade * 0.4 + studentsB[i].student.finalGrade * 0.6;
   }

}

void insert(studentInfo studentsB[], int size, studentInfo insertedStudent){
      // Inserts a new student when space allows.
     for (int i = size; i > 0; i--) {
        studentsB[i] = studentsB[i - 1];
    }
   studentsB[0] = insertedStudent;

}

void sortbyGrade(studentInfo studentsB[], int size){
   for (int i = 0; i < size; i++){
      for (int j = 0; j < size - 1 - i; j++){
           if (studentsB[j].student.weightedAverage < studentsB[j+1].student.weightedAverage){
               studentInfo temp = studentsB[j];   
               studentsB[j] = studentsB[j+1];
               studentsB[j+1] = temp;
           }
         
      }
   }
}

#endif 