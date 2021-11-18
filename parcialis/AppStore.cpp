//
// Created by Adek on 2021. 11. 11..
//

#include "AppStore.h"
#include <algorithm>

AppStore::AppStore(const string &filename) {
    ifstream MyReadFile(filename);
    if(!MyReadFile){
        throw runtime_error("ERROR!");
    }
    string line;
    while (getline (MyReadFile, line)) {
        if(line.empty()){
            continue;
        }
        istringstream ss(line);
        string name;
        string category;
        string developer;
        string version;
        string rating;
        string price;
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, developer, ',');
        getline(ss, version, ',');
        getline(ss, rating, ',');
        getline(ss, price, ',');
        applications.emplace_back(Application(name, category, developer, stoi(version), stoi(rating), stod(price)));
    }
    MyReadFile.close();
}

void AppStore::print(ostream &out, const string& term) {
    for(auto const &app: applications){
        if(term == "free"){
            if(app.getPrice() == 0){
                out << app <<endl;
            }
            else{
                continue;
            }
        }
        else if(app.getName().find(term) != string::npos){
            out << app << endl;
        }
        else if(app.getCategory().find(term) != string::npos){
            out << app << endl;
        }
        else if(app.getDeveloper().find(term) != string::npos){
            out << app << endl;
        }
    }
}

Application AppStore::bestApp(bool freeOnly, int minVersion) {
    int bestAppInt = -1;
    int bestAppRating = 0;
    for(int i = 0; i < applications.size(); ++i){
        if(freeOnly && applications[i].getPrice() == 0){
            if(minVersion > applications[i].getVersion()){
                continue;
            }
            if(applications[i].getRating() > bestAppRating){
                bestAppInt = i;
                bestAppRating = applications[i].getRating();
            }
        }
        else{
            if(minVersion > applications[i].getVersion()){
                continue;
            }
            if(applications[i].getRating() > bestAppRating){
                bestAppRating = applications[i].getRating();
                bestAppInt = i;
            }
        }
    }
    return applications[bestAppInt];
}

void AppStore::remove(int belowRating) {
    erase_if(applications, [belowRating] (const Application& app){
        if(app.getRating() < belowRating){
            return true;
        }
        return false;
    });
}

bool compareFree(const Application& app1, const Application& app2){
    if(app2.getPrice() == 0 && app1.getPrice() != 0){
        return true;
    }
    if(app2.getPrice() == 0 && app1.getPrice() == 0){
        if(app2.getRating() > app1.getRating()){
            return true;
        }
    }
    return false;
}
bool compareRating(const Application& app1, const Application& app2){
    if(app1.getPrice() == 0){
        return false;
    }
    if(app2.getRating() > app1.getRating()){
        return true;
    }
    return false;
}


void AppStore::sortByFreeAndRating() {
    sort(applications.begin(), applications.end(), compareFree);
    sort(applications.begin(), applications.end(), compareRating);
}

int AppStore::size() {
    return applications.size();
}

Application &AppStore::operator[](int index) {
    if(index < 0 || index > applications.size()){
        throw out_of_range("OUT OF RANGE!");
    }
    return applications[index];
}

Application AppStore::operator[](int index) const {
    if(index < 0 || index > applications.size()){
        throw out_of_range("OUT OF RANGE!");
    }
    return applications[index];
}
