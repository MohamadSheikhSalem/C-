//
//  main.cpp
//  Hausaufgabe
//
//  Created by Majed Abdalrahman on 20.05.20.
//  Copyright © 2020 Majed Abdalrahman. All rights reserved.
//

#include <iostream>
#include <string>
# include <vector>

using namespace std;

vector<string> split(string eingabe, char operation) {
    // diese Vector wird zurückgegeben
    vector <string> sVec;
    bool findOp = false;

    string part1 = "";
    string part2 = "";

    for (unsigned int i = 0; i < eingabe.size(); i++) {
        if (eingabe.at(i) != operation && findOp == false) {
            part1 += eingabe.at(i);

        } else if (eingabe.at(i) == operation) {
            findOp = true;

        } else if (eingabe.at(i) != operation && findOp == true) {
            part2 += eingabe.at(i);
        }
    }
    sVec.push_back(part1);
    sVec.push_back(part2);


    return sVec;
}

vector<double> stringToDouble(vector<string> str) {
    vector<double> zahlen;
    double zahl1 = 0;
    double zahl2 = 0;

    try {
        zahl1 = stod(str.at(0));
        zahl2 = stod(str.at(1));


    } catch (invalid_argument) {
        cout << "Falsche Eingabe" << endl;
    }
    zahlen.push_back(zahl1);
    zahlen.push_back(zahl2);
    return zahlen;
}

void addition(vector<double> zahlen) {
    cout << zahlen.at(0) << " " << "+ " << zahlen.at(1) << " = " << zahlen.at(0) + zahlen.at(1) << endl;
}
void subtraktion(vector<double> zahlen) {
    cout << zahlen.at(0) << " " << "- " << zahlen.at(1) << " = " << zahlen.at(0) - zahlen.at(1) << endl;
}
void multiplikation(vector<double> zahlen) {
    cout << zahlen.at(0) << " " << "* " << zahlen.at(1) << " = " << zahlen.at(0) * zahlen.at(1) << endl;
}
void division(vector<double> zahlen) {
    cout << zahlen.at(0) << " " << "/ " << zahlen.at(1) << " = " << zahlen.at(0) / zahlen.at(1) << endl;
}
void modulo(vector<int> zahlen) {
    cout << zahlen.at(0) << " " << "% " << zahlen.at(1) << " = " << zahlen.at(0) % zahlen.at(1) << endl;
}

void eingabeBehandlung(int startwert);

void menueAnzeige() {
    string startwert;
    int intStartwert = 10;

    cout << "Bitte wählen Sie einen Startwert aus der Menü ein" << endl;
    cout << "<1> Addition" << endl;
    cout << "<2> Subtraktion" << endl;
    cout << "<3> Multiplikation" << endl;
    cout << "<4> Division" << endl;
    cout << "<5> Modulo" << endl;
    cout << "<6> 15 Fibonacci-Zahlen" << endl;
    cout << "<7> Fakultät" << endl;
    cout << "<0> Beenden" << endl;

    cin >> startwert;
    
    try {
        intStartwert = stoi(startwert);

    } catch (invalid_argument) {
        cout << "Falsche Eingabe! Keine Buchstaben zulässig" << endl;
        menueAnzeige();
    }
    eingabeBehandlung(intStartwert);

}


int main(int argc, const char * argv[]) {
    // insert code here...
    menueAnzeige();
    return 0;
}

// Methode zur EingabeBehandlung
void eingabeBehandlung(int startwert) {
    string opEingabe;
    vector <string> eingabe;
    vector<double> zEingabe;

    switch(startwert) {
    case 1:
        cout << "Schreiben Sie bitte Zahlen zum Addieren" << endl;
        cin >> opEingabe;
        eingabe = split(opEingabe, '+');
        zEingabe = stringToDouble(eingabe);
        addition(zEingabe);

        break;
    case 2:
        cout << "Schreiben Sie bitte Zahlen zum Subtraktion" << endl;
        cin >> opEingabe;
        eingabe = split(opEingabe, '-');
        zEingabe = stringToDouble(eingabe);
        subtraktion(zEingabe);
        break;
    case 3:
        cout << "Schreiben Sie bitte Zahlen zum Multiplikation" << endl;
        cin >> opEingabe;
        eingabe = split(opEingabe, '*');
        zEingabe = stringToDouble(eingabe);
        multiplikation(zEingabe);

        break;
    case 4:
        cout << "Schreiben Sie bitte Zahlen zum Division" << endl;
        cin >> opEingabe;
        eingabe = split(opEingabe, '/');
        zEingabe = stringToDouble(eingabe);
        division(zEingabe);
        break;
    case 5:
        cout << "Schreiben Sie bitte Zahlen zum Modulo" << endl;
        cin >> opEingabe;
        eingabe = split(opEingabe, '%');
        zEingabe = stringToDouble(eingabe);
        addition(zEingabe);
        break;
    case 6:
        break;
    case 7:
        break;
    case 0:
        break;
    default:
        cout << "Falsche Eingabe!\n" << endl;
        menueAnzeige();
        break;

    }

}
