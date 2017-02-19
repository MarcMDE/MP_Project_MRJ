#include <allegro5/allegro.h> // Allegro 5
#include <allegro5/allegro_font.h> // Incluim la llibreria que conte les utilitats corresponents a les Fonts (Add-on). El Add-on corresponent ha d'estar activat (Project->Properties->Allegro5->Add-ons)

void BasicAllegroExemple();


int main()
{
	//BasicAllegroExemple();

	return 0;
}

void BasicAllegroExemple()
{
	al_init(); // Inicialitzem utilitats basiques de Allegro 5
	al_init_font_addon(); // Inicialitzem les diferents utilitats del "Add-on"
	ALLEGRO_DISPLAY* display = al_create_display(800, 600); // Creem finestra
	ALLEGRO_FONT* font = al_create_builtin_font(); // Inicialitzem font
	al_clear_to_color(al_map_rgb(255, 255, 255)); // "Borrem" finestra
	al_draw_text(font, al_map_rgb(0, 0, 0), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!"); // Escribim text amb font cargada
	al_flip_display(); // back buffer <-> front buffer
	al_rest(5.0); // "sleep"
	al_destroy_display(display); // "Destroys" and frees the display memory
}