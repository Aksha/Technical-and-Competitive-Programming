#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <unistd.h>
#include <sys/time.h>
#include <getopt.h>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

struct SortNode{
        string field;
        string sentence;
};

vector <SortNode> str;
vector <SortNode> custom_str;

int items = 0;

bool 
acompare(const SortNode &a, const SortNode &b)
{
    return a.field < b.field;
}

void
custom_sort (vector <SortNode> str, int num)
{
    int round, r, i;
    for (round = 0; round < num; round++) {
        for (i = 0; i < num-1; i++) {
                r = str[i].field.compare(str[i+1].field);
                if (r > 0) {
                	swap(str[i], str[i+1]);
		}
        }
    }
}


string
getField (string input_str, char ch, int fieldNum)
{
        istringstream ss(input_str);
        string temp;
        string field;
        int count = 0;
        vector <string> input;
        while(getline(ss,temp,ch)) {
                if(count < fieldNum) {
                        input.push_back(temp);
                        count++;
                }
        }
        field = input.back();
        //cout << "Hey this is the field : " << field << endl;
           return field;
}

void
getInput(char ch, string input, int field_variable) 
{
	string name = "";
	ifstream myfile;
	myfile.open(input.c_str());
	if (myfile.is_open()) {
		while (getline (myfile,name)) {
			SortNode snode;
			snode.field = getField(name,ch,field_variable);
			snode.sentence = name;
			str.push_back(snode);
			custom_str.push_back(snode);
			//cout << "testing " << str.back().field << " sentence : " << str.back().sentence << endl;
			items++;
		}
		myfile.close();
	}
	else {
		cout << "Not a file or unable to open a file. Enter values in the standard input" << endl;
		while (getline(cin,name)) {
			SortNode snode;
			snode.field = getField (name, ch, field_variable);
			snode.sentence = name;
			str.push_back(snode);
			items++;
		}
	}
}

void writeOutput (string output) {
	ofstream outputfile;
	outputfile.open(output.c_str());
	if (outputfile.is_open()) { 
		for (int i = 0; i < items; i++) { 
			outputfile << "The selected field is : " << str[i].field << " Sentence is :" << str[i].sentence << endl;
		}	
	outputfile.close();   
	}
	else {
		for (int i = 0; i < items; i++) {
                        cout << "The selected field is : " << str[i].field << " Sentence is :" << str[i].sentence << endl;
                }
	}
}

int
main (int argc, char** argv) 
{
	int c;
        int items = 0;
        string action_variable = "";
        string input_variable = "";
        string output_variable = "";
        string separation_variable = "";
        int field_variable = 0;
        while(1) {
                int option_index = 0;
                struct option long_options[] = {
                        {"action", required_argument, 0, 'a'},
                        {"input", required_argument, 0, 'i'},
                        {"output", required_argument, 0, 'o'},
                        {"separator", required_argument, 0, 's'},
                        {"field", required_argument, 0, 'f'},
                };

                c = getopt_long(argc, argv, "a:i:o:s:f:",long_options, &option_index);

                if (c == -1) {
                        break;
                }

                switch (c) {
                        case 'a':
                                action_variable = optarg;
                                cout << "action :" << action_variable << endl;
                                break;
                        case 'i':
                                input_variable = optarg;
                                cout << "input :" << input_variable << endl;
                                break;
                        case 'o':
                                output_variable = optarg;
                                cout << "output :" << output_variable << endl;
                                break;
                        case 's':
                                separation_variable = optarg;
                                cout << "Separation variable :" << separation_variable << endl;
                                break;
                        case 'f':
                                field_variable = atoi(optarg);
                                cout << "Field variable :" << field_variable << endl;
                                break;
			default:
				 cout <<  "Usage: myfilter --input arg  --action arg --output arg" << action_variable << endl;
                                exit(0);
		}	
	}
	
	//Get the input in a vector
	char ch = separation_variable[0];
	getInput(ch, input_variable, field_variable);	


	//Sort the input
	struct timeval tv1, tv2;

	//my sorting routine
	double start_time = gettimeofday(&tv1, NULL);
	custom_sort(custom_str,items);
	double end_time = gettimeofday(&tv2, NULL);

	printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
	
	//sort method
	struct timeval qtv1, qtv2;
	double q_start_time = gettimeofday(&qtv1, NULL);
	sort(str.begin(), str.end(), acompare);
	double q_end_time = gettimeofday(&qtv2, NULL);
	printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec));
	

	//Write the output to stdin/file
	writeOutput(output_variable);
	return 0;
}
