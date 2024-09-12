dino_src = [
  'main.cpp',
  'cceditor.cpp',
  'controllerdialog.cpp',
  'dinogui.cpp',
  'infoeditor.cpp',
  'noteeditor.cpp',
  'octavelabel.cpp',
  'patterneditor.cpp',
  'patterndialog.cpp',
  'ruler.cpp',
  'sequenceeditor.cpp',
  'singletextcombo.cpp',
  'tempolabel.cpp',
  'tempowidget.cpp',
  'trackdialog.cpp',
  'tracklabel.cpp',
  'trackwidget.cpp'
]

executable('dino', dino_src,
           dependencies: [libglademm_dep, libxmlpp_dep, jack_dep, lash_dep, libdinoseq_dep],
           cpp_args: ['-DDATA_DIR="@0@"'.format(dir_pkgdata)],
           include_directories: [conf_inc],
           install: true)
