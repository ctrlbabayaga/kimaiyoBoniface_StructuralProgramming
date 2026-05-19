#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


struct Party {
    string name;
    string symbol;
};

class Candidate {
public:
    string name, position, region, gender, id;
    Party party;
    int voteCount = 0;

    Candidate(string n, string p, string r, string g, string i, Party pt) 
        : name(n), position(p), region(r), gender(g), id(i), party(pt) {}
};

class Voter {
public:
    string name, pollingStation, id;
    bool hasVoted = false;

    Voter(string n, string ps, string i) : name(n), pollingStation(ps), id(i) {}
};


bool authenticateAdmin() {
    string pass;
    cout << "\n[======================\n";
    cout << "\n[ADMIN ACCESS REQUIRED]\nEnter Admin Password: ";
    cout << "\n[======================\n";
    cin >> pass;
    return (pass == "admin2026"); 
}

void addNewVoter(vector<Voter>& voters) {
    string name, id, station;
    cout << "\n[======================\n";
    cout << "\n--- Register New Voter ---\n";
    cout << "\n[======================\n";
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter ID Number: ";
    cin >> id;
    cout << "Enter Polling Station: ";
    cin >> station;


    for (const auto& v : voters) {
        if (v.id == id) {
            cout << "Error: Voter ID already exists in the system.\n";
            return;
        }
    }

    voters.push_back(Voter(name, station, id));
    cout << "Voter successfully added to the system.\n";
}

void votingProcess(vector<Voter>& voters, vector<Candidate>& candidates) {
    string voterID;
    cout << "\n[======================\n";
    cout << "\n--- Voting Process ---\n";
    cout << "\n[======================\n";
    cout << "Enter your ID to verify: ";
    cin >> voterID;

    Voter* currentVoter = nullptr;
    for (auto& v : voters) {
        if (v.id == voterID) {
            currentVoter = &v;
            break;
        }
    }

    if (currentVoter == nullptr) {
        cout << "Error: ID not found. Please register first.\n";
        return;
    }

    if (currentVoter->hasVoted) {
        cout << "Access Denied: You have already cast your vote.\n";
        return;
    }

    cout << "Verification Successful. Welcome, " << currentVoter->name << ".\n";

    string positions[] = {"MCA", "MP", "Governor"};
    
    for (const string& pos : positions) {
        cout << "\nSelect candidate for " << pos << ":\n";
        vector<int> localIndices;
        
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i].position == pos) {
                cout << i << ". " << candidates[i].name << " (" << candidates[i].party.name << ")\n";
                localIndices.push_back(i);
            }
        }

        int choice;
        cout << "Enter index number: ";
        cin >> choice;

        // Simple validation
        bool valid = false;
        for (int idx : localIndices) if (idx == choice) valid = true;

        if (valid) {
            candidates[choice].voteCount++;
            cout << "Vote cast for " << pos << ".\n";
        } else {
            cout << "Invalid choice. Vote for this position skipped.\n";
        }
    }

    currentVoter->hasVoted = true;
    cout << "\nThank you for voting! Your data has been stored.\n";
}

void checkResults(vector<Candidate> candidates) {
    if (candidates.empty()) {
        cout << "No candidates registered.\n";
        return;
    }

    cout << "\n--- Final Results & Winners ---\n";
    string positions[] = {"MCA", "MP", "Governor"};

    for (const string& pos : positions) {
        vector<Candidate> filtered;
        for (const auto& c : candidates) {
            if (c.position == pos) filtered.push_back(c);
        }

        if (filtered.empty()) continue;

        // Sort to find winner
        sort(filtered.begin(), filtered.end(), [](const Candidate& a, const Candidate& b) {
            return a.voteCount > b.voteCount;
        });

        cout << "\nPOSITION: " << pos << "\n";
        cout << "-------------------------------------------\n";
        for (const auto& c : filtered) {
            cout << left << setw(15) << c.name << " | " << setw(10) << c.party.name << " | Votes: " << c.voteCount << "\n";
        }
        cout << "WINNER: " << filtered[0].name << " with " << filtered[0].voteCount << " votes.\n";
    }
}

int main() {
    if (!authenticateAdmin()) {
        cout << "Incorrect Password. System Locking.\n";
        return 0;
    }

    vector<Voter> voters;
    vector<Candidate> candidates;

    // Pre-seeding some candidates for testing
    Party pA = {"Orange Democratic Party", "ODM"};
    Party pB = {"Universal Democratic Association", "UDA"};
    Party pC = {"Wiper", "WIP"};
    Party pD = {"Democrats Church Party", "DCP"};
    Party pE = {"Collective Advisory Party", "CAP"};
    
    candidates.push_back(Candidate("Jane Wanjiku", "MCA", "Nairobi", "Female", "C1", pA));
    candidates.push_back(Candidate("John Omari", "MCA", "Nairobi", "Male", "C2", pB));
    candidates.push_back(Candidate("Alice Mutua", "MP", "Nairobi", "Female", "C3", pA));
    candidates.push_back(Candidate("Bob Kariuki", "MP", "Nairobi", "Male", "C4", pB));
    candidates.push_back(Candidate("John Mbadi", "Governor", "Nairobi", "Male", "C5", pA));
    candidates.push_back(Candidate("Evans Kidero", "Governor", "Nairobi", "Male", "C6", pB));
    candidates.push_back(Candidate("Nancy Chepchumba", "MCA", "Nairobi", "Female", "C7", pC));
    candidates.push_back(Candidate("Rigathi Gachagua", "MCA", "Nairobi", "Male", "C8", pD));
    candidates.push_back(Candidate("Peter Stanley", "MP", "Nairobi", "Male", "C9", pC));
    candidates.push_back(Candidate("Lamar Johnson", "MP", "Nairobi", "Male", "C10", pD));
    candidates.push_back(Candidate("Esther Pasaris", "Governor", "Nairobi", "Female", "C11", pC));
    candidates.push_back(Candidate("Jerry Can", "Governor", "Nairobi", "Male", "C12", pD));
    candidates.push_back(Candidate("Micheal Flexx", "MCA", "Nairobi", "Male", "C13", pE));
    candidates.push_back(Candidate("Chris Odinga", "MP", "Nairobi", "Male", "C14", pE));
    candidates.push_back(Candidate("Mellisa Ochundo", "Governor", "Nairobi", "Female", "C15", pE));

    int choice;
    do {
        cout << "\n==============================\n";
        cout << "   DIGITAL VOTING SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Add New Voter\n";
        cout << "2. Voting Process\n";
        cout << "3. Check Results\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addNewVoter(voters); break;
            case 2: votingProcess(voters, candidates); break;
            case 3: checkResults(candidates); break;
            case 4: cout << "Exiting system...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}