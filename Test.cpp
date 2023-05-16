#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;
using namespace doctest;

TEST_CASE("initialize character")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12,81));
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64,57));
    //checking that all the data of each kind of character was initialized correctly
    CHECK_EQ(tom->getHitPoint(), 110);
    CHECK_EQ(tom->getNumOfBoolets(), 6);
    CHECK_EQ(sushi->getHitPoint(), 150);
    CHECK_EQ(sushi->getSpeed(), 8);
    CHECK_EQ(hikari->getHitPoint(), 120);
    CHECK_EQ(hikari->getSpeed(), 12);
    CHECK_EQ(yogi->getHitPoint(), 100);
    CHECK_EQ(yogi->getSpeed(), 14);

    CHECK_NOTHROW(tom->print());
    CHECK_NOTHROW(sushi->print());
    CHECK_NOTHROW(hikari->print());
    CHECK_NOTHROW(yogi->print());
    Team team_A(tom); 
    team_A.add(yogi);
    CHECK_NOTHROW(team_A.print());
    delete tom;
    delete sushi;
    delete hikari;
    delete yogi;
}

TEST_CASE("start of game")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom); 
    Team team_B(sushi);
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12,81));
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64,57));
    team_A.add(yogi);
    team_B.add(hikari);
    //checking if the number of members in the twam is really 2, both teams didn't attack so all the members shoul'd be allive
    CHECK_EQ(team_A.stillAlive(), 2);
    CHECK_EQ(team_B.stillAlive(), 2);
    //trying one attack of each team, the members should still be allive
    CHECK_NOTHROW(team_A.attack(&team_B));
    team_B.attack(&team_A);
    CHECK_EQ(team_A.stillAlive(), 2);
    CHECK_EQ(team_B.stillAlive(), 2);
    //check that at least 0 point got decreased from eack player
    CHECK_LE(tom->getHitPoint(), 110);
    CHECK_LE(sushi->getHitPoint(), 150);
    CHECK_LE(hikari->getHitPoint(), 120);
    CHECK_LE(yogi->getHitPoint(), 100);
    delete tom;
    delete sushi;
    delete hikari;
    delete yogi;
}

TEST_CASE("end of a game")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom); 
    Team team_B(sushi);
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12,81));
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64,57));
    team_A.add(yogi);
    team_B.add(hikari);
    while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
    }
    if(team_A.stillAlive() == 0)
    {
        CHECK_FALSE(tom->isAlive());
        CHECK_FALSE(yogi->isAlive());
    }
    else
    {
        CHECK_FALSE(sushi->isAlive());
        CHECK_FALSE(hikari->isAlive());
    }    
    delete tom;
    delete sushi;
    delete hikari;
    delete yogi;
}

TEST_CASE("game with team2")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team2 team_A(tom); 
    Team2 team_B(sushi);
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12,81));
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64,57));
    team_A.add(yogi);
    team_B.add(hikari);
    Cowboy *andrew = new Cowboy("Andrew", Point(5,21));  
    team_B.add(andrew);
    string outTeamA = "C: Tom, 110 hit points, location: (32.3,44)\nN: Yogi, 100 hit points, location: (64,57)";
    string outTeamB = "N: Sushi, 150 hit points, location: (1.3,3.5)\nN: hikari, 120 hit points, location: (12,81)\nC: Andrew, 110 hit points, location: (5,21)";
    CHECK_EQ(team_A.print(), outTeamA);
    CHECK_EQ(team_B.print(), outTeamB);
    delete tom;
    delete sushi;
    delete hikari;
    delete yogi;
    delete andrew;
}

TEST_CASE("throwing errors")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom); 
    Team team_B(sushi);
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12,81));
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64,57));
    team_A.add(yogi);
    team_B.add(hikari);
    //a character trying to hit herself
    CHECK_THROWS(tom->shoot(tom));
    CHECK_THROWS(sushi->slash(sushi));
    //the cowboy use all his boolets and try to soot when he is booletless
    for(int i = 0; i < 6; i++)
    {
        tom->shoot(sushi);
    }
    CHECK_THROWS(tom->shoot(sushi));
    //a team that has no members allive tries to attack the other team or the other team tries to attack her
    while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
    }
    CHECK_THROWS(team_A.attack(&team_B));
    CHECK_THROWS(team_B.attack(&team_A));
    delete tom;
    delete sushi;
    delete hikari;
    delete yogi;
}