project('gtkimageviewer',['cpp','c'], version: '0.9.3')
gtkdep = dependency('gtk+-3.0')
incs = include_directories('src')
interface_age = 0
interface_version = 0
soversion = 0
libversion = '@0@.@1@.0'.format(soversion, interface_version, interface_age)
gtkdep = dependency('gtk+-3.0')
subdir('src')
subdir('examples')

# gtkimageviewer.pc
pkg = import('pkgconfig')
pkg.generate(name: 'GtkImageViewer',
  filebase: 'gtkimagevewer',
  description: 'A zoomable image viewer for gtk',
  libraries: libgtkimageviewer, 
  subdirs: 'lib',
  version: meson.project_version())
