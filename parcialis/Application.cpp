//
// Created by Adek on 2021. 11. 11..
//

#include "Application.h"

Application::Application(const string &name, const string &category, const string &developer, int version, int rating, double price) {
    this->name = name;
    this->category = category;
    this->developer = developer;
    this->version = version;
    this->rating = rating;
    this->price = price;
}

const string &Application::getName() const {
    return name;
}

const string &Application::getCategory() const {
    return category;
}

const string &Application::getDeveloper() const {
    return developer;
}

int Application::getVersion() const {
    return version;
}

int Application::getRating() const {
    return rating;
}

double Application::getPrice() const {
    return price;
}

ostream &operator<<(ostream &os, const Application &application) {
    os << "name: " << application.name << " category: " << application.category << " developer: "
       << application.developer << " version: " << application.version << " rating: " << application.rating
       << " price: " << application.price;
    return os;
}

