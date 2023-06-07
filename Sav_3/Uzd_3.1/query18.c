#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Student {
    char data[30];
    char surdata[30];
    int course;                 // year of study
    double average;             // average grade

    int load;                   // number of courses
    char courses[10][30];       // course datas
    int grades[10];             // course grades

    char languages[100];        // spoken languages

} Student;

struct LinkedList {
    char data[30];
    int occurances;
    int id;
    struct LinkedList* next;
};

int count = 0;

struct LinkedList* Add(struct LinkedList* node, char* data, int id) {
    node->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    strcpy(node->next->data, data);
    node->next->occurances = 1;
    node->next->id = id;
    node->next->next = NULL;
    return node;
}

struct LinkedList* CheckPresence(struct LinkedList* node, char* data, int id) {  
    if (strcmp(data, node->data) == 0) {
        ++(node->occurances);
        return node;
    }
    if (node->next) {
        node->next = CheckPresence(node->next, data, id);
        return node;
    } else {
        return Add(node, data, id);
    }
}

int main(int argc, char *argv[]) {
    FILE *db = NULL;
    // open database file for reading, provide a parameter or use default "db.bin"
    if (argc > 1)
        db = fopen(argv[1], "rb");
    else
        db = fopen("db.bin", "rb");

    if (db) {
        Student students[1000];         // all the data goes here
        int size = 0;                   // how many students in database

        // reading data from file
        fread(&size, sizeof(int), 1, db);

        for (int i = 0; i < size; i++){
            fread(&students[i], sizeof(Student), 1, db);
        }
        printf("%d records loaded succesfully\n", size);

        // MODIFY CODE BELOW

        struct LinkedList* names = (struct LinkedList*) malloc(sizeof(struct LinkedList));
        strcpy(names->data, students[0].data);
        names->occurances = 1;
        names->id = 0;
        names->next = NULL;

        struct LinkedList* surnames = (struct LinkedList*) malloc(sizeof(struct LinkedList));
        strcpy(surnames->data, students[0].surdata);
        surnames->occurances = 1;
        surnames->id = 0;
        surnames->next = NULL;

        for (int i = 1; i < size; ++i){ 
            Student s = students[i]; 

            names = CheckPresence(names, students[i].data, i);
            surnames = CheckPresence(surnames, students[i].surdata, i);
        }

        int counterDemo = 0; // for counting students

        while(names != NULL || surnames != NULL) {
            struct LinkedList* node;

            if (names != NULL && surnames != NULL && names->id < surnames->id) {
                node = names;
                names = names->next;
            } else if (names != NULL && surnames != NULL && names->id > surnames->id) {
                node = surnames;
                surnames = surnames->next;
            } else if (names != NULL && surnames != NULL) {
                node = names->occurances <= surnames->occurances ? names : surnames;
                names = names->next;
                surnames = surnames->next;
            } else {
                if (names != NULL) {
                    node = names;
                    names = names->next;
                } else {
                    node = surnames;
                    surnames = surnames->next;
                }
            }
    
            if (node->occurances == 1) {
                Student s = students[node->id];    
                ++counterDemo; 

                printf("%s %s, %dc., avg. %.1f, %d courses", s.data, s.surdata, s.course, s.average, s.load);

                for (int i = 0; i < s.load; ++i) { 
                    printf(", %s %d", s.courses[i], s.grades[i]);
                }
                printf(", languages: %s\n\n", s.languages);
            }
        }  
        
        printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
        fclose(db);
    } else {
        printf("File db.bin not found, check current folder\n");
    }

    return 0;
}
