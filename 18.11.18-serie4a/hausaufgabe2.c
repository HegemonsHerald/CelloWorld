#include <stdio.h>
void printBinary(int zahl, int stellen)
{
    // Aufgabe a)
    if (stellen<=0 || stellen>sizeof(int)*8)  // Es wird geprűft, ob die Stellenzahl kleiner als 0 sein soll (in welchem Falle sie nicht darstellbar ist)
                                              // oder ob mehr als 32 Stellen (sizeof(int)*8 = 32) dargestellt werden sollen, was bei 32-bit floats keinen Sinn ergeben wűrde
    {
        stellen=sizeof(int)*8;                // Wenn mehr als 32 Stellen oder weniger als 0 Stellen ausgegeben werden sollen, sollen stattdessen einfach 32 Stellen ausgegeben werden
    }
    for (int i=stellen-1; i>=0; i--)          // stellen-1 ist der Index des MSB, i zählt also vom Index des MSB zum Index des LSB (=0)
    {
        int b;                                // b wird deklariert
        b = zahl >> i;                        // b sei gleich: die Zahl um i Stellen nach rechts verschoben, was die i-te Stelle der Binärrepresentation der Zahl auf das LSB bewegt
        b = b & 0x00000001;                   // b wird Bit-verundet mit der Zahl '1': hier wird eine Bitmaske auf das LSB angelegt, so dass b hinterher den Wert des LSB, dass es zuvor hatte, trägt
        printf("%X",b);                       // b wird als Hexadezimalzahl ausgegeben, also 0, wenn es jetzt den Wert 0 trägt, oder 1, wenn es jetzt den Wert 1 trägt
        if ((i%8) == 0) printf(" ");          // Es werden immer 8 Bits in Gruppen ausgegeben, fűr die Lesbarkeit, indem alle 8 Bits ein Leerzeichen ausgegeben wird
    }
}

// Eine Funktion, die Potenzen berechnet
unsigned int pow(unsigned int number, unsigned int exponent) {
        unsigned int result = 1;
        while (exponent > 0) { // so lange der exponent nicht 0 wird...
                result *= number; // die zahl mit sich selbst multiplizieren!
                exponent--;
        }
        return result;
}

int main()
{
    // Interpretation IEEE Floatformat
    unsigned int vorzeichen, mantisse, exponent ; // Natuerliche Zahlen Vorzeichen, Exponent, Mantisse. Nutzen Sie diese Variablen zur Speicherung der Komponenten der IEEE-Zahl
    char expUnbiased; // Fuer den Exponenten ohne Bias
    float eingabe; // zu interpretierende Zahl

    union {  // dient zur Adressierung der Bitfolge der floatzahl ieee.f mittels der Integerzahl ieee.i
        float f;
        unsigned int i;
    } ieee;

    printf("Gib die zu analysierende Zahl ein: ");
    scanf("%f",&eingabe); // lies die Zahl ein

    // Wert von ieee mittels Floating Point-Repraesentation ieee.f auf eingabe setzen
    ieee.f = eingabe;



    // Aufgabe b ==============================================================

    // Geben Sie hier Ihr Codefragment fuer Aufgabe b) ein
    // Beachten Sie: Bitweise logische Operationen und Shifts sind nur fuer die
    // Integer-Repraesentation ieee.i definiert

    char vorzeichen_shift = 31; // Um wie viele Stellen man shiften muss, damit MSB (=Vorzeichen) zu LSB wird
    char exponent_shift = 23; // Um wie viele Stellen man shiften muss, um das letzte Bit des Exponenten auf das LSB zu bringen

    unsigned int exponent_mask = pow(2, 8) -1; // Bitmaske mit 8 Einsen: 0...011111111
    exponent_mask = exponent_mask << exponent_shift; // Bitmaske auf die Position des Exponenten verschieben

    unsigned int mantisse_mask = pow(2, 23) -1; // Bitmaske mit 23 Einsen


    vorzeichen = ieee.i >> vorzeichen_shift; // Vorzeichen auf LSB schieben,
                                     // Muss nicht maskiert werden, da >> mit 0 auffűllt, wenn MSB = 0 ist. Ist MSB = 1, macht
                                     // es keinen Unterschied, ob mit 0 oder mit 1 aufgefűllt wird

    if (vorzeichen != 0) { vorzeichen = 1; } // Vorzeichen auf 1 setzen, wenn es 1 sein sollte

    exponent = ieee.i & exponent_mask; // Exponent via Bitmaske isolieren
    exponent = exponent >> exponent_shift; // Exponent auf LSB verschieben

    mantisse = ieee.i & mantisse_mask; // Mantisse isolieren, ist bereits auf LSB


    expUnbiased = exponent + 127; // ExpUnbiased nach Standardfall des IEEE


    // ========================================================================



    // Ausgabe der Zerlegung, nutzen Sie diesen Code fuer die Ausgabe:
    printf("Float %f als Hex %X ist zerlegt in\nVorzeichen %d \nMantisse %X, \nExponent %d, \nExpUnbiased %d\n", ieee.f, ieee.i, vorzeichen, mantisse, exponent, expUnbiased);

    printf("\nVorzeichen ist \t");
    printBinary(vorzeichen,1);

    printf("\nMantisse binaer ist \t");
    printBinary(mantisse,23);

    printf("\nExponent binaer ist \t");
    printBinary(exponent,8);

    printf("\nExpUnbiased binaer ist \t");
    printBinary(expUnbiased,8);


    // Aufgabe c ==============================================================

    // Pruefe die Sonderfaelle

    // Fuegen Sie Ihren Code fuer Aufgabe c) ein (die vier Sonderfaelle)

    // Fall 1: Sehr kleine Zahl
    if (exponent == 0 && mantisse != 0) {
        printf("\nSehr kleine Zahl! Eingabe = %f\n", eingabe);
        return 0;
    }

    // Fall 2: Null
    if (exponent == 0 && mantisse == 0) {
        printf("\nNull! Eingabe = %f\n", eingabe);
        return 0;
    }

    // Fall 3: Unendlichkeit
    if (exponent == 255 && mantisse == 0) {
        printf("\nUnendlichkeit! Eingabe = %f\n", eingabe);
        return 0;
    }

    // Fall 4: Not a Number
    if (exponent == 255 && mantisse != 0) {
        printf("\nNaN! Eingabe = %f\n", eingabe);
        return 1;
    }


    // ========================================================================



    // Aufgabe d===============================================================

    // Fuer den Standardfall (normalisiert), bauen Sie die IEEE-Zahl wieder zusammen,
    // so dass sie ueber ieee.f ausgegeben werden kann:

    // Fall 5: (Nicht) Standardfall
    // Wenn es sich NICHT um Standardfall handelt, abbrechen
    if ( ! (0 < exponent && exponent < 255) ) { printf("\nEs handelt sich nicht um eine gűltige IEEE float Zahl!"); return 1; }

    // Wenn einer der Fälle aus c ausgelőst wird, wird das Programm abgebrochen,
    // bevor es hier ankommt.
    // Wenn das obige if-statement ausgelőst wird, kann es sich bei der Zahl weder um eine IEEE Zahl
    // in einem der Spezialfälle, noch um den Standardfall handeln.
    // Wenn die Zahl durch das obige if-statement durchkommt, ist sie im Standardfall.

    unsigned int zusammengesetzt = 0; // wir fangen mit 32 0en an

    zusammengesetzt = vorzeichen; // als erstes das zukűnftige MSB wieder einsetzen
    zusammengesetzt = zusammengesetzt << 8; // um die Stellenzahl des Exponenten shiften, um Platz fűr die Exponenten Bits zu machen
    zusammengesetzt = zusammengesetzt | exponent; // Exponenten Bits einfűgen, per Bitwise OR, weil sonst das vorzeichen űberschrieben wűrde
    zusammengesetzt = zusammengesetzt << exponent_shift; // Vorzeichen und Exponenten shiften, um Platz fűr die Mantisse zu schaffen
    zusammengesetzt = zusammengesetzt | mantisse; // Mantisse einsetzen ohne Vorzeichen und Exponeneten zu űberschreiben

    ieee.i = zusammengesetzt; // beweisen, dass die zusammengesetzte Zahl, die richtige ist!

    // Fuegen Sie Ihren Code fuer Aufgabe d) hier ein. Geben Sie die Zahl mit
    printf("\nZahl ist: %f\n", ieee.f);
    //   aus.

    // ========================================================================

    return 0;
}
