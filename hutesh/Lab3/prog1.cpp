#include <bits/stdc++.h>

using namespace std;

bool has_special_char(std::string const &str) {
    return std::find_if(str.begin(), str.end(),
        [](char ch) { return !(isalnum(ch) || ch == '_'); }) != str.end();
}

bool is_number(std::string const &str) {
    return std::find_if(str.begin(), str.end(),
        [](char ch) { return (isdigit(ch) || ch == '.'); }) != str.end();
}

int main()
{
        map< string , pair<int,int> > mp;
        
        //begin code
        mp["begin"].first = 1;
        mp["begin"].second = 0;

        //end code
        mp["end"].first = 2;
        mp["end"].second = 0;

        //if code
        mp["if"].first = 3;
        mp["if"].second = 0;

        //else code
        mp["else"].first = 4;
        mp["else"].second = 0;

        //then code
        mp["then"].first = 5;
        mp["then"].second = 0;

        //== code
        mp["=="].first = 8;
        mp["=="].second = 1;
        
        //!= code
        mp["!="].first = 8;
        mp["!="].second = 2;

        //>= code
        mp[">="].first = 8;
        mp[">="].second = 3;

        //<= code
        mp["<="].first = 8;
        mp["<="].second = 4;

        //< code
        mp["<"].first = 8;
        mp["<"].second = 5;

        //> code
        mp[">"].first = 8;
        mp[">"].second = 6;

		mp["identifier"].first = 6;
        mp["identifier"].second = 0;

		mp["constant"].first = 6;
        mp["constant"].second = 7;

		cout << "\n\n---------------------------------\n\n";

		string s, s1;
        while(cin >> s)
        {
                
                if(s == "begin" or s == "end" or s == "if" or s == "else" or s == "then")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp[s].first << " " << mp[s].second << endl;
                else if(is_number(s))
                        cout << "Detected constant : " << s << endl << "Symbol : " << mp["constant"].first << " " << mp["constant"].second << endl;
                else if(!has_special_char(s))
                        cout << "Detected identifier : " << s << endl << "Symbol : " << mp["identifier"].first << " " << mp["identifier"].second << endl;
                else if(s == "==")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp["=="].first << " " << mp["=="].second << endl;
                else if(s == "!=")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp["!="].first << " " << mp["!="].second << endl;
                else if(s == ">=")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp[">="].first << " " << mp[">="].second << endl;
                else if(s == "<=")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp["<="].first << " " << mp["<="].second << endl;
                else if(s == "<")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp["<"].first << " " << mp["<"].second << endl;
                else if(s == ">")
                        cout << "Detected token : " << s << endl << "Symbol : " << mp[">"].first << " " << mp[">"].second << endl;
                else if(s == "(" or s == ")")
                        continue;
				else
					cout << "Detected error : " << s << endl;
        }
		cout << "\n\n---------------------------------\n\n";
        return 0;
}
