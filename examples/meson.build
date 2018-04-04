subdir('agg')

m_dep = cc.find_library('m', required : false)
expat_dep = cc.find_library('expat', required : true)

executable('mandelbrot',
  'mandelbrot.c',
  include_directories: incs,
  link_with: libgtkimageviewer,
  install: false,
  dependencies : [gtkdep, m_dep]
  )

executable('test_file',
  'test_file.c',
  include_directories: incs,
  link_with: libgtkimageviewer,
  install: false,
  dependencies : [gtkdep, m_dep]
  )

executable('test_scroll',
  'test_scroll.c',
  include_directories: incs,
  link_with: libgtkimageviewer,
  install: false,
  dependencies : [gtkdep, m_dep]
  )

executable('testgtkimageviewer',
  'testgtkimageviewer.c',
  include_directories: incs,
  link_with: libgtkimageviewer,
  install: false,
  dependencies : [gtkdep, m_dep]
  )

executable('agg-lion',
  'agg-lion.cc',
  include_directories: incs,
  link_with: [libgtkimageviewer, libagg],
  install: false,
  dependencies : [gtkdep, m_dep, expat_dep]
  )

executable('agg-circles',
  'agg-circles.cc',
  include_directories: incs,
  link_with: [libgtkimageviewer, libagg],
  install: false,
  dependencies : [gtkdep, m_dep, expat_dep]
  )

executable('cairo-circles',
  'cairo-circles.c',
  include_directories: incs,
  link_with: [libgtkimageviewer],
  install: false,
  dependencies : [gtkdep, m_dep]
  )

executable('hello_image_viewer',
  'hello_image_viewer.c',
  include_directories: incs,
  link_with: [libgtkimageviewer],
  install: false,
  dependencies : [gtkdep, m_dep]
  )


