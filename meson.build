project('dino', ['cpp'],
        license : 'GPLv3',
        license_files : ['COPYING'],
        version : '0.2.8',
        default_options : ['cpp_std=c++14']
       )


dir_prefix = get_option('prefix')
dir_bin = dir_prefix / get_option('bindir')
dir_data = dir_prefix / get_option('datadir')
dir_pkgdata = dir_data / 'dino'
dir_include = dir_prefix / get_option('includedir')
dir_pkginclude = dir_include / meson.project_name()

#glib_dep = dependency('glib-2.0', version : '>=2.22.4')
#gtkmm_dep = dependency('gtkmm-2.4')
jack_dep = dependency('jack')
libxmlpp_dep = dependency('libxml++-2.6')
libsigcpp_dep = dependency('sigc++-2.0')
lash_dep = dependency('lash-1.0')
#dbus_dep = dependency('dbus-1')
#boost_dep = dependency('boost')
libglademm_dep = dependency('libglademm-2.4')

subdir('src')
subdir('pixmaps')

install_data('dino.glade', install_dir: dir_pkgdata)
