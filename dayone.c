#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char* left_pointer;
    char* right_pointer;
    unsigned long total = 0; 

    /* Checking where the file size is valid*/    
    if (argc != 2){
        printf("Invalid Syntax. Usage: ./dayone input.txt");
        return(1);
    }
    else {
        fp = fopen(argv[1], "r");
        if (fp == NULL){
            printf("Not able to open file");
            return(1);
        }
        while((read = getline(&line, &len, fp)) != -1){
            char number[3];
            left_pointer = &line[0];
            right_pointer = &line[read-2];

             /* Check whether the current character is a number*/
            for (int i = 0; i < read - 1; i++){                
                if (!(*left_pointer >= '0' && *left_pointer <='9')){
                    left_pointer++;
                 }

                if (!(*right_pointer >= '0' && *right_pointer <= '9')){
                    right_pointer--;
                }
            }
            number[0] = *left_pointer;
            number[1] = *right_pointer;
            total = total + atoi(number);
        }
        printf("Total: %lu", total);
        free(line);
        fclose(fp);
        return(0);   
    }
}