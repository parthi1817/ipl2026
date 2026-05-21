#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function to write array of structures into file
void writeRecords(struct Student s[], int n) {
    FILE *fp;
    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n",
                s[i].roll,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);
}

// Function to store seek positions
void createSeekPositions(long pos[], int n) {
    FILE *fp;
    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    struct Student s;

    for (int i = 0; i < n; i++) {

        // store beginning position of record
        pos[i] = ftell(fp);

        // read one record
        fscanf(fp, "%d %s %f",
               &s.roll,
               s.name,
               &s.marks);
    }

    fclose(fp);
}

// Function to display record using position
void displayRecord(long position) {

    FILE *fp;
    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    struct Student s;

    // move pointer to required position
    fseek(fp, position, SEEK_SET);

    // read record
    fscanf(fp, "%d %s %f",
           &s.roll,
           s.name,
           &s.marks);

    printf("\nRecord Found:\n");
    printf("Roll : %d\n", s.roll);
    printf("Name : %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    fclose(fp);
}

int main() {

    struct Student s[3] = {
        {1, "Arun", 85.5},
        {2, "Bala", 90.0},
        {3, "Charan", 78.2}
    };

    long positions[3];

    // write records
    writeRecords(s, 3);

    // create seek positions
    createSeekPositions(positions, 3);

    printf("Seek Positions:\n");

    for (int i = 0; i < 3; i++) {
        printf("Record %d -> %ld\n", i + 1, positions[i]);
    }

    // display second record
    displayRecord(positions[1]);

    return 0;
}