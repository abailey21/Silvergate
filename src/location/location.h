#ifndef LOCATION_H
#define LOCATION_H

class Location
{
    public:
        Location();
        ~Location();

        void set_description(std::string);
        void set_locationTitle(std::string);

        std::string get_description();
        std::string get_locationTitle();

        void print_description();

    protected:
        std::string description;
        std::string locationTitle;
};

#endif
