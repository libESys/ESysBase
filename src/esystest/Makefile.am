## ****************************************************************************
##
## __legal_b__
## 
## Copyright (c) 2016 Michel Gillet  
## Distributed under the wxWindows Library Licence, Version 3.1. 
## (See accompanying file LICENSE_3_1.txt or 
## copy at http://www.wxwidgets.org/about/licence)
## 
## __legal_e__
##
## ****************************************************************************
##
##  src/esystest/Makefile.am
##  Process this file with automake to produce a Makefile.in file.
##
##  Original Author: Michel Gillet, 2016-07-26
##
## ****************************************************************************
##
##  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
##  changes you are making here.
##
##      Name, Affiliation, Date:
##  Description of Modification:
##
## ****************************************************************************


include $(top_srcdir)/config/Make-rules

lib_LTLIBRARIES = libesystest.la
libesystest_la_CXXFLAGS = $(AM_CXXFLAGS)
libesystest_la_LDFLAGS = $(EXTRA_LD_CONFIG)  \
        -lboost_program_options \
        ../../$(ESYS_LIB)/libesys.la

H_FILES =

CXX_FILES = \
    exception.cpp \
    globalfixture.cpp \
    logger.cpp \
    mastertestsuite.cpp \
    order.cpp \
    report.cpp \
    stdlogger.cpp \
    testcase.cpp \
    testcasectrlbase.cpp \
    testcaseinfo.cpp \
    testsuite.cpp \
    types.cpp
    

libesystest_la_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/esystest

libesystest_la_LIBADD= \
    ./boost/libesystest_boost.la

SUBDIRS = \
    boost \
    .

install-data-local:
    @$(NORMAL_INSTALL) \
    $(mkinstalldirs) $(INCLUDE_DIR) \
    for file in $(noinst_HEADERS); do \
      $(INSTALL_DATA) $(srcdir)/$$file $(INCLUDE_DIR)/$$file; \
    done

uninstall-local:
    @$(NORMAL_UNINSTALL) \
    for file in $(noinst_HEADERS); do \
      rm -f $(INCLUDE_DIR)/$$file; \
    done \
    -rmdir $(INCLUDE_DIR)



