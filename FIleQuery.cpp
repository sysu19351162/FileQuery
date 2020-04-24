#include<iterator>
#include<string>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include"FileQuery.h"

using namespace std;

FileQuery::FileQuery(string filename):filename_(filename)
{
	fstream infile(filename_);

	stringstream s;

	s << infile.rdbuf();

	string text;

	while (getline(s, text))			// for each line in the file
	{
		sentences_.push_back(text);		// remember this line of text

		int n = sentences_.size() - 1;		// the current line number

		istringstream line(text);			// separate the line into words

		string word;

		while (line >> word)				// for each word in that line
		{       
			word = cleanup_str(word);		// if word isn't already in wm, subscripting adds a new entry
			
			auto& lines = wm_[word];			// lines is a pointer 

			if (!lines)						// that pointer is null the first time we see word
				lines = new set<line_no>;	// allocate a new set

			lines->insert(n);				// insert this line number
		}
	}
}


FileQuery::FileQuery(FileQuery& a):sentences_(a.sentences_),wm_(a.wm_),filename_(a.filename_){}


FileQuery::~FileQuery()
{
	for (auto item : wm_)
	{
		delete item.second;  //set<line_no> *
	}
}


string FileQuery::cleanup_str(const string& word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it) {
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}



void FileQuery::PrintSentencesOrdered()
{
	vector<string> sentencesInOrder;

	sentencesInOrder = sentences_;

	
	for (int i = 0; i < sentencesInOrder.end() - sentencesInOrder.begin();i++)				//sort the sentences
	{
		for (int j=0; j < sentencesInOrder.end() - sentencesInOrder.begin()- i - 1; j++)
		{
			if (sentencesInOrder[j] < sentencesInOrder[j+1])
			{
				string s;
				s = sentencesInOrder[j];
				sentencesInOrder[j] = sentencesInOrder[j + 1];
				sentencesInOrder[j + 1] = s;
			}
		}
	}

	vector<string>::iterator it;

	for (it = sentencesInOrder.begin(); it != sentencesInOrder.end(); it++)//print
		cout << *it<<endl;

}


void FileQuery::PrintSentencesFiltered(const string& str)
{
	vector<string> sentencesFiltered;

	for (auto i : sentences_)									//filter the sentences
	{
		for (auto j : i)
		{
			for (int k = 0; k < (int)str.size() ; k++)
			{
				if (*(&j + k) != str[k])
					break;
				if (k == (int)str.size() - 1)  
					sentencesFiltered.push_back(i);
			}
		}
	}
	for (auto i : sentencesFiltered)
		cout << i << endl;
}


void FileQuery::PrintWordCount()
{

	for (auto i: wm_)																//读取次数
	{
		cout << i.first << " occurs " << (*(i.second)).size() << " times " << endl;
	}

}


void FileQuery::ReplaceWord(const std::string& old_word, const std::string& new_word)
{
	fstream file_old{ "file_old.txt"};

	fstream file{ filename_ };

	stringstream ss;

	ss << file.rdbuf();

	file_old << ss.rdbuf();

	file.close();

	string text=ss.str();

	string seperator = " ,;()";

	string::size_type wordstartpos = text.find_first_not_of(seperator);

		int flag = 0;

	while (wordstartpos != string::npos)//找到目标单词进行更改
	{
		string::size_type wordendpos = text.find_first_of(seperator, wordstartpos);

		string word(text, wordstartpos, wordendpos - wordstartpos);

		if (isalpha(word[0]))
		{
			if (word == old_word)
				text.replace(wordstartpos, wordendpos - wordstartpos, new_word);
			flag = 1;
		}

		wordstartpos = text.find_first_not_of(seperator, wordendpos);
	}

	if(flag==0)cout << "no such word" << endl;

	fstream file_new{ filename_ ,ofstream::out};

	file_new << text;

	file_old.close();
	file_new.close();

	//*this = FileQuery(filename_);
}