#include <iostream>
#include <gtk/gtk.h>

static void hello() {
	g_print( "Hello World\n" );
}

int main( int argc, char *argv[] ) {

	gtk_init( &argc, &argv );

	GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

	GtkWidget *button = gtk_button_new_with_label( "Hello World" );
	g_signal_connect ( button, "clicked",
	                   G_CALLBACK( hello ), NULL );
	gtk_container_add(GTK_CONTAINER ( window ), button );

	gtk_widget_show( button );
	gtk_widget_show( window );

	gtk_main();

	return 0;
}
