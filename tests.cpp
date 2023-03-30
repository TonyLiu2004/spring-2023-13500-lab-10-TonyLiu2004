#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("minutesSinceMidnight") {
    CHECK(minutesSinceMidnight({2,10}) == 130);
    CHECK(minutesSinceMidnight({7,50}) == 470);
}

TEST_CASE("minutesUntil"){
    CHECK(minutesUntil({2,10},{7,50}) == 340);
    CHECK(minutesUntil({9,2},{1,39}) == -443);
    CHECK(minutesUntil({7,20}, {7, 55}) == 35);
    CHECK(minutesUntil({0,41}, {15, 4}) == 863);
}

TEST_CASE("addMinutes"){
    Time t1 = {8,10};
    Time added1 = addMinutes(t1,75);
    Time t2 = {24,10};
    Time added2 = addMinutes(t2,50);
    CHECK(added1.h == 9);
    CHECK(added1.m == 25);
    CHECK(added2.h == 0);
    CHECK(added2.m == 0);
}

TEST_CASE("getTimeSlot"){
    Movie bananas = {"bananas", ACTION, 130};
    TimeSlot t1 = {bananas,{14,10}};
    Movie caesar = {"Julius Caesar",ROMANCE,90};
    TimeSlot t2 = {caesar,{10,10}};
    CHECK(getTimeSlot(t1) == "bananas ACTION (130 min) [starts at 14:10, ends by 16:20]\n");
    CHECK(getTimeSlot(t2) == "Julius Caesar ROMANCE (90 min) [starts at 10:10, ends by 11:40]\n");
}

TEST_CASE("scheduleAfter"){
    Movie bananas = {"bananas", ACTION, 130};
    Movie rick = {"Never gonna give you up", ROMANCE,90};
    TimeSlot testing = {bananas,{14,10}};

    TimeSlot t1 = scheduleAfter(testing,rick);
    CHECK(t1.startTime.h == 16);
    CHECK(t1.startTime.m == 20);
    CHECK(t1.movie.title == "Never gonna give you up");
}

TEST_CASE("timeOverlap"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Julius Caesar",ROMANCE,90};
    Movie movie4 = {"Never gonna give you up", ROMANCE,90};

    TimeSlot t1 = {movie3,{10,10}}; 
    TimeSlot t2 = {movie4,{11,30}};
    TimeSlot t3 = {movie1,{9,10}};
    TimeSlot t4 = {movie2,{13,21}};
    CHECK(timeOverlap(t1,t2) == 1);
    CHECK(timeOverlap(t3,t1) == 1);
    CHECK(timeOverlap(t3,t4) == 0);
    CHECK(timeOverlap(t1,t4) == 0);

}