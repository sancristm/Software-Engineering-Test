//
// Created by sancrist  on 5/7/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

// Function to fetch API data
string getApiData(string url) {

    string result = "";

    string command = "curl -s \"" + url + "\"";

    char buffer[256];

    FILE* pipe = popen(command.c_str(), "r");

    if (!pipe) {
        return "";
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    pclose(pipe);

    return result;
}

// Extract value from JSON text
string extractValue(string text, string key) {

    size_t start = text.find(key);

    if (start == string::npos) {
        return "";
    }

    start = text.find(":", start);

    if (start == string::npos) {
        return "";
    }

    start++;

    // Skip spaces and quotes
    while (start < text.size() &&
           (text[start] == ' ' ||
            text[start] == '\"')) {
        start++;
    }

    size_t end = start;

    while (end < text.size() &&
           text[end] != '\"' &&
           text[end] != ',' &&
           text[end] != '}') {
        end++;
    }

    return text.substr(start, end - start);
}

// Function to get top articles
vector<string> topArticles(int limit) {

    vector<pair<string, int>> articles;

    int currentPage = 1;
    int totalPages = 1;

    while (currentPage <= totalPages) {

        string url =
            "https://jsonmock.hackerrank.com/api/articles?page="
            + to_string(currentPage);

        string response = getApiData(url);

        // Get total pages
        if (currentPage == 1) {

            string total =
                extractValue(response, "\"total_pages\"");

            totalPages = stoi(total);
        }

        // Find each article block
        size_t pos = 0;

        while ((pos = response.find("\"title\"", pos))
               != string::npos) {

            size_t nextPos =
                response.find("\"title\"", pos + 1);

            string block;

            if (nextPos != string::npos) {
                block = response.substr(pos, nextPos - pos);
            } else {
                block = response.substr(pos);
            }

            string title =
                extractValue(block, "\"title\"");

            string storyTitle =
                extractValue(block, "\"story_title\"");

            string commentsText =
                extractValue(block, "\"num_comments\"");

            string articleName = "";

            if (title != "null" && title != "") {
                articleName = title;
            }
            else if (storyTitle != "null" &&
                     storyTitle != "") {
                articleName = storyTitle;
            }
            else {
                pos++;
                continue;
            }

            int comments = 0;

            if (commentsText != "null" &&
                commentsText != "") {
                comments = stoi(commentsText);
            }

            articles.push_back(
                make_pair(articleName, comments)
            );

            pos++;
        }

        currentPage++;
    }

    // Sort articles
    sort(articles.begin(), articles.end(),
        [](pair<string, int> a,
           pair<string, int> b) {

            if (a.second != b.second) {
                return a.second > b.second;
            }

            return a.first > b.first;
        });

    vector<string> answer;

    for (int i = 0;
         i < limit && i < articles.size();
         i++) {

        answer.push_back(articles[i].first);
    }

    return answer;
}

// int main() {
//
//     int limit;
//
//     cout << "Enter number of top articles: ";
//     cin >> limit;
//
//     vector<string> result =
//         topArticles(limit);
//
//     cout << "\nTop Articles:\n";
//
//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << endl;
//     }
//
//     return 0;
// }