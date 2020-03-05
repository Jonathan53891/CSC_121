#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <array>
#include <cmath>
#include <cctype>

using namespace std;

const size_t size_of_alphabet = 26;

inline void gather_text(istream & source, string & text)
{
    string line;
    source.peek();
    while (!source.eof())
    {
        getline(source, line);
        text += line + '\n';
        source.peek();
    }
    return;
}

inline void count_freqs(const string & text,
                        array<string::size_type, size_of_alphabet> & freqs)
{
    for ( char c : text )
    {
        if ( isalpha(c) )
        {
            freqs[ tolower(c) - static_cast<int>('a') ]++;
        }
    }
    return;
}

inline string::size_type largest(const array<string::size_type, size_of_alphabet> & data)
{
    size_t max_at = 0;
    for ( size_t looking_at = 1; looking_at < data.size(); looking_at++)
    {
        if ( data[looking_at] > data[max_at] )
        {
            max_at = looking_at;
        }
    }
    return data[max_at];
}

inline streamsize int_width(long long num)
{
    short sign = static_cast<short>(num < 0);
    num = abs(num);
    return num == 0 ? 1 : static_cast<streamsize>(sign + floor(log10(static_cast<long double>(num)))+1);
}

inline void disp_freqs(const array<string::size_type, size_of_alphabet> & freqs)
{
    string::size_type max_freq = largest(freqs);
    streamsize freq_width = int_width(max_freq);
    cout << "Letter" + string(5,' ') + "Frequency\n"
            "------" + string(5,' ') + "---------\n";
    for ( size_t p = 0; p != freqs.size(); p++ )
    {
        if ( freqs[p] != 0 )
        {
            cout << "   "
                 << static_cast<char>(p+static_cast<string::size_type>('a'))
                 << ":       ";
            cout.width(freq_width);
            cout << freqs[p] << '\n';
        }
    }
    return;
}

int main(void)
{
    char source;
    string fname, text;
    ifstream text_file;
    array<string::size_type, size_of_alphabet> frequencies = { 0 };

    cout << "Would you like to (E)nter the text or is it in a (F)ile already?\n";
    cin >> source;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (tolower(source) == 'e')
    {
        cout << "\nPlease enter your text, ^D to end:\n\n";
        gather_text(cin, text);
    }
    else
    {
        cout << "\nEnter the name of your file:  ";
        getline(cin, fname);
        text_file.open(fname);
        while ( ! text_file )
        {
            text_file.close();
            text_file.clear();
            cout << "\n\aCould not open '" << fname << "'!\n\n"
                    "Please enter another filename:  ";
            getline(cin, fname);
            text_file.open(fname);
        }
        gather_text(text_file, text);
    }
    if ( ! text.empty() )
    {
        count_freqs(text, frequencies);
        disp_freqs(frequencies);
    }
    else
    {
        cout << "\nNo text entered...good day!\n";
    }
    return 0;
}
