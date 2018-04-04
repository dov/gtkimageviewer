/*======================================================================
//  testgtkimageviewer.c - A trivial test program.
//
//  Dov Grobgeld <dov.grobgeld@gmail.com>
//  Sun Nov 19 09:33:20 2006
//----------------------------------------------------------------------
*/
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "gtk-image-viewer.h"
#include <stdio.h>

static gint
cb_key_press_event(GtkWidget *widget, GdkEventKey *event)
{
  gint k = event->keyval;
  
  if (k == 'q')
      exit(0);

  return FALSE;
}

#define E_AND_F (GTK_FILL | GTK_EXPAND)

#define CASE(s) if (strcmp(s, S_) == 0)

int 
main (int argc, char *argv[])
{
  GtkWidget *window, *image_viewer, *scrolled_win;
  const char *filename;
  gboolean do_linear = FALSE;
  int argp = 1;

  gtk_init (&argc, &argv);

  /* Parse command line */
  while(argp < argc && argv[argp][0] == '-')
    {
      char *S_ = argv[argp++];
      CASE("-linear") { do_linear++; continue; };
      
      fprintf(stderr, "Unknown option %s!\n",S_);
      exit(-1);
    }
  

  if (argp >= argc)
    filename = "../examples/cat.jpg";
  else
    filename = argv[argp++];
    
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
  gtk_window_set_title (GTK_WINDOW (window), "Image Widget Demo");
  
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);

  image_viewer = gtk_image_viewer_new_from_file(filename);
#if 0
  gtk_image_viewer_set_use_linear_zoom_steps(GTK_IMAGE_VIEWER(image_viewer),
					     do_linear);
  gtk_image_viewer_set_flip(GTK_IMAGE_VIEWER(image_viewer),
                            TRUE, TRUE);
#endif
  //  width = gtk_image_viewer_get_image_width (GTK_IMAGE_VIEWER(image_viewer));
  //  height = gtk_image_viewer_get_image_height (GTK_IMAGE_VIEWER(image_viewer));

  gtk_widget_set_size_request (window,
                               400,200);
  g_signal_connect (G_OBJECT(window),     "key_press_event",
                    G_CALLBACK(cb_key_press_event), NULL);

  scrolled_win = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_win),
				 GTK_POLICY_AUTOMATIC,
				 GTK_POLICY_AUTOMATIC);
  gtk_container_add (GTK_CONTAINER (scrolled_win), image_viewer);
  gtk_container_add (GTK_CONTAINER (window), scrolled_win);
  
  gtk_widget_show_all (window);
  
  gtk_main ();
  
  return 0;
}
