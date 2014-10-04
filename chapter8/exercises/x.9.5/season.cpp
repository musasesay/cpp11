// clang++ --std=c++11 season.cpp -o season

#include <iostream>
#include <locale>
#include <vector>

using namespace std;

enum class ESeason : char {
    Spring,
    Summer,
    Autumn,
    Winter
};

ESeason& operator--(ESeason& season) {
    if (season == ESeason::Spring) {
        season = ESeason::Winter;
    } else {
        season = static_cast<ESeason>(static_cast<char>(season) - 1);
    }
    return season;
}

ESeason& operator++(ESeason& season) {
    if (season == ESeason::Winter) {
        season = ESeason::Spring;
    } else {
        season = static_cast<ESeason>(static_cast<char>(season) + 1);
    }
    return season;
}

class TSeasonFacet : public locale::facet {
public:
    TSeasonFacet() {}
    const char* write(const ESeason& season) const {
        size_t index {static_cast<size_t>(season) - static_cast<size_t>(ESeason::Spring)};
        if (index >= Seasons().size()) {
            return "unkonwn season";
        }
        return Seasons()[index];
    }
    bool read(const string& str, ESeason& season) const {
        auto iter = find(Seasons().begin(), Seasons().end(), str);
        if (iter == Seasons().end()) {
            return false;
        }
        season = static_cast<ESeason>(static_cast<size_t>(ESeason::Spring) + (iter - Seasons().begin()));
        return true;
    }
public:
    static locale::id id;
protected:
    using SeasonNames = vector<const char*>;
    virtual const SeasonNames& Seasons() const = 0;
};

locale::id TSeasonFacet::id;

class TEnglishSeasonFacet : public TSeasonFacet {
protected:
    virtual const SeasonNames& Seasons() const {
        return Names;
    }
private:
    SeasonNames Names {"spring", "summer", "autumn", "winter"};
};

class TRussianSeasonFacet : public TSeasonFacet {
protected:
    virtual const SeasonNames& Seasons() const {
        return Names;
    }
private:
    SeasonNames Names {"весна", "лето", "осень", "зима"};
};

class TArmenianSeasonFacet : public TSeasonFacet {
protected:
    virtual const SeasonNames& Seasons() const {
        return Names;
    }
private:
    SeasonNames Names {"գարունը", "ամառ", "աշուն", "ձմեռը"};
};

ostream& operator<<(ostream& os, const ESeason& season) {
    locale loc {os.getloc()};
    if (has_facet<TSeasonFacet>(loc)) {
        os << use_facet<TSeasonFacet>(loc).write(season);
    } else {
        os << static_cast<int>(season);
    }
    return os;
}

istream& operator>>(istream& is, ESeason& season) {
    locale loc {is.getloc()};
    if (has_facet<TSeasonFacet>(loc)) {
        const TSeasonFacet& facet {use_facet<TSeasonFacet>(loc)};
        string str;
        if (not (is >> str and facet.read(str, season))) {
            is.setstate(ios_base::failbit);
        }
    } else {
        int i;
        cin >> i;
        season = static_cast<ESeason>(i);
    }
    return is;
}

template<typename TFacet>
void PrintSeasons(ESeason season, size_t count=1) {
    locale loc {locale(), new TFacet {}};
    while(count--) {
        cout.imbue(locale());
        cout << season << " ";
        cout.imbue(loc);
        cout << season << endl;
        ++season;
    }
    cout.imbue(locale());
}

template<typename TFacet>
ESeason ReadSeason() {
    locale loc {locale(), new TFacet {}};
    cin.imbue(loc);
    ESeason season;
    cout << "enter season in english: ";
    cin >> season;
    return season;
}

void TestSeasons() {
    {
        ESeason season {ESeason::Spring};
        for(size_t i {5}; --i; --season) {
            cout << season << endl;
        }
    }
    cout << "---" << endl;
    {
        ESeason season {ESeason::Spring};
        for(size_t i {5}; --i; ++season) {
            cout << season << endl;
        }
    }
}

int main(int, char* []) {
    TestSeasons();
    cout << "---" << endl;
    PrintSeasons<TEnglishSeasonFacet>(ESeason::Summer, 4);
    cout << "---" << endl;
    PrintSeasons<TRussianSeasonFacet>(ESeason::Summer, 4);
    cout << "---" << endl;
    PrintSeasons<TArmenianSeasonFacet>(ESeason::Summer, 4);
    cout << "---" << endl;
    {
        ESeason season {ReadSeason<TEnglishSeasonFacet>()};
        cout << "The season you entered is:" << endl;
        PrintSeasons<TEnglishSeasonFacet>(season);
        PrintSeasons<TRussianSeasonFacet>(season);
        PrintSeasons<TArmenianSeasonFacet>(season);
    }
    return 0;
}
