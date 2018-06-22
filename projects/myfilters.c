/* * myfilter [--action <action>] [--input <filename>] [--output <filename>]
 * * execute default action on standard input, delivering to standard output
 * * ACTION-1: sort
 * * Each line is a record. Records are sorted alphanumerically
 * *
 * * cat myfile.txt | myfilter --action sort > myoutputfile
 * * cat myfile.txt | myfilter --action sort --output myoutputfile
 * * myfilter --input myfile.txt --output myoutputfile --action sort
 * * cat myfile.txt | myfilter --input - --output - --action sort > myoutputfile
 * *
 * * FILE:
 * * hello there
 * * how are you
 * * somewhere over the
 * * rainbow
 * *
 * *
 * * hello there
 * * how are you
 * * rainbow
 * * somewhere over the
 * * 9287578
  */

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>

#define BUFFERSIZE 10000


char**
custom_sort(char str[500][BUFFERSIZE], int num) {
    int round, r, i;
    char s[BUFFERSIZE];
    for (round = 0; round < num; round++) {
        for (i = 0; i < num-1; i++) {
                r = strcmp(str[i], str[i+1]);
                if (r > 0) {
                        strcpy(s,str[i]);
                        strcpy(str[i],str[i+1]);
                        strcpy(str[i+1],s);
                }
        }
    }
}
    
int
main(int argc, char** argv)
{
        int c;
        char* action_variable = "";
        char* input_variable = "";
        char* output_variable = "";
        char str[500][BUFFERSIZE] = {};

        while (1) {
                int option_index = 0;
                static struct option long_options[] = {
                        {"action", required_argument, 0, 'a'},
                        {"input", required_argument, 0, 'i'},
                        {"output", required_argument, 0, 'o'}
                };

                c = getopt_long(argc, argv, "a:i:o:",long_options, &option_index);

                if (c == -1) {
                        break;
                }

                switch (c) {
                        case 'a':
                                action_variable = optarg;
                                printf("action : %s \n", action_variable);
                                break;
                        case 'i':
                                input_variable = optarg;
                                printf("input : %s \n", input_variable);
                                break;
                        case 'o':
                                output_variable = optarg;
                                printf("output : %s \n", output_variable);
                                break;
                        default:
                                fprintf (stderr, "Usage: myfilter --action %s",action_variable);
                                printf ("\n");
                                exit(0);
                }
        }
        
        if ((strcmp(input_variable,"-") == 0) || (strcmp(input_variable,"stdin") == 0)) {
                struct timeval tv1, tv2;
                char name[BUFFERSIZE];
                int num;
                int i;
                printf(" enter the num of strings: ");
                scanf("%d",&num);
                printf ("\nenter the strings : \n");

                for (i = 0; i < num; i++) {
                        fgets(name,BUFFERSIZE,stdin);
                        strcpy(str[i], name);

                }

                double start_time = gettimeofday(&tv1, NULL);
                custom_sort(str,num);
                double end_time = gettimeofday(&tv2, NULL);


                for (i = 0; i < num; i++) {
                        printf("The %d string is : %s \n", i+1, str[i]);
                }
                printf ("Total time = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
        }

        return 0;
}
