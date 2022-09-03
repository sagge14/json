
#include "myJsonFilms.h"
#define FILM_COUNT 6

int main()
{
    std::map<std::string, Film> mFilms;
    int command;
    cout << "---JSON Films---" << endl;
    while(true)
    {
        showMenu();
        cout << "Enter the command:";
        cin >> command;
        system("cls");
        if(command > 2 && command < 7 && mFilms.empty())
        {
            cout << "Films is not found!" << endl;
            cout << "First run command 1 or 2" << endl;
        }
        else if (command == FROMTXT)
        {
            cout << "Loading films from txt..." << endl;
            for (int i = 0; i < FILM_COUNT; ++i)
            {
                string fileName = "txt//"+to_string(i+1)+".txt";
                ifstream file(fileName);
                if(!file.is_open())
                {
                    cout << "File '" << fileName << "' is not found!" << endl;
                    continue;
                }
                mFilms.insert(filmFromTxt(file));
                cout << "-Success!" << endl;
                file.close();
            }
        }
        else if (command == WRITEJSON)
        {
            nh::json jsonFilms = mFilms;
            ofstream jsonFilmsFile("Films.json");
            jsonFilmsFile << jsonFilms;
            cout << "-Success!" << endl;
            jsonFilmsFile.close();
        }
        else if (command == FROMJSON)
        {
            cout << "Loading films from json..." << endl;
            ifstream jsonFilmsFile("Films.json");
            if(jsonFilmsFile.is_open())
            {
                try
                {
                    nh::json jsonFilms;
                    jsonFilmsFile >> jsonFilms;
                    cout << "-Success!" << endl;
                    mFilms.clear();
                    mFilms = jsonFilms.get<std::map<std::string, Film>>();

                }
                catch (nh::json::parse_error& e)
                {
                    cout << "Message: " << e.what() << '\n'
                         << "Exception id: " << e.id << '\n'
                         << "Byte position of error: " << e.byte << std::endl;
                    cout << "--Try running commands 1 and 3--" << endl;
                }
            }
            else
            {
                cout << "File 'Films.json' is not found!" << endl;
                cout << "Try running commands 1 and 3" << endl;
            }
            jsonFilmsFile.close();
        }
        else if (command == SHOWALLINFO)
        {
            nh::json jsonFilm = mFilms;
            stringstream ss;
            ss << std::setw(2) << jsonFilm;
            std::cout << "---All films info---\n" << ss.str() << "\n";
        }
        else if (command == SHOWFILMINFO)
        {
            string filmName;
            cout << "Enter the film name:";
            cin >> filmName;
            if(mFilms.find(filmName) == mFilms.end())
                cout << "The film '" << filmName << "' is not found!" << endl;
            else
            {
                nh::json jsonFilm = mFilms.at(filmName);
                stringstream ss;
                ss << std::setw(2) << jsonFilm;
                std::cout << "--- " << filmName << " info---\n" << ss.str() << "\n";
            }
        }
        else if (command == SEARCH)
        {
            string name;
            cout << "Enter search name(use '_'):";
            cin >> name;
            std::vector<string> result;
            for(const auto& f:mFilms)
                for(const auto& c:f.second.Characters)
                    if(c.actor == name)
                        result.push_back(f.first + " (" + c.character + ")");
            cout << "Films with " << name << ":" << endl;
            for (const auto& f:result)
                cout <<" - " << f << endl;
        }
        else if (command == EXIT)
        {
            cout << "---Bey, bye!---" << endl;
            system("pause");
            break;
        }
        else
            cout << "Unknown command!" << endl;

        system("pause");
        system("cls");
        cin.clear();
        cin.ignore();
    }

}