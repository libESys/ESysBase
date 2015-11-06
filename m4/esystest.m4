AC_DEFUN([AM_SYSTEMC],
[
test "${SYSTEMCNAME+set}" = set || SYSTEMCNAME=systemc
SYSTEMCNAME=systemc
AC_ARG_VAR([SYSTEMCNAME],[library name of systemc (defaults is systemc)])
])