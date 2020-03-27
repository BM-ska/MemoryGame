#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "gra.h"


int main (int argc, char *argv[])
{

gtk_init (&argc, &argv);

//OKNO NICK
{
//window
{

    okno3 = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_position(okno3, GTK_WIN_POS_CENTER);
    gtk_window_set_title(okno3, "Memory Game");
    gtk_window_set_resizable(okno3, FALSE);
}
//glowny box
{
    glowny_box3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add (GTK_CONTAINER(okno3), GTK_WIDGET(glowny_box3));
}
//wpisz nick
{
    wpisz_nick = gtk_label_new("Wpisz nicki");
    gtk_container_add(GTK_CONTAINER(glowny_box3), wpisz_nick);

    gtk_widget_set_size_request(wpisz_nick, 300, 50);

}
//nicki
{
    ramka_gracz_1 = gtk_frame_new("gracz 1:");
    ramka_gracz_2 = gtk_frame_new("gracz 2:");
    gtk_container_add(GTK_CONTAINER(glowny_box3), ramka_gracz_1);
    gtk_container_add(GTK_CONTAINER(glowny_box3), ramka_gracz_2);


    nick1 =gtk_entry_new();
    nick2 =gtk_entry_new();

    gtk_container_add(GTK_CONTAINER(ramka_gracz_1), nick1);
    gtk_container_add(GTK_CONTAINER(ramka_gracz_2), nick2);
{
    gtk_widget_set_size_request(ramka_gracz_1, 290, 50);
    gtk_widget_set_size_request(ramka_gracz_2, 290, 50);

    gtk_widget_set_margin_start (ramka_gracz_1,5);
    gtk_widget_set_margin_end (ramka_gracz_1,5);
    gtk_widget_set_margin_top(ramka_gracz_1,5);
    gtk_widget_set_margin_bottom(ramka_gracz_1,5);

    gtk_widget_set_margin_start(ramka_gracz_2,5);
    gtk_widget_set_margin_end(ramka_gracz_2,5);
    gtk_widget_set_margin_top(ramka_gracz_2,5);
    gtk_widget_set_margin_bottom(ramka_gracz_2,5);

    gtk_widget_set_margin_start(nick1,5);
    gtk_widget_set_margin_end(nick1,5);
    gtk_widget_set_margin_top(nick1,5);
    gtk_widget_set_margin_bottom(nick1,5);

    gtk_widget_set_margin_start(nick2,5);
    gtk_widget_set_margin_end(nick2,5);
    gtk_widget_set_margin_top(nick2,5);
    gtk_widget_set_margin_bottom(nick2,5);
}
}

//dalej
{
    dalej3 = gtk_button_new_with_label("Dalej");
    gtk_box_pack_start(GTK_BOX(glowny_box3), dalej3, TRUE, FALSE,0);


    gtk_widget_set_size_request(dalej3, 300, 50);

    gtk_widget_set_margin_start(dalej3,10);
    gtk_widget_set_margin_end(dalej3,10);
    gtk_widget_set_margin_top(dalej3,10);
    gtk_widget_set_margin_bottom(dalej3,10);

}

}

//OKNO GRY_xxxxxxxxxxxxxxxxxxxxxxx
{
//window
{
    okno = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(okno), "Memory Game");
    gtk_window_set_resizable(okno, FALSE);
}

//glowny box
{
    glowny_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add (GTK_CONTAINER(okno), glowny_box);

}

//punktacja
{
    punktacja = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(glowny_box), punktacja, TRUE, FALSE,0);


    ramka1 = gtk_frame_new ("Gracz 1");
    ramka2 = gtk_frame_new ("Gracz 2");
    ramka3 = gtk_frame_new ("Tura:");

    gracz1 = gtk_label_new ("0"); //zmiana
    gracz2 = gtk_label_new ("0");//zmiana
    tura = gtk_label_new("Gracz ...");//zmiana

    gtk_container_add (GTK_CONTAINER(punktacja), ramka1);
    gtk_container_add (GTK_CONTAINER(punktacja), ramka2);
    gtk_container_add (GTK_CONTAINER(punktacja), ramka3);

    gtk_container_add (GTK_CONTAINER(ramka1), gracz1);
    gtk_container_add (GTK_CONTAINER(ramka2), gracz2);
    gtk_container_add (GTK_CONTAINER(ramka3), tura);

    //rozmiary
    {
    gtk_widget_set_margin_start(punktacja,10);
    gtk_widget_set_margin_end(punktacja,10);
    gtk_widget_set_margin_top(punktacja,10);

    gtk_widget_set_margin_start(ramka1,5);
    gtk_widget_set_margin_start(ramka2,5);
    gtk_widget_set_margin_end(ramka1,5);
    gtk_widget_set_margin_end(ramka2,5);
    gtk_widget_set_margin_start(ramka3,5);
    gtk_widget_set_margin_end(ramka3,5);

    gtk_widget_set_margin_start(gracz1,40);
    gtk_widget_set_margin_start(gracz2,40);
    gtk_widget_set_margin_end(gracz1,40);
    gtk_widget_set_margin_end(gracz2,40);

    gtk_widget_set_margin_top(gracz1,30);
    gtk_widget_set_margin_bottom(gracz1,30);

    gtk_widget_set_margin_end(tura,145);
    gtk_widget_set_margin_start(tura, 145);
    }

}

//plansza
{

    ramka_plansza = gtk_frame_new("");
    gtk_container_add (GTK_CONTAINER(glowny_box), ramka_plansza);
    gtk_widget_set_margin_start(ramka_plansza,10);
    gtk_widget_set_margin_end(ramka_plansza,10);

    plansza = gtk_grid_new();
    gtk_container_add (GTK_CONTAINER(ramka_plansza), plansza);


    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            box_na_przyciski[x][y] = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
            gtk_grid_attach (GTK_GRID(plansza), box_na_przyciski[x][y], x, y, 1, 1);

            przyciski[x][y] = gtk_button_new();
            gtk_widget_set_size_request(przyciski[x][y], 100, 100);
            gtk_container_add (GTK_CONTAINER(box_na_przyciski[x][y]), przyciski[x][y]);

        //    tablica_obrazkow[y][x] = gtk_image_new();
          //  gtk_box_pack_start(GTK_BOX(box_na_przyciski[y][x]), tablica_obrazkow[y][x], FALSE, FALSE,0);
        //    gtk_container_add (GTK_CONTAINER(), tablica_obrazkow[y][x]);


            gtk_widget_set_margin_end(box_na_przyciski[x][y],1);
            gtk_widget_set_margin_start(box_na_przyciski[x][y],1);
            gtk_widget_set_margin_top(box_na_przyciski[x][y],1);
            gtk_widget_set_margin_bottom(box_na_przyciski[x][y],1);



        }
    }
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            tablica_obrazkow[y][x] = gtk_image_new();
            gtk_container_add (GTK_CONTAINER(box_na_przyciski[y][x]), tablica_obrazkow[y][x]);

            tablica_obrazkow_szare[y][x] = gtk_image_new();
            gtk_container_add (GTK_CONTAINER(box_na_przyciski[y][x]), tablica_obrazkow_szare[y][x]);
        }
    }

    gtk_widget_set_margin_start(plansza,10);
    gtk_widget_set_margin_end(plansza,10);
    gtk_widget_set_margin_bottom(plansza,10);
}

//opcje
{


    opcje = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(glowny_box), opcje, TRUE, FALSE,0);

    reset = gtk_button_new_with_label("Reset");
    zapisz_gre = gtk_button_new_with_label("Zapisz");
    zamknij = gtk_button_new_with_label("Zamknij");

    gtk_box_pack_start(GTK_BOX(opcje), reset, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(opcje), zapisz_gre, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(opcje), zamknij, TRUE, FALSE,0);

    gtk_widget_set_size_request(reset, 120, 50);
    gtk_widget_set_size_request(zapisz_gre, 120, 50);
    gtk_widget_set_size_request(zamknij, 120, 50);

    gtk_widget_set_margin_start(reset,70);
    gtk_widget_set_margin_start(zapisz_gre,5);
    gtk_widget_set_margin_start(zamknij,5);
    gtk_widget_set_margin_end(reset,5);
    gtk_widget_set_margin_end(zapisz_gre,5);
    gtk_widget_set_margin_end(zamknij,70);

    gtk_widget_set_margin_bottom (opcje,20);
    gtk_widget_set_margin_top (opcje,20);
}
}

//OKNO WEJSCIA_xxxxxxxxxxxxxxxxxxx
{
//window
{
    okno1 = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_position(GTK_WINDOW(okno1), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(okno1), "Memory Game");
    gtk_window_set_resizable(okno1, FALSE);
}

//glowny box
{
    glowny_box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add (GTK_CONTAINER(okno1), glowny_box1);

    obrazek_tytul = gtk_image_new_from_file("obrazy/memory_nazwa.png");
    gtk_container_add(GTK_CONTAINER(glowny_box1), obrazek_tytul);

    nowa_gra1 = gtk_button_new_with_label("Nowa gra");
    wczytaj_gre1 = gtk_button_new_with_label("Wczytaj ostatni zapis");
    zamknij1 = gtk_button_new_with_label("Zamknij");

    gtk_box_pack_start(GTK_BOX(glowny_box1), nowa_gra1, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(glowny_box1), wczytaj_gre1, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(glowny_box1), zamknij1, TRUE, FALSE,0);

    gtk_widget_set_size_request(nowa_gra1, 120, 50);
    gtk_widget_set_size_request(wczytaj_gre1, 120, 50);
    gtk_widget_set_size_request(zamknij1, 120, 50);


    gtk_widget_set_margin_start(glowny_box1,20);
    gtk_widget_set_margin_end(glowny_box1,20);
    gtk_widget_set_margin_top(glowny_box1,20);
    gtk_widget_set_margin_bottom(glowny_box1,20);

    gtk_widget_set_margin_bottom(nowa_gra1,5);
    gtk_widget_set_margin_bottom(wczytaj_gre1,5);
    gtk_widget_set_margin_bottom(zamknij1,5);
}
}
//OKNO WYGRANEJ_xxxxxxxxxxxxxxxxxx
{
//window
{
    okno2 = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_position(GTK_WINDOW(okno2), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(okno2), "Memory Game");
    gtk_window_set_resizable(okno2, FALSE);
}
//glowny box
{
    glowny_box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add (GTK_CONTAINER(okno2), GTK_WIDGET(glowny_box2));
}
//wygrana
{
    ramka_wygrana = gtk_frame_new("");
    gtk_container_add(GTK_CONTAINER(glowny_box2), ramka_wygrana);

    wygrana2 = gtk_label_new("Wygrał Gracz ...!!!");
    gtk_container_add(GTK_CONTAINER(ramka_wygrana), wygrana2);

    gtk_widget_set_size_request(ramka_wygrana, 300, 200);

    gtk_widget_set_margin_start(ramka_wygrana,10);
    gtk_widget_set_margin_end(ramka_wygrana,10);
    gtk_widget_set_margin_top(ramka_wygrana,0);
    gtk_widget_set_margin_bottom(ramka_wygrana,10);



}
//opcje
{
    opcje2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(glowny_box2), opcje2);


    nowa_gra2 = gtk_button_new_with_label("Nowa gra");
    zamknij2 = gtk_button_new_with_label("Zamknij");

    gtk_box_pack_start(GTK_BOX(opcje2), nowa_gra2, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(opcje2), zamknij2, TRUE, FALSE,0);

    gtk_widget_set_size_request(nowa_gra2, 130, 50);
    gtk_widget_set_size_request(zamknij2, 130, 50);

    gtk_widget_set_size_request(opcje2, 300, 70);

    gtk_widget_set_margin_bottom(opcje2,10);
    gtk_widget_set_margin_start(nowa_gra2,10);
    gtk_widget_set_margin_end(zamknij2,10);
}
}

//RESZTA_xxxxxxxxxxxxxxxxxxxxxxxxx
{
    gtk_widget_show_all(GTK_WIDGET(okno1));

    g_signal_connect (G_OBJECT(nowa_gra1), "clicked", G_CALLBACK(f_nowa_gra), NULL);
    g_signal_connect (G_OBJECT(zamknij1), "clicked", G_CALLBACK(f_zamknij_gre), NULL);
    g_signal_connect (G_OBJECT(zamknij), "clicked", G_CALLBACK(f_zamknij_gre), NULL);
    g_signal_connect (G_OBJECT(zamknij2), "clicked", G_CALLBACK(f_zamknij_gre), NULL);
    g_signal_connect (G_OBJECT(nowa_gra2), "clicked", G_CALLBACK(f_nowa_gra), NULL);
    g_signal_connect (G_OBJECT(dalej3), "clicked", G_CALLBACK(f_dalej), NULL);
    g_signal_connect (G_OBJECT(wczytaj_gre1), "clicked", G_CALLBACK(f_wczytaj_gre), NULL);
    g_signal_connect (G_OBJECT(zapisz_gre), "clicked", G_CALLBACK(f_zapisz_gre), NULL);
    g_signal_connect (G_OBJECT(reset), "clicked", G_CALLBACK(f_nowa_gra), NULL);

    int t[36];
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            t[i*6+j]=i*6+j;
            g_signal_connect (G_OBJECT(przyciski[i][j]), "clicked", G_CALLBACK(f_klik), &t[i*6+j]);
        }

    }



    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(okno1), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(okno2), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(okno3), "destroy", G_CALLBACK(gtk_main_quit), NULL);

}


    gtk_main ();
    return 0;

}

