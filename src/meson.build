gob2 = find_program('gob2')
patch_src = find_program('patch_src')

gen_src = custom_target('gen-output',
  output : ['gtk-image-viewer.c','gtk-image-viewer.h','gtk-image-viewer-private.h'],
  input : 'gtk-image-viewer.gob',
  command : [gob2, '-o', '@OUTDIR@', '@INPUT@'],
  )

fixed_src = custom_target('patch-output',
  output : ['gtk-image-viewer-fixed.c'],
  input : gen_src,
  command : [patch_src, '@INPUT0@','@OUTPUT@'],
  )

cc = meson.get_compiler('cpp')
m_dep = cc.find_library('m', required : false)

libgtkimageviewer = library('gtkimageviewer',
  fixed_src, 
  include_directories: incs,
  version: libversion,
  soversion: soversion,
  install: true,
  dependencies : [gtkdep, m_dep]
)
