// clang++ --std=c++11 user_type_io.cpp -o user_type_io
//
// Simple Credit Card I/O

#include <cstdlib>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TCard {
    string Name;
    int CreditLine;
    int Balance;
    enum class CardType {
        VISA,
        MASTER,
        AMEX
    } Type;
};

ostream& operator<<(ostream& os, const TCard::CardType& type) {
    switch(type) {
    case TCard::CardType::VISA:
        return os << "VISA";
    case TCard::CardType::MASTER:
        return os << "MASTER";
    case TCard::CardType::AMEX:
        return os << "AMEX";
    default:
        ostringstream oss;
        oss << "unsupported card type " << static_cast<int>(type);
        throw runtime_error(oss.str());
    }
    return os;
}

ostream& operator<<(ostream& os, const TCard& card) {
    return os << "{\"" << card.Name << "\"," << card.CreditLine << ',' << card.Balance << ',' << card.Type << '}';
}

istream& operator>>(istream& is, TCard::CardType& type) {
    char c;
    if (is >> c) {
        is.putback(c);
        string card_type;
        while(is.get(c) and isalpha(c)) {
            card_type += tolower(c);
        }
        is.putback(c);
        if (card_type == "visa") {
            type = TCard::CardType::VISA;
        } else if (card_type == "master") {
            type = TCard::CardType::MASTER;
        } else if (card_type == "amex") {
            type = TCard::CardType::AMEX;
        } else {
            throw runtime_error("unsupported card type " + card_type);
        }
    }
    is.setf(ios_base::failbit);
    return is;
}

istream& operator>>(istream& is, TCard& card) {
    // format: { "<name>", <credit_line>, <balance>, <TYPE> }
    //
    char c;
    if (is >> c and c == '{' and is >> c and c == '"') {
        TCard tmp_card;
        while(is.get(c) and c != '"') {
            tmp_card.Name += c;
        }
        if (is >> c and c == ',') {
            if (is >> tmp_card.CreditLine >> c and c == ',') {
                if (is >> tmp_card.Balance >> c and c == ',') {
                    if (is >> tmp_card.Type >> c and c == '}') {
                        card = tmp_card;
                        return is;
                    }
                }
            }
        }
    }
    is.setf(ios_base::failbit);
    return is;
}

int main(int argc, const char* argv[])
try
{
    vector<TCard> cards;
    if (1 < argc) {
        ifstream is(argv[1]);
        if (not is.is_open()) {
            throw runtime_error(string{"failed to open input file "} + argv[1]);
        }
        for(TCard card; is >> card; cards.push_back(card)) {
        }
    } else {
        cout << "Enter credit cards in format: { \"<name>\", <credit_line>, <balance>, <TYPE> }" << endl;
        for(TCard card; cin >> card; cards.push_back(card)) {
        }
    }
    if (not cards.empty()) {
        size_t i {0};
        for(const auto& card: cards) {
            cout << ++i << ": " << card << endl;
        }
    } else {
        cout << "no cards are read" << endl;
    }
} catch(const exception& err) {
    cerr << "error: " << err.what() << endl;
}
