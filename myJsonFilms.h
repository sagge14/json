//
// Created by Sg on 03.09.2022.
//
#pragma once
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
namespace nh = nlohmann;
using namespace std;
enum filmInfo
{
    NAME,
    COUNTRY,
    DATE,
    PRODUCED,
    PRODUCTION,
    DIRECTED,
    SCREENPLAY
};
enum commands
{
    FROMTXT = 1,
    FROMJSON,
    WRITEJSON,
    SEARCH,
    SHOWALLINFO,
    SHOWFILMINFO,
    EXIT
};
struct Character
{
    std::string character = "None";
    std::string actor = "None";
};
struct Film
{
    string info[7];
    std::vector<Character> Characters;
};

pair<string, Film> filmFromTxt(ifstream& file);
void from_json(const nh::json& j,Character& val);
void to_json(nh::json& j, const Character& val);
void from_json(const nh::json& j, Film& val);
void to_json(nh::json& j, const Film& val);
void showMenu();