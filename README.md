# MemoryGame

Opis projektu
Wykonawca: Barbara Moczulska
Temat: Memory Game

1. Zasady gry.

Gra polega na odnajdowaniu par takich samych obrazków. Gracz odsłania 2 karty.
Jeśli są takie same, to zostaną zdjęte z planszy, a gracz dostaje punkt. Jeśli karty
będą różne, zostaną odwrócone z powrotem a turę rozpoczyna kolejny gracz. Celem
graczy jest zdjęcie wszystkich kart przy możliwie najmniejszej liczbie odsłon. Grę
wygrywa przeciwnik o najwyższej liczbie punktów.

2. Menu startu

Gracze mają wybór wczytać ostatni zapis, rozpocząć nową gre lub ją zamknąć

3. Nowa gra

rozpoczynajac nową grę każdy z graczy wpisuje swój nick.

4. Gra

Otwieramy planszę 6x6. Na górze jest punktacja i informacja czyja jest tura.
Następnie jest plansza, po wybraniu pola odsłania się obrazek. Za kazdym drugim
odsłonięciem mamy niecałe 2 sekundy na zapamiętanie ich ułożenia. Przy odłonięciu obu
poprawnie, one znikają z planszy. W trakcie rozgrywki gracze mają możliwość zresetowania
gry, zapisania jej bądź zamknięcia bez zapisu.

5. Zakonczenie

Po poprawnym odsłonięciu wszystkich obrazków, gra się kończy a gracze dostają
informacje kto wygrał.


Gra podzielona jest na dwa modoly i plik nagłówkowy:

1. grafika.c

Modol odpowiedzialny za okna i wigdety. Zawiera sygnały przekazujace informacje do
funkcji po naciśnięciu przycisku.

2. Funkcje.c

Modol zawiera deklaracje zmiennych. Zawierajacy funkcje dzialania programu.

Tablice:

• Przyciski – zawiera przyciski z rewersem
• tablica_obrazkow - zawiera 18 obrazków po dwa takie same
• tablica_obrazkow_szare – zawiera jednokolorowe identyczne obrazki, pokazywane
po odkryciu dwóch takich samych
• t_obrazki – tablica zawierajaca wylosowane numery, będące bazą pod powstanie
nowej planszy z obrazkami
• t_odsloniete – tablica zawierająca -1, 0 lub 1, służy jako parametr do zapisu gry

Funkcje:

• void f() - funkcja przetrzymująca przez ok sekundę stan odsłoniętych obrazków
przed ich ukryciem
• void punkty () - wyświetla podczas rozgrywki aktualną punktacje
• void tworzy_t_obrazki() - tworzy losowo t_obrazki
• bool sprawdz ()- funkcja sprawdza czy odznaczone obrazki są identyczne
• void f_klik(GtkWidget *widget, int *t) – funkacja wywoływana po naciśnięciu
obrazka, przydziela punkty, przekazuje informacje ile obrazków jest naciśniętych
• void koniec_wygrana() - okno i komunikat o wygranej
• void wyswietlanie_1() - wyswietlanie po pierwszym kliknięciu
• void wyswietlanie_2() - wyswietlanie po drugim kliknięciu
• void f_nowa_gra( GtkWidget *widget, gpointer data ) - tworzenie nowej gry
• void f_zamknij_gre( GtkWidget *widget, gpointer data ) - zamkniecie programu
• void f_dalej( GtkWidget *widget, gpointer data ) - tworzenie nicków
• void f_wczytaj_gre( GtkWidget *widget, gpointer data ) - Wczytanie ostatniego
zapisu
• void f_zapisz_gre( GtkWidget *widget, gpointer data ) - Zapis gry3. Gra.h
plik nagłowkowy

Użyte biblioteki:

• gtk/gtk.h
• stdbool.h
• stdlib.h
• stdio.h

