#include <bits/stdc++.h>
using namespace std;

struct Transaction {
    int id;
    double amount;
    string date;
    bool isRefund;
};

struct Settlement {
    int id;
    double amount;
    string date;
};

int getMonth(string date) {
    return stoi(date.substr(3, 2));
}

// -------- DATA --------
void generateData(vector<Transaction>& transactions, vector<Settlement>& settlements) {

    transactions.push_back({1, 100.0, "01-01", false});
    settlements.push_back({1, 100.0, "02-01"});

    transactions.push_back({2, 200.0, "31-01", false});
    settlements.push_back({2, 200.0, "01-02"});

    transactions.push_back({3, 33.33, "05-01", false});
    transactions.push_back({4, 33.33, "05-01", false});
    transactions.push_back({5, 33.34, "05-01", false});
    settlements.push_back({3, 100.0, "06-01"});

    transactions.push_back({6, 150.0, "10-01", false});
    transactions.push_back({6, 150.0, "10-01", false});
    settlements.push_back({6, 150.0, "11-01"});

    transactions.push_back({7, 500.0, "15-01", false});

    transactions.push_back({8, -100.0, "20-01", true});
}

// -------- ANALYSIS --------
void analyze(vector<Transaction>& transactions, vector<Settlement>& settlements) {

    unordered_map<int, vector<Transaction>> txnMap;
    unordered_map<int, Settlement> settleMap;

    vector<int> duplicates, missingSettlement, lateSettlement, invalidRefund;

    double totalTxn = 0, totalSettle = 0;

    // Fill transaction map
    for (auto& t : transactions) {
        txnMap[t.id].push_back(t);
        totalTxn += t.amount;
    }

    // Fill settlement map
    for (auto& s : settlements) {
        settleMap[s.id] = s;
        totalSettle += s.amount;
    }

    // Find duplicates
    for (auto& it : txnMap) {
        if (it.second.size() > 1)
            duplicates.push_back(it.first);
    }

    // Check mismatches
    for (auto& it : txnMap) {
        int id = it.first;
        Transaction t = it.second[0];

        if (t.isRefund && settleMap.find(id) == settleMap.end()) {
            invalidRefund.push_back(id);
            continue;
        }

        if (settleMap.find(id) == settleMap.end()) {
            missingSettlement.push_back(id);
        } else {
            if (getMonth(t.date) != getMonth(settleMap[id].date)) {
                lateSettlement.push_back(id);
            }
        }
    }

    // -------- OUTPUT --------
    cout << "\n========== ANALYSIS REPORT ==========\n";

    cout << "\nMissing Settlements:\n";
    for (int id : missingSettlement) cout << id << endl;

    cout << "\nLate Settlements:\n";
    for (int id : lateSettlement) cout << id << endl;

    cout << "\nDuplicate Transactions:\n";
    for (int id : duplicates) cout << id << endl;

    cout << "\nInvalid Refunds:\n";
    for (int id : invalidRefund) cout << id << endl;

    double diff = abs(totalTxn - totalSettle);
    cout << "\nRounding Difference: " << diff << endl;
}

// -------- MAIN --------
int main() {
    vector<Transaction> transactions;
    vector<Settlement> settlements;

    generateData(transactions, settlements);
    analyze(transactions, settlements);

    return 0;
}