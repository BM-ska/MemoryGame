#include <gtk/gtk.h>
#include <stdbool.h>
#ifndef GRA_H
#define GRA_H

//okno gry

extern GtkWindow *okno;

extern GtkWidget *glowny_box;
extern GtkWidget *box_pierwszy;
extern GtkWidget *ramka;
extern GtkWidget *punktacja;
extern GtkWidget *plansza;
extern GtkWidget *opcje;

extern GtkWidget *gracz1;
extern GtkWidget *gracz2;
extern GtkWidget *tura;
extern GtkWidget *ramka1;
extern GtkWidget *ramka2;
extern GtkWidget *ramka3;

extern GtkWidget *ramka_plansza;
extern GtkWidget *box_na_przyciski[6][6];
extern GtkWidget *przyciski[6][6];

extern GtkWidget *reset;
extern GtkWidget *zapisz_gre;
extern GtkWidget *zamknij;

extern GtkWidget *tablica_obrazkow[6][6];
extern GtkWidget *tablica_obrazkow_szare[6][6];



//okno wejscia

extern GtkWindow *okno1;
extern GtkWidget *glowny_box1;

extern GtkWidget *nowa_gra1;
extern GtkWidget *wczytaj_gre1;
extern GtkWidget *zamknij1;
extern GtkWidget *obrazek_tytul;

//okno wygranej

extern GtkWindow *okno2;

extern GtkWidget *glowny_box2;
extern GtkWidget *wygrana2;
extern GtkWidget *opcje2;
extern GtkWidget *ramka_wygrana;

extern GtkWidget *nowa_gra2;
extern GtkWidget *zamknij2;

//okno nick
extern GtkWindow *okno3;

extern GtkWidget *glowny_box3;
extern GtkWidget *wpisz_nick;
extern GtkWidget *nick1;
extern GtkWidget *nick2;
extern GtkWidget *ramka_gracz_1;
extern GtkWidget *ramka_gracz_2;
extern GtkWidget *dalej3;

extern char * nazwa[2];

extern int t_obrazki[6][6];
extern int t_odsloniete[6][6];

extern int pkt[2];
extern int tura_gracz_nr;

extern int i;

//funkcje
void f();

void punkty ();

void tworzy_t_obrazki();

bool sprawdz ();

void f_klik(GtkWidget *widget,  int *t);

void koniec_wygrana();

void wyswietlanie_1();

void wyswietlanie_2();


void f_nowa_gra( GtkWidget *widget, gpointer data );

void f_zamknij_gre( GtkWidget *widget, gpointer data );

void f_dalej( GtkWidget *widget, gpointer data );
void f_wczytaj_gre( GtkWidget *widget, gpointer data );
void f_zapisz_gre( GtkWidget *widget, gpointer data );



#endif



