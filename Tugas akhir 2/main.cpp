#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Match {
public:
    string team1, team2;
    int score1, score2;

    Match(string t1, string t2, int s1, int s2) {
        team1 = t1;
        team2 = t2;
        score1 = s1;
        score2 = s2;
    }

    void displayMatch() const {
        cout << team1 << " (" << score1 << ") vs " << team2 << " (" << score2 << ")\n";
    }
};

class MatchStatistics {
private:
    vector<Match> matches;

public:

    void addMatch(string t1, string t2, int s1, int s2) {
        matches.push_back(Match(t1, t2, s1, s2));
        cout << "Pertandingan berhasil ditambahkan!\n";
    }


    void viewAllMatches() const {
        if (matches.size() == 0) {
            cout << "Belum ada pertandingan yang dicatat.\n";
            return;
        }

        cout << "\nDaftar semua hasil pertandingan:\n";
        for (int i = 0; i < matches.size(); i++) {
            matches[i].displayMatch();
        }
    }


    void viewTeamStats(string team) const {
        int matchesPlayed = 0, wins = 0, losses = 0, draws = 0, goalsScored = 0, goalsConceded = 0;

        for (int i = 0; i < matches.size(); i++) {
            if (matches[i].team1 == team || matches[i].team2 == team) {
                matchesPlayed++;
                if (matches[i].team1 == team) {
                    goalsScored += matches[i].score1;
                    goalsConceded += matches[i].score2;
                    if (matches[i].score1 > matches[i].score2) wins++;
                    else if (matches[i].score1 < matches[i].score2) losses++;
                    else draws++;
                } else if (matches[i].team2 == team) {
                    goalsScored += matches[i].score2;
                    goalsConceded += matches[i].score1;
                    if (matches[i].score2 > matches[i].score1) wins++;
                    else if (matches[i].score2 < matches[i].score1) losses++;
                    else draws++;
                }
            }
        }

        if (matchesPlayed == 0) {
            cout << "Tidak ada data pertandingan untuk tim " << team << ".\n";
            return;
        }

        cout << "\nStatistik untuk tim: " << team << "\n";
        cout << "Pertandingan dimainkan: " << matchesPlayed << "\n";
        cout << "Menang: " << wins << "\n";
        cout << "Kalah: " << losses << "\n";
        cout << "Seri: " << draws << "\n";
        cout << "Gol yang dicetak: " << goalsScored << "\n";
        cout << "Gol yang kebobolan: " << goalsConceded << "\n";
    }
};

int main() {
    MatchStatistics stats;
    int choice;

    do {
        cout << "\nSistem Pencatatan Statistik Hasil Pertandingan Sepakbola\n";
        cout << "1. Tambahkan hasil pertandingan\n";
        cout << "2. Lihat semua pertandingan\n";
        cout << "3. Lihat statistik tim\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string t1, t2;
                int s1, s2;
                cout << "Masukkan nama tim pertama: ";
                cin.ignore();
                getline(cin, t1);
                cout << "Masukkan skor tim pertama: ";
                cin >> s1;
                cout << "Masukkan nama tim kedua: ";
                cin.ignore();
                getline(cin, t2);
                cout << "Masukkan skor tim kedua: ";
                cin >> s2;
                stats.addMatch(t1, t2, s1, s2);
                break;
            }
            case 2:
                stats.viewAllMatches();
                break;
            case 3: {
                string team;
                cout << "Masukkan nama tim yang ingin dilihat statistiknya: ";
                cin.ignore();
                getline(cin, team);
                stats.viewTeamStats(team);
                break;
            }
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
