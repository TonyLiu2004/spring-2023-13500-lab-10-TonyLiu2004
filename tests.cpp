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
    CHECK(getTimeSlot(t1) == "bananas ACTION (130 min) [starts at 14:10, ends by 16:20]");
    CHECK(getTimeSlot(t2) == "Julius Caesar ROMANCE (90 min) [starts at 10:10, ends by 11:40]");
}