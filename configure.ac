dnl ***************************************************************************
dnl
dnl __legal_b__
dnl __legal_e__
dnl
dnl ***************************************************************************
dnl
dnl  configure.ac --
dnl  Process this file with autoconf to produce a configure script.
dnl
dnl  Original Author: Michel Gillet, 2016-07-26
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

AC_INIT([esystest], [0.0.1])
AC_CONFIG_HEADERS([include/esystest/unix/setup.h])

AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE
AC_CONFIG_MACRO_DIR([m4])

echo "********************************************************"
echo "** esystest                                           **"
echo "********************************************************"

AC_CANONICAL_BUILD
dnl AC_INCLUDES_DEFAULT
AC_CHECK_HEADERS([stdint.h], [ESYS_HAVE_STDINT_H="1"], [ESYS_HAVE_STDINT_H="0"])
AC_CHECK_HEADERS([inttypes.h], [ESYS_HAVE_INTTYPES_H="1"], [ESYS_HAVE_INTTYPES_H="0"])

dnl
dnl Some simple checks.
dnl

LT_INIT

AM_PROG_AS
AC_PROG_CC
AC_PROG_CXX
dnl AC_PROG_RANLIB
AC_PROG_INSTALL

AX_BOOST_BASE([1.5], [HAS_BOOST="yes"], [HAS_BOOST="no"])
dnl BOOST_REQUIRE
dnl BOOST_FIND_HEADER([boost/lexical_cast.hpp],
dnl [
dnl HAS_BOOST="no"
dnl ],
dnl [
dnl ESYS_BOOST=1
dnl HAS_BOOST="yes"
dnl AC_DEFINE(ESYS_BOOST,[1],[Boost is present])
dnl ])

AC_ARG_ENABLE(samples,
                AS_HELP_STRING([--enable-samples], 
                             [build also the samples default: not build.]),
                [
dnl Action if given: disable the feature 
        BUILD_SAMPLES="yes"
        AC_DEFINE(BUILD_SAMPLES,[1],[Build the samples])
                ],
                [
dnl Action if not given: By default enable it
        BUILD_SAMPLES="no"

        ])
        
        
if test "$BUILD_SAMPLES" = "yes" ; then     
    SAMPLES_DIR="samples"
    
fi


dnl
dnl extra "package" included ?
dnl

AC_ARG_ENABLE(dbg_class,        [  --enable-dbg_class      use dbg_class], [UP_DBG_CLASS="$enableval"])


dnl
dnl --enable-debug
dnl
AC_ARG_ENABLE([debug],
                AS_HELP_STRING([--enable-debug],
                             [Enable debugging. default: disabled.]),
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS} -g"
                 DEBUG="yes"
                ],
                [
                 EXTRA_CXXFLAGS="${EXTRA_CXXFLAGS}"
                 DEBUG="no"
                ])

                
dnl --enable-usewx
dnl
AC_ARG_ENABLE([usewx],
                AS_HELP_STRING([--enable-usewx],
                             [Enable usage of wxWidgets. default: enabled.]),
                [
                 USE_WX="$enableval"
                ],
                [
                 USE_WX="yes"
                ])
                
dnl --enable-multios
dnl
AC_ARG_ENABLE([multios],
                AS_HELP_STRING([--enable-multios],
                             [Enable usage multios support. default: enabled.]),
                [
                 MULTIOS="$enableval"
                ],
                [
                 MULTIOS="yes"
                ])

dnl --disable-mp
dnl
AC_ARG_ENABLE([mp],
                AS_HELP_STRING([--disable-mp],
                             [Disable multiplaform build. default: enabled.]),
                [
                 ESYS_MULTI_PLAT="$enableval"
                ],
                [
                 ESYS_MULTI_PLAT="yes"
                ])
                
dnl
dnl --disable-verbose
dnl Disable verbose compilation line (need special patch for automake/autoconf)
dnl
AC_ARG_ENABLE([verbose],
                AS_HELP_STRING([--disable-verbose],
                             [Display short compilation line. default: normal output.]),
                [
                 enable_niceoutput="yes"
                ],
                [
                 enable_niceoutput="no"
                ])

    AM_CONDITIONAL(NICEOUTPUT, test x$enable_niceoutput = xyes)


AC_ARG_WITH([board], 
                AS_HELP_STRING([--with-board=BOARD],
                             [Set the board to build for]),
                [
                 ESYS_BOARD="${withval}"
                ],
                [
                 ESYS_BOARD=""
                ])
    
dnl -------------------------------------------------------
dnl We now detect headers
dnl -------------------------------------------------------
dnl

dnl -------------------------------------------------------
dnl create the config.h file
dnl -------------------------------------------------------
dnl

CFG_VHW_LIBS="no"

if test "$ESYS_BOARD" = "vhw" ; then
    CFG_VHW_LIBS="yes"
else
    UP_DBG_CLASS="no"
    USE_WX="no"
    ESYS_MULTI_PLAT="no"
    MULTIOS="no"
fi

AM_CONDITIONAL([ESYS_VHW], [test "$ESYS_BOARD" = "vhw"])

if test "$UP_DBG_CLASS" = "yes" ; then  
    AC_DEFINE(UP_DBG_CLASS,[1],[Define to 1 if you have want to use dbg_class feature])
    AC_DEFINE(DBG_LOG,[1],[Define to 1 if you have want to use dbg_class feature])
fi

if test "$USE_WX" = "yes" ; then
    AC_DEFINE(ESYS_USE_WX,[1],[Define to 1 if you have want to use wxWdigets implementation of some classes])
fi

if test "$ESYS_MULTI_PLAT" = "yes" ; then
    AC_DEFINE(ESYS_MULTI_PLAT,[1],[Define to 1 if you have want to build the multiplaform library])
fi

if test "$MULTIOS" = "yes" ; then
    AC_DEFINE(MULTIOS,[1],[Define to 1 if you have want to use multios implementation of some classes])
    ESYS_MULTIOS="1"
else
    ESYS_MULTIOS="0"
fi

if test "$HAS_BOOST" = "yes" ; then
    echo "The value of HAS_BOOST yes is ${HAS_BOOST}"
else
    echo "The value of HAS_BOOST no is ${HAS_BOOST:-no}"
fi

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
AC_SUBST(SAMPLES_DIR)
AC_SUBST(ESYS_HAVE_STDINT_H)
AC_SUBST(ESYS_HAVE_INTTYPES_H)
AC_SUBST(ESYS_MULTIOS)
AC_SUBST(USE_WX)
AC_SUBST(ESYSCFG)

dnl Takes the environment variable ESYS_DEV and make it available to all Makefile as ESYS_DEV
AC_SUBST(ESYS_DEV, ${ESYS_DEV})

dnl
dnl Create the Makefiles.
dnl

AC_OUTPUT(Makefile
src/Makefile
src/esystest/Makefile
src/esystest/boost/Makefile

src/esystest_t/Makefile
)

dnl -------------------------------------------------------
dnl       Do the reporting.  
dnl -------------------------------------------------------

echo "The value of HAS_BOOST is       ${HAS_BOOST:-no}"
echo "The value of USE_WX is          ${USE_WX:-no}"
echo "The value of ESYS_MULTI_PLAT is ${ESYS_MULTI_PLAT:-no}"
echo "The value of MULTIOS is         ${MULTIOS:-no}"
echo "The value of UP_DBG_CLASS is    ${UP_DBG_CLASS:-no}"
echo "The value of DEBUG is           ${DEBUG}"
echo " "

dnl done
