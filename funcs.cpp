#include <iostream>
#include "funcs.h"
using namespace std;

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}
int minutesUntil(Time earlier, Time later){
    // if earlier's time is more late than later
    if((later.h < earlier.h) || ((later.h <= earlier.h) && (later.m < earlier.m))){
        return (((later.h - earlier.h) * 60) + (later.m - earlier.m));
    }
    //if earlier's minute is greater than later's minute,
    //substracting them won't work -> 1:41 to 2:04 != hour(2-1)  : minute(abs(4-41)), you get 1 hour 37 mins inbetween
    //Adds 1 hour to earlier.h but earlier.m subtracts 60 and gets added to later.m
    //ex: 2:41 to 3:04, hours(3 - (2+1)), minutes((60-41) + 4) -> 0 hours 23 mins
    if(earlier.m > later.m){
        return (abs((earlier.h+1) - later.h) * 60) + abs(later.m + abs(earlier.m-60));
    }
    return (abs(earlier.h - later.h) * 60) + abs(earlier.m - later.m);
}

Time addMinutes(Time time0, int min){
    int minutes = time0.m + min; 
    int hours = time0.h;
    if(minutes >=60){
        hours += minutes/60;
        minutes = minutes%60;
    }
    if(hours > 24){
        hours = 0;
    }
    return {hours,minutes};
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

string getTimeSlot(TimeSlot ts){
    string ret = "";
    string g;
    switch (ts.movie.genre) { // g becomes the genre
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    Time end = addMinutes(ts.startTime,ts.movie.duration); // the ending time for the movie
    ret+= ts.movie.title + " " + g + " (" + std::to_string(ts.movie.duration) + " min) [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " + std::to_string(end.h) + ":" + std::to_string(end.m) + "]\n";
    return ret;
}