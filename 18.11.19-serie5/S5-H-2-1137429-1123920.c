#include <stdio.h>

int func(int x2, int x1, int x0)
{
  // Aufgabe 3a)
  // Berechnen Sie das Ergenis der Booleschen Funktion und
  // geben den resultierenden Wert zurück

  // Note: you have to set parens for precedence, because C doesn't treat '&&' preferentially to '||'
  return ((!x2 && x0) || (x2 && x1) || (!x2 && !x0)) && (x1 || x0) && ((!x2 && x1) || (x2 && !x1));

}

int main()
{
  // Aufgabe 3b)
  // Geben Sie hier den Tabellenkopf aus

  printf("x2 x1 x0 | f | Mintermfunktion\n------------------------------\n");


  // Nutzen Sie verschachtelte for-Schleifen, um
  // alle moeglichen Eingabekombinationen zu durchlaufen

  // Geben Sie in der inneren Schleife die jeweiligen
  // Tabellenzeilen aus

  // Aufgabe 3c)
  // Erweitern Sie die Tabelle um die Spalte "Mintermfunktion"
  // wie in der Beispielausgabe gezeigt

  // Loop over the inputs
  for (int x2 = 0; x2 < 2; x2++) {

          for (int x1 = 0; x1 < 2; x1++) {

                  for (int x0 = 0; x0 < 2; x0++) {

                          // Compute the function's result
                          int result = func(x2, x1, x0);

                          // Output the table's row
                          printf(" %X  %X  %X | %X | ", x2, x1, x0, result);

                          /* Print mintermfunction */

                          // If this is indeed a minterm
                          if (result == 1) {

                                  // Init minterm without any inversions
                                  char minterm[] = " x2 x1 x0";

                                  // Decide, whether one of the inputs is inverted...

                                  if (x2 == 0) {
                                          minterm[0] = '!'; // ... add the inverter symbol, if it is...
                                  }

                                  if (x1 == 0) {
                                          minterm[3] = '!';
                                  }

                                  if (x0 == 0) {
                                          minterm[6] = '!';
                                  }

                                  // ... and output the minterm
                                  printf("%s", minterm);
                          }

                          printf("\n");

                  }
          }
  }


  return 0;
}
