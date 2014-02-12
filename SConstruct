# -*- python -*-

env = Environment(CPPFLAGS=['-g','-Wall'])

import re

env['prefix'] = '/usr/local'
env['exec_prefix'] = env['prefix']
env['libdir'] = env['prefix']+'/lib'
env['includedir'] = env['prefix']+'/include'
env['VERSION'] = '0.1.0'
env['PREFIX'] = env['prefix']

def patch_src(env, target, source):
    out = open(str(target[0]), "wb")
    inp = open(str(source[0]), "r")

    in_area = 0
    for line in inp.readlines():
        if in_area:
            line = re.sub('G_TYPE_OBJECT',
                          'GTK_TYPE_ADJUSTMENT',
                          line)
            if re.search(r'\);', line):
                in_area=0
        else:
            if re.search(r"object_signals\[SET_SCROLL_ADJUSTMENTS_SIGNAL\]",line):
                in_area=1

        out.write(line)
        
    out.close()
    inp.close()


# All purpose template filling routine
def template_fill(env, target, source):
    out = open(str(target[0]), "wb")
    inp = open(str(source[0]), "r")

    for line in inp.readlines():
        line = re.sub('@(.*?)@',
                      lambda x: env[x.group(1)],
                      line)
        out.write(line)
        
    out.close()
    inp.close()

env.ParseConfig("pkg-config --cflags --libs gtk+-2.0")

src = ["testgtkimageviewer.c", 
       "gtk-image-viewer-fixed.c"
       ]

lib = env.Library('gtkimageviewer-1.0',
                  ['gtk-image-viewer-fixed.c'])
include = ['gtk-image-viewer.h']
env.Command("gtk-image-viewer-fixed.c",
            ["gtk-image-viewer.c"],
            patch_src)

env.Program("testgtkimageviewer",
            ['testgtkimageviewer.c', lib])

for gob in ("gtk-image-viewer",
            ) :
    env.Command([gob + ".c",
                 gob + ".h"
                 ],
                [gob + ".gob"],
                ["gob2 -o ${SOURCES.dir}  $SOURCES"]
                )

env.Command("gtkimageviewer.pc",
            ["gtkimageviewer.pc.in"],
            template_fill)

env.Alias("install",
          [env.Install('${PREFIX}/lib',
                       lib),
           env.Install('${PREFIX}/include/gtkimageviewer-1.0/gtkimageviewer',
                       include),
           env.AlwaysBuild(env.Install('${PREFIX}/lib/pkgconfig',
                                       'gtkimageviewer.pc')),
           ],
          )
