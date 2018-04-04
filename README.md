# GtkImageViewer

A pannable and zoomable image viewing widget for Gtk3.

## Background

As a writer of several scientific image displaying tools I have always
wanted a good general purpose image display widget. The goal of the
GtkImageViewer widget is to fullfill that gap. Its interaction is a
mixture of the user interfaces of Gimp and of xv. The widget itself
handles zoom and panning. Additional functionality may be added
through callbacks.

Considerable emphasis has been put into the speed and the memory
requirements of the widget. While panning only the exposed areas
are redrawn, and the zoomed up image outside the display area is
never kept in memory. 

The GtkImageViewer is perfectly suited to be used by any photo display
program and will provide a uniform interface for interacting with
images.

The 0.9 series is a major rewrite of the gtk image viewer with a new 
callback model.

See docs/tutorial for a description of how to use the widget.

## Example usage

Here is a minimal example that loads an image into the GtkImageViewer widget.

```c
#include <gtk-image-viewer.h>

int 
main (int argc, char *argv[])
{
  GtkWidget *window, *image_viewer, *scrolled_win;
  GdkPixbuf *img;
  
  gtk_init (&argc, &argv);

  if (argc < 2)
    {
      printf("Need name of image!\n");
      exit(0);
    }
  else
    {
      GError *error = NULL;
      img = gdk_pixbuf_new_from_file (argv[1], &error);
    }
    
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window), 600,400);
  gtk_window_set_title (GTK_WINDOW (window), argv[1]);
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  scrolled_win = gtk_scrolled_window_new(NULL,NULL);
  gtk_container_add(GTK_CONTAINER(window), scrolled_win);

  image_viewer = gtk_image_viewer_new(img);
  gtk_container_add (GTK_CONTAINER (scrolled_win), image_viewer);
  gtk_widget_show_all (window);

  gtk_main ();
  
  return 0;
}
```

## Documentation

See the doc directory.

## Similar software

* GtkImageView - An independent and non-related widget, with a similar  use-case.

