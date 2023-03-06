/*
    Copyright(c) 2022 Tyler Crockett | Macdaddy4sure.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissionsand
    limitations under the License.
*/

#include "WikipediaParser3.h"

using namespace std;
using namespace filesystem;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string input;
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "============= Main Menu =============" << endl;
        cout << "| 1. Parse Wiki Dumps               |" << endl;
        cout << "| 2. CUDA Processing                |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 0. Settings                       |" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl;
        if (conn)
            cout << "MySQL Connection: True" << endl;
        else
            cout << "MySQL Connection: False" << endl;
        cout << "MySQL Hostname: " << mysql_hostname << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << "MySQL Database: " << mysql_database << endl;
        cout << "MySQL Location: " << mysql_location << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input == "1")
        {
            Parser();
        }
        if (input == "2")
        {
            //CUDA();
        }
        if (input == "0")
        {
            Settings();
        }
    }
}

void Settings()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string input;
    bool boolean = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    while (!boolean)
    {
        system("cls");

        cout << endl;
        cout << "============= Settings ==============" << endl;
        cout << "| 1. Set MySQL Hostname             |" << endl;
        cout << "| 2. Set MySQL Username             |" << endl;
        cout << "| 3. Set MySQL Password             |" << endl;
        cout << "| 4. Set MySQL Database             |" << endl;
        cout << "| 5. Wiki Dump Location             |" << endl;
        cout << "| 6. Clean Tables                   |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 0. Settings                       |" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl;
        if (conn)
            cout << "MySQL Connection: True" << endl;
        else
            cout << "MySQL Connection: False" << endl;
        cout << "MySQL Hostname: " << mysql_hostname << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << "MySQL Database: " << mysql_database << endl;
        cout << "MySQL Location: " << mysql_location << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input == "1")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
                //system("cls");

                cout << "MySQL Hostname: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_hostname = input;
                    boolean2 = true;
                }
            }
        }
        if (input == "2")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
                //system("cls");

                cout << "MySQL Username: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_username = input;
                    boolean2 = true;
                }
            }
        }
        if (input == "3")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
                //system("cls");

                cout << "MySQL Password: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_password = input;
                    boolean2 = true;
                }
            }
        }
        if (input == "4")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
                //system("cls");

                cout << "MySQL Database: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_database = input;
                    boolean2 = true;
                }
            }
        }
        if (input == "5")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
                //system("cls");

                cout << "MySQL Dump Location: ";
                getline(cin, input);

                if (input != "")
                {
                    mysql_location = input;
                    boolean2 = true;
                }
            }
        }
        if (input == "6")
        {
            bool boolean2 = false;

            while (!boolean2)
            {
 /*               system("cls");*/

                cout << "Are you sure?(y/n): ";
                getline(cin, input);

                if (input == "y")
                {
                    //Clean_Tables();
                    boolean2 = true;
                }
                else
                {
                    boolean2 = false;
                }
            }
        }
        if (input == "0")
        {
            boolean = true;
        }
    }
}

void Parser()
{
    string temp_path;
    string temp_path2;
    wstring temp_path3;
    string input;
    string heading;
    string sub_heading;
    string sub_sub_heading;
    string sub_sub_sub_heading;
    string wiki_text;
    long progress = 0;
    bool boolean = false;
    bool bool_heading = false;
    bool bool_sub_heading = false;
    bool bool_sub_sub_heading = false;
    bool bool_sub_sub_sub_heading = false;
    bool next = false;
    bool written = false;

    fstream file;

    // Progress
    long count = CountFiles();
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for (auto& q : directory_iterator(mysql_location.c_str()))
    {
        temp_path3 = q.path().wstring();

        /*_setmode(_fileno(stdout),_O_U16TEXT);*/

        file.open(temp_path3.c_str());

        if (file.is_open())
        {
            bool_heading = false;
            bool_sub_heading = false;
            bool_sub_sub_heading = false;
            bool_sub_sub_sub_heading = false;
            heading = "NULL";
            sub_heading = "NULL";
            sub_sub_heading = "NULL";
            sub_sub_sub_heading = "NULL";
            wiki_text.clear();
            title.clear();

            // Parse the title
            for (int z = temp_path3.length(); z >= 0; z--)
            {
                if (temp_path3[z - 1] == '/')
                {
                    for (int a = z; temp_path3[a] != '.'; a++)
                    {
                        title += temp_path3[a];
                    }
                    break;
                }
            }

            wcout << "TITLE: " << title << endl;
            cout << "Progress: " << progress << "/" << count << endl;

            // Because there is a summary before any of the headings, we need to check if a heading has been found. If the heading has not been found, copy the 
            while (getline(file, input))
            {
                /*cout << input << endl;*/

                for (int x = 0; x <= input.length(); x++)
                {
                    if ((input[x] == '=' && input[x + 1] == '=') && input[x + 2] != '=')
                    {
                        heading.clear();
                        /*cout << "input: " << input << endl;*/

                        for (int y = x + 2; input[y] != '='; y++)
                        {
                            heading += input[y];
                        }

                        /*cout << "heading: " << heading << endl;*/

                        written = true;
                        sub_heading = "NULL";
                        sub_sub_heading = "NULL";
                        sub_sub_sub_heading = "NULL";
                        break;
                    }
                    else if ((input[x] == '=' && input[x + 1] == '=' && input[x + 2] == '=') && input[x + 3] != '=')
                    {
                        sub_heading.clear();

                        /*cout << "input: " << input << endl;*/

                        for (int y = x + 3; y <= input.length(); y++)
                        {
                            if (input[y] != '=')
                            {
                                sub_heading += input[y];
                            }
                        }

                        written = true;
                        /*cout << "sub_heading: " << sub_heading << endl;*/
                        sub_sub_heading = "NULL";
                        sub_sub_sub_heading = "NULL";
                        break;
                    }
                    else if ((input[x] == '=' && input[x + 1] == '=' && input[x + 2] == '=' && input[x + 3] == '=') && input[x + 4] != '=')
                    {
                        sub_sub_heading.clear();

                        /*cout << "input: " << input << endl;*/

                        for (int y = x + 4; y <= input.length(); y++)
                        {
                            if (input[y] != '=')
                            {
                                sub_sub_heading += input[y];
                            }
                        }

                        written = true;
                        /*cout << "sub_sub_heading: " << sub_sub_heading << endl;*/
                        sub_sub_sub_heading = "NULL";
                        break;
                    }
                    else if ((input[x] == '=' && input[x + 1] == '=' && input[x + 2] == '=' && input[x + 3] == '=' && input[x + 4] == '=') && input[x + 5] != '=')
                    {
                        sub_sub_sub_heading.clear();

                        /*cout << "input: " << input << endl;*/

                        for (int y = x + 5; y <= input.length(); y++)
                        {
                            if (input[y] != '=')
                            {
                                sub_sub_sub_heading += input[y];
                            }
                        }

                        written = true;
                        //cout << "sub_sub_sub_heading: " << sub_sub_sub_heading << endl;
                        break;
                    }
                }

                if (heading == "NULL" && input.empty())
                {
                    wiki_text = input;
                    MySQL(title);
                }
                if (heading != "NULL" && input != "" && !written)
                {
                    wiki_text = input;
                    MySQL(title);
                }
                else if (heading != "NULL" && input != "" && written)
                {
                    written = false;
                }
            }
        }
        file.close();

        progress++;
    }
}

void MySQL(wstring table)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_RES* result;
    MYSQL_ROW row;
    ostringstream query1;
    ostringstream query2;
    ostringstream query3;
    string sql1;
    string sql2;
    string sql3;
    string table2;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    table = ReplaceSpaces(table);
    table = ToLowercase(table);
    /*wiki_text = removeQuotes(wiki_text);*/
    //table2 = stripUnicode(table);
    table = fixCharacterSyntax(table);
    //heading2 = stripUnicode(heading);
    //sub_heading2 = stripUnicode(sub_heading);
    //sub_sub_heading2 = stripUnicode(sub_sub_heading);
    //sub_sub_sub_heading2 = stripUnicode(sub_sub_sub_heading);

    if (conn)
    {
        string new_title(table.begin(), table.end());

        sql1 = "CREATE TABLE IF NOT EXISTS ";
        sql1 += new_title.c_str();
        sql1 += "(heading TEXT, sub_heading TEXT, sub_sub_heading TEXT, sub_sub_sub_heading TEXT, wiki_text TEXT);";
        //cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        //fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
    }

    if (conn2)
    {
        string new_title(table.begin(), table.end());

        //query2 << "INSERT INTO " << table.c_str() << "(heading, sub_heading, sub_sub_heading, sub_sub_sub_heading, wiki_text) VALUES(\"" << heading2.c_str() << "\", \"" << sub_heading2.c_str() << "\", \"" << sub_sub_heading2.c_str() << "\", \"" << sub_sub_sub_heading2.c_str() << "\", \"" << wiki_text.c_str() << "\");";
        sql2 = "INSERT INTO ";
        sql2 += new_title.c_str();
        sql2 += "(heading, sub_heading, sub_sub_heading, sub_sub_sub_heading, wiki_text) VALUES(\"";
        sql2 += heading.c_str();
        sql2 += "\", \"";
        sql2 += sub_heading.c_str();
        sql2 += "\", \"";
        sql2 += sub_sub_heading.c_str();
        sql2 += "\", \"";
        sql2 += sub_sub_sub_heading.c_str();
        sql2 += "\", \"";
        sql2 += wiki_text.c_str();
        sql2 += "\");";
        //cout << "SQL2: " << sql2 << endl;
        mysql_query(conn2, sql2.c_str());
        //fprintf(stderr, "%s\n", mysql_error(conn2));
        //cin.get();
        mysql_close(conn2);
    }
}

bool Check_Present(string new_title)
{
    MYSQL* conn;
    MYSQL_RES* result;
    MYSQL_ROW row;
    ostringstream query1;
    string sql1;
    wstring table;
    wstring temp_path3;
    wstring _title;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "127.0.0.1", mysql_username.c_str(), mysql_password.c_str(), mysql_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        //cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);
        //fprintf(stderr, "%s\n", mysql_error(conn));
        //cin.get();

        while (row = mysql_fetch_row(result))
        {
            for (auto& q : directory_iterator(mysql_location.c_str()))
            {
                temp_path3 = q.path().wstring();

                // Parse the title
                for (int z = temp_path3.length(); z >= 0; z--)
                {
                    if (temp_path3[z - 1] == '/')
                    {
                        for (int a = z; temp_path3[a] != '.'; a++)
                        {
                            _title += temp_path3[a];
                        }
                        break;
                    }
                }

                _title = ReplaceSpaces(_title);
                _title = ToLowercase(_title);
                _title = fixCharacterSyntax(_title);
                string new_title(_title.begin(), _title.end());

                if (new_title == row[0])
                {
                    return true;
                }
            }
        }
        return false;
        mysql_close(conn);
    }
}

wstring fixCharacterSyntax(wstring input)
{
    wstring temp;

    for (int x = 0; x <= input.length(); x++)
    {
        if (input[x] == '\'')
        {
            temp += L"\'\'";
        }
        else if (input[x] == '\"')
        {
            temp += L"\"\"";
        }
        else if (input[x] == '&')
        {

        }
        else if (input[x] == '%')
        {

        }
        else if (input[x] == '(')
        {

        }
        else if (input[x] == ')')
        {

        }
        else if (input[x] == ';')
        {

        }
        else if (input[x] == '!')
        {

        }
        else if (input[x] == ':')
        {

        }
        else if (input[x] == ';')
        {

        }
        else if (input[x] == '?')
        {

        }
        else if (input[x] == '+')
        {

        }
        else if (input[x] == '=')
        {

        }
        else
        {
            temp += input[x];
        }
    }

    temp += L"\'";

    return temp;
}

long CountFiles()
{
    string temp_path;
    long count = 0;

    if (mysql_database == "wikipedia")
        return 4512796;
    if (mysql_database == "wikipedia2")
        return 4512796;
    if (mysql_database == "wikisimple")
        return 75859;
    if (mysql_database == "wiktionary")
        return 1420563;
    if (mysql_database == "wikibooks")
        return 147164;
    if (mysql_database == "wikisource")
        return 1136;
    if (mysql_database == "wikibooks")
        return 147164;
    if (mysql_database == "wikiquote")
        return 14549;
    if (mysql_database == "wikinews")
        return 27982;
    if (mysql_database == "wikispecies")
        return 139612;
    if (mysql_database == "wikicommons")
        return 0;
    else
        return 0;
}

wstring ReplaceSpaces(wstring title)
{
    wstring output;

    for (int x = 0; x <= title.length(); x++)
    {
        if (title[x] == ' ')
        {
            output += '_';
        }
        else if (title[x] == '-')
        {
            // Check if the first three characters are a hyphen
            if (x == 0 || title[x + 1] == '-')
            {

            }
            else
            {
                if (title[x + 1] == ' ')
                {

                }
                else
                {
                    output += '_';
                }
            }
        }
        else
        {
            output += title[x];
        }
    }

    return output;
}

wstring ToLowercase(wstring sentence)
{
    wstring temp;

    for (int x = 0; x <= sentence.length(); x++)
    {
        temp += tolower(sentence[x]);
    }

    return temp;
}

//void Rename(string temp_path, string title)
//{
//    //string output;
//    //string filename = title;
//
//    //if (mysql_database == "wikipedia")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikipedia/backup/";
//    //if (mysql_database == "wikisimple")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikisimple/backup/";
//    //if (mysql_database == "wiktionary")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wiktionary/backup/";
//    //if (mysql_database == "wikibooks")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikibooks/backup/";
//    //if (mysql_database == "wikisource")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikisource/backup/";
//    //if (mysql_database == "wikibooks")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikibooks/backup/";
//    //if (mysql_database == "wikiquote")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikiquote/backup/";
//    //if (mysql_database == "wikinews")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikinews/backup/";
//    //if (mysql_database == "wikispecies")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikispecies/backup/";
//    //if (mysql_database == "wikicommons")
//    //    output = "D:/_AugmentedIntelligence/Wikis2SQL/wikicommons/backup/";
//
//    //filename += ".txt";
//    //output += filename;
//
//    //rename(temp_path, output);
//}

wstring removeQuotes(wstring query)
{
    wstring temp;

    for (int x = 0; x <= query.length(); x++)
    {
        if (query[x] == '\'')
        {

        }
        else if (query[x] == '\"')
        {

        }
        else
        {
            temp += query[x];
        }
    }

    return temp;
}
