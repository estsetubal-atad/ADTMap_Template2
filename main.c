#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "list.h"
#include "student.h"

PtList importStudents();

int main() {

    PtList students = importStudents();
    if(students == NULL) return EXIT_FAILURE;

    listPrint(students);
    /* TODO: ADT Map exercise */

    listDestroy(&students);

    return EXIT_SUCCESS;
}

PtList importStudents() {

    PtList list = listCreate();
    if(list == NULL) return NULL;

    FILE* stream = fopen("students.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
   
        char* tmp = strdup(line);
        
        char** tokens = splitString(tmp, 3, ";");
        
        int grade = atoi(tokens[2]);
        Student s = studentCreate(tokens[0], tokens[1], grade);

        int size;
        listSize(list, &size);

        listAdd(list, size,  s);

	    free(tokens);
        free(tmp);
    }

    fclose(stream);

    return list;
}