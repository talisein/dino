libdinoseq_src = [
#  'controller_numbers.hpp',
  'controller.cpp',
#  'controller.hpp',
#  'deleter.hpp',
  'interpolatedevent.cpp',
#  'interpolatedevent.hpp',
  'midibuffer.cpp',
#  'midibuffer.hpp',
  'note.cpp',
#  'note.hpp',
  'notecollection.cpp',
#  'notecollection.hpp',
  'noteevent.cpp',
#  'noteevent.hpp',
  'pattern.cpp',
#  'pattern.hpp',
  'patternselection.cpp',
#  'patternselection.hpp',
  'track.cpp',
#  'track.hpp',
  'song.cpp',
#  'song.hpp',
#  'ringbuffer.hpp',
  'sequencer.cpp',
#  'sequencer.hpp',
  'tempomap.cpp',
#  'tempomap.hpp',
#  'cdtree.hpp',
#  'debug.hpp',
  'debug.cpp',
#  'xmlserialisable.hpp'
]

libdinoseq_inc = include_directories('.')
libdinoseq_lib = static_library('dinoseq', libdinoseq_src,
                                dependencies: [libxmlpp_dep, libsigcpp_dep, jack_dep])

libdinoseq_dep = declare_dependency(link_with: libdinoseq_lib,
                                    dependencies: [libxmlpp_dep, libsigcpp_dep, jack_dep],
                                    include_directories: libdinoseq_inc)
