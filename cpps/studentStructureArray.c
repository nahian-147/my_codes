#include <stdio.h>

struct Student{
    
    int id;
    float marksInMath;
    float marksInPhysics;
    float marksInChemistry;
    float marksInProgramming;
    float total;
};

int main(){

    struct Student s1 = {1,97.00,95.75,93.5,98.00,0.0};
    struct Student s2 = {2,94.00,85.75,95.5,83.00,0.0};
    struct Student s3 = {3,95.00,95.75,93.5,98.00,0.0};
    struct Student s4 = {4,91.00,98.50,93.5,90.00,0.0};

    struct Student students[4] = {s1,s2,s3,s4};

    float totalMArksInMath = 0;
    float totalMArksInPhysics = 0;
    float totalMArksInChemistry = 0;
    float totalMArksInProgramming = 0;
    float totalMArks = 0;

    for (int i = 0; i < 4; i++){
        students[i].total = students[i].marksInChemistry + students[i].marksInMath + students[i].marksInPhysics + students[i].marksInProgramming;

        totalMArksInMath += students[i].marksInMath;
        totalMArksInPhysics += students[i].marksInPhysics;
        totalMArksInChemistry += students[i].marksInChemistry;
        totalMArksInProgramming += students[i].marksInProgramming;
        totalMArks += students[i].total;
    }

    printf("Total Marks in Math : %f\n",totalMArksInMath);
    printf("Total Marks in Physics : %f\n",totalMArksInPhysics);
    printf("Total Marks in Chemistry : %f\n",totalMArksInChemistry);
    printf("Total Marks in Programming : %f\n",totalMArksInProgramming);
    printf("Total Marks : %f\n",totalMArks);
        
    return 0;
}