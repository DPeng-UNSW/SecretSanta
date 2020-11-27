#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RECEIVED 1
#define NOT_RECEIVED -1

int main(int argc, char *argv[]) {
    int count = 0;
    int *received = malloc(sizeof(int) * (argc - 2));
    for(int i = 0; i < argc - 2; i++) {
        received[i] = NOT_RECEIVED;
    }
    int seed = atoi(argv[1]);
    srand(seed);
    int iterations = 0;
    while(count < argc - 2) {
        int draw = (rand() % (argc - 2));
        if((draw != count) && (received[draw] == NOT_RECEIVED)){
           received[draw] = RECEIVED;
           char *Name = malloc(sizeof(char) * 80);
           Name = strcpy(Name, argv[count + 2]);
           strcat(Name, ".txt");
           FILE * file = fopen(Name, "w");
           fprintf(file, "%s", argv[draw + 2]);
           fclose(file);
           count++;
        }
        iterations++;
        if(iterations == 1000) {
            printf("Run it again, Someone is Lonely\n");
            return 0;
        }
    }
    return 0;
}
