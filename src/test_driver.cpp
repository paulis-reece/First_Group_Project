/*************************************************************************
 *
 * Project III: Start testing here.
 *
 * File Name:       test_driver.cpp
 * Name(s):         ?
 * Course:          CPTR 142
 * Date:            ?
 *
 */
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "Campus.h"
#include "Fountain.h"
#include "User.h"

TEST_CASE("Create a Fountain", "[fountain]") {
    // Setup
    Fountain* theFountain =
        new Fountain("69420nice", "Mordor", "Literally Sauron");

    SECTION("Details are correct") {
        REQUIRE(theFountain->getId() == "69420nice");
        REQUIRE(theFountain->getName() == "Literally Sauron");
    }

    // Create a review
    Review* theReview = new Review(
        "Not a good place for a date",
        "I asked my girlfriend to join me but she never showed up", 0);
    User* theUser = new User("007", "James Bond", "yesthisisanothermovie");
    theReview->assignUser(theUser);
    theReview->assignFountain(theFountain);

    SECTION("Adding a review works") {
        REQUIRE(theReview->getUser()->getId() == "007");
        REQUIRE(theReview->getUser()->getName() == "James Bond");
        REQUIRE(theReview->getUser()->getPasscode() == "yesthisisanothermovie");
        REQUIRE(theReview->getFountain() == theFountain);
    }
    theFountain->addReview(theReview);
    theFountain->printReviews();

    // Teardown
    delete theFountain;
    delete theReview;
    delete theUser;
}

TEST_CASE("Campus", "[campus]") {
    // Setup

    std::ifstream in("./src/Users.txt", std::ios::in | std::ios::binary);
    std::ifstream in2("./src/Fountains.txt", std::ios::in | std::ios::binary);
    std::ifstream in3("./src/Review.txt", std::ios::in | std::ios::binary);

    SECTION("Files have stuff in them") {
        REQUIRE(in.good());
        // REQUIRE(in2.good());
        // REQUIRE(in3.good());
    }

    // Assign cout to text file
    std::streambuf *psbuf, *backup;
    std::ofstream filestr;
    filestr.open("test.txt");
    backup = std::cout.rdbuf();  // back up cout's streambuf

    psbuf = filestr.rdbuf();  // get file's streambuf
    std::cout.rdbuf(psbuf);   // assign streambuf to cout

    // Now call constructor
    Campus theCampus;

    // Restore cout's original streambuf
    std::cout.rdbuf(backup);
    filestr.close();

    std::ifstream bufout("test.txt", std::ios::in | std::ios::binary);

    std::cout << "Reached section 2\n";

    SECTION("Cout is not empty") {
        REQUIRE(bufout.good());
    }

    // Teardown
    std::remove("./src/Users.txt");
    std::remove("./src/Fountains.txt");
    std::remove("./src/Review.txt");
    std::remove("./src/test.txt");
}

TEST_CASE("Campus2", "[campus]") {
    // Setup

    // Teardown
}
