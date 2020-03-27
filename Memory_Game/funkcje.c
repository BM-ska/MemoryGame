#include "gra.h"
#include <stdbool.h>
#include <gtk/gtk.h>

//okno gry

GtkWindow *okno;

GtkWidget *glowny_box;
GtkWidget *box_pierwszy;
GtkWidget *ramka;
GtkWidget *punktacja;
GtkWidget *plansza;
GtkWidget *opcje;

GtkWidget *gracz1;
GtkWidget *gracz2;
GtkWidget *tura;
GtkWidget *ramka1;
GtkWidget *ramka2;
GtkWidget *ramka3;

GtkWidget *ramka_plansza;

GtkWidget *box_na_przyciski[6][6];
GtkWidget *przyciski[6][6];
GtkWidget *tablica_obrazkow[6][6];
GtkWidget *tablica_obrazkow_szare[6][6];

GtkWidget *reset;
GtkWidget *zapisz_gre;
GtkWidget *zamknij;









//okno wejscia

GtkWindow *okno1;
GtkWidget *glowny_box1;

GtkWidget *nowa_gra1;
GtkWidget *wczytaj_gre1;
GtkWidget *zamknij1;
GtkWidget *obrazek_tytul;

//okno wygranej

GtkWindow *okno2;

GtkWidget *glowny_box2;
GtkWidget *wygrana2;
GtkWidget *opcje2;
GtkWidget *ramka_wygrana;

GtkWidget *nowa_gra2;
GtkWidget *zamknij2;

//okno nick
GtkWindow *okno3;

GtkWidget *glowny_box3;
GtkWidget *wpisz_nick;
GtkWidget *nick1;
GtkWidget *nick2;
GtkWidget *ramka_gracz_1;
GtkWidget *ramka_gracz_2;
GtkWidget *dalej3;

char * nazwa[2];


int pkt[2]= {0, 0};
int tura_gracz_nr = 0;

int t_obrazki[6][6];
int t_odsloniete[6][6];

int czy_dwa_klikniete=0;

int a,b,c,d;
int i;


void punkty()
{
    char punkty1[100];
    sprintf(punkty1, "pkt: %d", pkt[0]);
    char punkty2[100];
    sprintf(punkty2, "pkt: %d", pkt[1]);

    gtk_label_set_text (GTK_LABEL(gracz1), punkty1);
    gtk_label_set_text (GTK_LABEL(gracz2), punkty2);

}

void koniec_wygrana(int a)
{
    char tmp[100];
    if(a==0)
    {
        if(pkt[0]>pkt[1])
        {
            sprintf(tmp, "Wygrał gracz %s!!!!",nazwa[0]);
        }
        else
            sprintf(tmp, "Wygrał gracz %s!!!!",nazwa[1]);
        gtk_label_set_text (GTK_LABEL(wygrana2), tmp);
    }
    else
    {
        gtk_label_set_text (GTK_LABEL(wygrana2), "REMIS!!!");

    }






    gtk_widget_show_all(GTK_WIDGET(okno2));
    gtk_widget_hide(GTK_WIDGET(okno));
}

void tworzy_t_obrazki()
{
    int i=0, j=0, z=0;
    int t[40]= {0};
    srand(time(NULL));

    while(z<36)
    {
        int x=(rand() % (18 + 1 - 1)) + 1;
        if(t[x]<2 && x>0 && x<=18)
        {
            t[x]++;
            z++;
            t_obrazki[i][j]=x;
            j++;
            if(j==6)
            {
                j=0;
                i++;
            }
        }
    }
}

bool sprawdz ()
{
    if( t_obrazki [b][a] == t_obrazki [d][c])
    {
        return 1;
    }
    return 0;
}

void f_klik(GtkWidget *widget, int *t)
{
    (void)widget;

    a = *t/6;
    b = *t%6;
    czy_dwa_klikniete ++;

    t_odsloniete[a][b]=1;


    if(czy_dwa_klikniete == 2)
    {
        czy_dwa_klikniete = 0;
        i = sprawdz();
        if(i==0)
        {
            tura_gracz_nr = (tura_gracz_nr+1)%2;
            gtk_label_set_text (GTK_LABEL(tura), nazwa[tura_gracz_nr]);

            t_odsloniete[a][b]=0;
            t_odsloniete[c][d]=0;
        }
        else
        {
            pkt[tura_gracz_nr]++;
            t_odsloniete[a][b]=-1;
            t_odsloniete[c][d]=-1;
        }
        wyswietlanie_2();


        if((pkt[0] + pkt[1]) == 18)
        {
            if(pkt[0]==pkt[1])
                koniec_wygrana(1);
            else
                koniec_wygrana(0);
        }

    }

    else
    {
        wyswietlanie_1();
        c = a;
        d = b;
    }
    punkty();
}

void wyswietlanie_1()
{
    gtk_widget_hide(GTK_WIDGET(przyciski[a][b]));
    gtk_widget_show(GTK_WIDGET(tablica_obrazkow[a][b]));
}
int p=0;
void f()
{
    if(i==0)
    {
        gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[a][b]));
        gtk_widget_show(GTK_WIDGET(przyciski[a][b]));

        gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[c][d]));
        gtk_widget_show(GTK_WIDGET(przyciski[c][d]));

    }
    if(i==1)
    {
        gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[a][b]));
        gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[c][d]));

        gtk_widget_show(GTK_WIDGET(tablica_obrazkow_szare[a][b]));
        gtk_widget_show(GTK_WIDGET(tablica_obrazkow_szare[c][d]));
    }
    g_source_remove(p);
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            gtk_widget_set_sensitive (GTK_WIDGET(przyciski[i][j]), TRUE);
        }
    }


}
void wyswietlanie_2()
{


    gtk_widget_show(GTK_WIDGET(tablica_obrazkow[a][b]));
    gtk_widget_hide(GTK_WIDGET(przyciski[a][b]));

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            gtk_widget_set_sensitive (GTK_WIDGET(przyciski[i][j]), FALSE);
        }
    }

    p = g_timeout_add (1000, (GSourceFunc)&f, NULL);
}


void wczytaj_t_ikony()
{

    GtkWidget *tablica_reversow[36];
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            char nazwa_obrazka[100];
            sprintf(nazwa_obrazka, "obrazy/%d.png", t_obrazki[i][j]);

            gtk_image_set_from_file (GTK_IMAGE(tablica_obrazkow[j][i]),nazwa_obrazka);

            gtk_widget_set_size_request(tablica_obrazkow[j][i], 100, 100);

            gtk_widget_set_margin_end(tablica_obrazkow[j][i],7);
            gtk_widget_set_margin_start(tablica_obrazkow[j][i],7);
            gtk_widget_set_margin_top(tablica_obrazkow[j][i],6);
            gtk_widget_set_margin_bottom(tablica_obrazkow[j][i],6);


            char xx[100];
            sprintf(xx, "obrazy/szare/%d.png", t_obrazki[i][j]);

            gtk_image_set_from_file (GTK_IMAGE(tablica_obrazkow_szare[j][i]),xx);

            gtk_widget_set_size_request(tablica_obrazkow_szare[j][i], 100, 100);

            gtk_widget_set_margin_end(tablica_obrazkow_szare[j][i],7);
            gtk_widget_set_margin_start(tablica_obrazkow_szare[j][i],7);
            gtk_widget_set_margin_top(tablica_obrazkow_szare[j][i],6);
            gtk_widget_set_margin_bottom(tablica_obrazkow_szare[j][i],6);
        }
    }
    for(int i=0; i<36; i++)
    {
        tablica_reversow[i] = gtk_image_new_from_file("obrazy/00.png");
    }
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            gtk_button_set_image(GTK_BUTTON(przyciski[i][j]), tablica_reversow[i*6+j]);
        }
    }


}
void f_dalej( GtkWidget *widget, gpointer data )
{
    (void)data;
    (void)widget;
    const gchar *n1;
    const gchar *n2;
    n1 = gtk_entry_get_text (GTK_ENTRY(nick1));
    nazwa[0] = malloc(strlen(n1)+1);
    strcpy(nazwa[0], n1);

    n2 = gtk_entry_get_text (GTK_ENTRY(nick2));
    nazwa[1] = malloc(strlen(n2)+1);
    strcpy(nazwa[1], n2);

    gtk_frame_set_label (GTK_FRAME(ramka1), nazwa[0]);
    gtk_frame_set_label (GTK_FRAME(ramka2), nazwa[1]);
    gtk_label_set_text (GTK_LABEL(tura), nazwa[0]);

    gtk_widget_show_all(GTK_WIDGET(okno));
    punkty();
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[i][j]));
            gtk_widget_hide(GTK_WIDGET(tablica_obrazkow_szare[i][j]));
        }

    }
    gtk_widget_hide(GTK_WIDGET(okno3));
}
void f_nowa_gra( GtkWidget *widget, gpointer data )
{
    (void)data;
    (void)widget;
    tworzy_t_obrazki();
    wczytaj_t_ikony();

    pkt[0]=0;
    pkt[1]=0;
    tura_gracz_nr = 0;
    czy_dwa_klikniete=0;

/*
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
        printf("%d ", t_obrazki[i][j]);

        }
        printf("\n");
    }
*/


    gtk_widget_show_all(GTK_WIDGET(okno3));
    gtk_widget_hide(GTK_WIDGET(okno1));
}
void f_zamknij_gre( GtkWidget *widget, gpointer data )
{
    (void)data;
    (void)widget;
    gtk_main_quit ();
}

void f_wczytaj_gre( GtkWidget *widget, gpointer data )
{
    (void)data;
    (void)widget;
    FILE *plik = fopen("zapisy/zap.txt", "r");

    char g[100], h[100];

    fscanf(plik, "%s %s %d %d %d %d",g, h, &pkt[0], &pkt[1], &tura_gracz_nr, &czy_dwa_klikniete);

    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            fscanf(plik, "%d", &t_obrazki[i][j]);
        }

    }
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            fscanf(plik, "%d", &t_odsloniete[i][j]);
        }

    }


    nazwa[0] = malloc(strlen(g)+1);
    nazwa[1] = malloc(strlen(h)+1);
    sprintf(nazwa[0], "%s", g);
    sprintf(nazwa[1], "%s", h);

    gtk_frame_set_label (GTK_FRAME(ramka1), nazwa[0]);
    gtk_frame_set_label (GTK_FRAME(ramka2), nazwa[1]);
    gtk_label_set_text (GTK_LABEL(tura), nazwa[tura_gracz_nr]);

    wczytaj_t_ikony();
    punkty();

    gtk_widget_show_all(GTK_WIDGET(okno));
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            gtk_widget_hide(GTK_WIDGET(tablica_obrazkow[i][j]));
            gtk_widget_hide(GTK_WIDGET(tablica_obrazkow_szare[i][j]));
        }

    }
    for(int i=0; i<6; i++)
    {
        for(int j= 0; j<6; j++)
        {
            if(t_odsloniete[j][i] == 1)
            {
                a=j;
                b=i;
                c=j;
                d=i;
                czy_dwa_klikniete ++;
                wyswietlanie_1();

            }
            if(t_odsloniete[j][i] == -1)
            {
                gtk_widget_hide(GTK_WIDGET(przyciski[i][j]));
                gtk_widget_show(GTK_WIDGET(tablica_obrazkow_szare[i][j]));
            }
        }
    }


    fclose(plik);
    gtk_widget_hide(GTK_WIDGET(okno1));
}
void f_zapisz_gre( GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    FILE *wyjscie = fopen("zapisy/zap.txt", "w");

    fprintf(wyjscie, "%s\n%s\n%d\n%d\n%d\n%d\n", nazwa[0], nazwa[1], pkt[0], pkt[1], tura_gracz_nr, czy_dwa_klikniete);
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            fprintf(wyjscie, "%d ", t_obrazki[i][j]);
        }
        fprintf(wyjscie,"\n");

    }
    for(int i = 0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            fprintf(wyjscie, "%d ", t_odsloniete[j][i]);
        }
        fprintf(wyjscie,"\n");
    }

    fclose(wyjscie);
}
