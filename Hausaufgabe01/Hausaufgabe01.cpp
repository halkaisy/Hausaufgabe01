/*
	C++ SoSe 2019
	Uebungsblatt 01
	Josefin Claus, _______
	Haidar Alkaisy, 295669

*/
#include <iostream>
#include <string>
using namespace std;
void menue();
void eingabeaufforderung();
void menueAusfuehren(int auswahlNummer);
void readOperation(string operationName, char op, int auswahlNummer);
double berechne(double zahl1, double zahl2, char op);
int fibonacci(int zahl);
int fakultaet(int zahl);
void sollErneutGerechnetWerden(int auswahlNummer);



//Main-Methode
int main()
{
	eingabeaufforderung();

	
}

//Diese Methode gibt das Menue auf der Konsole aus.
void menue() {
	cout << "<1> Addition\n<2> Subtraktion\n<3> Multiplikation\n<4> Division\n<5> Modulo\n<6> 15 Fibonnacci-Zahlen\n<7> Fakultaet\n<0> Beenden" << endl;

	return;
}

//Methode zum Ausgeben des Menues und einlesen der Benutzereingabe.
void eingabeaufforderung() {
	int auswahlNummer;
	bool weiter = true;
	//Gebe das Menue aus und lese eine Zahl ein, bis vom Benutzer eine 0 eingegeben wird.
	do {
		menue();
		cin >> auswahlNummer;
		//Fuehre das vom Benutzer ausgewaehlte Programm aus.
		menueAusfuehren(auswahlNummer);

		//Gehe aus der Schleife heraus, wenn 0 eingegeben wurde.
		if (auswahlNummer == 0) {
			weiter = false;
		}
	} while (weiter);

	cout << "Programm wird beendet." << endl;

}

//Funktion zum berechnen einfacher Rechenoperationen.
double berechne(double zahl1, double zahl2, char op) {

	switch (op) {
	
	case '+':
		return zahl1 + zahl2;
		break;
	case '-':
		return zahl1 - zahl2;
		break;
	case '*':
		return zahl1 * zahl2;
	case '/':
		return zahl1 / zahl2;
		break;
	case '%':
		//zahl1 und zahl2 werden gecasted, weil Modulo keine Berechnungen mit double erlaubt.
		return ((int) zahl1) % ((int) zahl2);
		break;
	default:
		break;
	}

}

//Liest die Rechenaufgabe des Benutzers ein und gibt das Ergebnis auf der Konsole aus.
void readOperation(string operationName, char zuPruefenderOperator, int auswahlNummer) {
	double zahl1;
	double zahl2;
	char op;
	double ergebnis;
	char weiter = true;

	//Der Benutzer soll solange Aufgaben eingeben, bis eine Rechenaufgabe mit korrektem Operator gestellt wird.
	do {
		//Lese Rechenaufgabe ein
		cout << operationName << endl;
		cin >> zahl1 >> op >> zahl2;

		//Gebe bei falschem Operator eine Fehlermeldung aus.
		if (op != zuPruefenderOperator) {

			cout << "Falscher Operator!" << endl;
		}
		else {
			ergebnis = berechne(zahl1, zahl2, zuPruefenderOperator);
			//Ausgabe vom Ergebnis
			cout << "Ergebnis von " << zahl1 << " " << zuPruefenderOperator << " " << zahl2 << " = " << ergebnis << endl;

			sollErneutGerechnetWerden(auswahlNummer);

			weiter = false;
		}
	} while (weiter);
}

//Die Auswahl der Rechenopertation des Benutzers wird hier durch ein switch-case ausgewaehlt.
void menueAusfuehren(int auswahlNummer) {

	double zahl1;
	double zahl2;
	char op;
	double ergebnis;

	//summe fuer die fibonnaci Berechnung
	int summe = 0;

	int fakultaetszahl;
	
	//Auswahlnummer (vom Benutzer eingegeben) wird uebergeben.
	switch (auswahlNummer) {
	case 1:
		readOperation("Addition", '+', auswahlNummer);
		break;
	case 2:
		readOperation("Subtraktion", '-', auswahlNummer);
		break;
	case 3:
		readOperation("Multipliaktion", '*', auswahlNummer);
		break;
	case 4:
		readOperation("Division", '/', auswahlNummer);
		break;
	case 5:
		readOperation("Modulo", '%', auswahlNummer);
		break;
	case 6:
		cout << "Fibonacci Folge:\n___________________________" << endl;

		//Ausgabe der ersten 15 fibonacci zahlen.
		for (int i = 0; i <= 15; i++) {
			cout << fibonacci(i) << endl;
			
			//Summe der ersten 15 fib-zahlen.
			summe += fibonacci(i);
		}
		cout << "Summe: " << summe << endl;
		break;
	case 7:
		cout << "Fakultaet welcher Zahl soll berechnet werden?" << endl;
		cin >> fakultaetszahl;
		if (fakultaetszahl < 0) {
			cout << "Keine Fakultaet von einer negativen Zahl" << endl;
		}
		else if (fakultaetszahl == 0) {
			cout << "0! = 1" << endl;
		}
		else {
			//Alle Faktoren ausgeben.
			for (int i = 1; i < fakultaetszahl; i++) {
				cout << i << " * ";

			}
			cout << fakultaetszahl << " = " << fakultaet(fakultaetszahl) << endl;
		}
		break;
	default:
		break;
	
	}

	return;
}

//Methode gibt die Fibonaccizahl der uebergebenen zahl zurueck.
int fibonacci(int zahl) {
	if (zahl == 0) {
		return 0;
	}
	else if (zahl == 1) {
		return 1;
	}
	else {

		return fibonacci(zahl - 1) + fibonacci(zahl - 2);
	}
}

//Gibt die fakultaet der zahl zurueck.
int fakultaet(int zahl) {
	int produkt = 1;
	for (int i = 1; i <= zahl; i++) {
		produkt *= i;
	}

	return produkt;
}

//Benutzer wird gefragt, ob er weiterrechnen moechte (mit der selben Operation) oder ob er zum Menue zurueck moechte.
void sollErneutGerechnetWerden(int auswahlNummer) {
	char erneutRechnen;
	bool weiter = true;
	do {
		
		cout << "Soll erneut gerechnet werden?" << endl;
		cin >> erneutRechnen;

		if (erneutRechnen == 'j') {
			menueAusfuehren(auswahlNummer);
			weiter = false;
		}
		else if (erneutRechnen == 'n') {
			weiter = false;
		}
		else {
			cout << "Es wird nur 'j' oder 'n' akzeptiert" << endl;
		}
	} while (weiter);
}



// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
