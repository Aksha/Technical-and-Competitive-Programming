
/*  myfilter [--action <action>] [--input <filename>] [--output <filename>]
 *   * execute default action on standard input, delivering to standard output
 *    * ACTION-1: sort
 *     * Each line is a record. Records are sorted alphanumerically
 *      *
 *       * cat myfile.txt | myfilter --action sort > myoutputfile
 *        * cat myfile.txt | myfilter --action sort --output myoutputfile
 *         *  myfilter --input myfile.txt --output myoutputfile --action sort
 *          *  cat myfile.txt | myfilter --input - --output - --action sort > myoutputfile
 *           * 
 *            * FILE:
 *             * hello there
 *              *  how are you
 *               * somewhere over the
 *                * rainbow
 *                 *
 *                  *
 *                   * hello there
 *                    *how are you
 *                     * rainbow
 *                      *somewhere over the
 *                       *9287578
 *
 * add opt args -s and -f where s refers to separation and f refers to field. 
 * for example when the arg of s = ',' and f = '3' then the corresponding sentences should be sorted alphanumerically based on the third field 
 *                        */

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
#include <map>
#include <iterator>
#include <tr1/unordered_map>

using namespace std::tr1;
using namespace std;

vector <string> str;

void
custom_sort (vector <string> str, int num)
{
    int round, r, i;
    for (round = 0; round < num; round++) {
        for (i = 0; i < num-1; i++) {
                r = str[i].compare(str[i+1]);
                if (r > 0) {
			string s = "";
                        s = str[i];
                        str[i] = str[i+1];
                        str[i+1] = s;
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

int
 main(int argc, char** argv)
{
	int c;
	int items = 0;
	unordered_map<string, vector<string> > output;
	unordered_map<string, vector<string> > custom_output;
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
	
	string name = "";
	char ch = separation_variable[0];
	ifstream myfile;
	myfile.open (input_variable.c_str());
	if (myfile.is_open()) {
		while(getline(myfile,name)) {
			string field = getField(name,ch,field_variable);
			output[field].push_back(name);
			custom_output[field].push_back(name);
			str.push_back(field);		
			items++;
		}
		myfile.close();
	} 
	else {
		cout << "Unable to open file. Enter values in the standard input" << endl;
		while (getline(cin,name)) {
			string field = getField(name,ch,field_variable);
                        output[field].push_back(name);
                        custom_output[field].push_back(name);
                        str.push_back(field);
                        items++;
		}		
	}

	struct timeval tv1, tv2;	
	struct timeval qtv1, qtv2;	
	double start_time = gettimeofday(&tv1, NULL);
	
	vector <string> custom_sort_output;
	//sorting = custom sorting routine
	custom_sort(str,items);
	int strLength = str.size();
	for(int i = 0; i < strLength; i++) {
		if(output.find(str[i]) != output.end()) {
			vector <string> temp = output[str[i]];
			int sz = temp.size();
			for(int j = 0; j < sz; j++) {
				custom_sort_output.push_back(temp[j]);
			}
		}
	}
	double end_time = gettimeofday(&tv2, NULL);

	double q_start_time = gettimeofday(&qtv1, NULL);	
	//sorting using an ordered_map
	map <string,vector<string> > sorted_output(output.begin(), output.end());
	double q_end_time = gettimeofday(&qtv2, NULL);
		printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
		printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec));

	//printing the output
	ofstream outputfile;
	outputfile.open(output_variable.c_str());
	if (outputfile.is_open()) {
		for( map<string, vector<string> >::iterator it = sorted_output.begin(); it != sorted_output.end(); ++it) {
			int length = it->second.size();
			for(int i = 0; i < length; i++) {
				outputfile << it->second[i] << endl;
			}
		}
		outputfile.close();
	}
	else {
		for( map<string,vector<string> >::iterator it = sorted_output.begin(); it != sorted_output.end(); ++it) {
                	int length = it->second.size();
                        for(int i = 0; i < length; i++) {
                                outputfile << it->second[i] << endl;
                        }
		}
	}		
	return 0;	
}


