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

#define MAXNAMELEN 1000
#define MAXLINELEN 5000
#define MAXITEMS 100000

char* str[MAXITEMS];
char* q_str[MAXITEMS];
char* linesptr[MAXITEMS];
char* q_linesptr[MAXITEMS];

int
compare_function(const void *name1, const void *name2)
{
    const char *name1_ = *(const char **)name1;
    const char *name2_ = *(const char **)name2;
    return strcmp(name1_, name2_);
}

void
custom_sort (char* str[], int num) 
{
    int round, r, i;
    for (round = 0; round < num; round++) {
        for (i = 0; i < num-1; i++) {
                r = strcmp(str[i], str[i+1]);
                if (r > 0) {
                        char* s = malloc(sizeof(char*));
                        s = str[i];
                        str[i] = str[i+1];
                        str[i+1] = s;
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
        // condition to check if input_variable is a file or not
	char* p;
        p = strchr (input_variable,'.');
        printf("%d",(p - input_variable + 1));

	/*When you read from standard input */
        if ((strcmp(input_variable,"-") == 0) || (strcmp(input_variable,"stdin") == 0)) {
                struct timeval tv1, tv2;
		char name[MAXNAMELEN];
    		char line[MAXLINELEN];
    		int i, items = 0;

		while (fgets(line, MAXLINELEN, stdin)) {
    			int length = strlen(line);
    			line[length-1] = '\0';
    			char *linecopy = malloc(length);
    			strcpy(linecopy, line);
    			str[items] = linecopy;
			q_str[items] = linecopy;
    			items++;
	    	 }
    
		//my sort method
                double start_time = gettimeofday(&tv1, NULL);
                custom_sort(str,items);
                double end_time = gettimeofday(&tv2, NULL);
               
                
                for (i = 0; i < items; i++) {
                        printf("The %d string with my sorting routine  is : %s \n", i+1, str[i]);
                }
                printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
		struct timeval qtv1, qtv2;

		//using qsort() method

		double q_start_time = gettimeofday(&qtv1, NULL);
                qsort(q_str, items, sizeof(char *), compare_function);
                double q_end_time = gettimeofday(&qtv2, NULL);


                for (i = 0; i < items; i++) {
                        printf("The %d string with my qsort method is is : %s \n", i+1, q_str[i]);
                }
                printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec)); 
		
        }
        
   //When the input argument is a file
     else if (p>0) {
	    FILE * infile, * outfile;
	    struct timeval tv1, tv2;
	    struct timeval qtv1, qtv2;
	    char lines[MAXLINELEN];

	    int i, items = 0;

	    infile = fopen(input_variable, "r");
	    while (fgets(lines, MAXLINELEN, infile)) {
	        int length = strlen(lines);
	        lines[length-1] = '\0';
	        char *linecopy = malloc(length);
	        strcpy(linecopy, lines);
	        linesptr[items] = linecopy;
		q_linesptr[items] = linecopy;
	        items++;
     	    }

	    double start_time = gettimeofday(&tv1, NULL);
            custom_sort(linesptr,items);
            double end_time = gettimeofday(&tv2, NULL);	    

	    printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));


	    double q_start_time = gettimeofday(&qtv1, NULL);
	    qsort(q_linesptr, items, sizeof(char *), compare_function);
	    double q_end_time = gettimeofday(&qtv2, NULL);

	    printf ("Total time to read, sort and display from standard input using qsort() method = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec));

	    outfile = fopen(output_variable, "w");
	    for (i=0; i<items; i++) {
	        fprintf(outfile, "%s\n", linesptr[i]);
	    }

	    fclose(infile);
	    fclose(outfile);
	}

// output_vraiable implementation.. where to write.. stdin or fileoutput.	
        return 0;
}

