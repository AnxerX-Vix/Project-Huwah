#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Kelas untuk menyimpan data pertandingan
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

// Kelas untuk Sistem Pencatatan Statistik
class MatchStatistics {
private:
    vector<Match> matches; // Array dinamis untuk menyimpan data pertandingan

public:
    // Menambahkan pertandingan ke daftar
    void addMatch(string t1, string t2, int s1, int s2) {
        matches.emplace_back(t1, t2, s1, s2);
        cout << "Pertandingan berhasil ditambahkan!\n";
    }

    // Menampilkan semua pertandingan
    void viewAllMatches() const {
        if (matches.empty()) {
            cout << "Belum ada pertandingan yang dicatat.\n";
            return;
        }

        cout << "\nDaftar semua hasil pertandingan:\n";
        for (const auto &match : matches) {
            match.displayMatch();
        }
    }

    // Menampilkan statistik tim tertentu
    void viewTeamStats(string team) const {
        int matchesPlayed = 0, wins = 0, losses = 0, draws = 0, goalsScored = 0, goalsConceded = 0;

        for (const auto &match : matches) {
            if (match.team1 == team || match.team2 == team) {
                matchesPlayed++;
                if (match.team1 == team) {
                    goalsScored += match.score1;
                    goalsConceded += match.score2;
                    if (match.score1 > match.score2) wins++;
                    else if (match.score1 < match.score2) losses++;
                    else draws++;
                } else if (match.team2 == team) {
                    goalsScored += match.score2;
                    goalsConceded += match.score1;
                    if (match.score2 > match.score1) wins++;
                    else if (match.score2 < match.score1) losses++;
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

// Fungsi utama
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
                cin >> t1;
                cout << "Masukkan skor tim pertama: ";
                cin >> s1;
                cout << "Masukkan nama tim kedua: ";
                cin >> t2;
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
                cin >> team;
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
