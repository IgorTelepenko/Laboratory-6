#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;
ifstream file;
ofstream fout;
ofstream fout_test;

void Display_integer(char word[], int n, bool if_it_last, bool was_hundred_before);

void find_integers_from_words(int n_of_numbers);

int main()
{
    fout.open("Res.txt", ios::out | ios::trunc);    
    fout.close();
 
    //file.open("Data2.txt");
    //file.open("Data1.txt");
    file.open("Data.txt");

    int n_of_numbers;
    char n_char;
    file.get(n_char);
    n_of_numbers = n_char-'0';    
    file.close();
    
    find_integers_from_words(n_of_numbers);

    return 0;
}

void Display_integer(char word[], int n, bool if_it_last, bool was_hundred_before)
{
    fout.open("Res.txt", ios::app);
    switch (word[0])
    {
    case 'z':
        fout << "0";
        break;
    case 'o':
        if (was_hundred_before)
            fout << "0";
        fout << "1";
    case 't':
        switch (word[1])
        {
        case 'e':
            fout << "10";
            break;
        case 'w':
            switch (word[2])
            {
            case 'o':
                if (was_hundred_before)
                    fout << "0";
                fout << "2";
                break;
            case 'e':
                switch (word[3])
                {
                case 'l':
                    fout << "12";
                    break;
                case 'n':
                    fout << "2";
                    if (if_it_last)
                        fout << "0";
                    break;
                }
                break;
            }
            break;
        case 'h':
            switch (word[2])
            {
            case 'r':
                if (was_hundred_before)
                    fout << "0";
                fout << "3";
                break;
            case 'i':
                switch (word[5])
                {
                case 'e':
                    fout << "13";
                    break;
                case 'y':
                    fout << "3";
                    if (if_it_last)
                        fout << "0";
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 'f':
        switch (word[1])
        {
        case 'o':
            switch (word[n - 1])
            {
            case 'r':
                if (was_hundred_before)
                    fout << "0";
                fout << "4";
                break;
            case 'n':
                fout << "14";
                break;
            case 'y':
                fout << "4";
                if (if_it_last)
                    fout << "0";
                break;
            }
            break;
        case 'i':
            switch (word[n - 1])
            {
            case 'e':
                if (was_hundred_before)
                    fout << "0";
                fout << "5";
                break;
            case 'n':
                fout << "15";
                break;
            case 'y':
                fout << "5";
                if (if_it_last)
                    fout << "0";
                break;
            }
            break;
        }
        break;
    case 's':
        switch (word[1])
        {
        case 'i':
            switch (word[n - 1])
            {
            case 'x':
                if (was_hundred_before)
                    fout << "0";
                fout << "6";
                break;
            case 'n':
                fout << "16";
                break;
            case 'y':
                fout << "6";
                if (if_it_last)
                    fout << "0";
                break;
            }
            break;
        case 'e':
            switch (n)
            {
            case 5:
                if (was_hundred_before)
                    fout << "0";
                fout << "7";
                break;
            case 9:
                fout << "17";
                break;
            case 7:
                fout << "7";
                if (if_it_last)
                    fout << "0";
                break;
            }
            break;
        }
        break;
    case 'e':
        switch (word[1])
        {
        case 'l':
            fout << "11";
            break;
        case 'i':
            switch (word[n - 1])
            {
            case 't':
                if (was_hundred_before)
                    fout << "0";
                fout << "8";
                break;
            case 'n':
                fout << "18";
                break;
            case 'y':
                fout << "8";
                if (if_it_last)
                    fout << "0";
                break;
            }
            break;
        }
        break;
    case 'n':
        switch (word[n - 1])
        {
        case 'e':
            if (was_hundred_before)
                fout << "0";
            fout << "9";
            break;
        case 'n':
            fout << "19";
            break;
        case 'y':
            fout << "9";
            if (if_it_last)
                fout << "0";
            break;
        }
        break;
    case 'h':
        if (if_it_last)
            fout << "00";

        break;
    }
    fout.close();
}

void find_integers_from_words(int n_of_numbers)
{
    //file.open("Data2.txt");
    //file.open("Data1.txt");
    file.open("Data.txt");
    int const max_len_of_number_string = 40;
    int const max_len_of_number_word = 10;

    char* line = new char[max_len_of_number_string];
    file.getline(line, max_len_of_number_string);

    for (int i = 0;i < n_of_numbers;i++)
    {
        file.getline(line, max_len_of_number_string);


        int numb_of_words = 1;
        char* word = new char[max_len_of_number_word];
        int word_ind = -1;
        bool help_if_hundred_before = false;
        for (int j = 0;j < strlen(line);j++)
        {
            if (line[j] != 32)
            {
                word_ind++;
                word[word_ind] = line[j];
            }
            else
            {
                Display_integer(word, word_ind + 1, 0, help_if_hundred_before);
                word_ind = -1;
                if (word[0] == 'h')
                    help_if_hundred_before = true;
                else help_if_hundred_before = false;
            }
        }
        Display_integer(word, word_ind + 1, 1, help_if_hundred_before);

        fout.open("Res.txt", ios::app);
        fout << "\n";
        fout.close();
    }
    file.close();
}

