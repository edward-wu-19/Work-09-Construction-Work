#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct class {char name[20]; int students; int id;};
struct class * make_class(char class_name[20], int class_size, int class_id);
void print_class(struct class *s);

int main() {
    struct class *systems;
    systems = make_class("Systems", 30, 5);

    print_class(systems);

    int i;
    srand(time(NULL));
    for (i = 1; i < 8; i++){
        char name[4]= {(char)(65 + rand() % 26), (char)(65 + rand() % 26), (char)(65 + rand() % 26), '\0'};

        struct class *a = make_class(name, rand() % 50, rand() % 1000);
        print_class(a);
    }

    return 0;
}

struct class *make_class(char class_name[20], int class_size, int class_id){
    struct class *n = malloc(sizeof(struct class));
    free(n);
    strcpy(n->name, class_name);
    n->students = class_size;
    n->id = class_id;
    return n;
}

void print_class(struct class *s){
    printf("The %s class (ID: %d) has %d students.\n", s->name, s->id,  s->students);
}