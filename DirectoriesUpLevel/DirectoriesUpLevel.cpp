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

#include <iostream>
#include <string>
#include <filesystem>
#include <chrono>
#include <thread>

using namespace std;
using namespace filesystem;

string AddQuotes(string input);
wstring AddQuotesWide(wstring input);

int main()
{
    string title;
    string new_path;
    string input;
    string input2;
    wstring temp_path;
    wstring temp_path2;
    wstring command;

    while (true)
    {
        cout << "Location: ";
        getline(cin, input);

        cout << "Destination: ";
        getline(cin, input2);

        // Get the filename of the file
        for (auto& a : directory_iterator(input.c_str()))
        {
            temp_path = a.path().string();

            for (auto& b : directory_iterator(temp_path.c_str()))
            {
                temp_path2 = b.path().string();
                //cout << "temp_path2: " << temp_path2 << endl;
                //cin.get();

                title.clear();
                new_path.clear();

                // Get the filename
                for (int x = temp_path2.length(); x >= 0; x--)
                {
                    if (temp_path2[x] == '\\' || temp_path2[x] == '/')
                    {
                        for (int y = x + 1; y <= temp_path2.length(); y++)
                        {
                            title += temp_path2[y];
                        }
                        break;
                    }
                }

                new_path = input2;
                new_path += title;
                new_path = AddQuotes(new_path);
                temp_path2 = AddQuotes(temp_path2);
                //command = "mv ";
                //command += temp_path2;
                //command += " ";
                //command += new_path;
                //command += title;
                //command += ".txt";
                command = "copy ";
                command += temp_path2;
                command += " ";
                command += new_path;
                /*cout << temp_path2 << " | " << new_path << endl;*/
                _wsystem(command.c_str());
                std::chrono::milliseconds timespan(100);
                std::this_thread::sleep_for(timespan);
                //cin.get();
            }
        }
    }
}

string AddQuotes(string input)
{
    string done;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            done = "\"";
            done += input[x];
        }
        else if (x == input.length())
        {
            done += '\"';
        }
        else
        {
            done += input[x];
        }
    }

    return done;
}

wstring AddQuotesWide(wstring input)
{
    wstring done;

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            done += '\"';
            done += input[x];
        }
        else if (x == input.length())
        {
            done += '\"';
        }
        else
        {
            done += input[x];
        }
    }

    return done;
}