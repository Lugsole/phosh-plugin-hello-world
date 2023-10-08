#define G_LOG_DOMAIN "phosh-plugin-hello-world"

#include "hello-world.h"
#include "phosh-plugin-hello-world.h"
#include <gio/gio.h>
#include <gtk/gtk.h>

char **g_io_phosh_plugin_hello_world_query (void);

void
g_io_module_load (GIOModule *module)
{
  g_print("g_io_module_load hello\n");
  g_type_module_use (G_TYPE_MODULE (module));

  g_io_extension_point_implement (PHOSH_PLUGIN_EXTENSION_POINT_LOCKSCREEN_WIDGET,
                                  HELLO_TYPE_WORLD,
                                  PLUGIN_NAME,
                                  10);
}

void
g_io_module_unload (GIOModule *module)
{
  g_print("g_io_module_unload hello\n");
}

char **
g_io_phosh_plugin_hello_world_query (void)
{
  g_print("g_io_query hello\n");
  char *extension_points[] = {PHOSH_PLUGIN_EXTENSION_POINT_LOCKSCREEN_WIDGET, NULL};

  return g_strdupv (extension_points);
}
