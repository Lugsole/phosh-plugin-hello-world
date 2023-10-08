api_version = '0.1'

#pkgdatadir = join_paths(get_option('prefix'), get_option('datadir'), application_id)

hello_world_resources = gnome.compile_resources(
  'phosh-plugin-hello-world-resources',
  'phosh-plugin-hello-world.gresources.xml',
  c_name: 'phosh_plugin_hello_world',
)

phosh_plugin_hello_world_sources = [
  'phosh-plugin-hello-world.c',
  'hello-world.c',
]

version_split = meson.project_version().split('.')
version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', version_split[0])
version_conf.set('MINOR_VERSION', version_split[1])
version_conf.set('MICRO_VERSION', version_split[2])

configure_file(
          input: 'phosh-plugin-hello-world-version.h.in',
         output: 'phosh-plugin-hello-world-version.h',
  configuration: version_conf,
        install: true,
    install_dir: join_paths(get_option('includedir'), 'phosh-plugin-hello-world')
)


phosh_plugins = dependency('phosh-plugins')
plugins_dir = phosh_plugins.get_pkgconfig_variable('lockscreen_plugins_dir')
plugin_dep = [
  dependency('gio-2.0'),
  dependency('gtk+-3.0'),
  dependency('phosh-plugins'),
]

name = 'hello-world'

phosh_plugin_hello_world_lib = shared_module(
  'phosh-plugin-hello-world',
  phosh_plugin_hello_world_sources,
  hello_world_resources,
  c_args : ['-DG_LOG_DOMAIN="phosh-plugin-@0@"'.format(name),
            '-DPLUGIN_NAME="@0@"'.format(name),
           ],
  dependencies: plugin_dep,
  install: true,
  install_dir: plugins_dir,
)

pluginconf = configuration_data()
pluginconf.set('name', name)
pluginconf.set('plugins_dir', plugins_dir)

i18n.merge_file(
  input: configure_file(
    input: name + '.desktop.in.in',
    output: name + '.desktop.in',
    configuration: pluginconf,
  ),
  output: name + '.plugin',
  po_dir:  join_paths(meson.source_root(), 'po'),
  install: true,
  install_dir: plugins_dir,
  type: 'desktop'
)

