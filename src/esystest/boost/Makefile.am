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
##  src/esystest/boost/Makefile.am
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

noinst_LTLIBRARIES = libesystest_boost.la
libesystest_boost_la_CXXFLAGS = $(AM_CXXFLAGS) -std=c++11
libesystest_boost_la_LDFLAGS = $(EXTRA_LD_CONFIG) \
    -lboost_filesystem \
    -lboost_system \
    -lboost_date_time

H_FILES =

CXX_FILES = \
    testcasectrl_boost.cpp

libesystest_boost_la_SOURCES = $(H_FILES) $(CXX_FILES) 

INCLUDE_DIR = $(prefix)/include/esystest/boost



