#pragma once

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
#include <fstream>
#include <filesystem>
#include <io.h>
#include <fcntl.h>
#include <sstream>
#include <mysql.h>
#include <chrono>

using namespace std;
using namespace filesystem;

static void Parser();
static void Settings();
static void MySQL(wstring table);
static wstring ReplaceSpaces(wstring title);
static wstring removeQuotes(wstring query);
static wstring ToLowercase(wstring sentence);
static wstring fixCharacterSyntax(wstring input);
//static void stripUnicode(wstring& str);
//static void Rename(string temp_path, string title);
//static bool invalidChar(char c);
//static string stripUnicode(string str);
//static bool MySQL2(wstring table);
static long CountFiles();
static bool Check_Present(string new_title);
//static void LoadSettings();
//static void SaveSettings();

//static void CUDA();
//__global__ void MySQLImport(int numElements, int blocksPerGrid, int threadsPerBlock);

string mysql_hostname = "localhost";
string mysql_username = "root";
string mysql_password = "Anaheim92801%";
string mysql_database = "wikipedia";
string mysql_location = "D:/Done/";

// Initialized Variables
//wstring _title1[1000000];
//wstring _title2[1000000];
//wstring _title3[1000000];
//wstring _title4[1000000];
//wstring _title5[497175];
//string _header1[1000000];
//string _header2[1000000];
//string _header3[1000000];
//string _header4[1000000];
//string _header5[497175];
//string _sub_header1[1000000];
//string _sub_header2[1000000];
//string _sub_header3[1000000];
//string _sub_header4[1000000];
//string _sub_header5[497175];
//string _sub_sub_header1[1000000];
//string _sub_sub_header2[1000000];
//string _sub_sub_header3[1000000];
//string _sub_sub_header4[1000000];
//string _sub_sub_header5[497175];
//string _sub_sub_sub_header1[1000000];
//string _sub_sub_sub_header2[1000000];
//string _sub_sub_sub_header3[1000000];
//string _sub_sub_sub_header4[1000000];
//string _sub_sub_sub_header5[497175];

wstring title;
string heading;
string sub_heading;
string sub_sub_heading;
string sub_sub_sub_heading;
string wiki_text;

#pragma once
