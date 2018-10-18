#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;


class xmltag//a tag of html
{
public:
	xmltag();
	xmltag(vector<string> data); //do not use recurvie formula
	string getname();//get name same as head("name")
	string getleftover(); // any non processdata data
	xmltag get(string name);//move down a tag
	string head(string name); //read data out of a head line
	void options(); //couts things to read
	int getendindex(); // used in recursive function to tells you the number of lines in the tag
	vector<string> getkeys(); //gets keys for other tags
	vector<string> getckeys(); // gets keys for header data
	void nameappend(string add); //used to change the name of the tag
	bool inhead(string name);
	string propetiesName();
	string propetiesValue();
private:
	vector<string> keys;//list of lower tags
	vector<xmltag> values; // path to lower tags
	map<string, string> content; //header data map
	vector<string> ckeys; // list of header data keys
	string leadingline; // used in passing likely grabage
	string tagtype; // what type of tag
	string raw; // leftover data not tag opens or closes
	int endindex; // using in recursive
};


class xmlfile
{
public:
	xmlfile();
	void setfile(const char * name);
	void tagprint();
	xmltag nav();

private:
	const char * name;
	xmltag content;
};
