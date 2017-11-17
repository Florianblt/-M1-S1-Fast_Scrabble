#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
int main (int argc, char *argv[])
{
    multimap<string, string> dico2;
    ifstream file(argv[2], ios::in);
    if(file) {
        string ligne;
        string mot;
        while (getline(file, ligne)) {
            mot = ligne;
            if (!ligne.empty() && ligne[ligne.size() - 1] == '\r')
               ligne.erase(ligne.size() - 1);
            transform(ligne.begin(), ligne.end(), ligne.begin(), ::tolower);
            sort(ligne.begin(), ligne.end());
            dico2.insert(make_pair(ligne, mot));
        }
    }else{
        cout << "Erreur de lecture du fichier";
    }
    while(true) {
        string motSaisi;
        cin >> motSaisi;
        transform(motSaisi.begin(), motSaisi.end(), motSaisi.begin(), ::tolower);
        sort(motSaisi.begin(), motSaisi.end());
        pair<multimap<string,string>::iterator, multimap<string,string>::iterator> ii;
        multimap<string, string>::iterator it; 
        ii = dico2.equal_range(motSaisi); 
        for(it = ii.first; it != ii.second; ++it)
            cout<<it->second<<endl;
    }
    return 0;
}