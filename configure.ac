dnl ***************************************************************************
dnl
dnl The following code is derived, directly or indirectly, from the Mipi UniPro
dnl source code Copyright (c) 2004-2005 by all Contributors.
dnl All Rights reserved.
dnl
dnl  License stuff here ????????
dnl
dnl ***************************************************************************
dnl
dnl  configure.in --
dnl  Process this file with autoconf to produce a configure script.
dnl
dnl  Original Author: Michel Gillet, Nokia, 2005-09-05
dnl
dnl ***************************************************************************
dnl
dnl  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
dnl  changes you are making here.
dnl
dnl      Name, Affiliation, Date:
dnl  Description of Modification:
dnl
dnl ***************************************************************************

dnl
dnl Initialization.
dnl

AC_INIT(NEWS)
AC_CONFIG_HEADERS([include/esystest/unix/setup.h])
AC_CONFIG_AUX_DIR(config)

dnl
dnl Some simple checks.
dnl

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE(package,version,do-no-define)

AC_PROG_LIBTOOL

AM_PROG_AS
AC_PROG_CC
AC_PROG_CXX
dnl AC_PROG_RANLIB
AC_PROG_INSTALL

AC_DEFUN([AM_SYSTEMC],
[
test "${SYSTEMCNAME+set}" = set || SYSTEMCNAME="systemc"
AC_ARG_VAR([SYSTEMCNAME],[library name of systemc (defaults is systemc)])
])

AM_SYSTEMC

dnl C_ARG_VAR([SYSTEMC],[library name of systemc (defaults is systemc)])

dnl
dnl Set the compiler flags and target architecture.
dnl

CXX_COMP=`basename $CXX`

case "$target" in
    sparc-sun-solaris*)
        case "$CXX_COMP" in
            CC)
                EXTRA_CXXFLAGS=""
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="sparcOS5"
		AR_TOOL="$CXX -xar -o"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="gccsparcOS5"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="sparc-os2"
        ;;
    *linux*)
        case "$CXX_COMP" in
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="linux"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="iX86"
        ;;
    *cygwin*)
        case "$CXX_COMP" in
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="cygwin"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="iX86"
        ;;
    *hpux11*)
        case "$CXX_COMP" in
            aCC)
                EXTRA_CXXFLAGS="-Aa -ext +DA2.0 +DS2.0"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="+O1"
                TARGET_ARCH="hpux11"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS -Wa,-w36"
                ;;
            c++ | g++)
                EXTRA_CXXFLAGS="-Wall"
                DEBUG_CXXFLAGS="-g"
                OPT_CXXFLAGS="-O3"
                TARGET_ARCH="gcchpux11"
        	CC="$CXX"
        	CFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"
                ;;
            *)
                AC_MSG_ERROR("sorry...compiler not supported")
		;;
        esac
        QT_ARCH="hppa"
        ;;
    *)
        AC_MSG_ERROR("sorry...architecture not supported")
        ;;
esac

dnl
dnl extra "package" included ?
dnl

AC_ARG_WITH(mysystemc,         [[  --with-mysystemc[=VERSION] use mysystemc library]], [USE_MYSYSTEMC="yes" SYSTEMC_VER="$withval"],[USE_MYSYSTEMC="no" SYSTEMC_VER="$withval"])
AC_ARG_WITH(systemc,           [[  --with-systemc[=VERSION]   use systemc library]], [SYSTEMC_VER="$withval"],[SYSTEMC_VER="$withval"])
AC_ARG_WITH(modelsim,          [[  --with-modelsim[=VERSION]  use modelsim]], [MODELSIM_VER="$withval"],[MODELSIM_VER="$withval"])
AC_ARG_WITH(newran03,           [  --with-newran03         use newran03], [USE_NEWRAN="$withval"])
AC_ARG_ENABLE(dbg_class,        [  --enable-dbg_class      use dbg_class], [UP_DBG_CLASS="$enableval"])
AC_ARG_ENABLE(unipro_own_rc,    [  --disable-unipro_own_rc disable reference counting], [UNIPRO_OWN_RC="no"],[UNIPRO_OWN_RC="yes"])
dnl by default build with no aggregation
AC_ARG_ENABLE(up_agg,         [  --disable-up_agg      disable aggregation models], [UP_NOAGG="no"],[UP_NOAGG="yes"])
AC_ARG_WITH(systemc-path,
           [  --with-systemc-path         path to root installation of systemC],
  		   [
  		    SYSTEMC_PATH="$withval"
  		    EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -I${SYSTEMC_PATH}/include"
  		    EXTRA_LIBS="${EXTRA_LIBS} -L${SYSTEMC_PATH}/lib-${TARGET_ARCH}"
  		   ])

dnl
dnl --enable-debug
dnl
AC_ARG_ENABLE([debug],
                AC_HELP_STRING([--enable-debug],
                             [Enable debugging. default: disabled.]),
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -g"
                 DEBUG="yes"
                ],
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS}"
                 DEBUG="no"
                ])

dnl
dnl --disable-verbose
dnl Disable verbose compilation line (need special patch for automake/autoconf)
dnl
AC_ARG_ENABLE([verbose],
                AC_HELP_STRING([--disable-verbose],
                             [Display short compilation line. default: normal output.]),
                [
                 enable_niceoutput="yes"
                ],
                [
                 enable_niceoutput="no"
                ])

    AM_CONDITIONAL(NICEOUTPUT, test x$enable_niceoutput = xyes)

dnl
dnl --disable-systemc-warnings
dnl Disable systemc warnings
dnl
AC_ARG_ENABLE([systemc-warnings],
                AC_HELP_STRING([--disable-systemc-warnings],
                             [Disable compilation warnings for some systemc versions. default: enabled.]),
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -Wno-deprecated -Wno-char-subscripts"
                ])

 


dnl -------------------------------------------------------
dnl       Set the path of the XERCEC-C library  
dnl -------------------------------------------------------

dnl -------------------------------------------------------
dnl XERCES-C PATH
dnl -------------------------------------------------------
AC_ARG_WITH([xerces-c-root],
		AC_HELP_STRING([--with-xerces-c-root],
		[Set path to the Xerces-C headers and library. default: $(XERCESCROOT) ]),
		[
		 XERCESCROOT="${withval}"
		])
		
dnl -------------------------------------------------------
dnl --disable-xml-parser
dnl -------------------------------------------------------
AC_ARG_ENABLE([xml-parser],
                AC_HELP_STRING([--disable-xml-parser], 
                             [disable the XML parser version of the simulator. default: enabled.]),
                [
dnl Action if given: disable the feature 
		BUILD_XML_PARSER="no"
				],
                [
dnl Action if not given: By default enable it
		BUILD_XML_PARSER="yes"
dnl
dnl Check that Xerces-C is available
dnl
		DUMMY="dummy $XERCESCROOT"
		if test "$DUMMY" = "dummy " ; then
			AC_MSG_WARN([XERCESCROOT variable is not set, we suppose that Xerces headers are in the standard search path and that Xerces-C library is in LD_LIBRARY_PATH.])
		fi	
				
		])


dnl -------------------------------------------------------
dnl We now detect headers
dnl -------------------------------------------------------
dnl
dnl SystemC

dnl AC_CHECK_HEADER([systemc.h],
dnl	[
dnl Action if found 
dnl		echo 1 > /dev/null
dnl	],
dnl	[
dnl Action if not found
dnl	AC_MSG_ERROR([SystemC was not found in $SYSTEMC!])
dnl	])

dnl
dnl XERCES-C
dnl

old_c_include_path="$C_INCLUDE_PATH"
C_INCLUDE_PATH="$XERCESCROOT/include:$C_INCLUDE_PATH"
export C_INCLUDE_PATH

if test "$BUILD_XML_PARSER" = "yes" ; then
	AC_CHECK_HEADER([xercesc/util/PlatformUtils.hpp],
		[
dnl Action if found 
		echo 1 > /dev/null
		],
		[
dnl Action if not found
			AC_MSG_WARN([Xerces-C was not found in $XERCESCROOT!])
			AC_MSG_WARN([XML parser build disabled])
			BUILD_XML_PARSER="no"
		])
fi

C_INCLUDE_PATH="$old_c_include_path"
export C_INCLUDE_PATH


dnl -------------------------------------------------------
dnl We test the pragma
dnl -------------------------------------------------------
dnl
dnl __attribute__((unused))

AC_MSG_CHECKING([compiler support for __attribute__((unused))])
AC_TRY_CPP([static int __attribute__ ((unused)) test = 0;],
			[
				PRAGMA_UNSUSED_SUPP=yes
			],
			[
				PRAGMA_UNSUSED_SUPP=no
			]
		   )
AC_MSG_RESULT([$PRAGMA_UNSUSED_SUPP])

dnl -------------------------------------------------------
dnl create the config.h file
dnl -------------------------------------------------------
dnl

if test "$USE_MYSYSTEMC" = "yes" ; then	
    AC_DEFINE(MYSYSTEMC,[1],[Define to 1 if you want to use mysystemc library])
    SYSTEMCNAME="mysystemc"
fi

case "${SYSTEMC_VER}" in
  *2.0.1* | *201* )
    AC_DEFINE(SYSTEMC_201,[1],[Define to 1 if you want to use systemc 2.0.1 library])
  ;;
  *2.1* | *21* )
	AC_DEFINE(SYSTEMC_21,[1],[Define to 1 if you want to use systemc 2.1 library])
  ;;
  yes )
	SYSTEMC_VER=2.0.1
	AC_DEFINE(SYSTEMC_201,[1],[Define to 1 if you want to use systemc 2.0.1 library])
  ;;
  no )
	SYSTEMC_VER=2.0.1
	AC_DEFINE(SYSTEMC_201,[1],[Define to 1 if you want to use systemc 2.0.1 library])
  ;;
  *)
    AC_MSG_ERROR(unknown systemc version ${SYSTEMC_VER}.)
esac

if test "$USE_NEWRAN" = "yes" ; then	
    AC_DEFINE(USE_NEWRAN,[1],[Define to 1 if you have newran03 library])
    LIBS="$LIBS -lmynewran03"
fi

if test "$UP_DBG_CLASS" = "yes" ; then	
    AC_DEFINE(UP_DBG_CLASS,[1],[Define to 1 if you have want to use dbg_class feature])
fi

if test "$UNIPRO_OWN_RC" = "yes" ; then	    
	AC_DEFINE(UNIPRO_OWN_RC,[1],[Unipro own reference counting])
fi

if test "$UP_NOAGG" = "yes" ; then	    
	AC_DEFINE(__UP_NOAGG,[1],[Unipro models with no aggregation])
fi

if test "$BUILD_XML_PARSER" = "yes" ; then
    AC_DEFINE(__BUILD_XML_PARSER,[1],[Unipro models with XML parser])
    DUMMY="dummy $XERCESCROOT"
    if test "$DUMMY" = "dummy " ; then
        OPT_CXXFLAGS="${OPT_CXXFLAGS} "
        EXTRA_LIBS="${EXTRA_LIBS} "
    else
        OPT_CXXFLAGS="${OPT_CXXFLAGS} -I${XERCESCROOT}/include"
        EXTRA_LIBS="${EXTRA_LIBS} -L${XERCESCROOT}/lib"
    fi
    LIBS="$LIBS -lxerces-c"
    XML_PARSER_DIR="unipro_xml"

fi

if test "$PRAGMA_UNSUSED_SUPP" = "yes" ; then
    AC_DEFINE(UP_PRAGMA_UNSUSED_SUPP,[1],[Define to 1 if the __attribute__((unused)) is supported])
fi

case "${MODELSIM_VER}" in
  *5.8* | *58* )
    AC_DEFINE(SYSTEMC_201,[1],[Define to 1 if you want to use systemc 2.0.1 library])
  ;;
  *6.0* | *60* )
	AC_DEFINE(SYSTEMC_21,[1],[Define to 1 if you want to use systemc 2.1 library])
  ;;
  *6.1* | *61* )
	AC_DEFINE(SYSTEMC_21,[1],[Define to 1 if you want to use systemc 2.1 library])
  ;;
  yes )
	SYSTEMC_VER=2.0.1
	AC_DEFINE(SYSTEMC_201,[1],[Define to 1 if you want to use systemc 2.0.1 library])
esac

LIBS="$LIBS $EXTRA_LIBS"

EXTRA_CXXFLAGS="$EXTRA_CXXFLAGS"
CXXFLAGS="$EXTRA_CXXFLAGS $OPT_CXXFLAGS"


dnl
dnl Substitution variables.
dnl

AC_SUBST(EXTRA_CXXFLAGS)
AC_SUBST(DEBUG_CXXFLAGS)
AC_SUBST(OPT_CXXFLAGS)
AC_SUBST(TARGET_ARCH)
AC_SUBST(QT_ARCH)
dnl AC_SUBST(LIBS)
AC_SUBST(XERCESCROOT)
AC_SUBST(BUILD_XML_PARSER)
AC_SUBST(XML_PARSER_DIR)

dnl
dnl Create the Makefiles.
dnl

AC_OUTPUT(Makefile
src/esystest/Makefile
src/esystest_t/Makefile
src/Makefile)

dnl -------------------------------------------------------
dnl       Do the reporting.  
dnl -------------------------------------------------------
echo "********************************************************"

echo "The value of SYSTEMCNAME is ${SYSTEMCNAME}"
echo "The value of MYSYSTEMC is ${USE_MYSYSTEMC:-no}"
echo "The value of SYSTEMC_VER is ${SYSTEMC_VER}"
echo "The value of USE_NEWRAN is ${USE_NEWRAN:-no}"
echo "The value of UP_DBG_CLASS is ${UP_DBG_CLASS:-no}"
echo "The value of UNIPRO_OWN_RC is ${UNIPRO_OWN_RC}"
echo "The value of UP_NOAGG is ${UP_NOAGG}"
echo "The value of XERCESCROOT is ${XERCESCROOT}"
echo "The value of BUILD_XML_PARSER is ${BUILD_XML_PARSER}"
echo "The value of DEBUG is ${DEBUG}"

dnl done
