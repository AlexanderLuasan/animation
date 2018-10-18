#include "xmlparser.h"
#include <string>
#include <fstream>
#include <allegro5/allegro.h>
#include <iostream>
#include <vector>


using namespace std;


xmlfile::xmlfile()
{
}

void xmlfile::setfile(const char * name)
{
	ifstream infile;
	char path[100];
	const char * here = al_get_current_directory();
	const char * filename = name;
	
	strcpy_s(path, 70, here);
	strcat_s(path, 70, "\\");
	strcat_s(path, 70, filename);
	strcat_s(path, 70, ".tmx");
	cout << path << endl;

	infile.open(path);
	if (!infile) {
		cout << "unable to open" << endl;
		system("pause");
		exit(1);
	}
	vector<string> file;
	string line;
	while (getline(infile, line)) {

		while (line[0] == ' ') {
			line = line.substr(1, line.size() - 1);
		}
		while ((line[line.size()] == ' ') | (line[line.size()] == '\n')) {
			line = line.substr(1, line.size() - 1);
		}

		file.push_back(line);
	}
	file.erase(file.begin());
	content = xmltag(file);

}







void xmlfile::tagprint()
{

}

xmltag xmlfile::nav()
{
	return content;
}

xmltag::xmltag()
{
}

xmltag::xmltag(vector<string> data)
{
	//cout << data[0] << endl;
	leadingline = data[0];
	tagtype = leadingline.substr(1,leadingline.find(" ")-1);
	//cout << tagtype << endl;

	content["name"] = tagtype;
	content["id"] = "";
	while (true) {
		int pair = leadingline.find("=");
		if (pair != string::npos) {
			int loc1 = pair;
			int loc2 = pair;
			while (leadingline[loc1] != ' ') {
				loc1--;
			}
			while (((leadingline[loc2] != ' ') && (leadingline[loc2] != '>') && (leadingline[loc2] != '/'))&(loc2 < leadingline.length())) {
				loc2++;
			}
			content[leadingline.substr(loc1 + 1, pair - loc1 - 1)] = leadingline.substr(pair + 2, loc2 - pair - 3);
			ckeys.push_back(leadingline.substr(loc1 + 1, pair - loc1 - 1));
			leadingline = leadingline.substr(pair + 1, leadingline.size() - (pair + 1));
		}
		else {
			break;
		}
	}
	content["name"] += content["id"];
	/*
	for (int i = 0; i < ckeys.size(); i++) {
		cout << ckeys[i] << "=>" << content[ckeys[i]] << endl;
	}
	*/
	int indents = 0;
	int index = 0;
	while (true) {

		if ((data[index].find(tagtype) != string::npos) && (data[index].find("/") != string::npos)) {
			if (indents < 2) {
				break;
			}
		}
		else if (data[index].find(tagtype)!=string::npos) {
			indents += 1;
		}

		if ((data[index][0] == '<')&(index!=0)) {
			vector<string> newdata;
			for (int i = index; i < data.size(); i++) {
				newdata.push_back(data[i]);
			}
			xmltag newtag(newdata);
			keys.push_back(newtag.getname());
			values.push_back(newtag);
			index += newtag.getendindex();
		}
		if (index >= data.size()-1) {
			break;
		}
		raw = raw + string(data[index]);

		index += 1;
	}
	endindex = index;



}
/*
	bool base = false;
	//setfirst line to my name
	int blade = data.find(">");
	string tagline = data.substr(0, blade + 1);
	leadingline = tagline;
	blade = tagline.find(" ");
	string tagtype = "</" + name + ">";
	//remove open and close of my tag
	string cutdata;
	if (data.find(tagtype) != string::npos) {
		cutdata = data.substr(data.find(">") + 2, data.find(tagtype) - (data.find(">") + 2));
	}
	else {
		cutdata = data;
		base = true;
	}

	content["name"] = tagline.substr(0 + 1, blade - 1);
	cout << content["name"] << endl;
	while (true) {
		int pair = leadingline.find("=");
		if (pair != string::npos) {
			int loc1 = pair;
			int loc2 = pair;
			while (leadingline[loc1] != ' ') {
				loc1--;
			}
			while (((leadingline[loc2] != ' ')&&(leadingline[loc2] != '>'))&(loc2 < leadingline.length())) {
				loc2++;
			}

			content[leadingline.substr(loc1 + 1, pair - loc1 - 1)] = leadingline.substr(pair + 2, loc2 - pair -3);

			leadingline = leadingline.substr(pair+1,leadingline.size()-(pair+1));

			
		}
		else {
			break;
		}
	}
	cout << content["name"] << endl;



	//find next tag create xml object is no more tags save base data and end
	int index = 0;
	while (true&!base) {
		blade = cutdata.find(">");
		if (blade != string::npos) {
			tagline = cutdata.substr(0, blade + 1);
			while (true) {
				if ((tagline[0] == ' ') | (tagline[0] == '\n')) {
					tagline = tagline.substr(1, tagline.size() - 1);
				}
				else {
					break;
				}
			}
			blade = tagline.find(" ");
			tagtype = "</" + tagline.substr(0 + 1, blade - 1) + ">";

			blade = cutdata.find(tagtype);


			if (blade != string::npos) {
				xmltag newtag(cutdata.substr(0, cutdata.find(tagtype) + tagtype.size()));
				values.push_back(newtag);
				keys.push_back(newtag.getname());
				cutdata = cutdata.substr(cutdata.find(tagtype) + tagtype.size(), cutdata.size() - cutdata.find(tagtype) - tagtype.size());
			}
			else {
				xmltag newtag(cutdata);
				values.push_back(newtag);
				keys.push_back(newtag.getname());
				cutdata = "                 ";
			}
			//makenewtag
			leftover = cutdata;
			cout << this->getname() << leftover << endl;
			break;
			//get it to tell me its name
			//setup key value relation
		}
	}



	//repeat to end of file




}
*/
string xmltag::getname()
{
	string end = content["name"];
	return end;
}

string xmltag::getleftover()
{
	return raw;
}

xmltag xmltag::get(string name)
{
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i] == name) {
			return values[i];
		}
	}
}

string xmltag::head(string name)
{
	return content[name];
}

void xmltag::options()
{
	for (int i = 0; i < keys.size(); i++) {
		cout << i <<keys[i] << endl;
	}
	for (map<string, string>::iterator it = content.begin(); it != content.end(); ++it)
		cout << it->first << " => " << it->second << '\n';


}

int xmltag::getendindex()
{
	return endindex;
}

vector<string> xmltag::getkeys()
{
	return keys;
}

vector<string> xmltag::getckeys()
{
	return ckeys;
}

void xmltag::nameappend(string add)
{
	content["name"] = content["name"] + add;
}

bool xmltag::inhead(string name)
{
	for (int i = 0; i < ckeys.size(); i++) {
		if (ckeys[i] == name) {
			return true;
		}
	}
	return false;
}

string xmltag::propetiesName()
{
	string end = ",";
	string clean = raw;
	while (clean.find("name=\"") != string::npos) {
		clean = clean.substr(clean.find("name=\"") + 6, clean.size());
		end += clean.substr(0, clean.find("\""));
		end += ",";
		clean = clean.substr(clean.find("\"") + 1, clean.size());
	}

	return end;
}

string xmltag::propetiesValue()
{
	string end = ",";
	string clean = raw;
	while (clean.find("value=\"") != string::npos) {
		clean = clean.substr(clean.find("value=\"") + 7, clean.size());

		end += clean.substr(0, clean.find("\""));
		end += ",";
		clean = clean.substr(clean.find("\"") + 1, clean.size());
	}

	return end;
}

