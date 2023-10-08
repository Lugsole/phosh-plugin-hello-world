#include "hello-world.h"

/**
 * HelloWorld
 *
 * Displays hello world on th eplugin screen.
 */
struct _HelloWorld {
  GtkBox        parent;
};

G_DEFINE_TYPE (HelloWorld, hello_world, GTK_TYPE_BOX);

static void
hello_world_class_init (HelloWorldClass *klass)
{
  g_print("hello_world_class_init\n");
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);


  gtk_widget_class_set_template_from_resource (widget_class,
                                               "/com/example/phosh/plugins/hello-world/hello-world.ui");

  gtk_widget_class_set_css_name (widget_class, "phosh-hello-world");
}

static void
hello_world_init (HelloWorld *self)
{
  g_print("hello_world_init\n");
  g_autoptr (GtkCssProvider) css_provider = NULL;

  gtk_widget_init_template (GTK_WIDGET (self));

  css_provider = gtk_css_provider_new ();
  gtk_css_provider_load_from_resource (css_provider,
                                       "/com/example/phosh/plugins/hello-world/stylesheet/common.css");
  gtk_style_context_add_provider (gtk_widget_get_style_context (GTK_WIDGET (self)),
                                  GTK_STYLE_PROVIDER (css_provider),
                                  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}
