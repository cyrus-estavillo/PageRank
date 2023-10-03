#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "AdjacencyList.h"
#include <sstream>

std::string graph(const std::string& input) {
    std::istringstream in(input);
    std::ostringstream out;

    // Your existing code, modified to use input and output streams
    int no_of_lines, power_iterations;
    std::string from, to;
    in >> no_of_lines;
    in >> power_iterations;

    //Create a graph object
    AdjacencyList graph(no_of_lines);

    for (int i = 0; i < no_of_lines; i++) {
        in >> from;
        in >> to;
        graph.addEdge(from, to);
    }

    // Rank pages and output alphabetically
    graph.pageRank(power_iterations, out);  // Modify your pageRank function to take an output stream as an additional argument

    return out.str();
}

TEST_CASE("Test Case 1", "[PageRank]") {
std::string input =
        "36 14\n"
        "instagram.com samsung.com\n"
        "chase.com github.com\n"
        "instagram.com github.com\n"
        "weather.com google.com\n"
        "aman.com weather.com\n"
        "pcbuildinguf.com mozilla.org\n"
        "aman.com twitter.com\n"
        "weather.com openai.com\n"
        "openai.com github.com\n"
        "samsung.com openai.com\n"
        "facebook.com samsung.com\n"
        "instagram.com facebook.com\n"
        "pcbuildinguf.com twitter.com\n"
        "facebook.com aman.com\n"
        "github.com getbootstrap.com\n"
        "facebook.com instagram.com\n"
        "samsung.com pcbuildinguf.com\n"
        "weather.com aman.com\n"
        "twitter.com facebook.com\n"
        "aman.com getbootstrap.com\n"
        "github.com twitter.com\n"
        "twitter.com chase.com\n"
        "mozilla.org aman.com\n"
        "twitter.com openai.com\n"
        "getbootstrap.com google.com\n"
        "openai.com twitter.com\n"
        "facebook.com twitter.com\n"
        "getbootstrap.com pcbuildinguf.com\n"
        "google.com facebook.com\n"
        "samsung.com mozilla.org\n"
        "google.com pcbuildinguf.com\n"
        "chase.com openai.com\n"
        "facebook.com google.com\n"
        "mozilla.org twitter.com\n"
        "github.com openai.com\n"
        "google.com instagram.com\n";

std::string expected_output =
        "aman.com 0.04\n"
        "chase.com 0.07\n"
        "facebook.com 0.10\n"
        "getbootstrap.com 0.06\n"
        "github.com 0.13\n"
        "google.com 0.05\n"
        "instagram.com 0.04\n"
        "mozilla.org 0.04\n"
        "openai.com 0.16\n"
        "pcbuildinguf.com 0.06\n"
        "samsung.com 0.03\n"
        "twitter.com 0.21\n"
        "weather.com 0.01\n";

REQUIRE(graph(input) == expected_output);
}


TEST_CASE("Test Case 2", "[PageRank]") {
    std::string input =
            "5 5\n"
            "samsung.com roblox.com\n"
            "samsung.com microsoft.com\n"
            "microsoft.com stackoverflow.com\n"
            "microsoft.com samsung.com\n"
            "roblox.com stackoverflow.com\n";

    std::string expected_output =
            "microsoft.com 0.02\n"
            "roblox.com 0.02\n"
            "samsung.com 0.02\n"
            "stackoverflow.com 0.05\n";

    REQUIRE(graph(input) == expected_output);
}


TEST_CASE("Test Case 3", "[PageRank]") {
    std::string input =
            "160 9\n"
            "github.com aman.com\n"
            "samsung.com ufl.edu\n"
            "instagram.com aman.com\n"
            "samsung.com getbootstrap.com\n"
            "samsung.com pcbuildinguf.com\n"
            "instagram.com reactjs.org\n"
            "python.org weather.com\n"
            "microsoft.com google.com\n"
            "roblox.com aman.com\n"
            "zoom.us apple.com\n"
            "microsoft.com instagram.com\n"
            "zoom.us reactjs.org\n"
            "instagram.com apple.com\n"
            "samsung.com google.com\n"
            "aman.com samsung.com\n"
            "roblox.com instagram.com\n"
            "weather.com ufl.edu\n"
            "roblox.com pcbuildinguf.com\n"
            "weather.com google.com\n"
            "disney.com zoom.us\n"
            "twitter.com roblox.com\n"
            "aman.com python.org\n"
            "chase.com microsoft.com\n"
            "twitter.com disney.com\n"
            "weather.com disney.com\n"
            "github.com reactjs.org\n"
            "google.com getbootstrap.com\n"
            "disney.com openai.com\n"
            "stackoverflow.com google.com\n"
            "aman.com google.com\n"
            "aman.com weather.com\n"
            "facebook.com chase.com\n"
            "microsoft.com reactjs.org\n"
            "apple.com samsung.com\n"
            "disney.com aman.com\n"
            "weather.com facebook.com\n"
            "samsung.com reactjs.org\n"
            "chase.com google.com\n"
            "reactjs.org openai.com\n"
            "reactjs.org ufl.edu\n"
            "twitter.com weather.com\n"
            "reactjs.org google.com\n"
            "instagram.com twitter.com\n"
            "samsung.com apple.com\n"
            "roblox.com stackoverflow.com\n"
            "stackoverflow.com apple.com\n"
            "github.com roblox.com\n"
            "roblox.com github.com\n"
            "mozilla.org samsung.com\n"
            "python.org pcbuildinguf.com\n"
            "mozilla.org openai.com\n"
            "google.com ufl.edu\n"
            "facebook.com samsung.com\n"
            "stackoverflow.com chase.com\n"
            "instagram.com getbootstrap.com\n"
            "instagram.com python.org\n"
            "mozilla.org google.com\n"
            "mozilla.org weather.com\n"
            "github.com samsung.com\n"
            "samsung.com facebook.com\n"
            "ufl.edu disney.com\n"
            "weather.com getbootstrap.com\n"
            "twitter.com samsung.com\n"
            "reactjs.org instagram.com\n"
            "roblox.com getbootstrap.com\n"
            "microsoft.com pcbuildinguf.com\n"
            "instagram.com zoom.us\n"
            "weather.com samsung.com\n"
            "chase.com facebook.com\n"
            "apple.com chase.com\n"
            "facebook.com github.com\n"
            "samsung.com openai.com\n"
            "instagram.com ufl.edu\n"
            "instagram.com samsung.com\n"
            "apple.com python.org\n"
            "stackoverflow.com aman.com\n"
            "chase.com apple.com\n"
            "facebook.com apple.com\n"
            "stackoverflow.com getbootstrap.com\n"
            "weather.com aman.com\n"
            "samsung.com github.com\n"
            "zoom.us twitter.com\n"
            "getbootstrap.com microsoft.com\n"
            "zoom.us python.org\n"
            "google.com weather.com\n"
            "reactjs.org samsung.com\n"
            "getbootstrap.com weather.com\n"
            "stackoverflow.com disney.com\n"
            "samsung.com roblox.com\n"
            "disney.com google.com\n"
            "python.org apple.com\n"
            "facebook.com aman.com\n"
            "reactjs.org pcbuildinguf.com\n"
            "openai.com mozilla.org\n"
            "chase.com openai.com\n"
            "pcbuildinguf.com facebook.com\n"
            "disney.com mozilla.org\n"
            "chase.com stackoverflow.com\n"
            "aman.com chase.com\n"
            "weather.com chase.com\n"
            "github.com instagram.com\n"
            "mozilla.org roblox.com\n"
            "microsoft.com openai.com\n"
            "google.com apple.com\n"
            "microsoft.com samsung.com\n"
            "openai.com samsung.com\n"
            "chase.com roblox.com\n"
            "twitter.com pcbuildinguf.com\n"
            "disney.com twitter.com\n"
            "instagram.com chase.com\n"
            "chase.com instagram.com\n"
            "getbootstrap.com twitter.com\n"
            "chase.com python.org\n"
            "chase.com reactjs.org\n"
            "getbootstrap.com disney.com\n"
            "apple.com reactjs.org\n"
            "roblox.com facebook.com\n"
            "microsoft.com roblox.com\n"
            "getbootstrap.com python.org\n"
            "github.com microsoft.com\n"
            "facebook.com google.com\n"
            "reactjs.org zoom.us\n"
            "weather.com pcbuildinguf.com\n"
            "samsung.com instagram.com\n"
            "ufl.edu weather.com\n"
            "python.org github.com\n"
            "openai.com google.com\n"
            "mozilla.org twitter.com\n"
            "openai.com aman.com\n"
            "aman.com facebook.com\n"
            "openai.com microsoft.com\n"
            "stackoverflow.com facebook.com\n"
            "getbootstrap.com github.com\n"
            "roblox.com apple.com\n"
            "microsoft.com twitter.com\n"
            "instagram.com github.com\n"
            "reactjs.org apple.com\n"
            "github.com chase.com\n"
            "python.org disney.com\n"
            "openai.com zoom.us\n"
            "getbootstrap.com samsung.com\n"
            "ufl.edu samsung.com\n"
            "facebook.com microsoft.com\n"
            "pcbuildinguf.com getbootstrap.com\n"
            "twitter.com instagram.com\n"
            "aman.com instagram.com\n"
            "aman.com zoom.us\n"
            "roblox.com twitter.com\n"
            "google.com pcbuildinguf.com\n"
            "chase.com ufl.edu\n"
            "ufl.edu mozilla.org\n"
            "github.com facebook.com\n"
            "facebook.com reactjs.org\n"
            "pcbuildinguf.com reactjs.org\n"
            "getbootstrap.com ufl.edu\n"
            "mozilla.org facebook.com\n"
            "twitter.com google.com\n"
            "python.org ufl.edu\n"
            "roblox.com openai.com\n"
            "disney.com facebook.com\n";

    std::string expected_output =
            "aman.com 0.04\n"
            "apple.com 0.06\n"
            "chase.com 0.04\n"
            "disney.com 0.04\n"
            "facebook.com 0.06\n"
            "getbootstrap.com 0.05\n"
            "github.com 0.04\n"
            "google.com 0.06\n"
            "instagram.com 0.04\n"
            "microsoft.com 0.03\n"
            "mozilla.org 0.03\n"
            "openai.com 0.04\n"
            "pcbuildinguf.com 0.05\n"
            "python.org 0.04\n"
            "reactjs.org 0.07\n"
            "roblox.com 0.03\n"
            "samsung.com 0.09\n"
            "stackoverflow.com 0.01\n"
            "twitter.com 0.03\n"
            "ufl.edu 0.06\n"
            "weather.com 0.05\n"
            "zoom.us 0.03\n";

    REQUIRE(graph(input) == expected_output);
}


TEST_CASE("Test Case 4", "[PageRank]") {
    std::string input =
            "17 16\n"
            "openai.com weather.com\n"
            "weather.com stackoverflow.com\n"
            "roblox.com github.com\n"
            "youtube.com aman.com\n"
            "zoom.us roblox.com\n"
            "facebook.com stackoverflow.com\n"
            "youtube.com zoom.us\n"
            "aman.com facebook.com\n"
            "github.com roblox.com\n"
            "ufl.edu roblox.com\n"
            "weather.com youtube.com\n"
            "stackoverflow.com ufl.edu\n"
            "zoom.us weather.com\n"
            "youtube.com openai.com\n"
            "openai.com roblox.com\n"
            "github.com stackoverflow.com\n"
            "openai.com github.com\n";

    std::string expected_output =
            "aman.com 0.00\n"
            "facebook.com 0.00\n"
            "github.com 0.30\n"
            "openai.com 0.00\n"
            "roblox.com 0.36\n"
            "stackoverflow.com 0.18\n"
            "ufl.edu 0.15\n"
            "weather.com 0.00\n"
            "youtube.com 0.00\n"
            "zoom.us 0.00\n";

    REQUIRE(graph(input) == expected_output);
}

TEST_CASE("Test Case 5", "[PageRank]") {
    std::string input =
            "3 11\n"
            "facebook.com weather.com\n"
            "getbootstrap.com zoom.us\n"
            "facebook.com getbootstrap.com\n";

    std::string expected_output =
            "facebook.com 0.00\n"
            "getbootstrap.com 0.00\n"
            "weather.com 0.00\n"
            "zoom.us 0.00\n";

    REQUIRE(graph(input) == expected_output);
}
