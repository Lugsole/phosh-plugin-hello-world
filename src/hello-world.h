#include <gtk/gtk.h>

#pragma once

G_BEGIN_DECLS

#define HELLO_TYPE_WORLD (hello_world_get_type ())
G_DECLARE_FINAL_TYPE (HelloWorld, hello_world, HELLO, WORLD, GtkBox)

G_END_DECLS
