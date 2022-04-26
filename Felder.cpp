// Felder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int main()
{
    locale::global(locale("German_germany"));

    int feld[6];

    cout << feld[0] << ", " << feld[1] << ", " << feld[2] << endl;

    int lotto[6];

    lotto[0] = 2;
    lotto[1] = 5;
    lotto[2] = 18;
    lotto[3] = 25;
    lotto[4] = 32;
    lotto[5] = 42;

    cout << "Array-Größe: " << sizeof(lotto) << endl;
    cout << "Größe der einzelnen Elemente: " << sizeof(lotto[0]) << endl;
    cout << "Anzahl der Array-Elemente mit sizeof(): " << sizeof(lotto) / sizeof(lotto[0]) << endl;
    cout << "Anzahl der Array-Elemente mit size(): " << size(lotto) << endl;

    for (int Index = 0; Index < size(lotto); Index++)
    {
        cout << lotto[Index] << endl;
    }

    constexpr int ANZAHL = 6;

    int feld1[ANZAHL]{ 0 };

    for (int Index = 0; Index < size(feld1); Index++)
    {
        cout << feld1[Index] << endl;
    }

    char feld2[]{ 'a', 'l', 'f', 'a', '\0'};

	for (int Index = 0; Index < size(feld2); Index++)
	{
		cout << feld2[Index] << endl;
	}

    cout << "feld2: " << feld2 << endl;
    cout << "lotto: " << lotto << endl;

    auto lotto2 = lotto;

    lotto2[0] = 4;


	for (int Index = 0; Index < size(lotto); Index++)
	{
		cout << lotto[Index] << endl;
	}

    cout << lotto << endl;
    cout << lotto2 << endl;

    int lotto3[6];

    copy(lotto, lotto + size(lotto), lotto3);

    lotto3[0] = 1;

	for (int Index = 0; Index < size(lotto3); Index++)
	{
		cout << lotto3[Index] << endl;
	}


	cout << lotto << endl;
	cout << lotto3 << endl;

    int lotto4[10]{ 0 };

    copy(lotto3, lotto3 + size(lotto3), lotto4);

	for (int Index = 0; Index < size(lotto4); Index++)
	{
		cout << lotto4[Index] << endl;
	}

    string s1 = "alfatraining";
    string s2 = "Bildungszentrum";
    string s3 = "Karlsruhe";

    string feldZeichenketten[]{ s1, s2, s3 };

    for (int i = 0; i < size(feldZeichenketten); i++)
    {
        cout << feldZeichenketten[i] << endl;
    }

    cout << "sizeof(feldZeichenketten): " << sizeof(feldZeichenketten) << endl;
    cout << "sizeof(feldZeichenketten[0]): " << sizeof(feldZeichenketten[0]) << endl;
    cout << "Länge der Zeichenkette im 1.Element: " << feldZeichenketten[0].length() << endl;
    cout << "Länge der Zeichenkette im 2.Element: " << feldZeichenketten[1].length() << endl;
    cout << "Länge der Zeichenkette im 3.Element: " << feldZeichenketten[2].length() << endl;

    int feld2D[2][4];

    cout << feld2D << endl;
    cout << feld2D[1] << endl;

	cout << size(feld2D) << endl;
	cout << size(feld2D[1]) << endl;


    for (int zeile = 0; zeile < size(feld2D); zeile++)
    {
        for (int spalte = 0; spalte < size(feld2D[1]); spalte++)
        {
            feld2D[zeile][spalte] = (zeile + 2) * (spalte + 3);
        }
    }

	for (int zeile = 0; zeile < size(feld2D); zeile++)
	{
		for (int spalte = 0; spalte < size(feld2D[1]); spalte++)
		{
            printf("%3d", feld2D[zeile][spalte]);
		}
        cout << endl;
	}

    int zweiD[2][2]{ {3,1},{4,2} };

    for (int i = 0; i < size(zweiD); i++)
    {
        for (int j = 0; j < size(zweiD[1]); j++)
        {
            printf("%3d", zweiD[i][j]);
        }
        cout << endl;
    }

    int feld3D[3][4][5];

    int n = 1;


    for (int i = 0; i < size(feld3D); i++)
    {
        for (int j = 0; j < size(feld3D[1]); j++)
        {
            for (int k = 0; k < size(feld3D[1][1]); k++)
            {
                feld3D[i][j][k] = n++;
            }
        }
    }

	for (int i = 0; i < size(feld3D); i++)
	{
		for (int j = 0; j < size(feld3D[1]); j++)
		{
			for (int k = 0; k < size(feld3D[1][1]); k++)
			{
				printf("%4d", feld3D[i][j][k]);
			}
            cout << endl;
		}
		cout << endl;
	}

    int anzahlElemente = 10;

    int* dynFeld = new int[anzahlElemente] {0};


    for (int i = 0; i < anzahlElemente ; i++)
    {
        cout << dynFeld[i] << ", ";
    }

    cout << endl;

	for (int i = 0; i < anzahlElemente; i++)
	{
        dynFeld[i] = i + 1;
	}

	for (int i = 0; i < anzahlElemente; i++)
	{
		cout << dynFeld[i] << ", ";
	}

	cout << endl;

    int neuAnzahlElemente = anzahlElemente + 5;

    int* tempDynFeld = new int[neuAnzahlElemente] {0};

    /*for (int i = 0; i < anzahlElemente ; i++)
    {
        tempDynFeld[i] = dynFeld[i];
    }*/

    // oder
    //memcpy(tempDynFeld, dynFeld, anzahlElemente * sizeof(int));

    //oder
    copy(dynFeld, dynFeld + anzahlElemente, tempDynFeld);

    delete[] dynFeld;

    dynFeld = tempDynFeld;

    anzahlElemente = neuAnzahlElemente;

	for (int i = 0; i < anzahlElemente; i++)
	{
		cout << dynFeld[i] << ", ";
	}

    cout << endl;

    delete[] dynFeld;

    return EXIT_SUCCESS;

}
