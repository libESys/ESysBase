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
##  src/esystest_t/Makefile.am
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

##lib_LTLIBRARIES = libesystest_tc.la
##libesystest_tc_la_CXXFLAGS = $(AM_CXXFLAGS)
##libesystest_tc_la_LDFLAGS = $(EXTRA_LD_CONFIG)        

bin_PROGRAMS = esystest_t
esystest_t_CXXFLAGS = $(AM_CXXFLAGS) -DBOOST_ALL_DYN_LINK -std=c++11 \
    -I$(top_srcdir)/../../$(ESYS)/include

esystest_t_LDFLAGS = $(EXTRA_LD_CONFIG) \
    -lboost_unit_test_framework \
    -lboost_system \
    -lboost_thread \
    -lboost_filesystem \
    -lboost_program_options \
    ../../$(ESYS_LIB)/libesys.la \
    ../esystest/libesystest.la
    
H_FILES =

CXX_FILES = \
    test01.cpp \
    test02.cpp \
    test03.cpp \
    unittest.cpp

    
esystest_t_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/esystest_t

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


