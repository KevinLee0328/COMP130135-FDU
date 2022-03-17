#include <algorithm>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;						using std::cout;
using std::domain_error;			using std::endl;
using std::string;					using std::max;
using std::vector;					using std::istream;
using std::ostream;					using std::transform;

struct word {
	string str;
	int count;
};
typedef vector<word>::size_type vec_sz;

istream& input(istream& in, word& record){
	in >> record.str;
	record.count = 1;
	return in;
}

ostream& output(ostream& out, const vector<word>& article, const string::size_type& maxlen){
	vec_sz size = article.size();
	out << "number of the words: " << size << endl;
	for(vec_sz i = 0; i < size; ++i){
		if(article[i].count != 0){
			out << article[i].str
		    	 << string(maxlen + 1 - article[i].str.size(), ' ')
		    	 << article[i].count << endl;
		}
	}
	return out;
}

void calculate(vector<word>& article){
	string temp1, temp2; 
	vec_sz size = article.size();
	if (size == 0)
		throw domain_error("No words entered. Please try again!");
	for(vec_sz i = 0; i < size; ++i){
		for(vec_sz j = i + 1; j < size; ++j){
			if(article[j].count == 1){
				temp1 = article[i].str; temp2 = article[j].str;
				transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
				transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
				if(temp1 == temp2){
					++article[i].count; --article[j].count;
				}
			}
		}
	}
}

int main()
{
	vector<word> article;
	word record;
	string::size_type maxlen = 0;
	while(input(cin, record)) {
		maxlen = max(maxlen, record.str.size());
		article.push_back(record);
	}
	try {
		calculate(article);
	} catch (domain_error e) {
		cout << e.what() << endl;
		return 1;
	}
	output(cout, article, maxlen);
	return 0;
}

