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
        string field1;
	string field2;
        string sentence;
};

vector <SortNode> str;
vector <SortNode> custom_str;

bool 
field1compare(const SortNode &a, const SortNode &b)
{
    return a.field1 < b.field1;
}

bool 
field2compare(const SortNode &a, const SortNode &b) 
{
	return a.field2 < b.field2;
}

void
custom_sort (int which_variable, int beginning, int end)
{
    int num = custom_str.size();
    int round, r, i;
    for (round = beginning; round < end; round++) {
        for (i = beginning; i < end-1; i++) {
		if (which_variable == 1) {
                	r = custom_str[i].field1.compare(custom_str[i+1].field1);
		}
		else {
			r = custom_str[i].field2.compare(custom_str[i+1].field2);
		}
                if (r > 0) {
                	swap(custom_str[i], custom_str[i+1]);
		}
        }
    }
}

void 
sort_again (int field_variable2) {
	int numItems = str.size();
        int count = 1;
        int track = 0;
        int beg = 0;
	if(field_variable2 != 0) {
                while (track < numItems-1) {
                        while ( (track < numItems - 1) && str[track].field1 ==  str[track+1].field1) {
                                if (count == 1) {
                                        beg = track;
                                }
                                count++;
                                track++;
                        }
                        sort(str.begin() + beg, str.begin() + beg + count, field2compare);
			custom_sort(2,beg,beg + count);
                        count = 1;
                        track++;
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
        return field;
}

void
getInput(char ch, string input, int field_variable1, int field_variable2) 
{
	string name = "";
	ifstream myfile;
	myfile.open(input.c_str());
	if (myfile.is_open()) {
		while (getline (myfile,name)) {
			SortNode snode;
			snode.field1 = getField(name,ch,field_variable1);
			if (field_variable2 != 0) {
				snode.field2 = getField(name,ch,field_variable2);
			}
			else {
				snode.field2 = "";
			}
			snode.sentence = name;
			str.push_back(snode);
			custom_str.push_back(snode);
		} 
		myfile.close();
	}
	else {
		cout << "Not a file or unable to open a file. Enter values in the standard input" << endl;
		while (getline(cin,name)) {
                        SortNode snode;
                        snode.field1 = getField(name,ch,field_variable1);
                        if (field_variable2 != 0) {
                                snode.field2 = getField(name,ch,field_variable2);
                        }
                        else {
                                snode.field2 = "";
                        }
                        snode.sentence = name;
                        str.push_back(snode);
                        custom_str.push_back(snode);
		}
	}
}

void writeOutput (string output) {
	int items = str.size();
	ofstream outputfile;
	outputfile.open(output.c_str());
	if (outputfile.is_open()) { 
		for (int i = 0; i < items; i++) { 
			outputfile << "Field 1: " << custom_str[i].field1 << " Field 2: " << custom_str[i].field2 << " Sentence is :" << custom_str[i].sentence << endl;
		}	
	outputfile.close();   
	}
	else {
		for (int i = 0; i < items; i++) {
                        cout << "Field 1 : " << str[i].field1 << " Field 2: " << str[i].field2 << " Sentence is :" << str[i].sentence << endl;
                }
	}
}

int
main (int argc, char** argv) 
{
	int c;
        string action_variable = "";
        string input_variable = "";
        string output_variable = "";
        string separation_variable = "";
        int field_variable = 0;
	int field_variable2 = 0;
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
				if(argv[optind])
					field_variable2 = atoi(argv[optind++]);
                                cout << "Field variable :" << field_variable << endl;
				cout << "Field variable 2: " << field_variable2 << endl;
                                break;
			default:
				 cout <<  "Usage: myfilter --input arg  --action arg --output arg" << action_variable << endl;
                                exit(0);
		}	
	}
	
	//Get the input in a vector
	char ch = separation_variable[0];
	getInput(ch, input_variable, field_variable, field_variable2);	

	//Sort the input
	struct timeval tv1, tv2;
	//my sorting routine
	double start_time = gettimeofday(&tv1, NULL);
	custom_sort(1, 0, custom_str.size());
	double end_time = gettimeofday(&tv2, NULL);
		
	
	printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));

	//sort method
	struct timeval qtv1, qtv2;
	double q_start_time = gettimeofday(&qtv1, NULL);
	sort(str.begin(), str.end(), field1compare);
	double q_end_time = gettimeofday(&qtv2, NULL);

	//sorting by the second field_variable 
	sort_again(field_variable2);
	printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec));
	
	//Write the output to stdin/file
	writeOutput(output_variable);
	return 0;
}
