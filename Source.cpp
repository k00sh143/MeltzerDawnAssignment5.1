//BRIAN GARCIA 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


/* Pull both files:
 -Misspelled words
 -Dictionary
 Compare both files and print out misspelled words
 */

bool loadWords(const string& filename, vector<string>& outWords) {
	ifstream in(filename);                                        //open the file for reading
	if (in.fail()) {                                             //checking if opening file fails
		return false;                                            //tell user file failed to open

	}

	string w;                                                //String will hold one WORD at a time
	while (in >> w) {                                        //Add words seperated by newline
		outWords.push_back(w);                              //Add word to the vector

	}
	return true;
}

bool contains(const vector<string>& list, const string& key) {
	for (int i = 0; i < (int)list.size(); i++) {            //visits each word
		if (list[i] == key) {                               //looking for exact match
			return true;                                    //found exact match
		}
	}
		return false;                                      //Not found, After checking all items
}


	bool collectMisspelled(const vector<string>&dictionary, const string & toCheckFile, vector<string>&misspelled) {
		ifstream in(toCheckFile);                         //open file to check
		if (in.fail()) {                                  //check if opening the file failed
			return false;                                 //tell user file failed to open

		}
		
		string w;                                         //one word from the file
		while (in >> w) {                                 //reads each word
			if (!contains(dictionary, w)) {               //if word is not in dictionary.....
				misspelled.push_back(w);                  //save it for later printing
			}
		}
		return true;

}




int main() {
	const string dictionaryFile = "dictionary.txt"; //file of correctly spelled words - dictionary
	const string checkFile = "input.txt";           //file to scan for mispelled words

	vector<string> dictionary;                      //will hold all the dictionary words
	vector<string> misspelled;                      //will hold all the words not matched in the dictionary file

	if (!loadWords(dictionaryFile, dictionary)) {   //attempt to read dictionary
		cout << "Error opening dictionary file \n"; // read error if file doesn't open
		return 1;
	}

	if (!collectMisspelled(dictionary, checkFile, misspelled)) {  //scan
		cout << "Error opening file to check \n";                //read error if file doesn't open
		return 1;

	}
	return 0;
}
