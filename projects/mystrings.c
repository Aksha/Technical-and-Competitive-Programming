/*
 * Task 004
 * Strings
 *
 * mystrings --action [-a]
 * reverse (reverse the string hello -> olleh)
 * lowercase (HEllo -> hello)
 * uppercase (HEllo -> HELLO)
 * invertcase (HEllo-> heLLO)
 *           --input <string>
 *
 * mystrings --action reverse --input "How is it going"
 *
 * Special type of input:stdin
 * Read string from stdin
 * mystrings --action reverse --input stdin
 * <reads string from stdin>
 *
 * Special type of input:file
 * mystrings --action reverse --input file --filename jjj.txt
 * Iterate through complete file, line by line, applying action
 *
 * For instance:
 * File jjj.txt contains:
 * This is
 * the end
 * of the world
 *
 * The output is:
 * si sihT
 * dne eht
 * dlrow eht fo
 *
 * In case of invalid input:
 * Print out: Usage: mystrings --action <reverse|lowerase|uppercase|invercase> --input <string|stdin|file> [--filename <filename>]
 *
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int
main(int argc, char** argv)
{
        int c;
        char* action_variable = "";
        char* input_variable = "";
        char* file_variable = "";
        while (1) {
                int option_index = 0;
                static struct option long_options[] = {
                        {"action", required_argument, 0, 'a'},
                        {"input", required_argument, 0, 'i'},
                        {"file", required_argument, 0, 'f'}
                };

                c = getopt_long(argc, argv, "a:i:f:",long_options, &option_index);

                if (c == -1) {
                        break;
                }

                switch (c) {
                        case 'a':
                                if (optarg) {
                                        action_variable = optarg;
                                }
                                break;
                        case 'i':
                                if (optarg) {
                                        input_variable = optarg;
                                }
                                break;
                        case 'f':
                                if (optarg) {
                                        file_variable = optarg;
                                }
                                break;
                        default:
                                fprintf (stderr, "Usage: mystrings --action> %s  --input %s",action_variable, input_variable);
                                if (file_variable[0] != '\0') {
                                        fprintf (stderr, "[--filename <%s>]", file_variable);
                                }
                                printf ("\n");
                                exit(0);
                }

        }

        /*ACTION RESPONSE */

        //Function to reverse a string
        char*
        reverse_string (char* input) {
                char temp;
                int i, j, len;
                len = strlen(input) - 1;
                for (i = 0; i < strlen(input)/2; i++)
                {
                        temp = input[i];
                        input[i] = input[len];
                        input[len--] = temp;
                }
                return input;
        }

        //function to convert to uppercase
        char*
        uppercase_string (char* input) {
                int index;
                for (index=0; input[index] != '\0'; index++) {
                        /* Check if character in inputArray is lower Case*/
                        if (islower(input[index])) {
                        /* Convert lower case character to upper case using toupper function */
                                input[index] = toupper(input[index]);
                        }
                        else {
                                input[index] = input[index];
                        }
                }
        }

        //function to convert to lowercase
        char*
        lowercase_string (char* input) {
                int index;
                for (index=0; input[index] != '\0'; index++) {
                        /* Check if character in inputArray is lower Case*/
                        if (isupper(input[index])) {
                        /* Convert lower case character to upper case using toupper function */
                                input[index] = tolower(input[index]);
                        }
                        else {
                                input[index] = input[index];
                        }
                }
        }
        
        //function to invert case
        char*
        invertcase_string (char* input) {
                int index;
                for (index=0; input[index] != '\0'; index++) {
                        /* Check if character in inputArray is lower Case*/
                        if (islower(input[index])) {
                        /* Convert lower case character to upper case using toupper function */
                                input[index] = toupper(input[index]);
                        }
                        else if (isupper(input[index])) {
                                input[index] = tolower(input[index]);
                        }
                }
        }

        switch (action_variable) {
                case "reverse":
                        int result_file;
                        int result_stdin;
                        result_file = strcmp(action_variable,"file");
                        result_file = strcmp(action_variable,"stdin");
                        if(result_file == 0) {

                        }
                        else if (result_stdin == 0) {
                                char Str[] = "";
                                printf ("Enter the message to %s :",action_variable);
                                scanf ("%s", Str);
                                printf ("the reversed string is : %s", Str);

                        }
                        else {
                                char* input = reverse_string(input_variable);
                                printf ("the reversed string is : %s", input);
                        }
                        break;

                case "uppercase":
                case "lowercase":
                case "invertcase":
                default:
                        fprintf (stderr, "Usage: mystrings --action> %s  --input %s",action_variable, input_variable);
                                if (file_variable[0] != '\0') {
                                        fprintf (stderr, "[--filename <%s>]", file_variable);
                                }
                                printf ("\n");
                                exit(0);
        }
        return 0;
}
