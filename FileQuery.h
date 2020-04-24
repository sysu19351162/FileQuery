#ifndef TEXTQUERY_H
#define TEXTQUERY_H


#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "FileQuery.h"


class QueryResut;
class FileQuery
{
public:

	//= typedef std::vector<std::string>::size_type line_no;
	using line_no = std::vector<std::string>::size_type;

	FileQuery(std::string filename);

	FileQuery(FileQuery& a);

	~FileQuery();

	void PrintSentencesOrdered();

	void PrintSentencesFiltered(const std::string& str);

	void PrintWordCount();

	void ReplaceWord(const std::string& old_word, const std::string& new_word);

private:
	std::vector<std::string>sentences_; // input file

	// maps each word to the set of the lines in which that word appears
	std::map<std::string, std::set<line_no>*> wm_;

	// canonicalizes text: removes punctuation and makes everything lower case
	static std::string cleanup_str(const std::string&);

	std::string filename_;
};
#endif