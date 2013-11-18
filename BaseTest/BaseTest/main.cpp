#include<cstdio>
#include<cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>

using namespace std;

void ScopeTest() {
	int a = 0;
	{
		int a = 1;
		{
			static int a = 2;
			a++;
			printf("Current a is %d\n", a);
		}
		printf("Current a is %d\n", a);
		int b = 3;
		printf("Current b is %d\n", b);
		{
			a++;
			b++;
		}
		printf("Current b is %d\n", b);
		printf("Current a is %d\n", a);
	}
	printf("Current a is %d\n", a);
}

void StackHeapTest() {
	int a;											// stack
	int* b;											// stack
	char c[] = "StackHeapTest";						// stack
	int *d = (int*) malloc(sizeof(int) * 5);		// heap
	free((void*) d);								// heap
}


vector<string> split(const string& s){
	const std::tr1::regex separator("[\.]|/|(://)");
	const std::tr1::sregex_token_iterator endOfSequence;
	vector<string> result;
	std::tr1::sregex_token_iterator token(s.begin(), s.end(), separator, -1);
	while(token != endOfSequence) 
	{
		result.push_back(*token++);
	}
	return result;
}

int main() {
	/*
	ScopeTest();
	ScopeTest();
	system("pause");
	*/

	string line = "http://msdn.microst.com/en-us/library/vstudio/hh279674.aspx";
	cin >> line;
	//getline(cin,line);
	vector<string> result = split(line);
	for(auto s: result){
		cout<<s<<endl;
	}
	system("pause");
}