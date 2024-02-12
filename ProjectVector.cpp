#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to simulate a match between two teams
void playMatch(const string& team1, const string& team2) {
    cout << "Team " << team1 << " vs Team " << team2 << endl;
    // Simulate match here
}

// Function to generate matches for a given set of teams
void generateMatches(const vector<string>& teams) {
    int n = teams.size();
    if (n <= 1) {
        return;
    }
    vector<string> nextRound;
    // Schedule matches for the current round
    for (int i = 0; i < n / 2; ++i) {
        playMatch(teams[i], teams[n - i - 1]);
    }
    // Generate next round with winners
    for (int i = 0; i < n / 2; ++i) {
        nextRound.push_back(teams[i]);
    }
    generateMatches(nextRound);
}

// Main function to initiate the tournament
void startTournament(int numTeams) {
    vector<string> teams;
    for (int i = 1; i <= numTeams; ++i) {
        cout << "Enter name for team " << i << ": ";
        string teamName;
        cin >> teamName;
        teams.push_back(teamName);
    }
    generateMatches(teams);
}

int main() {
    int numTeams = 8; // Change this to desired number of teams (should be a power of 2)
    startTournament(numTeams);
    return 0;
}

