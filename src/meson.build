conf_data = configuration_data()

conf_data.set_quoted('CR_YEAR', '2006 - 2010', description: 'The copyright year')
conf_data.set_quoted('PACKAGE', meson.project_name(), description: 'Name of package')
#conf_data.set('PACKAGE_BUGREPORT', '', description: 'Define to the address where bug reports for this package should be sent.')
conf_data.set_quoted('PACKAGE_NAME', meson.project_name(), description: 'Define to the full name of this package.')
conf_data.set_quoted('PACKAGE_STRING', '@0@ @1@'.format(meson.project_name(), meson.project_version()), description: 'Define to the full name and version of this package.')
#conf_data.set('PACKAGE_TARNAME', '', description: 'Define to the one symbol short name of this package.')
#conf_data.set('PACKAGE_URL', '', description: 'Define to the home page for this package.')
conf_data.set_quoted('PACKAGE_VERSION', meson.project_version(), description: 'Define to the version of this package.')
conf_data.set_quoted('VERSION', meson.project_version(), description: 'Version number of package')

configure_file(input: 'config.hpp.meson',
               output: 'config.hpp',
               configuration: conf_data)
conf_inc = include_directories('.')

subdir('libdinoseq')
subdir('gui')
