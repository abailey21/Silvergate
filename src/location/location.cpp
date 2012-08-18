#include "../main files/library.h"

Location::Location(){}
Location::~Location(){}

void Location::set_description(string newDescription)
{
    description = newDescription;
}
void Location::set_locationTitle(string newLocationTitle)
{
    locationTitle = newLocationTitle;
}

string Location::get_description()
{
    return description;
}
string Location::get_locationTitle()
{
    return locationTitle;
}

void Location::print_description()
{
    #ifdef WINDOWS
    system("cls");
    #else
    system("clear");
    #endif

    cout << locationTitle << "\n\n";
    cout << description;
}
