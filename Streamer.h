/*
 * Wade Bradford
 * CS 124
 * Project 1
 */

#ifndef CS124_PROJECT_1_STREAMER_H
#define CS124_PROJECT_1_STREAMER_H


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using std::cout, std::endl, std::string, std::vector, std::ifstream, std::ostream;

/*
 * Class representing data related to the Top Streamers on Twitch.tv over the course of one year
 * Dataset downloaded from https://www.kaggle.com/datasets/aayushmishra1512/twitchdata.
 */

/* Fields:
 * streamerName: the name associated with the streamer's profile
 * watchTime: the amount of time viewers spent watching
 * streamTime: the amount of time the viewer spent streaming
 * peakViewers: the most viewers the streamer had at once
 * followers: the amount of followers the streamer has
 * followersGained: the amount of followers the streamer gained
 * viewsGained: the amount of views gained
 * partnered: whether the streamer is partnered or not
 * mature: whether the streamer is considered for mature audiences
 * language: what language the streamer broadcasts in
 */

class Streamer {

private:
    string streamerName;
    long long int watchTime;
    int streamTime;
    int peakViewers;
    int averageViewers;
    int followers;
    int followersGained;
    int viewsGained;
    string partnered;
    string mature;
    string language;

public:
    // constructors

    Streamer() {
    }

    Streamer(string streamerName, long long int watchTime, int streamTime, int peakViewers, int averageViewers, int followers,
             int followersGained, int viewsGained, string partnered, string mature, string language) {
        this->streamerName = streamerName;
        this->watchTime = watchTime;
        this->streamTime = streamTime;
        this->peakViewers = peakViewers;
        this->averageViewers = averageViewers;
        this->followers = followers;
        this->followersGained = followersGained;
        this->viewsGained = viewsGained;
        this->partnered = partnered;
        this->mature = mature;
        this->language = language;
    }

    // getters

    string getStreamerName() const {
        return streamerName;
    }

    long long int getWatchTime() const {
        return watchTime;
    }

    int getStreamTime() const {
        return streamTime;
    }

    int getPeakViewers() const {
        return peakViewers;
    }

    int getAverageViewers() const {
        return averageViewers;
    }

    int getFollowers() const {
        return followers;
    }

    int getFollowersGained() const {
        return followersGained;
    }

    int getViewsGained() const {
        return viewsGained;
    }

    string getPartnered() const {
        return partnered;
    }

    string getMature() const {
        return mature;
    }

    string getLanguage() const {
        return language;
    }

    // setters

    void setStreamerName(string streamerName) {
        this->streamerName = streamerName;
    }

    void setWatchTime(long long int watchTime) {
        this->watchTime = watchTime;
    }

    void setStreamTime(int streamTime) {
        this->streamTime = streamTime;
    }

    void setPeakViewers(int peakViewers) {
        this->peakViewers = peakViewers;
    }

    void setAverageViewers(int averageViewers) {
        this->averageViewers = averageViewers;
    }

    void setFollowers(int followers) {
        this->followers = followers;
    }

    void setFollowersGained(int followersGained) {
        this->followersGained = followersGained;
    }

    void setViewsGained(int viewsGained) {
        this->viewsGained = viewsGained;
    }

    void setPartnered(string partnered) {
        this->partnered = partnered;
    }

    void setMature(string mature) {
        this->mature = mature;
    }

    void setLanguage(string language) {
        this->language = language;
    }

    // Overloading operators for future projects (found in example project)

    // overload < operator for object comparison
    friend bool operator < (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() < rhs.getAverageViewers();
    }

    // overload > operator for object comparison
    friend bool operator > (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() > rhs.getAverageViewers();
    }

    // overload <= operator for object comparison
    friend bool operator <= (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() <= rhs.getAverageViewers();
    }

    // overload >= operator for object comparison
    friend bool operator >= (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() >= rhs.getAverageViewers();
    }

    // overload == operator for object comparison
    friend bool operator == (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() == rhs.getAverageViewers();
    }

    // overload != operator for object comparison
    friend bool operator != (const Streamer& Ihs, const Streamer& rhs) {
        return Ihs.getAverageViewers() != rhs.getAverageViewers();
    }

    // overload << to print streamer objects
    friend ostream& operator << (ostream& output, const Streamer& s) {
        return output << s.getStreamerName() << ", "
        << s.getWatchTime() << ", "
        << s.getStreamTime() << ", "
        << s.getPeakViewers() << ", "
        << s.getAverageViewers() << ", "
        << s.getFollowers() << ", "
        << s.getFollowersGained() << ", "
        << s.getViewsGained() << ", "
        << s.getPartnered() << ", "
        << s.getMature() << ", "
        << s.getLanguage() << ", ";

    }

};

// method to read the file and store into a vector of objects
 bool readDataFromFile(string fileName, vector<Streamer>& objs) {

     ifstream f_in;
     f_in.open(fileName);

// check if file opened
     if (!f_in.is_open()) {
         cout << "The file could not be opened." << endl;
         return false;
     }

     // read and skip first line
     string firstLine;
     getline(f_in, firstLine);

     int count = 1;

     // while loops to read through file and construct objects
     while (f_in.good() && count < 1001) {

         // sentinel values
         char comma = ',';
         string streamerName = "invalid";
         long long int watchTime = -1;
         int streamTime = -1;
         int peakViewers = -1;
         int averageViewers = -1;
         int followers = -1;
         int followersGained = -1;
         int viewsGained = -1;
         string partnered = "invalid";
         string mature = "invalid";
         string language = "invalid";

         // reading file into ints/strings
         getline(f_in, streamerName, ',');
         f_in >> watchTime;
         f_in >> comma;
         f_in >> streamTime;
         f_in >> comma;
         f_in >> peakViewers;
         f_in >> comma;
         f_in >> averageViewers;
         f_in >> comma;
         f_in >> followers;
         f_in >> comma;
         f_in >> followersGained;
         f_in >> comma;
         f_in >> viewsGained;
         f_in >> comma;
         getline(f_in, partnered, ',');
         getline(f_in, mature, ',');
         getline(f_in, language);

        // new streamer object
        Streamer twitchStreamer(streamerName, watchTime, streamTime, peakViewers, averageViewers,
                                followers, followersGained, viewsGained, partnered, mature, language);

        objs.push_back(twitchStreamer);
        count++;
     }

     f_in.close();
     return true;


    }

    // calculates the average number of followers amongst all streamers
 void calculateAverageFollowers(vector<Streamer>& objs) {
    int averages = 0;
    int counter = 0;

 for(int i = 0; i < objs.size(); i++) {

     averages = averages + objs.at(i).getFollowers();
     counter++;

 }

    cout << "The average number of followers of the 1000 streamers is: " << averages/counter << endl;

 }







#endif //CS124_PROJECT_1_STREAMER_H
