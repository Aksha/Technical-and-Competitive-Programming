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

using namespace std;

vector <string> str;
vector <string> q_str;
int items = 0;

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

int
 main(int argc, char** argv)
{
	int c;
	string action_variable = "";
	string input_variable = "";
	string output_variable = "";
	
 	while(1) {
		int option_index = 0;
		struct option long_options [] = {
			{"action", required_argument, 0, 'a'},
                        {"input", required_argument, 0, 'i'},
                        {"output", required_argument, 0, 'o'}
		};
	
		c = getopt_long(argc, argv, "a:i:o:",long_options, &option_index);	

		if(c == -1) {
			break;
		}
		
		switch (c) {
			case 'a':
                                action_variable = optarg;
                                cout << "action : \n" << action_variable << endl;
                                break;
                        case 'i':
                                input_variable = optarg;
                                cout << "input : \n" << input_variable << endl;
                                break;
                        case 'o':
                                output_variable = optarg;
                                cout << "output : \n" << output_variable << endl;
                                break;
                        default:
                                cout <<  "Usage: myfilter --action " << action_variable << endl;
                               
                                exit(0);
		}
	}
	
	size_t filefound = input_variable.find('.');

	if ((input_variable == "-") || (input_variable == "stdin")) {
		string name = "";
		while(getline(cin,name)) {
			str.push_back(name);
			q_str.push_back(name);
			items++;
		}
	}

	else if (filefound > 0) {
		string line = "";
		ifstream myfile;
		myfile.open(input_variable.c_str());
		if (myfile.is_open()) {
			while (getline (myfile, line)) {
				str.push_back(line);
				q_str.push_back(line);
				items++;
			}
		myfile.close();
		}	
		else {
			cout << "unable to open file" << endl;
		}	
	}

	else if (input_variable.empty()) {
		string input = "";
		string line = "";
		cout << "please enter the name of the file you wish to read from : " << endl;
		cin >> input;
		ifstream myfile(input.c_str());
		if (myfile.is_open()) {
                        while (getline (myfile, line)) {
                                str.push_back(line);
                                q_str.push_back(line);
				items++;
                        }
                myfile.close();
                }
                else {
                        cout << "unable to open file" << endl;
                }
	}

	if ((action_variable == "sort") || (action_variable.empty())) {
		struct timeval tv1, tv2;	
		struct timeval qtv1, qtv2;	
		double start_time = gettimeofday(&tv1, NULL);
                custom_sort(str,items);
                double end_time = gettimeofday(&tv2, NULL);
		double q_start_time = gettimeofday(&qtv1, NULL);
                sort(q_str.begin(), q_str.end());
		double q_end_time = gettimeofday(&qtv2, NULL);
		printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));
		printf ("Total time to read, sort and display from standard input using my sorting routine = %f seconds\n",(double) (qtv2.tv_usec - qtv1.tv_usec) / 1000000 + (double) (qtv2.tv_sec - qtv1.tv_sec));
	}
	
	size_t filefound_output = output_variable.find('.');

	if((output_variable == "-") || (output_variable == "stdout")){
                for(int i = 0; i < items; i++) {
                	 cout << "The sorted input is" << q_str[i] << endl;
                }
	}
	
	else if ((output_variable == "myoutputfile") || output_variable.empty()) {
		string filename = "";
		cout << "Enter the destination source name " << endl;
		cin >> filename;
		ofstream outputfile;
		outputfile.open(filename.c_str());
		for (int i = 0; i < items; i++) {
			outputfile << q_str[i] << endl;
		}
		outputfile.close();
	}

	else if (filefound_output > 0){
		ofstream outputfile;
                outputfile.open(output_variable.c_str());
                for (int i = 0; i < items; i++) {
                        outputfile << q_str[i] << endl;
                }
                outputfile.close();
	}
	return 0;	
}


