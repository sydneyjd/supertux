#!/bin/sh
xgettext --keyword='_' -C -o translations/messages.pot `find src -name "*.cpp"`
for LEVELSET in `ls data/levels`; do
  find data/levels/$LEVELSET "(" -name "*.stl" -or -name "*.stwm" -or -name "*.txt" ")" -print0 | xargs -0 xgettext --keyword='_:1' --language=Lisp --sort-by-file --output translations/$LEVELSET.pot
done
