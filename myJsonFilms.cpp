//
// Created by Sg on 03.09.2022.
//
#include "myJsonFilms.h"
pair<string, Film> filmFromTxt(ifstream& file)
{
    Film myFilm;
    string dummy;
    for (auto & s : myFilm.info) {
        file >> dummy >> s;
    }
    while  (true)
    {
        Character p;
        file >> p.character >> p.actor;
        if(file.eof())
            break;
        myFilm.Characters.push_back(p);
    }
    return make_pair(myFilm.info[NAME],myFilm);
}
void from_json(const nh::json& j,Character& val)
{
    j.at("name").get_to(val.character);
    j.at("actor").get_to(val.actor);
}
void to_json(nh::json& j, const Character& val)
{
    j["name"]=val.character;
    j["actor"]=val.actor;
}
void from_json(const nh::json& j, Film& val)
{

    j.at("Name").get_to(val.info[NAME]);
    j.at("Country").get_to(val.info[COUNTRY]);
    j.at("Date").get_to(val.info[DATE]);
    j.at("Produced").get_to(val.info[PRODUCED]);
    j.at("Production").get_to(val.info[PRODUCTION]);
    j.at("Directed").get_to(val.info[DIRECTED]);
    j.at("Screenplay").get_to(val.info[SCREENPLAY]);
    j.at("Characters").get_to(val.Characters);
}
void to_json(nh::json& j, const Film& val)
{
    j["Name"] = val.info[NAME];
    j["Country"] = val.info[COUNTRY];
    j["Date"] = val.info[DATE];
    j["Produced"] = val.info[PRODUCED];
    j["Production"] = val.info[PRODUCTION];
    j["Directed"] = val.info[DIRECTED];
    j["Screenplay"] = val.info[SCREENPLAY];
    j["Characters"] = val.Characters;
}

void showMenu()
{
    cout<<"Valid command format:'1' for load films from txt;"<<endl;
    cout<<"                     '2' for load films from json;"<<endl;
    cout<<"                     '3' for write films to json;"<<endl;
    cout<<"                     '4' for search actor;"<<endl;
    cout<<"                     '5' for show all films info;"<<endl;
    cout<<"                     '6' for show film info;"<<endl;
    cout<<"                     '7' for exit."<<endl;
}