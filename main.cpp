#include <iostream>
#include "funcs.h"
using namespace std;

int main(){
    
    cout << "MinutesSinceMidnight and Minutes Until:" << endl;
    Time t1 = {2,10};
    Time t2 = {7,50};
    cout << minutesSinceMidnight(t1) << endl;
    cout << minutesSinceMidnight(t2) << endl;
    cout << minutesUntil(t1,t2) << endl;
    cout << minutesUntil({9,2},{1,39}) << endl;
    cout <<   minutesUntil({7,20}, {7, 55}) << endl;
    cout <<   minutesUntil({0,41}, {15, 4}) << endl;
    cout << "-------------------------------" << endl;
    
    //testing addMinutes
    cout << "Add minutes:" << endl;
    Time t3 = {8,10};
    Time t4 = addMinutes(t3,75); 
    Time t5 = {24,10};
    Time t6 = addMinutes(t5,50);
    cout << t4.h << " " << t4.m << endl;
    cout << t6.h << " " << t6.m << endl;
    cout << "-------------------------------" << endl;

    
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Julius Caesar",ROMANCE,90};
    Movie movie4 = {"Never gonna give you up", ROMANCE,90};
    Movie bananas = {"bananas", ACTION, 130};

    TimeSlot testing = {bananas,{14,10}};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot late1 = {movie3,{10,10}}; 
    TimeSlot late2 = {movie4,{11,30}};

    cout << "getTimeSlot: " << endl;
    string what = getTimeSlot(testing);
    string pls = "";
    for(auto x : what){
        pls+=x;
    }
    cout << (what == pls) << endl;
    for (auto x : pls){
        cout << x << "-" << endl;
    }
    cout << what << endl;
    cout << "----------------------------" << endl;
    //cout << timeOverlap(late1,late2) << endl; 

    //TimeSlot testEarly = earlierStart(testing, daytime);
    //printTimeSlot(testEarly);

    //printMovie(movie1);
    /* testing print time slot
    cout << "\n";
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(late1);
    printTimeSlot(late2);
    */

    /*
    TimeSlot t1 = scheduleAfter(testing,bananas);
    printTimeSlot(t1);
    */
    Movie rick = {"Never gonna give you up", ROMANCE,90};    
    TimeSlot schedule = scheduleAfter(testing,rick);
    cout << getTimeSlot(schedule) << endl;
    cout << schedule.startTime.h << " " << schedule.startTime.m << endl;
    cout << schedule.movie.title << " " << schedule.movie.duration << " " << endl;
    return 0;
}