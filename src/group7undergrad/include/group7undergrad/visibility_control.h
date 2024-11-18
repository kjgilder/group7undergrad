#ifndef GROUP7UNDERGRAD__VISIBILITY_CONTROL_H_
#define GROUP7UNDERGRAD__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define GROUP7UNDERGRAD_EXPORT __attribute__ ((dllexport))
    #define GROUP7UNDERGRAD_IMPORT __attribute__ ((dllimport))
  #else
    #define GROUP7UNDERGRAD_EXPORT __declspec(dllexport)
    #define GROUP7UNDERGRAD_IMPORT __declspec(dllimport)
  #endif
  #ifdef GROUP7UNDERGRAD_BUILDING_LIBRARY
    #define GROUP7UNDERGRAD_PUBLIC GROUP7UNDERGRAD_EXPORT
  #else
    #define GROUP7UNDERGRAD_PUBLIC GROUP7UNDERGRAD_IMPORT
  #endif
  #define GROUP7UNDERGRAD_PUBLIC_TYPE GROUP7UNDERGRAD_PUBLIC
  #define GROUP7UNDERGRAD_LOCAL
#else
  #define GROUP7UNDERGRAD_EXPORT __attribute__ ((visibility("default")))
  #define GROUP7UNDERGRAD_IMPORT
  #if __GNUC__ >= 4
    #define GROUP7UNDERGRAD_PUBLIC __attribute__ ((visibility("default")))
    #define GROUP7UNDERGRAD_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define GROUP7UNDERGRAD_PUBLIC
    #define GROUP7UNDERGRAD_LOCAL
  #endif
  #define GROUP7UNDERGRAD_PUBLIC_TYPE
#endif
#endif  // GROUP7UNDERGRAD__VISIBILITY_CONTROL_H_
// Generated 18-Nov-2024 12:50:31
// Copyright 2019-2020 The MathWorks, Inc.
