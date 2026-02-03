#include <bits/stdc++.h>
using namespace std;

struct Card {
    string name;
    long long ID;
    int type;
    string dateTimeRaw;
};

vector<string> splitString (string str, const string& delimiters) {
    for(char& c : str){
        if(delimiters.find(c) != string::npos) c = ',';
    }
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while(getline(ss >> ws, token, ',')){
        tokens.push_back(token);
    }
    
    return tokens;
}

vector<Card> sortCardsByName(vector<Card> cards) {
    stable_sort(cards.begin(), cards.end(), [](Card a, Card b) {
        return a.name < b.name;
    });
    return cards;
}

vector<Card> sortCardsByID(vector<Card> cards) {
    stable_sort(cards.begin(), cards.end(), [](Card a, Card b) {
        return a.ID < b.ID;
    });
    return cards;
}

vector<Card> sortCardsByType(vector<Card> cards) {
    stable_sort(cards.begin(), cards.end(), [](Card a, Card b) {
        return a.type < b.type;
    });
    return cards;
}

vector<Card> sortCardsByDate(vector<Card> cards) {
    stable_sort(cards.begin(), cards.end(), [](Card a, Card b) {
        return a.dateTimeRaw < b.dateTimeRaw;
    });
    return cards;
}

int main() {
    size_t n;
    cin >> n;
    vector<string> inputs(n);
    vector<Card> cards(n);
    vector<int> ordinal;
    unordered_map<string, int> typeMap = {
    {"Skrimsli", 1},
    {"Skrimsli - Venjulegt", 2},
    {"Skrimsli - Ahrifa", 3},
    {"Skrimsli - Bodunar", 4},
    {"Skrimsli - Samruna", 5},
    {"Skrimsli - Samstillt", 6},
    {"Skrimsli - Thaeo", 7},
    {"Skrimsli - Penduls", 8},
    {"Skrimsli - Tengis", 9},
    {"Galdur", 10},
    {"Galdur - Venjulegur", 11},
    {"Galdur - Bunadar", 12},
    {"Galdur - Svida", 13},
    {"Galdur - Samfelldur", 14},
    {"Galdur - Bodunar", 15},
    {"Galdur - Hradur", 16},
    {"Gildra", 17},
    {"Gildra - Venjuleg", 18},
    {"Gildra - Samfelld", 19},
    {"Gildra - Mot", 20},
    {"Annad", 21}
    };
    unordered_map<string, int> ordinalMap = {
        {"nafn",1}, 
        {"id",2},
        {"flokkur",3},
        {"dagsetning",4}
    };
    for(size_t i = 0; i < n; ++i) {
        getline(cin >> ws, inputs[i]);
    }
    for(size_t i=0; i<4; ++i){
        string s;
        cin >> s;
        ordinal.push_back(ordinalMap[s]);
    }
    reverse(ordinal.begin(), ordinal.end());
    
    for(size_t i = 0; i < n; ++i) {
        vector<string> input = splitString(inputs[i], ",");
        int noObjects = input.size();
        cards[i].name = input[0];
        cards[i].ID = stoll(input[1]);
        cards[i].type = typeMap[input[2]];
        cards[i].dateTimeRaw = input[3];
    }

    for(int& i : ordinal){
        if(i == 1) cards = sortCardsByName(cards);
        if(i == 2) cards = sortCardsByID(cards);
        if(i == 3) cards = sortCardsByType(cards);
        if(i == 4) cards = sortCardsByDate(cards);
    }
    for(size_t i = 0; i < n; ++i) {
        cout << cards[i].name << endl;
    }
    
    return 0;
}
